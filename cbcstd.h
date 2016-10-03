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

#ifndef CBC_STD_H
#define CBC_STD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define CBC_CLASS_HEADER cbc_var* __type__; cbc_var __size__;
#define CBC_INSTANCE_HEADER void* __ctable__; uint8_t __flags__;

#define cbc_true ((cbc_bool)!0)
#define cbc_false ((cbc_bool)0)

#define cbc_None cbc_getNone()

#define CBC_NEW(type, count) (type*)cbc_alloc(((size_t)(count))*sizeof(type))

#define cbc_try if(setjmp(cbc_registerExceptionBuffer())==0)
#define cbc_catch(e) if(cbc_getRaisedException(&(e))==NULL){cbc_unregisterExceptionBuffer(0);} else
#define cbc_throw(e) cbc_raiseException(e)

#define cbc_getClass(o, c) cbc_getClassByID(o, c##___type__[0])

#define cbc_instanceof(o, c) (cbc_getClass(o, c) != NULL)
#define cbc_typeof(o, c)  (((cbc_Object_Class)(((cbc_Object)o)->__ctable__))->__type__[0] == c##___type__[0])

#define CBC_STACK_TRACE char* __cbc_stack_trace__[3] = {NULL, NULL, (char*)__func__}; \
	cbc_addStackTrace((char**)__cbc_stack_trace__);

typedef size_t cbc_var;
typedef int8_t cbc_char;
typedef int16_t cbc_short;
typedef int32_t cbc_int;
typedef int64_t cbc_long;
typedef uint8_t cbc_bool;

typedef enum cbc_error_code{
	CBC_NO_ERROR,
	CBC_UNHANDLED_EXCEPTION,
	CBC_THREADMGR_ERROR_ALLOC_BUFF
}cbc_error_code;

typedef struct cbc_Class_struct{
	CBC_CLASS_HEADER
} cbc_Class_struct;

typedef cbc_Class_struct* cbc_Class;

typedef enum{
	CBC_IS_SINGLETON = 1,
	CBC_DISABLE_END = 2,
	CBC_DISABLE_FREE = 4
} cbc_object_flags;

extern cbc_var cbc_init(int argc, char** argv);

extern cbc_var cbc_getArgs();

extern cbc_var cbc_getNone();

extern cbc_var cbc_destroyObject(cbc_var o);

extern cbc_bool cbc_isinstanceof(cbc_var o, cbc_var classid);

#include "cbc_memmgr.h"

#endif
