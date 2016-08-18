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

#include <types/cbc_exception.h>

static cbc_var _cbc_Exception_type[3] = {
	CBC_EXCEPTION_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_Exception_Class_struct _cbc_Exception___class__ = {
	.__type__ = _cbc_Exception_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Exception___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
};

cbc_var* cbc_Exception___type__ = _cbc_Exception_type;
cbc_var cbc_Exception___size__ = sizeof(cbc_Exception_struct);

cbc_Exception cbc_Exception___new__(const char* description){
	cbc_Exception self = (cbc_Exception)cbc_alloc(cbc_Exception___size__);
	void* exception = NULL;
	cbc_try{
		cbc_Exception___init__(self, description);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_Exception___init__(cbc_Exception self, const char* description){
	cbc_Exception___sysinit__(self);
	cbc_Exception___usrinit__(self, description);
	return self;
}

static cbc_var _cbc_Exception___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_EXCEPTION_ID:
		case CBC_OBJECT_ID: return &_cbc_Exception___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_EXCEPTION_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_Exception___sysinit__(cbc_Exception self){
	self->__getclass__ = &_cbc_Exception___getclass__;
	return self;
}

cbc_var cbc_Exception___usrinit__(cbc_Exception self, const char* description){
	self->description = cbc_String___new__(description);
	return self;
}

cbc_var cbc_Exception___end__(cbc_Exception self){
	cbc_destroyObject(self->description);
	return self;
}
