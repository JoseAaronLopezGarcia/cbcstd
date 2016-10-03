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

#include <collections/cbc_binarytree.h>

static cbc_var _cbc_BinaryTree_type[3] = {
	CBC_BINARYTREE_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct{
	cbc_BinaryTree_Class_struct class;
	cbc_var none;
} _cbc_BinaryTree___ctable__ = {
	{
	.__type__ = _cbc_BinaryTree_type,
	.__size__ = sizeof(cbc_BinaryTree_Class_struct),
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_BinaryTree___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
	.insert = &cbc_BinaryTree_insert,
	.contains = &cbc_BinaryTree_contains,
	.search = &cbc_BinaryTree_search,
	.remove = &cbc_BinaryTree_remove,
	.size = &cbc_BinaryTree_size
	}, 0
};

cbc_var* cbc_BinaryTree___type__ = _cbc_BinaryTree_type;
cbc_var cbc_BinaryTree___size__ = sizeof(cbc_BinaryTree_struct);

cbc_BinaryTree cbc_BinaryTree___new__(ssize_t (*cmpitem)(cbc_var, cbc_var),
		ssize_t (*cmpid)(cbc_var, cbc_var)){
	cbc_BinaryTree self = (cbc_BinaryTree)cbc_alloc(cbc_BinaryTree___size__);
	void* exception = NULL;
	cbc_try{
		cbc_BinaryTree___init__(self, cmpitem, cmpid);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_BinaryTree___init__(cbc_BinaryTree self, ssize_t (*cmpitem)(cbc_var, cbc_var),
		ssize_t (*cmpid)(cbc_var, cbc_var)){
	cbc_BinaryTree___sysinit__(self);
	cbc_BinaryTree___usrinit__(self, cmpitem, cmpid);
}

cbc_var cbc_BinaryTree___sysinit__(cbc_BinaryTree self){
	self->__ctable__ = &_cbc_BinaryTree___ctable__;
}

cbc_var cbc_BinaryTree___usrinit__(cbc_BinaryTree self, ssize_t (*cmpitem)(cbc_var, cbc_var),
		ssize_t (*cmpid)(cbc_var, cbc_var)){
	self->item = self->left = self->right = self->parent = self->count = 0;
	self->cmpitem = cmpitem;
	self->cmpid = cmpid;
}

cbc_var _cbc_BinaryTree_destroy(cbc_BinaryTree self){
	if (self != NULL){
		_cbc_BinaryTree_destroy(self->left);
		_cbc_BinaryTree_destroy(self->right);
		cbc_dealloc(self);
	}
}

cbc_var cbc_BinaryTree___end__(cbc_BinaryTree self){
	if (self != NULL){
		_cbc_BinaryTree_destroy(self->left);
		_cbc_BinaryTree_destroy(self->right);
	}
}

static void _cbc_BinaryTree_createChild(cbc_BinaryTree parent, cbc_BinaryTree* child, cbc_var item){
	*child = cbc_alloc(cbc_BinaryTree___size__);
	(*child)->__ctable__ = &_cbc_BinaryTree___ctable__;
	(*child)->item = item;
	(*child)->parent = parent;
	(*child)->cmpitem = parent->cmpitem;
	(*child)->cmpid = parent->cmpid;
	(*child)->count = 1;
	(*child)->left = NULL;
	(*child)->right = NULL;
}

cbc_var cbc_BinaryTree_insert(cbc_BinaryTree self, cbc_var item){
	ssize_t (*cmpid)(cbc_var, cbc_var) = self->cmpid;
	ssize_t (*cmpitem)(cbc_var, cbc_var) = self->cmpitem;
	for (;;){
		self->count++;
		if (self->count == 1){
			self->item = item;
			break;
		}
		else{
			ssize_t cmp = cmpitem(self->item, item);
			if (cmp == 0){
				self->item = item;
				break;
			}
			else if (cmp < 0){
				if (self->right == NULL){
					_cbc_BinaryTree_createChild(self, &(self->right), item);
					break;
				}
				else self = self->right;
			}
			else{
				if (self->left == NULL){
					_cbc_BinaryTree_createChild(self, &(self->left), item);
					break;
				}
				else self = self->left;
			}
		}
	}
	return item;
}

cbc_var cbc_BinaryTree_contains(cbc_BinaryTree self, cbc_var id){
	return cbc_BinaryTree_search(self, id) != cbc_getNone();
}

cbc_var cbc_BinaryTree_search(cbc_BinaryTree self, cbc_var id){
	ssize_t (*cmpid)(cbc_var, cbc_var) = self->cmpid;
	while (self != NULL && self->count > 0){
		ssize_t cmp = cmpid(self->item, id);
		if (cmp == 0) return self->item;
		else if (cmp < 0) self = self->right;
		else self = self->left;
	}
	return cbc_getNone();
}

cbc_var cbc_BinaryTree_remove(cbc_BinaryTree self, cbc_var id){
	ssize_t (*cmpid)(cbc_var, cbc_var) = self->cmpid;	
	while (self != NULL && self->count > 0){
		self->count--;
		ssize_t cmp = cmpid(self->item, id);
		if (cmp == 0){
			cbc_var ret = self->item;
			cbc_var aux = NULL;
			if (self->left == NULL && self->right == NULL){
				aux = self;
				if (self->parent->left == self)
					self->parent->left = NULL;
				else
					self->parent->right = NULL;
			}
			else{
				if (self->left == NULL){
					cbc_var aux = self->right;
					self->item = self->right->item;
					self->left = self->right->left;
					self->right = self->right->right;
					if (self->right != NULL) self->right->parent = self;
					if (self->left != NULL) self->left->parent = self;
				}
				else if (self->right == NULL){
					cbc_var aux = self->left;
					self->item = self->left->item;
					self->left = self->left->left;
					self->right = self->left->right;
					if (self->right != NULL) self->right->parent = self;
					if (self->left != NULL) self->left->parent = self;
				}
				else{
					cbc_var aux = self->left;
					cbc_var right = self->left->right;
					cbc_BinaryTree tree = self->right;
					self->item = self->left->item;
					self->left = self->left->left;
					if (self->left != NULL) self->left->parent = self;
					while (tree->left != NULL){
						tree = tree->left;
					}
					tree->left = right;
				}
			}
			cbc_dealloc(aux);
			return ret;
		}
		else if (cmp < 0){
			self = self->right;
		}
		else{
			self = self->left;
		}
	}
	return cbc_getNone();
}

cbc_var cbc_BinaryTree_size(cbc_BinaryTree self){
	return self->count;
}
