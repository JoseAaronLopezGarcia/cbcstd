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

#ifndef CBC_THREAD_MANAGER_H
#define CBC_THREAD_MANAGER_H

#include <cbcstd.h>
#include <types/cbc_exception.h>
#include <pthread.h>

typedef pthread_t cbc_thread_t;

typedef struct cbc_ExceptionBuffer cbc_ExceptionBuffer;

typedef struct cbc_ThreadBuffer{
	cbc_thread_t thread;
	cbc_ExceptionBuffer* exc_buf;
	cbc_Exception raised;
	char** first_trace;
	char** last_trace;
}cbc_ThreadBuffer;

cbc_thread_t cbc_getThreadId();
cbc_bool cbc_equalThreads(cbc_thread_t, cbc_thread_t);
cbc_ThreadBuffer* cbc_getThreadBuffer(cbc_thread_t);
cbc_ThreadBuffer* cbc_getCurrentThreadBuffer();

#endif
