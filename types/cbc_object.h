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

#ifndef CBC_OBJECT_H
#define CBC_OBJECT_H

#include <cbcstd.h>

#define CBC_OBJECT_ID 4537509944773574818
#define CBC_NONE_OBJECT_ID 6090825331494670320

#define CBC_OBJECT_METHODS \
	cbc_var (*__getitem__)(cbc_var, cbc_var); \
	cbc_var (*__setitem__)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*__callmethod__)(cbc_var, cbc_var, ...); \
	cbc_var (*__end__)(cbc_var); \
	cbc_var (*__hash__)(cbc_var); \
	cbc_var (*__cmp__)(cbc_var);

#define CBC_OBJECT_ATTRIBUTES 

typedef struct cbc_Object_Class_struct{
	CBC_CLASS_HEADER
	CBC_OBJECT_METHODS
}cbc_Object_Class_struct;

typedef struct cbc_Object_struct{
	CBC_INSTANCE_HEADER
	CBC_OBJECT_ATTRIBUTES
}cbc_Object_struct;

typedef cbc_Object_struct* cbc_Object;
typedef cbc_Object_Class_struct* cbc_Object_Class;

typedef cbc_Object_Class cbc_NoneObject_Class;
typedef cbc_Object cbc_NoneObject;

extern cbc_var* cbc_Object___type__;
extern cbc_var cbc_Object___size__;

extern cbc_Object cbc_Object___new__();
extern cbc_var cbc_Object___init__(cbc_Object);
extern cbc_var cbc_Object___sysinit__(cbc_Object);
extern cbc_var cbc_Object___usrinit__(cbc_Object);
extern cbc_var cbc_Object___end__(cbc_Object);
extern cbc_var cbc_Object___getitem__(cbc_Object, cbc_var);
extern cbc_var cbc_Object___setitem__(cbc_Object, cbc_var, cbc_var);
extern cbc_var cbc_Object___callmethod__(cbc_Object, cbc_var, ...);
extern cbc_var cbc_Object___hash__(cbc_Object);
extern cbc_var cbc_Object___cmp__(cbc_Object, cbc_Object);
extern cbc_var cbc_NoneObject___init__(cbc_NoneObject);

#endif
