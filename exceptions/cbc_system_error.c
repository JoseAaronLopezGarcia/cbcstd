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

#include <exceptions/cbc_system_error.h>

static cbc_var _cbc_SystemError_type[4] = {
	CBC_SYSTEM_ERROR_ID,
	CBC_EXCEPTION_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct{
	cbc_Exception_Class_struct class;
	cbc_var none;
} _cbc_SystemError___ctable__ = {
	{
	.__type__ = _cbc_SystemError_type,
	.__size__ = sizeof(cbc_Exception_Class_struct),
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Exception___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
	}, 0
};

cbc_var* cbc_SystemError___type__ = _cbc_SystemError_type;
cbc_var cbc_SystemError___size__ = sizeof(cbc_SystemError_struct);

cbc_SystemError cbc_SystemError___new__(const char* desc){
	cbc_SystemError self = (cbc_SystemError)cbc_alloc(cbc_SystemError___size__);
	void* exception = NULL;
	cbc_try{
		cbc_SystemError___init__(self, desc);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_SystemError___init__(cbc_SystemError self, const char* desc){
	cbc_SystemError___sysinit__(self);
	cbc_SystemError___usrinit__(self, desc);
	return self;
}

cbc_var cbc_SystemError___sysinit__(cbc_SystemError self){
	self->__ctable__ = &_cbc_SystemError___ctable__;
	return self;
}

cbc_var cbc_SystemError___usrinit__(cbc_SystemError self, const char* desc){
	cbc_Exception___usrinit__(self, desc);
	return self;
}
