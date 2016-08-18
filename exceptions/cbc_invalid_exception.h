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

#ifndef CBC_INVALID_EXCEPTION_H
#define CBC_INVALID_EXCEPTION_H

#include <types/cbc_exception.h>

#define CBC_INVALID_EXCEPTION_ID -5928752414158608385

#define CBC_INVALID_EXCEPTION_METHODS CBC_EXCEPTION_METHODS
#define CBC_INVALID_EXCEPTION_ATTRIBUTES CBC_EXCEPTION_ATTRIBUTES \
	cbc_Object cause;

typedef cbc_Exception_Class_struct cbc_InvalidException_Class_struct;

typedef struct cbc_InvalidException_struct{
	CBC_INSTANCE_HEADER
	CBC_INVALID_EXCEPTION_ATTRIBUTES
}cbc_InvalidException_struct;

typedef cbc_InvalidException_Class_struct* cbc_InvalidException_Class;
typedef cbc_InvalidException_struct* cbc_InvalidException;

extern cbc_var* cbc_InvalidException___type__;
extern cbc_var cbc_InvalidException___size__;

extern cbc_InvalidException cbc_InvalidException___new__(cbc_Object cause);
extern cbc_var cbc_InvalidException___init__(cbc_InvalidException, cbc_Object cause);
extern cbc_var cbc_InvalidException___sysinit__(cbc_InvalidException);
extern cbc_var cbc_InvalidException___usrinit__(cbc_InvalidException, cbc_Object cause);

#endif
