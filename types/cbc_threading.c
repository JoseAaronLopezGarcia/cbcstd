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

#include <types/cbc_threading.h>

//////////////////////////////////// cbc Mutex //////////////////////////////////////

static cbc_var _cbc_Mutex_type[3] = {
	CBC_MUTEX_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_Mutex_Class_struct _cbc_Mutex___class__ = {
	.__type__ = _cbc_Mutex_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Mutex___end__,
	.lock = &cbc_Mutex_lock,
	.unlock = &cbc_Mutex_unlock
};

cbc_var* cbc_Mutex___type__ = _cbc_Mutex_type;
cbc_var cbc_Mutex___size__ = sizeof(cbc_Mutex_struct);

cbc_Mutex cbc_Mutex___new__(){
	cbc_Mutex self = (cbc_Mutex)cbc_alloc(cbc_Mutex___size__);
	cbc_var exception = NULL;
	cbc_try{
		cbc_Mutex___init__(self);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_Mutex___init__(cbc_Mutex self){
	cbc_Mutex___sysinit__(self);
	cbc_Mutex___usrinit__(self);
	return self;
}

static cbc_var _cbc_Mutex___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_MUTEX_ID:
		case CBC_OBJECT_ID: return &_cbc_Mutex___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_MUTEX_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_Mutex___sysinit__(cbc_Mutex self){
	self->__getclass__ = &_cbc_Mutex___getclass__;
	return self;
}

cbc_var cbc_Mutex___usrinit__(cbc_Mutex self){
	pthread_mutex_init(&(self->mutex), NULL);
	self->owner = -1;
	return self;
}

cbc_var cbc_Mutex___end__(cbc_Mutex self){
	pthread_mutex_destroy(&(self->mutex));
	return self;
}

cbc_var cbc_Mutex_lock(cbc_Mutex self){
	pthread_mutex_lock(&(self->mutex));
	self->owner = cbc_getThreadId();
	return cbc_getNone();
}

cbc_var cbc_Mutex_unlock(cbc_Mutex self){
	self->owner = -1;
	pthread_mutex_unlock(&(self->mutex));
	return cbc_getNone();
}



///////////////////////////////////// cbc Semaphore /////////////////////////////////

static cbc_var _cbc_Semaphore_type[3] = {
	CBC_SEMAPHORE_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_Semaphore_Class_struct _cbc_Semaphore___class__ = {
	.__type__ = _cbc_Semaphore_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Object___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
	.wait = &cbc_Semaphore_wait,
	.release = &cbc_Semaphore_release
};

cbc_var* cbc_Semaphore___type__ = _cbc_Semaphore_type;
cbc_var cbc_Semaphore___size__ = sizeof(cbc_Semaphore_struct);

cbc_Semaphore cbc_Semaphore___new__(cbc_int n){
	cbc_Semaphore self = (cbc_Semaphore)cbc_alloc(cbc_Semaphore___size__);
	cbc_var exception = NULL;
	cbc_try{
		cbc_Semaphore___init__(self, n);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_Semaphore___init__(cbc_Semaphore self, cbc_int n){
	cbc_Semaphore___sysinit__(self);
	cbc_Semaphore___usrinit__(self, n);
	return self;
}

static cbc_var _cbc_Semaphore___getclass__(cbc_var id){
	switch((size_t)id){
		case CBC_SEMAPHORE_ID:
		case CBC_OBJECT_ID: return &_cbc_Semaphore___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_SEMAPHORE_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_Semaphore___sysinit__(cbc_Semaphore self){
	self->__getclass__ = &_cbc_Semaphore___getclass__;
	return self;
}

cbc_var cbc_Semaphore___usrinit__(cbc_Semaphore self, cbc_int n){
	sem_init(&(self->sema), 0, n);
	return self;
}

cbc_var cbc_Semaphore_wait(cbc_Semaphore self){
	sem_wait(&(self->sema));
	return cbc_getNone();
}

cbc_var cbc_Semaphore_release(cbc_Semaphore self){
	sem_post(&(self->sema));
	return cbc_getNone();
}
