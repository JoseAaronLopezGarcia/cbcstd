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

#ifndef CBC_SYSTEM_EXIT_H
#define CBC_SYSTEM_EXIT_H

#include <types/cbc_exception.h>

#define CBC_SYSTEM_EXIT_ID -5928752414158608385

#define CBC_SYSTEM_EXIT_METHODS CBC_EXCEPTION_METHODS

#define CBC_SYSTEM_EXIT_ATTRIBUTES CBC_EXCEPTION_ATTRIBUTES \
	int exit_status;

typedef cbc_Exception_Class_struct cbc_SystemExit_Class_struct;

typedef struct cbc_SystemExit_struct{
	CBC_INSTANCE_HEADER
	CBC_SYSTEM_EXIT_ATTRIBUTES
}cbc_SystemExit_struct;

typedef cbc_Exception_Class_struct* cbc_SystemExit_Class;
typedef cbc_SystemExit_struct* cbc_SystemExit;

extern cbc_var* cbc_SystemExit___type__;
extern cbc_var cbc_SystemExit___size__;

extern cbc_SystemExit cbc_SystemExit___new__(int exit_status);
extern cbc_var cbc_SystemExit___init__(cbc_SystemExit, int exit_status);
extern cbc_var cbc_SystemExit___sysinit__(cbc_SystemExit);
extern cbc_var cbc_SystemExit___usrinit__(cbc_SystemExit, int exit_status);

#endif
