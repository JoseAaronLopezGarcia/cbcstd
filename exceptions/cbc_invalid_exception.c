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

#include <exceptions/cbc_invalid_exception.h>

static cbc_var _cbc_InvalidException_type[4] = {
	CBC_INVALID_EXCEPTION_ID,
	CBC_EXCEPTION_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct{
	cbc_Exception_Class_struct class;
	cbc_var none;
} _cbc_InvalidException___ctable__ = {
	{
	.__type__ = _cbc_InvalidException_type,
	.__size__ = sizeof(cbc_Exception_Class_struct),
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Exception___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
	}, 0
};

cbc_var* cbc_InvalidException___type__ = _cbc_InvalidException_type;
cbc_var cbc_InvalidException___size__ = sizeof(cbc_InvalidException_struct);

cbc_InvalidException cbc_InvalidException___new__(cbc_Object cause){
	cbc_InvalidException self = (cbc_InvalidException)cbc_alloc(cbc_InvalidException___size__);
	void* exception = NULL;
	cbc_try{
		cbc_InvalidException___init__(self, cause);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_InvalidException___init__(cbc_InvalidException self, cbc_Object cause){
	cbc_InvalidException___sysinit__(self);
	cbc_InvalidException___usrinit__(self, cause);
	return self;
}

cbc_var cbc_InvalidException___sysinit__(cbc_InvalidException self){
	self->__ctable__ = &_cbc_InvalidException___ctable__;
	return self;
}

cbc_var cbc_InvalidException___usrinit__(cbc_InvalidException self, cbc_Object cause){
	self->cause = cause;
	char buf[128];
	snprintf(buf, 128, "Trying to raise an instance of type %zd\n"
		"Which is not compatible with cbc_Exception\n", ((cbc_Object_Class)(cause->__ctable__))->__type__[0]);
	cbc_Exception___usrinit__(self, buf);
	return self;
}
