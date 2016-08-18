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

#include <signal.h>

#include <cbc_exceptionmgr.h>
#include <cbc_stacktrace.h>
#include <cbc_threadmgr.h>
#include <types/cbc_string.h>
#include <exceptions/cbc_invalid_exception.h>
#include <exceptions/cbc_invalid_pointer.h>
#include <exceptions/cbc_fpu_exception.h>
#include <exceptions/cbc_system_error.h>
#include <exceptions/cbc_system_exit.h>

typedef struct cbc_ExceptionBuffer{
	jmp_buf buffer;
	cbc_ExceptionBuffer* next;
}cbc_ExceptionBuffer;

static cbc_InvalidPointer_struct _invalid_pointer;
static cbc_InvalidPointer invalid_pointer = NULL;
static cbc_FloatingPointException_struct _fpu_exception;
static cbc_FloatingPointException fpu_exception = NULL;

jmp_buf* cbc_registerExceptionBuffer(){
	cbc_ThreadBuffer* thread_buf = cbc_getCurrentThreadBuffer();
	cbc_ExceptionBuffer* buf = (cbc_ExceptionBuffer*)cbc_alloc(sizeof(cbc_ExceptionBuffer));
	buf->next = thread_buf->exc_buf;
	thread_buf->exc_buf = buf;
	return &(buf->buffer);
}

void cbc_unregisterExceptionBuffer(){
	cbc_ThreadBuffer* thread_buf = cbc_getCurrentThreadBuffer();
	cbc_ExceptionBuffer* buf = thread_buf->exc_buf;
	if (buf != NULL){
		thread_buf->exc_buf = buf->next;
		cbc_dealloc(buf);
	}
}

cbc_var cbc_raiseException(cbc_Exception exc){
	cbc_ThreadBuffer* thread_buf = cbc_getCurrentThreadBuffer();
	cbc_ExceptionBuffer* buf = thread_buf->exc_buf;
	
	if (!cbc_isinstanceof(exc, CBC_EXCEPTION_ID))
		exc = cbc_InvalidException___new__(exc);
	
	if (cbc_isinstanceof(exc, CBC_SYSTEM_ERROR_ID)){
		fprintf(stderr, "\n\nInstance of SystemError raised (cannot be caught!)\n\n");
		fprintf(stderr, "Thread ID: %zu\n", cbc_getThreadId());
		fprintf(stderr, "Message:\n%s\n", exc->description->_buf);
		cbc_printCurrentStackTrace();
		exit(cbc_String_hash(exc->description));
	}
	
	if (buf == NULL){
		cbc_unhandledException(exc);
	}
	else{
		jmp_buf buffer;
		memcpy(buffer, &(buf->buffer), sizeof(jmp_buf));
		thread_buf->exc_buf = buf->next;
		cbc_dealloc(buf);
		thread_buf->raised = exc;
		longjmp(&buffer, -1);
	}
	return cbc_getNone();
}

cbc_var cbc_unhandledException(cbc_Exception exc){
	if (cbc_isinstanceof(exc, CBC_SYSTEM_EXIT_ID)){
		exit(((cbc_SystemExit)exc)->exit_status);
	}
	else{
		fprintf(stderr, "\n\nUnhandled exception caugth!\n\n");
		fprintf(stderr, "Thread ID: %zu\n", cbc_getThreadId());
		fprintf(stderr, "Exception ID: %zd\n", (size_t)(((cbc_Object_Class)(exc->__getclass__(0)))->__type__[0]));
		fprintf(stderr, "Message:\n%s\n", (cbc_String)(exc->description)->_buf);
		cbc_printCurrentStackTrace();
		exit(CBC_UNHANDLED_EXCEPTION);
	}
}

cbc_Exception cbc_getRaisedException(cbc_Exception* e){
	cbc_ThreadBuffer* thread_buf = cbc_getCurrentThreadBuffer();
	*e = thread_buf->raised;
	thread_buf->raised = NULL;
	return *e;
}

static void handleSignal(int sig){
	switch (sig){
		case SIGBUS:
		case SIGSEGV:
			cbc_throw(invalid_pointer);
			break;
		case SIGFPE:
			cbc_throw(fpu_exception);
			break;
		case SIGTERM:
			cbc_throw(cbc_SystemExit___new__(CBC_NO_ERROR));
			break;
		case SIGILL:
		case SIGABRT:
			cbc_throw(cbc_SystemError___new__("Abnormal program termination\n"));
			break;
		default:
			cbc_throw(cbc_SystemExit___new__(sig));
			break;
	}
}

void _cbc_setupSignalHandler(){
	size_t signals[6] = {SIGBUS, SIGSEGV, SIGILL, SIGFPE, SIGTERM, SIGABRT};
	int i;for (i=0; i<6; i++)
		signal(signals[i], &handleSignal);
}

void _cbc_initExceptionMgr(){
	invalid_pointer = &_invalid_pointer;
	cbc_InvalidPointer___init__(invalid_pointer);
	fpu_exception = &_fpu_exception;
	cbc_FloatingPointException___init__(fpu_exception);
	_cbc_setupSignalHandler();
}
