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

#ifndef CBC_INVALID_POINTER_H
#define CBC_INVALID_POINTER_H

#include <types/cbc_exception.h>

#define CBC_INVALID_POINTER_ID -4971273277858642

#define CBC_INVALID_POINTER_METHODS CBC_EXCEPTION_METHODS
#define CBC_INVALID_POINTER_ATTRIBUTES CBC_EXCEPTION_ATTRIBUTES

typedef cbc_Exception_Class_struct cbc_InvalidPointer_Class_struct;
typedef cbc_Exception_struct cbc_InvalidPointer_struct;

typedef cbc_Exception_Class_struct* cbc_InvalidPointer_Class;
typedef cbc_Exception_struct* cbc_InvalidPointer;

extern cbc_var* cbc_InvalidPointer___type__;
extern cbc_var cbc_InvalidPointer___size__;

extern cbc_InvalidPointer cbc_InvalidPointer___new__();
extern cbc_var cbc_InvalidPointer___init__(cbc_InvalidPointer);
extern cbc_var cbc_InvalidPointer___sysinit__(cbc_InvalidPointer);
extern cbc_var cbc_InvalidPointer___usrinit__(cbc_InvalidPointer);

#endif
