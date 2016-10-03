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

#include <exceptions/cbc_system_exit.h>

static cbc_var _cbc_SystemExit_type[4] = {
	CBC_SYSTEM_EXIT_ID,
	CBC_EXCEPTION_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct{
	cbc_Exception_Class_struct class;
	cbc_var none;
} _cbc_SystemExit___ctable__ = {
	{
	.__type__ = _cbc_SystemExit_type,
	.__size__ = sizeof(cbc_Exception_Class_struct),
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Exception___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
	}, 0
};

cbc_var* cbc_SystemExit___type__ = _cbc_SystemExit_type;
cbc_var cbc_SystemExit___size__ = sizeof(cbc_SystemExit_struct);

cbc_SystemExit cbc_SystemExit___new__(int exit_status){
	cbc_SystemExit self = (cbc_SystemExit)cbc_alloc(cbc_SystemExit___size__);
	void* exception = NULL;
	cbc_try{
		cbc_SystemExit___init__(self, exit_status);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_SystemExit___init__(cbc_SystemExit self, int exit_status){
	cbc_SystemExit___sysinit__(self);
	cbc_SystemExit___usrinit__(self, exit_status);
	return self;
}

cbc_var cbc_SystemExit___sysinit__(cbc_SystemExit self){
	self->__ctable__ = &_cbc_SystemExit___ctable__;
	return self;
}

cbc_var cbc_SystemExit___usrinit__(cbc_SystemExit self, int exit_status){
	self->exit_status = exit_status;
	cbc_Exception___usrinit__(self, "SystemExit\n");
	return self;
}
