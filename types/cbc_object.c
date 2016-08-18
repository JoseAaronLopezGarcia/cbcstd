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

#include <types/cbc_object.h>

extern cbc_var cbc_CastError___new__(cbc_var, cbc_var);

static cbc_var _cbc_NoneObject_type[3] = {
	CBC_NONE_OBJECT_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_Object_Class_struct _cbc_Object___class__ = {
	.__type__ = &_cbc_NoneObject_type[1],
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Object___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
};

static struct cbc_Object_Class_struct _cbc_NoneObject___class__ = {
	.__type__ = _cbc_NoneObject_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_Object___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
};

cbc_var* cbc_Object___type__ = &_cbc_NoneObject_type[1];
cbc_var cbc_Object___size__ = sizeof(cbc_Object_struct);

cbc_Object cbc_Object___new__(){
	cbc_Object self = (cbc_Object)cbc_alloc(cbc_Object___size__);
	void* exception = NULL;
	cbc_try{
		cbc_Object___init__(self);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_Object___init__(cbc_Object self){
	cbc_Object___sysinit__(self);
	cbc_Object___usrinit__(self);
	return self;
}

static cbc_var _cbc_Object___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_OBJECT_ID: return &_cbc_Object___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_OBJECT_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_Object___sysinit__(cbc_Object self){
	self->__getclass__ = &_cbc_Object___getclass__;
	return self;
}

cbc_var cbc_Object___usrinit__(cbc_Object self){
	return self;
}

cbc_var cbc_Object___end__(cbc_Object self){
	return self;
}

cbc_var cbc_Object___getitem__(cbc_Object self, cbc_var id){
	return self;
}

cbc_var cbc_Object___setitem__(cbc_Object self, cbc_var id, cbc_var value){
	return self;
}

cbc_var cbc_Object___callmethod__(cbc_Object self, cbc_var id, ...){
	return self;
}

cbc_var cbc_Object___hash__(cbc_Object self){
	return self;
}

cbc_var cbc_Object___cmp__(cbc_Object self, cbc_Object other){
	return (ssize_t)((size_t)self - (size_t)other);
}

cbc_var _cbc_NoneObject___getclass__(cbc_var id){
	return &_cbc_NoneObject___class__;
}

cbc_var cbc_NoneObject___init__(cbc_NoneObject self){
	self->__getclass__ = &_cbc_NoneObject___getclass__;
	return self;
}
