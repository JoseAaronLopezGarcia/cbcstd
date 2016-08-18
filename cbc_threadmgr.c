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

#include <cbc_threadmgr.h>
#include <types/cbc_threading.h>
#include <collections/cbc_hashmap.h>

static cbc_Mutex_struct threadmgr_mutex;
static cbc_HashMap_struct threadmap;

void _cbc_initThreadMgr(){
	cbc_Mutex___init__(&threadmgr_mutex);
	cbc_HashMap___init__(&threadmap);
}

cbc_thread_t cbc_getThreadId(){
	return pthread_self();
}

cbc_bool cbc_equalThreads(cbc_thread_t thread1, cbc_thread_t thread2){
	return pthread_equal(thread1, thread2);
}

cbc_ThreadBuffer* cbc_getThreadBuffer(cbc_thread_t curThread){
	cbc_ThreadBuffer* threadbuf = cbc_HashMap_get(&threadmap, curThread);
	if (threadbuf == cbc_getNone()){
		threadbuf = (cbc_ThreadBuffer*)cbc_alloc(sizeof(cbc_ThreadBuffer));
		threadbuf->thread = curThread;
		threadbuf->exc_buf = NULL;
		threadbuf->raised = NULL;
		threadbuf->first_trace = NULL;
		threadbuf->last_trace = NULL;
		cbc_Mutex_lock(&threadmgr_mutex);
		cbc_HashMap_insert(&threadmap, curThread, threadbuf);
		cbc_Mutex_unlock(&threadmgr_mutex);
	}
	return threadbuf;
}

cbc_ThreadBuffer* cbc_getCurrentThreadBuffer(){
	return cbc_getThreadBuffer(cbc_getThreadId());
}
