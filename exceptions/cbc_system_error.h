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

#ifndef CBC_SYSTEM_ERROR_H
#define CBC_SYSTEM_ERROR_H

#include <types/cbc_exception.h>

#define CBC_SYSTEM_ERROR_ID -3719964586616036597

#define CBC_SYSTEM_ERROR_METHODS CBC_EXCEPTION_METHODS
#define CBC_SYSTEM_ERROR_ATTRIBUTES CBC_EXCEPTION_ATTRIBUTES

typedef cbc_Exception_Class_struct cbc_SystemError_Class_struct;
typedef cbc_Exception_struct cbc_SystemError_struct;

typedef cbc_Exception_Class_struct* cbc_SystemError_Class;
typedef cbc_Exception_struct* cbc_SystemError;

extern cbc_var* cbc_SystemError___type__;
extern cbc_var cbc_SystemError___size__;

extern cbc_SystemError cbc_SystemError___new__(const char* desc);
extern cbc_var cbc_SystemError___init__(cbc_SystemError, const char* desc);
extern cbc_var cbc_SystemError___sysinit__(cbc_SystemError);
extern cbc_var cbc_SystemError___usrinit__(cbc_SystemError, const char* desc);

#endif
