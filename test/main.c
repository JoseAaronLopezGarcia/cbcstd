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

#include "cbc.h"

void exceptionTest(){
	CBC_STACK_TRACE
	printf("\n-------------- CbC exceptions test --------------\n");
	cbc_Exception e = NULL;
	
	cbc_try{
		*(int*)NULL = 0;
	}
	cbc_catch(e){
		if (cbc_instanceof(e, cbc_InvalidPointer)){
			printf("NULL pointer exception!\n");
		}
		else{
			printf("Exception caught: %s\n", cbc_String_getCString(e->description));
		}
	}
}

void listTest(cbc_List l){
	CBC_STACK_TRACE
	printf("\n-------------- CbC list test --------------\n");
	cbc_List_Class lcls = cbc_getClass(l, cbc_List);
	
	int i;
	for (i=0; i<10; i++)
		lcls->add(l, (cbc_var)i);
	
	printf("[");
	for (i=0; i<10; i++)
		printf("%d%c", lcls->get(l, i), (i==9)? ']':',');
	printf("\n");
	
	cbc_destroyObject(l);
}

void doStackTraceTest(){
	CBC_STACK_TRACE
	cbc_throw(cbc_SystemError___new__("Force exiting with SystemError...\n"));
}

void stackTest(){
	CBC_STACK_TRACE
	printf("\n-------------- CbC stack trace test --------------\n");
	doStackTraceTest();
}

ssize_t intcmp(cbc_var int1, cbc_var int2){
	if ((int)int1==(int)int2) return 0;
	else if ((int)int1 < (int)int2) return -1;
	return 1;
}

void _printTree(cbc_BinaryTree tree){
	CBC_STACK_TRACE
	if (tree != NULL && tree->count > 0){
		_printTree(tree->left);
		printf("%d, ", tree->item);
		_printTree(tree->right);
	}
}

void printTree(cbc_BinaryTree tree){
	CBC_STACK_TRACE
	_printTree(tree);
	printf("\n");
	printf("tree size: %d\n", cbc_BinaryTree_size(tree));
}

void binaryTreeTest(){
	CBC_STACK_TRACE
	printf("\n-------------- CbC binary tree test --------------\n");
	int items[11] = {99, 70, 16, 77, 44, 41, 53, 56, 66, 6, 112, 2, 7};
	cbc_BinaryTree tree = cbc_BinaryTree___new__(&intcmp, &intcmp);
	int i=0; for (; i<sizeof(items)/sizeof(int); i++){
		cbc_BinaryTree_insert(tree, items[i]);
	}
	printTree(tree);
	cbc_BinaryTree_remove(tree, 112);
	printTree(tree);
	cbc_BinaryTree_remove(tree, 53);
	printTree(tree);
	cbc_BinaryTree_remove(tree, 16);
	printTree(tree);
}

void hashMapTest(){
	CBC_STACK_TRACE
	printf("\n-------------- CbC hashmap test --------------\n");
	static char* tests[26] = {"hola", "mundo", "hello", "world", "jose", "aaron", "lopez",
		"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
		"11", "12", "13", "14", "15", "16", "17", "18"};
	static cbc_String strs[26];
	cbc_HashMap map = cbc_HashMap___new__();
	
	int i=0; for (;i<sizeof(tests)/sizeof(char*); i++){
		strs[i] = cbc_String___new__(tests[i]);
		cbc_HashMap_insert(map, cbc_String_hash(strs[i]), strs[i]);
	}
	
	for (i=0; i<sizeof(tests)/sizeof(char*); i++){
		cbc_String str = cbc_HashMap_get(map, cbc_String_hash(strs[i]));
		printf("%s\n", cbc_String_getCString(str));
	}
	printf("HashMap distribution: [");
	for (i=0; i<map->bufsize; i++){
		printf("%zu,", cbc_BinaryTree_size(&(map->buf[i])));
	}
	printf("]\n");
}

int main(int argc, char** argv){
	cbc_init(argc, argv);
	CBC_STACK_TRACE
	
	binaryTreeTest();
	
	hashMapTest();
	
	exceptionTest();
	
	listTest(cbc_LinkedList___new__());
	listTest(cbc_StaticArray___new__(10));
	listTest(cbc_DynamicArray___new__());

	stackTest();
	
	return 0;
}
