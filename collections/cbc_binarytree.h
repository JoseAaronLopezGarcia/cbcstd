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

#ifndef CBC_BINARYTREE_H
#define CBC_BINARYTREE_H

#include <types/cbc_object.h>

#define CBC_BINARYTREE_ID 4129016758225036251

#define CBC_BINARYTREE_METHODS CBC_OBJECT_METHODS \
	cbc_var (*insert)(cbc_var, cbc_var); \
	cbc_var (*contains)(cbc_var, cbc_var); \
	cbc_var (*search)(cbc_var, cbc_var); \
	cbc_var (*remove)(cbc_var, cbc_var); \
	cbc_var (*size)(cbc_var);

#define CBC_BINARYTREE_ATTRIBUTES CBC_OBJECT_ATTRIBUTES \
	cbc_var item; \
	cbc_var empty; \
	struct cbc_BinaryTree_struct* parent; \
	struct cbc_BinaryTree_struct* left; \
	struct cbc_BinaryTree_struct* right; \
	ssize_t (*cmpitem)(cbc_var, cbc_var); \
	ssize_t (*cmpid)(cbc_var, cbc_var);

typedef struct cbc_BinaryTree_Class_struct{
	CBC_CLASS_HEADER
	CBC_BINARYTREE_METHODS
}cbc_BinaryTree_Class_struct;

typedef struct cbc_BinaryTree_struct{
	CBC_INSTANCE_HEADER
	CBC_BINARYTREE_ATTRIBUTES
}cbc_BinaryTree_struct;

typedef cbc_BinaryTree_struct* cbc_BinaryTree;
typedef cbc_BinaryTree_Class_struct* cbc_BinaryTree_Class;

extern cbc_var* cbc_BinaryTree___type__;
extern cbc_var cbc_BinaryTree___size__;

extern cbc_BinaryTree cbc_BinaryTree___new__(ssize_t (*cmpitem)(cbc_var, cbc_var),
	ssize_t (*cmpid)(cbc_var, cbc_var););
extern cbc_var cbc_BinaryTree___init__(cbc_BinaryTree, ssize_t (*cmpitem)(cbc_var, cbc_var),
	ssize_t (*cmpid)(cbc_var, cbc_var));
extern cbc_var cbc_BinaryTree___sysinit__(cbc_BinaryTree);
extern cbc_var cbc_BinaryTree___usrinit__(cbc_BinaryTree, ssize_t (*cmpitem)(cbc_var, cbc_var),
	ssize_t (*cmpid)(cbc_var, cbc_var));
extern cbc_var cbc_BinaryTree___end__(cbc_BinaryTree);
extern cbc_var cbc_BinaryTree_insert(cbc_BinaryTree, cbc_var);
extern cbc_var cbc_BinaryTree_contains(cbc_BinaryTree, cbc_var);
extern cbc_var cbc_BinaryTree_search(cbc_BinaryTree, cbc_var);
extern cbc_var cbc_BinaryTree_remove(cbc_BinaryTree, cbc_var);
extern cbc_var cbc_BinaryTree_size(cbc_BinaryTree);

#endif
