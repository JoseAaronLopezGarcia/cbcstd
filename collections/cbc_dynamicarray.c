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

#include <collections/cbc_dynamicarray.h>

#define ARRAY_CHUNK_max 10

static cbc_var _cbc_DynamicArray_type[4] = {
	CBC_DYNAMIC_ARRAY_ID,
	CBC_STATIC_ARRAY_ID,
	CBC_LIST_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_DynamicArray_Class_struct _cbc_DynamicArray___class__ = {
	.__type__ = _cbc_DynamicArray_type,
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
	.checkSize = &cbc_DynamicArray_checkSize,
	.checkIndex = &cbc_StaticArray_checkIndex,
	.size = &cbc_StaticArray_size,
	.resize = &cbc_DynamicArray_resize,
	.fit = &cbc_DynamicArray_fit
};

cbc_var* cbc_DynamicArray___type__ = _cbc_DynamicArray_type;
cbc_var cbc_DynamicArray___max__ = sizeof(cbc_DynamicArray_struct);

cbc_DynamicArray cbc_DynamicArray___new__(){
	cbc_DynamicArray self = (cbc_DynamicArray)cbc_alloc(cbc_DynamicArray___max__);
	void* exception = NULL;
	cbc_try{
		cbc_DynamicArray___init__(self);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_DynamicArray___init__(cbc_DynamicArray self){
	cbc_DynamicArray___sysinit__(self);
	cbc_DynamicArray___usrinit__(self);
	return self;
}

static cbc_var _cbc_DynamicArray___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_LIST_ID:
		case CBC_DYNAMIC_ARRAY_ID:
		case CBC_OBJECT_ID: return &_cbc_DynamicArray___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_DYNAMIC_ARRAY_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_DynamicArray___sysinit__(cbc_DynamicArray self){
	self->__getclass__ = &_cbc_DynamicArray___getclass__;
	return self;
}

cbc_var cbc_DynamicArray___usrinit__(cbc_DynamicArray self){
	self->_buf = NULL;
	self->_size = 0;
	self->_max = 0;
	return self;
}

cbc_var cbc_DynamicArray_checkSize(cbc_DynamicArray self){
	cbc_DynamicArray_Class cls = self->__getclass__(0);
	if (self->_size >= self->_max)
		cls->resize(self, self->_max+ARRAY_CHUNK_max);
	return self->_max;
}

cbc_var cbc_DynamicArray_resize(cbc_DynamicArray self, cbc_var new_max){
	if (new_max < self->_size)
		return self->_max;
	
	cbc_var* new_elems = CBC_NEW(cbc_var, new_max);
	memcpy(new_elems, self->_buf, self->_max*sizeof(cbc_var));
	self->_max = new_max;
	cbc_var* aux = self->_buf;
	self->_buf = new_elems;
	cbc_dealloc(aux);
	return self->_max;
}

cbc_var cbc_DynamicArray_fit(cbc_DynamicArray self){
	cbc_DynamicArray_Class cls = self->__getclass__(0);
	cls->resize(self, self->_size);
	return self->_max;
}
