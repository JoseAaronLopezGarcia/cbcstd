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

#ifndef CBC_BUILTINS_H
#define CBC_BUILTINS_H

#include <cbc.h>

#define Object cbc_Object
#define List cbc_List
#define String cbc_String
#define LinkedList cbc_LinkedList
#define StaticArray cbc_StaticArray
#define DynamicArray cbc_DynamicArray

#define instanceof cbc_instanceof
#define typeof cbc_typeof

#define try cbc_try
#define catch cbc_catch
#define throw cbc_throw

#define None cbc_getNone()

#endif
