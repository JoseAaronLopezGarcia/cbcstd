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

#include <collections/cbc_staticarray.h>

static cbc_var _cbc_StaticArray_type[4] = {
	CBC_STATIC_ARRAY_ID,
	CBC_LIST_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_StaticArray_Class_struct _cbc_StaticArray___class__ = {
	.__type__ = _cbc_StaticArray_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_StaticArray___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
	.get = &cbc_StaticArray_get,
	.set = &cbc_StaticArray_set,
	.del = &cbc_StaticArray_del,
	.add = &cbc_StaticArray_add,
	.checkSize = &cbc_StaticArray_checkSize,
	.checkIndex = &cbc_StaticArray_checkIndex,
	.size = &cbc_StaticArray_size
};

cbc_var* cbc_StaticArray___type__ = _cbc_StaticArray_type;
cbc_var cbc_StaticArray___size__ = sizeof(cbc_StaticArray_struct);

cbc_StaticArray cbc_StaticArray___new__(cbc_var max){
	cbc_StaticArray self = (cbc_StaticArray)cbc_alloc(cbc_StaticArray___size__);
	void* exception = NULL;
	cbc_try{
		cbc_StaticArray___init__(self, max);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_StaticArray___init__(cbc_StaticArray self, cbc_var max){
	cbc_StaticArray___sysinit__(self);
	cbc_StaticArray___usrinit__(self, max);
	return self;
}

static cbc_var _cbc_StaticArray___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_LIST_ID:
		case CBC_STATIC_ARRAY_ID:
		case CBC_OBJECT_ID: return &_cbc_StaticArray___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_STATIC_ARRAY_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_StaticArray___sysinit__(cbc_StaticArray self){
	self->__getclass__ = &_cbc_StaticArray___getclass__;
	return self;
}

cbc_var cbc_StaticArray___usrinit__(cbc_StaticArray self, cbc_var max){
	self->_max = max;
	self->_size = 0;
	self->_buf = CBC_NEW(cbc_var, max);
	return self;
}
	
cbc_var cbc_StaticArray_insert(cbc_StaticArray self, cbc_var data, cbc_var pos){
	return data;
}

cbc_var cbc_StaticArray_add(cbc_StaticArray self, cbc_var data){
	cbc_StaticArray_Class cls = self->__getclass__(0);
	cls->checkSize(self);
	self->_buf[self->_size++] = data;
	return data;
}

cbc_var cbc_StaticArray_get(cbc_StaticArray self, cbc_var pos){
	cbc_StaticArray_Class cls = self->__getclass__(0);
	pos = cls->checkIndex(self, pos);
	return self->_buf[(int)pos];
}

cbc_var cbc_StaticArray_set(cbc_StaticArray self, cbc_var pos, cbc_var data){
	cbc_StaticArray_Class cls = self->__getclass__(0);
	pos = cls->checkIndex(self, pos);
	self->_buf[(int)pos] = data;
	return data;
}

cbc_var cbc_StaticArray_del(cbc_StaticArray self, cbc_var pos){
	cbc_StaticArray_Class cls = self->__getclass__(0);
	
	cbc_var ret = cls->get(self, pos);

	int i;
	for (i=(int)pos+1; i<self->_size; i++){
		self->_buf[(int)pos++] = self->_buf[i];
	}
	self->_size--;

	for (i=self->_size; i<self->_max; i++){
		self->_buf[i] = 0;
	}
	
	return ret;
}

cbc_var cbc_StaticArray_contains(cbc_StaticArray self, cbc_var data){
	int i;
	for (i=0; i<self->_size; i++){
		if (self->_buf[i] == data)
			return (cbc_var)-1;
	}
	return (cbc_var)0;
}

cbc_var cbc_StaticArray_size(cbc_StaticArray self){
	return self->_size;
}

cbc_var cbc_StaticArray___end__(cbc_StaticArray self){
	cbc_dealloc(self->_buf);
	return cbc_getNone();
}
	
cbc_var cbc_StaticArray_checkIndex(cbc_StaticArray self, cbc_var index){
	if ((int)index >= self->_size || (int)index < 0){
		fprintf(stderr, "Out of bounds exception\n");
		exit(-1);
	}
	return index;
}

cbc_var cbc_StaticArray_checkSize(cbc_StaticArray self){
	if (self->_size >= self->_max){
		fprintf(stderr, "Array full\n");
		exit(-1);
	}
	return cbc_getNone();
}
