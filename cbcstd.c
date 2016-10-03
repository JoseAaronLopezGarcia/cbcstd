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

#include <cbcstd.h>
#include <types/cbc_object.h>
#include <collections/cbc_staticarray.h>

extern void _cbc_initThreadMgr();
extern void _cbc_initExceptionMgr();
extern void _cbc_initMemoryMgr();
extern void _cbc_startMemoryMgr();

static cbc_Object_struct __noneobj__;
static cbc_NoneObject __none__ = NULL;
static cbc_StaticArray_struct _args;
static cbc_StaticArray args = NULL;

cbc_var cbc_getNone(){
	return (cbc_var)__none__;
}

cbc_var cbc_getArgs(){
	return (cbc_var)args;
}

cbc_var cbc_destroyObject(cbc_var o){
	if (o != NULL && o != __none__){
		cbc_Object_Class cls = ((cbc_Object)o)->__ctable__;
		cls->__end__(o);
		cbc_dealloc(o);
	}
	return cbc_getNone();
}

cbc_Class cbc_getClassByID(cbc_var o, cbc_var classid){
	if (o==NULL) return NULL;
	register int i=0;
	register cbc_Class cls = ((cbc_Object)o)->__ctable__;
	if (cls == NULL) return NULL;
	register cbc_var* __type__ = NULL;
	while((__type__ = cls->__type__) != NULL){
		register cbc_var type = 0;
		do{
		type = __type__[i];
		if (type == classid)
			return cls;
		i++;
		}while (type);
		cls = (cbc_Class)((size_t)cls + cls->__size__);
	}
	return NULL;
}

cbc_var cbc_init(int argc, char** argv){
	__none__ = (cbc_NoneObject)&__noneobj__;
	cbc_NoneObject___init__(__none__);
	_cbc_initThreadMgr();
	_cbc_initExceptionMgr();
	args = &_args;
	cbc_StaticArray___init__(args, argc);
	int i; for (i=0; i<argc; i++)
		cbc_StaticArray_add(args, cbc_String___new__(argv[i]));
	_cbc_initMemoryMgr();
}
