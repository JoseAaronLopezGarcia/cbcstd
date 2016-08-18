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

#ifndef CBC_EXCEPTION_H
#define CBC_EXCEPTION_H

#include <cbcstd.h>
#include <types/cbc_object.h>
#include <types/cbc_string.h>

#define CBC_EXCEPTION_ID 9096519807519483325

#define CBC_EXCEPTION_METHODS CBC_OBJECT_METHODS

#define CBC_EXCEPTION_ATTRIBUTES CBC_OBJECT_ATTRIBUTES \
	cbc_String description;

typedef struct cbc_Exception_Class_struct{
	CBC_CLASS_HEADER
	CBC_EXCEPTION_METHODS
}cbc_Exception_Class_struct;

typedef struct cbc_Exception_struct{
	CBC_INSTANCE_HEADER
	CBC_EXCEPTION_ATTRIBUTES
}cbc_Exception_struct;

typedef cbc_Exception_Class_struct* cbc_Exception_Class;
typedef cbc_Exception_struct* cbc_Exception;

extern cbc_var* cbc_Object___type__;
extern cbc_var cbc_Object___size__;

extern cbc_Exception cbc_Exception___new__(const char* description);
extern cbc_var cbc_Exception___init__(cbc_Exception, const char* description);
extern cbc_var cbc_Exception___sysinit__(cbc_Exception);
extern cbc_var cbc_Exception___usrinit__(cbc_Exception, const char* description);
extern cbc_var cbc_Exception___end__(cbc_Exception);

#endif
