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

#ifndef CBC_EXCEPTION_MANAGER_H
#define CBC_EXCEPTION_MANAGER_H

#include <cbcstd.h>
#include <types/cbc_exception.h>
#include <setjmp.h>

typedef struct cbc_ExceptionBuffer cbc_ExceptionBuffer;

extern jmp_buf* cbc_registerExceptionBuffer();
extern cbc_var cbc_unregisterExceptionBuffer(cbc_var ret);
extern cbc_var cbc_raiseException(cbc_Exception exc);
extern cbc_var cbc_unhandledException(cbc_Exception exc);
extern cbc_Exception cbc_getRaisedException(cbc_Exception* e);

#endif
