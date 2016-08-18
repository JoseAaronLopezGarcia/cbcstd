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

#ifndef CBC_HASHMAP_H
#define CBC_HASHMAP_H

#include <types/cbc_object.h>
#include <collections/cbc_binarytree.h>

#define CBC_HASHMAP_ID -3036194072350174190

#define CBC_HASHMAP_METHODS CBC_OBJECT_METHODS \
	cbc_var (*insert)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*get)(cbc_var, cbc_var); \
	cbc_var (*remove)(cbc_var, cbc_var);

#define CBC_HASHMAP_ATTRIBUTES CBC_OBJECT_ATTRIBUTES \
	cbc_BinaryTree_struct* buf; \
	size_t count; \
	size_t bufsize;

typedef struct cbc_HashMap_Class_struct{
	CBC_CLASS_HEADER
	CBC_HASHMAP_METHODS
}cbc_HashMap_Class_struct;

typedef struct cbc_HashMap_struct{
	CBC_INSTANCE_HEADER
	CBC_HASHMAP_ATTRIBUTES
}cbc_HashMap_struct;

typedef cbc_HashMap_Class_struct* cbc_HashMap_Class;
typedef cbc_HashMap_struct* cbc_HashMap;

extern cbc_var* cbc_HashMap___type__;
extern cbc_var cbc_HashMap___size__;

extern cbc_HashMap cbc_HashMap___new__();
extern cbc_var cbc_HashMap___init__(cbc_HashMap);
extern cbc_var cbc_HashMap___sysinit__(cbc_HashMap);
extern cbc_var cbc_HashMap___usrinit__(cbc_HashMap);
extern cbc_var cbc_HashMap___end__(cbc_HashMap);
extern cbc_var cbc_HashMap_insert(cbc_HashMap, cbc_var hash, cbc_var item);
extern cbc_var cbc_HashMap_get(cbc_HashMap, cbc_var hash);
extern cbc_var cbc_HashMap_remove(cbc_HashMap, cbc_var hash);


#endif
