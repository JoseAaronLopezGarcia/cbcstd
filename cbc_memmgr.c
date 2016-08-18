/*

 * Copyright 2016 by Jose Aaron Lopez Garcia <joseaaronlopez@gmail.com>

 * This file is part of cbcstd.

 * cbcstd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * cbcstd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with cbcstd. If not, see <http://www.gnu.org/licenses/ .
 */

#include <cbcstd.h>

#include <types/cbc_threading.h>
#include <exceptions/cbc_out_of_mem.h>

#define MAX_MEM_CHUNKS 20

typedef struct _cbc_Mem_Chunk{
	void* ptr;
	size_t size;
}_cbc_Mem_Chunk;

static cbc_OutOfMemoryError_struct _out_of_mem;
static cbc_OutOfMemoryError out_of_mem;
static cbc_Mutex_struct _memmgr_mutex;
static cbc_Mutex memmgr_mutex = NULL;

static cbc_bool _cbc_memmgr_started = cbc_false;
static _cbc_Mem_Chunk __cbc_mem_chunk__[MAX_MEM_CHUNKS] = {0};

static cbc_var _findMemChunk(size_t size){
	// reverse find the best fit
	int i; for (i=MAX_MEM_CHUNKS-1; i>=0; i--){
		if (__cbc_mem_chunk__[i].size >= size){
			cbc_var ptr = (cbc_var)(__cbc_mem_chunk__[i].ptr);
			// relocate other chunks
			int j; for (j=i; j<MAX_MEM_CHUNKS-1; j++){
				__cbc_mem_chunk__[j].ptr = __cbc_mem_chunk__[j+1].ptr;
				__cbc_mem_chunk__[j].size = __cbc_mem_chunk__[j+1].size;
			}
			// free memory
			__cbc_mem_chunk__[MAX_MEM_CHUNKS-1].ptr = 0;
			__cbc_mem_chunk__[MAX_MEM_CHUNKS-1].size = 0;
			cbc_Mutex_unlock(memmgr_mutex);
			return ptr;
		}
	}
	return (cbc_var)0;
}

static cbc_var _addMemChunk(cbc_var ptr){
	size_t size = *(size_t*)((size_t)ptr-sizeof(size_t));
	int i; for (i=0; i<MAX_MEM_CHUNKS; i++){
		if (__cbc_mem_chunk__[i].size < size){
			void* aux_ptr = __cbc_mem_chunk__[MAX_MEM_CHUNKS-1].ptr;
			int j; for(j=MAX_MEM_CHUNKS-1; j>i; j--){
				__cbc_mem_chunk__[j].ptr = __cbc_mem_chunk__[j-1].ptr;
				__cbc_mem_chunk__[j].size = __cbc_mem_chunk__[j-1].size;
			}
			__cbc_mem_chunk__[i].ptr = ptr;
			__cbc_mem_chunk__[i].size = size;
			if (aux_ptr) free((void*)((size_t)aux_ptr-sizeof(size_t)));
		}
	}
}

cbc_var cbc_alloc(cbc_var size){

	if (size == 0)
		return 0;

	if (!_cbc_memmgr_started)
		return (cbc_var)malloc((size_t)size); // forward to basic malloc

	cbc_Mutex_lock(memmgr_mutex);

	if (!_cbc_memmgr_started){
		cbc_Mutex_unlock(memmgr_mutex);
		return (cbc_var)malloc((size_t)size); // forward to basic malloc
	}
	
	cbc_var ret = _findMemChunk((size_t)size);
	cbc_Mutex_unlock(memmgr_mutex);
	if (ret == 0){
		cbc_var ret = (cbc_var)malloc((size_t)size+sizeof(size_t));
		if (ret == 0){
			cbc_throw(out_of_mem);
		}
		*(size_t*)ret = size;
		ret = (cbc_var)((size_t)ret + sizeof(size_t));
	}
	return ret;
}

cbc_var cbc_dealloc(cbc_var ptr){
	if (ptr && _cbc_memmgr_started){
		cbc_Mutex_lock(memmgr_mutex);
		if (!_cbc_memmgr_started)
			free(ptr);
		else
			_addMemChunk(ptr);
		cbc_Mutex_unlock(memmgr_mutex);
	}
	return cbc_getNone();
}

void _cbc_initMemoryMgr(){
	out_of_mem = &_out_of_mem;
	cbc_OutOfMemoryError___init__(out_of_mem);
	memmgr_mutex = &_memmgr_mutex;
	cbc_Mutex___init__(memmgr_mutex);
	//_cbc_memmgr_started = cbc_true;
}

cbc_var cbc_startMemoryManager(){
	cbc_Mutex_lock(memmgr_mutex);
	_cbc_memmgr_started = cbc_true;
	cbc_Mutex_unlock(memmgr_mutex);
	return cbc_true;
}

cbc_var cbc_stopMemoryManager(){
	cbc_Mutex_lock(memmgr_mutex);
	_cbc_memmgr_started = cbc_false;
	cbc_Mutex_unlock(memmgr_mutex);
	return cbc_false;
}
