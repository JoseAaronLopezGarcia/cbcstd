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

#ifndef CBC_FPU_EXCEPTION_H
#define CBC_FPU_EXCEPTION_H

#include <types/cbc_exception.h>

#define CBC_FPU_EXCEPTION_ID -4129832772611056195

#define CBC_FPU_EXCEPTION_METHODS CBC_EXCEPTION_METHODS
#define CBC_FPU_EXCEPTION_ATTRIBUTES CBC_EXCEPTION_ATTRIBUTES

typedef cbc_Exception_Class_struct cbc_FloatingPointException_Class_struct;
typedef cbc_Exception_struct cbc_FloatingPointException_struct;

typedef cbc_Exception_Class_struct* cbc_FloatingPointException_Class;
typedef cbc_Exception_struct* cbc_FloatingPointException;

extern cbc_var* cbc_FloatingPointException___type__;
extern cbc_var cbc_FloatingPointException___size__;

extern cbc_FloatingPointException cbc_FloatingPointException___new__();
extern cbc_var cbc_FloatingPointException___init__(cbc_FloatingPointException);
extern cbc_var cbc_FloatingPointException___sysinit__(cbc_FloatingPointException);
extern cbc_var cbc_FloatingPointException___usrinit__(cbc_FloatingPointException);

#endif
