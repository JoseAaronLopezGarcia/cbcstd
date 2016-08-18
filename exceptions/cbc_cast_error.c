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

#include <exceptions/cbc_cast_error.h>

static cbc_var _cbc_CastError_type[4] = {
	CBC_CAST_ERROR_ID,
	CBC_EXCEPTION_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_Exception_Class_struct _cbc_CastError___class__ = {
	.__type__ = _cbc_CastError_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Exception___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
};

cbc_var* cbc_CastError___type__ = _cbc_CastError_type;
cbc_var cbc_CastError___size__ = sizeof(cbc_CastError_struct);

cbc_CastError cbc_CastError___new__(cbc_var id1, cbc_var id2){
	cbc_CastError self = (cbc_CastError)cbc_alloc(cbc_CastError___size__);
	void* exception = NULL;
	cbc_try{
		cbc_CastError___init__(self, id1, id2);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_CastError___init__(cbc_CastError self, cbc_var id1, cbc_var id2){
	cbc_CastError___sysinit__(self);
	cbc_CastError___usrinit__(self, id1, id2);
	return self;
}

static cbc_var _cbc_CastError___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_CAST_ERROR_ID:
		case CBC_OBJECT_ID: return &_cbc_CastError___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_CAST_ERROR_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_CastError___sysinit__(cbc_CastError self){
	self->__getclass__ = &_cbc_CastError___getclass__;
	return self;
}

cbc_var cbc_CastError___usrinit__(cbc_CastError self, cbc_var id1, cbc_var id2){
	char buf[128];
	snprintf(buf, 128, "Casting error: expected %zd, got %zd\n", id1, id2);
	cbc_Exception___usrinit__(self, buf);
	return self;
}
