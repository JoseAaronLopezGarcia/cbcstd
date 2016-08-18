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

#ifndef CBC_STRING_H
#define CBC_STRING_H

#include <cbcstd.h>
#include <types/cbc_object.h>
#include <string.h>

#define CBC_STRING_ID -6676251210892904582

#define CBC_STRING_METHODS CBC_OBJECT_METHODS \
	cbc_var (*getCString)(cbc_var); \
	cbc_var (*len)(cbc_var); \
	cbc_var (*span)(cbc_var, cbc_var); \
	cbc_var (*pbrk)(cbc_var, cbc_var); \
	cbc_var (*findChar)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*rfindChar)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*rfind)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*find)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*exists)(cbc_var, cbc_var); \
	cbc_var (*charExists)(cbc_var, cbc_var); \
	cbc_var (*copy)(cbc_var); \
	cbc_var (*substr)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*get)(cbc_var, cbc_var); \
	cbc_var (*cat)(cbc_var, cbc_var); \
	cbc_var (*capitalize)(cbc_var); \
	cbc_var (*count)(cbc_var, cbc_var); \
	cbc_var (*endswith)(cbc_var, cbc_var); \
	cbc_var (*startswith)(cbc_var, cbc_var); \
	cbc_var (*expandTabs)(cbc_var, cbc_var); \
	cbc_var (*isAlphaNumeric)(cbc_var); \
	cbc_var (*isAlpha)(cbc_var); \
	cbc_var (*isNumeric)(cbc_var); \
	cbc_var (*isHexadecimal)(cbc_var); \
	cbc_var (*isFloat)(cbc_var); \
	cbc_var (*isBinary)(cbc_var); \
	cbc_var (*isOctal)(cbc_var); \
	cbc_var (*isLower)(cbc_var); \
	cbc_var (*isUpper)(cbc_var); \
	cbc_var (*isWhitespace)(cbc_var); \
	cbc_var (*ljust)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*rjust)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*lower)(cbc_var); \
	cbc_var (*upper)(cbc_var); \
	cbc_var (*swapcase)(cbc_var); \
	cbc_var (*replace)(cbc_var, cbc_var, cbc_var); \
	cbc_var (*rstrip)(cbc_var, cbc_var); \
	cbc_var (*rstripWhitespace)(cbc_var); \
	cbc_var (*lstrip)(cbc_var, cbc_var); \
	cbc_var (*lstripWhitespace)(cbc_var); \
	cbc_var (*strip)(cbc_var, cbc_var); \
	cbc_var (*stripWhitespace)(cbc_var);

#define CBC_STRING_ATTRIBUTES CBC_OBJECT_ATTRIBUTES \
	cbc_char* _buf; \
	size_t _len; \
	long _hash;

typedef struct cbc_String_Class_struct{
	CBC_CLASS_HEADER
	CBC_STRING_METHODS
}cbc_String_Class_struct;

typedef struct cbc_String_struct{
	CBC_INSTANCE_HEADER
	CBC_STRING_ATTRIBUTES
}cbc_String_struct;

typedef cbc_String_Class_struct* cbc_String_Class;
typedef cbc_String_struct* cbc_String;

extern cbc_var* cbc_String___type__;
extern cbc_var cbc_String___size__;

extern cbc_String cbc_String___new__(const char* c_str);
extern cbc_var cbc_String___init__(cbc_String, const char* c_str);
extern cbc_var cbc_String___sysinit__(cbc_String);
extern cbc_var cbc_String___usrinit__(cbc_String, const char* c_str);
extern cbc_var cbc_String___end__(cbc_String);
extern cbc_var cbc_String_getCString(cbc_String);
extern cbc_var cbc_String_hash(cbc_String);
extern cbc_var cbc_String_len(cbc_String);
extern cbc_var cbc_String_cmp(cbc_String, cbc_String);
extern cbc_var cbc_String_span(cbc_String, cbc_String);
extern cbc_String cbc_String_pbrk(cbc_String, cbc_String);
extern cbc_var cbc_String_findChar(cbc_String, cbc_var search, cbc_var pos);
extern cbc_var cbc_String_rfindChar(cbc_String, cbc_var search, cbc_var pos);
extern cbc_var cbc_String_rfind(cbc_String, cbc_var search, cbc_var pos);
extern cbc_var cbc_String_find(cbc_String, cbc_var search, cbc_var pos);
extern cbc_var cbc_String_exists(cbc_String, cbc_var search);
extern cbc_var cbc_String_charExists(cbc_String, cbc_var search);
extern cbc_String cbc_String_copy(cbc_String);
extern cbc_String cbc_String_substr(cbc_String, cbc_var start, cbc_var end);
extern cbc_var cbc_String_get(cbc_String, cbc_var pos);
extern cbc_String cbc_String_cat(cbc_String, cbc_var append);
extern cbc_String cbc_String_capitalize(cbc_String);
extern cbc_var cbc_String_count(cbc_String, cbc_var str);
extern cbc_var cbc_String_endswith(cbc_String, cbc_var str);
extern cbc_var cbc_String_startswith(cbc_String, cbc_var str);
extern cbc_String cbc_String_expandTabs(cbc_String, cbc_var tabsize);
extern cbc_var cbc_String_isAlphaNumeric(cbc_String);
extern cbc_var cbc_String_isAlpha(cbc_String);
extern cbc_var cbc_String_isNumeric(cbc_String);
extern cbc_var cbc_String_isHexadecimal(cbc_String);
extern cbc_var cbc_String_isFloat(cbc_String);
extern cbc_var cbc_String_isBinary(cbc_String);
extern cbc_var cbc_String_isOctal(cbc_String);
extern cbc_var cbc_String_isLower(cbc_String);
extern cbc_var cbc_String_isUpper(cbc_String);
extern cbc_var cbc_String_isWhitespace(cbc_String);
extern cbc_String cbc_String_ljust(cbc_String, cbc_var width, cbc_var fill);
extern cbc_String cbc_String_rjust(cbc_String, cbc_var width, cbc_var fill);
extern cbc_String cbc_String_lower(cbc_String);
extern cbc_String cbc_String_upper(cbc_String);
extern cbc_String cbc_String_swapcase(cbc_String);
extern cbc_String cbc_String_replace(cbc_String, cbc_var oldstr, cbc_var newstr);
extern cbc_String cbc_String_rstrip(cbc_String, cbc_var remove);
extern cbc_String cbc_String_rstripWhitespace(cbc_String);
extern cbc_String cbc_String_lstrip(cbc_String, cbc_var remove);
extern cbc_String cbc_String_lstripWhitespace(cbc_String);
extern cbc_String cbc_String_strip(cbc_String, cbc_var remove);
extern cbc_String cbc_String_stripWhitespace(cbc_String);

#define IS_WHITESPACE(c) (c==' '||c=='\n'||c=='\t'||c=='\r')
#define IS_ALPHA(c) ((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
#define IS_NUMERIC(c) (c>='0'&&c<='9')
#define IS_ALPHANUMERIC(c) IS_ALPHA(c)||IS_NUMERIC(c)

extern const cbc_var cbc_String_npos;
extern long strhash(const char* str);
extern char* cbcstr2c(cbc_String src, char* dst);



#endif
