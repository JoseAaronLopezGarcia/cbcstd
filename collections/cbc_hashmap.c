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

#include <collections/cbc_hashmap.h>

#define INITIAL_BUF_SIZE 8

typedef struct _MapNode_struct{
	cbc_var hash;
	cbc_var item;
} _MapNode_struct;
typedef _MapNode_struct* _MapNode;

static ssize_t _cmpNodes(cbc_var node1, cbc_var node2){
	cbc_var hash1 = ((_MapNode)node1)->hash;
	cbc_var hash2 = ((_MapNode)node2)->hash;
	if (hash1 == hash2) return 0;
	else if (hash1 < hash2) return -1;
	return 1;
}

static ssize_t _cmpNodeHash(cbc_var node, cbc_var hash2){
	cbc_var hash1 = ((_MapNode)node)->hash;
	if (hash1 == hash2) return 0;
	else if (hash1 < hash2) return -1;
	return 1;
}

static void _cbc_HashMap_distributeTree(cbc_HashMap self, cbc_BinaryTree tree){
	if (tree != NULL && tree->count > 0){
		_cbc_HashMap_distributeTree(self, tree->left);
		_cbc_HashMap_distributeTree(self, tree->right);
		_MapNode node = tree->item;
		size_t pos = ((size_t)node->hash)%self->bufsize;
		cbc_BinaryTree tree2 = &(self->buf[pos]);
		cbc_BinaryTree_insert(tree2, node);
	}
}

static void _cbc_HashMap_resize(cbc_HashMap self, size_t newSize){
	cbc_BinaryTree_struct* oldbuf = self->buf;
	size_t oldSize = self->bufsize;
	self->buf = CBC_NEW(cbc_BinaryTree_struct, newSize);
	self->bufsize = newSize;
	int i=0; for (;i<newSize; i++)
		cbc_BinaryTree___init__(&(self->buf[i]), &_cmpNodes, &_cmpNodeHash);
	for (i=0; i<oldSize; i++){
		_cbc_HashMap_distributeTree(self, &(oldbuf[i]));
		cbc_BinaryTree___end__(&(oldbuf[i]));
	}
	cbc_dealloc(oldbuf);
}

static cbc_var _cbc_HashMap_type[3] = {
	CBC_HASHMAP_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_HashMap_Class_struct _cbc_HashMap___class__ = {
	.__type__ = _cbc_HashMap_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_HashMap___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
	.get = &cbc_HashMap_get,
	.insert = &cbc_HashMap_insert,
	.remove = &cbc_HashMap_remove
};

cbc_var* cbc_HashMap___type__ = _cbc_HashMap_type;
cbc_var cbc_HashMap___size__ = sizeof(cbc_HashMap_struct);

static cbc_var _cbc_HashMap___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_HASHMAP_ID:
		case CBC_OBJECT_ID: return &_cbc_HashMap___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_HASHMAP_ID, id)); break;
	}
	return NULL;
}

cbc_HashMap cbc_HashMap___new__(){
	cbc_HashMap self = (cbc_HashMap)cbc_alloc(cbc_HashMap___size__);
	void* exception = NULL;
	cbc_try{
		cbc_HashMap___init__(self);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_HashMap___init__(cbc_HashMap self){
	cbc_HashMap___sysinit__(self);
	cbc_HashMap___usrinit__(self);
}

cbc_var cbc_HashMap___sysinit__(cbc_HashMap self){
	self->__getclass__ = &_cbc_HashMap___getclass__;
}

cbc_var cbc_HashMap___usrinit__(cbc_HashMap self){
	self->buf = CBC_NEW(cbc_BinaryTree_struct, INITIAL_BUF_SIZE);
	self->bufsize = INITIAL_BUF_SIZE;
	self->count = 0;
	int i=0; for (; i<INITIAL_BUF_SIZE; i++){
		cbc_BinaryTree___init__(&(self->buf[i]), &_cmpNodes, &_cmpNodeHash);
	}
}

cbc_var cbc_HashMap___end__(cbc_HashMap self){
	int i=0; for(; i<self->bufsize; i++)
		cbc_BinaryTree___end__(&(self->buf[i]));
	cbc_dealloc(self->buf);
}

cbc_var cbc_HashMap_insert(cbc_HashMap self, cbc_var hash, cbc_var item){
	_MapNode node = CBC_NEW(_MapNode, 1);
	node->hash = hash;
	node->item = item;
	size_t pos = ((size_t)hash)%self->bufsize;
	cbc_BinaryTree tree = &(self->buf[pos]);
	cbc_BinaryTree_insert(tree, node);
	self->count++;
	if (self->count > (size_t)(self->bufsize*1.7f))
		_cbc_HashMap_resize(self, self->bufsize*2);
	return item;
}

cbc_var cbc_HashMap_get(cbc_HashMap self, cbc_var hash){
	size_t pos = ((size_t)hash)%self->bufsize;
	cbc_BinaryTree tree = &(self->buf[pos]);
	_MapNode node = cbc_BinaryTree_search(tree, hash);
	if (node == cbc_getNone()) return node;
	return node->item;
}

cbc_var cbc_HashMap_remove(cbc_HashMap self, cbc_var hash){
	cbc_var ret = cbc_getNone();
	size_t pos = ((size_t)hash)%self->bufsize;
	cbc_BinaryTree tree = &(self->buf[pos]);
	_MapNode node = cbc_BinaryTree_remove(tree, hash);
	if (node == cbc_getNone()) return node;
	ret = node->item;
	cbc_dealloc(node);
	self->count--;
	if (self->count < self->bufsize/2)
		_cbc_HashMap_resize(self, self->bufsize/2);
	return ret;
}
