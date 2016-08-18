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

#include <cbc_threadmgr.h>

static const char* stack_trace_magic1 = "CBC_STACK_TRACE_MAGIC_1";
static const char* stack_trace_magic2 = "CBC_STACK_TRACE_MAGIC_2";

void cbc_addStackTrace(char** trace){
	cbc_ThreadBuffer* sto = cbc_getCurrentThreadBuffer();
	trace[0] = stack_trace_magic1;
	trace[1] = stack_trace_magic2;
	sto->last_trace = trace;
	if (sto->first_trace == NULL)
		sto->first_trace = trace;
}

void cbc_printThreadStackTrace(cbc_ThreadBuffer* sto){
	if (sto == NULL)
		sto = cbc_getCurrentThreadBuffer();
	if (sto->first_trace == NULL){
		puts("Cannot print stack trace for current thread: no traces defined.\n");
		return;
	}
	
	register char** stack_end = sto->last_trace;
	register char** stack = sto->first_trace;
	register char* check1 = stack_trace_magic1;
	register char* check2 = stack_trace_magic2;
	
	printf("Traceback (for thread %zu):\n", sto->thread);
	
	for (;;){
		if (stack[0] == check1 && stack[1] == check2)
			printf("\t%s\n", stack[2]);
		if (stack < stack_end){
			stack++;
			if (stack > stack_end)
				break;
		}
		else{
			stack--;
			if (stack < stack_end)
				break;
		}
	}
}

void cbc_printCurrentStackTrace(){
	cbc_printThreadStackTrace(cbc_getCurrentThreadBuffer());
}
