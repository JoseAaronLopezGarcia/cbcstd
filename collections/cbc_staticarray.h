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

#ifndef CBC_STATICARRAY_H
#define CBC_STATICARRAY_H

#include <cbcstd.h>
#include <collections/cbc_list.h>

#define CBC_STATIC_ARRAY_ID -337206409966755012

#define CBC_STATIC_ARRAY_METHODS CBC_LIST_METHODS \
	cbc_var (*checkIndex)(void*, cbc_var index); \
	cbc_var (*checkSize)(void*);

#define CBC_STATIC_ARRAY_ATTRIBUTES CBC_LIST_ATTRIBUTES\
	cbc_var* _buf; \
	size_t _size; \
	size_t _max;

typedef struct cbc_StaticArray_Class_struct{
	CBC_CLASS_HEADER
	CBC_STATIC_ARRAY_METHODS
}cbc_StaticArray_Class_struct;

typedef struct cbc_StaticArray_struct{
	CBC_INSTANCE_HEADER
	CBC_STATIC_ARRAY_ATTRIBUTES
}cbc_StaticArray_struct;

typedef cbc_StaticArray_struct* cbc_StaticArray;
typedef cbc_StaticArray_Class_struct* cbc_StaticArray_Class;

extern cbc_var* cbc_StaticArray___type__;
extern cbc_var cbc_StaticArray___size__;

extern cbc_StaticArray cbc_StaticArray___new__(cbc_var max);
extern cbc_var cbc_StaticArray___init__(cbc_StaticArray, cbc_var max);
extern cbc_var cbc_StaticArray___sysinit__(cbc_StaticArray);
extern cbc_var cbc_StaticArray___usrinit__(cbc_StaticArray, cbc_var max);
extern cbc_var cbc_StaticArray_insert(cbc_StaticArray, cbc_var, cbc_var);
extern cbc_var cbc_StaticArray_add(cbc_StaticArray, cbc_var);
extern cbc_var cbc_StaticArray_get(cbc_StaticArray, cbc_var);
extern cbc_var cbc_StaticArray_set(cbc_StaticArray, cbc_var, cbc_var);
extern cbc_var cbc_StaticArray_del(cbc_StaticArray, cbc_var);
extern cbc_var cbc_StaticArray_contains(cbc_StaticArray, cbc_var);
extern cbc_var cbc_StaticArray_size(cbc_StaticArray);
extern cbc_var cbc_StaticArray___end__(cbc_StaticArray);
extern cbc_var cbc_StaticArray_checkIndex(cbc_StaticArray, cbc_var index);
extern cbc_var cbc_StaticArray_checkSize(cbc_StaticArray);

#endif
