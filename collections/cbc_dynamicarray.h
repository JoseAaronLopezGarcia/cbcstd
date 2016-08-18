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

#ifndef CBC_DYNAMICARRAY_H
#define CBC_DYNAMICARRAY_H

#include <cbcstd.h>
#include <collections/cbc_staticarray.h>

#define CBC_DYNAMIC_ARRAY_ID 7195463879364445185

#define CBC_DYNAMIC_ARRAY_METHODS CBC_STATIC_ARRAY_METHODS \
	cbc_var (*resize)(void*, cbc_var new_size); \
	cbc_var (*fit)(void*);

#define CBC_DYNAMIC_ARRAY_ATTRIBUTES CBC_STATIC_ARRAY_ATTRIBUTES

typedef struct cbc_DynamicArray_Class_struct{
	CBC_CLASS_HEADER
	CBC_DYNAMIC_ARRAY_METHODS
}cbc_DynamicArray_Class_struct;

typedef struct cbc_StaticArray_struct cbc_DynamicArray_struct;

typedef cbc_DynamicArray_struct* cbc_DynamicArray;
typedef cbc_DynamicArray_Class_struct* cbc_DynamicArray_Class;

extern cbc_var* cbc_DynamicArray___type__;
extern cbc_var cbc_DynamicArray___size__;

extern cbc_DynamicArray cbc_DynamicArray___new__();
extern cbc_var cbc_DynamicArray___init__(cbc_DynamicArray);
extern cbc_var cbc_DynamicArray___sysinit__(cbc_DynamicArray);
extern cbc_var cbc_DynamicArray___usrinit__(cbc_DynamicArray);
extern cbc_var cbc_DynamicArray_checkSize(cbc_DynamicArray);
extern cbc_var cbc_DynamicArray_resize(cbc_DynamicArray, cbc_var new_size);
extern cbc_var cbc_DynamicArray_fit(cbc_DynamicArray);

#endif
