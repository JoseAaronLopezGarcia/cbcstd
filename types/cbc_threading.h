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

#ifndef CBC_THREADING_H
#define CBC_THREADING_H

#include <cbcstd.h>
#include <types/cbc_object.h>
#include <types/cbc_exception.h>
#include <cbc_threadmgr.h>
#include <semaphore.h>

typedef pthread_mutex_t cbc_mutex_t;
typedef sem_t cbc_sema_t;

////////////////// cbc Mutex //////////////////////////////

#define CBC_MUTEX_ID 8300993973499921195

#define CBC_MUTEX_METHODS CBC_OBJECT_METHODS \
	cbc_var (*lock)(void*); \
	cbc_var (*unlock)(void*);

#define CBC_MUTEX_ATTRIBUTES CBC_OBJECT_ATTRIBUTES \
	cbc_thread_t owner; \
	cbc_mutex_t mutex;

typedef struct cbc_Mutex_Class_struct{
	CBC_CLASS_HEADER
	CBC_MUTEX_METHODS
}cbc_Mutex_Class_struct;

typedef struct cbc_Mutex_struct{
	CBC_INSTANCE_HEADER
	CBC_MUTEX_ATTRIBUTES
}cbc_Mutex_struct;

typedef cbc_Mutex_Class_struct* cbc_Mutex_Class;
typedef cbc_Mutex_struct* cbc_Mutex;

extern cbc_var* cbc_Mutex___type__;
extern cbc_var cbc_Mutex___size__;

extern cbc_Mutex cbc_Mutex___new__();
extern cbc_var cbc_Mutex___init__(cbc_Mutex);
extern cbc_var cbc_Mutex___sysinit__(cbc_Mutex);
extern cbc_var cbc_Mutex___usrinit__(cbc_Mutex);
extern cbc_var cbc_Mutex___end__(cbc_Mutex);
extern cbc_var cbc_Mutex_lock(cbc_Mutex);
extern cbc_var cbc_Mutex_unlock(cbc_Mutex);

/////////////////////////// cbc Semaphore /////////////////////////////

#define CBC_SEMAPHORE_ID 8300993973499921195

#define CBC_SEMAPHORE_METHODS CBC_OBJECT_METHODS \
	cbc_var (*wait)(void*); \
	cbc_var (*release)(void*);

#define CBC_SEMAPHORE_ATTRIBUTES CBC_OBJECT_ATTRIBUTES \
	cbc_sema_t sema;

typedef struct cbc_Semaphore_Class_struct{
	CBC_CLASS_HEADER
	CBC_SEMAPHORE_METHODS
}cbc_Semaphore_Class_struct;

typedef struct cbc_Semaphore_struct{
	CBC_INSTANCE_HEADER
	CBC_SEMAPHORE_ATTRIBUTES
}cbc_Semaphore_struct;

typedef cbc_Semaphore_Class_struct* cbc_Semaphore_Class;
typedef cbc_Semaphore_struct* cbc_Semaphore;

extern cbc_var* cbc_Semaphore___type__;
extern cbc_var cbc_Semaphore___size__;

extern cbc_Semaphore cbc_Semaphore___new__(cbc_int n);
extern cbc_var cbc_Semaphore___init__(cbc_Semaphore, cbc_int n);
extern cbc_var cbc_Semaphore___sysinit__(cbc_Semaphore);
extern cbc_var cbc_Semaphore___usrinit__(cbc_Semaphore, cbc_int n);
extern cbc_var cbc_Semaphore_wait(cbc_Semaphore);
extern cbc_var cbc_Semaphore_release(cbc_Semaphore);
#endif
