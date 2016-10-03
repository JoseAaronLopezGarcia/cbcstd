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

#ifndef CBC_LIST_H
#define CBC_LIST_H

#include <cbcstd.h>
#include <types/cbc_object.h>

#define CBC_LIST_ID -40676293443786093

#define CBC_LIST_METHODS CBC_OBJECT_METHODS \
	cbc_var (*get)(void*, cbc_var); \
	cbc_var (*set)(void*, cbc_var, cbc_var); \
	cbc_var (*del)(void*, cbc_var); \
	cbc_var (*add)(void*, cbc_var); \
	cbc_var (*insert)(void*, cbc_var, cbc_var); \
	cbc_var (*contains)(void*, cbc_var data); \
	cbc_var (*size)(void*);

typedef struct cbc_List_Class_struct{
	CBC_CLASS_HEADER
	CBC_LIST_METHODS
}cbc_List_Class_struct;

typedef cbc_Object_struct* cbc_List;
typedef cbc_List_Class_struct* cbc_List_Class;

extern cbc_var* cbc_List___type__;

#endif
