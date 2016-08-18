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

#ifndef CBC_LINKEDLIST_H
#define CBC_LINKEDLIST_H

#include <cbcstd.h>
#include <collections/cbc_list.h>

#define CBC_LINKED_LIST_ID -1460672172481338078

#define CBC_LINKED_LIST_METHODS CBC_LIST_METHODS

#define CBC_LINKED_LIST_ATTRIBUTES CBC_LIST_ATTRIBUTES\
	void* _first; \
	void* _last; \
	size_t _size;

typedef struct cbc_List_Class_struct cbc_LinkedList_Class_struct;

typedef struct cbc_LinkedList_struct{
	CBC_INSTANCE_HEADER
	CBC_LINKED_LIST_ATTRIBUTES
}cbc_LinkedList_struct;

typedef cbc_LinkedList_struct* cbc_LinkedList;
typedef cbc_List_Class_struct* cbc_LinkedList_Class;

extern cbc_var* cbc_LinkedList___type__;
extern cbc_var cbc_LinkedList___size__;

extern cbc_LinkedList cbc_LinkedList___new__();
extern cbc_var cbc_LinkedList___init__(cbc_LinkedList);
extern cbc_var cbc_LinkedList___sysinit__(cbc_LinkedList);
extern cbc_var cbc_LinkedList___usrinit__(cbc_LinkedList);
extern cbc_var cbc_LinkedList_insert(cbc_LinkedList, cbc_var, cbc_var);
extern cbc_var cbc_LinkedList_add(cbc_LinkedList, cbc_var);
extern cbc_var cbc_LinkedList_get(cbc_LinkedList, cbc_var);
extern cbc_var cbc_LinkedList_set(cbc_LinkedList, cbc_var, cbc_var);
extern cbc_var cbc_LinkedList_del(cbc_LinkedList, cbc_var);
extern cbc_var cbc_LinkedList_contains(cbc_LinkedList, cbc_var);
extern cbc_var cbc_LinkedList_size(cbc_LinkedList);
extern cbc_var cbc_LinkedList___end__(cbc_LinkedList);

#endif
