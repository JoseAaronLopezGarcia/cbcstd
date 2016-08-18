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

#include <exceptions/cbc_fpu_exception.h>

static cbc_var _cbc_FloatingPointException_type[4] = {
	CBC_FPU_EXCEPTION_ID,
	CBC_EXCEPTION_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_Exception_Class_struct _cbc_FloatingPointException___class__ = {
	.__type__ = _cbc_FloatingPointException_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Exception___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
};

cbc_var* cbc_FloatingPointException___type__ = _cbc_FloatingPointException_type;
cbc_var cbc_FloatingPointException___size__ = sizeof(cbc_FloatingPointException_struct);

cbc_FloatingPointException cbc_FloatingPointException___new__(){
	cbc_FloatingPointException self = (cbc_FloatingPointException)cbc_alloc(cbc_FloatingPointException___size__);
	void* exception = NULL;
	cbc_try{
		cbc_FloatingPointException___init__(self);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_FloatingPointException___init__(cbc_FloatingPointException self){
	cbc_FloatingPointException___sysinit__(self);
	cbc_FloatingPointException___usrinit__(self);
	return self;
}

static cbc_var _cbc_FloatingPointException___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_FPU_EXCEPTION_ID:
		case CBC_OBJECT_ID: return &_cbc_FloatingPointException___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_FPU_EXCEPTION_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_FloatingPointException___sysinit__(cbc_FloatingPointException self){
	self->__getclass__ = &_cbc_FloatingPointException___getclass__;
	return self;
}

cbc_var cbc_FloatingPointException___usrinit__(cbc_FloatingPointException self){
	cbc_Exception___usrinit__(self, "Floating Point Exception (e.g. division by zero)\n");
	return self;
}
