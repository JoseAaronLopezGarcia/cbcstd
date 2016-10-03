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

#include <collections/cbc_linkedlist.h>

static cbc_var _cbc_LinkedList_type[4] = {
	CBC_LINKED_LIST_ID,
	CBC_LIST_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct{
	cbc_List_Class_struct class;
	cbc_var none;
} _cbc_LinkedList___ctable__ = {
	{
	.__type__ = _cbc_LinkedList_type,
	.__size__ = sizeof(cbc_List_Class_struct),
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_LinkedList___end__,
	.__hash__ = &cbc_Object___hash__,
	.__cmp__ = &cbc_Object___cmp__,
	.get = &cbc_LinkedList_get,
	.set = &cbc_LinkedList_set,
	.del = &cbc_LinkedList_del,
	.add = &cbc_LinkedList_add,
	.insert = &cbc_LinkedList_insert,
	.contains = &cbc_LinkedList_contains,
	.size = &cbc_LinkedList_size
	}, 0
};

cbc_var* cbc_LinkedList___type__ = _cbc_LinkedList_type;
cbc_var cbc_LinkedList___size__ = sizeof(cbc_LinkedList_struct);

typedef struct _ListNode_struct{
	struct _ListNode_struct* next;
	struct _ListNode_struct* prev;
	cbc_var data;
}_ListNode_struct;

typedef _ListNode_struct* _ListNode;

static _ListNode _createListNode(cbc_var data){
	_ListNode ret = (_ListNode)cbc_alloc(sizeof(_ListNode_struct));
	ret->next = NULL;
	ret->prev = NULL;
	ret->data = data;
	return ret;
}

static _ListNode _findNode(cbc_LinkedList list, size_t pos){
	_ListNode cur = list->_first;
	while (cur && pos){
		cur = cur->next;
		pos--;
	}
	return cur;
}

cbc_LinkedList cbc_LinkedList___new__(){
	cbc_LinkedList self = (cbc_LinkedList)cbc_alloc(cbc_LinkedList___size__);
	void* exception = NULL;
	cbc_try{
		cbc_LinkedList___init__(self);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_LinkedList___init__(cbc_LinkedList self){
	cbc_LinkedList___sysinit__(self);
	cbc_LinkedList___usrinit__(self);
	return self;
}

cbc_var cbc_LinkedList___sysinit__(cbc_LinkedList self){
	self->__ctable__ = &_cbc_LinkedList___ctable__;
	return self;
}

cbc_var cbc_LinkedList___usrinit__(cbc_LinkedList self){
	self->_first = NULL;
	self->_last = NULL;
	self->_size = 0;
	return self;
}

cbc_var cbc_LinkedList_add(cbc_LinkedList self, cbc_var data){
	cbc_LinkedList_Class cls = self->__ctable__;
	return cls->insert(self, data, -1);
}

cbc_var cbc_LinkedList_insert(cbc_LinkedList self, cbc_var data, cbc_var pos){
	_ListNode first = (_ListNode)(self->_first);
	_ListNode last = (_ListNode)(self->_last);
	if (first == NULL){
		self->_first = _createListNode(data);
		self->_last = self->_first;
	}
	else{
		_ListNode node = _findNode(self, pos);
		if (node != NULL){
			_ListNode aux = node->next;
			_ListNode new_node = _createListNode(data);
			node->next = new_node;
			new_node->next = aux;
			new_node->prev = node;
			if (aux == NULL)
				self->_last = new_node;
			else
				aux->prev = new_node;
		}
		else{
			_ListNode new_node = _createListNode(data);
			last->next = new_node;
			new_node->prev = last;
			self->_last = last->next;
		}
	}
	self->_size++;
	return cbc_getNone();
}

cbc_var cbc_LinkedList_get(cbc_LinkedList self, cbc_var pos){
	_ListNode node = _findNode(self, pos);
	if (node != NULL){
		return node->data;
	}
	return cbc_getNone();
}

cbc_var cbc_LinkedList_set(cbc_LinkedList self, cbc_var pos, cbc_var data){
	_ListNode node = _findNode(self, pos);
	if (node != NULL){
		node->data = data;
	}
	return data;
}

cbc_var cbc_LinkedList_del(cbc_LinkedList self, cbc_var pos){
	_ListNode node = _findNode(self, pos);
	if (node != NULL){
		_ListNode prev = node->prev;
		_ListNode next = node->next;
		prev->next = next;
		next->prev = prev;
		cbc_dealloc(node);
	}
	return cbc_getNone();
}

cbc_var cbc_LinkedList_contains(cbc_LinkedList self, cbc_var data){
	_ListNode node = self->_first;
	while (node != NULL){
		if (node->data == data)
			return (cbc_var)-1;
		node = node->next;
	}
	return (cbc_var)0;
}

cbc_var cbc_LinkedList_size(cbc_LinkedList self){
	return self->_size;
}

cbc_var cbc_LinkedList___end__(cbc_LinkedList self){
	_ListNode node = self->_first;
	while (node != NULL){
		void* aux = node;
		node = node->next;
		cbc_dealloc(aux);
	}
	return cbc_getNone();
}
