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

#include <types/cbc_string.h>

const cbc_var cbc_String_npos = -1;

long strhash(const char* str){
	size_t _slen = strlen(str);
	ssize_t _len = _slen - 1;
	unsigned char* p = (unsigned char*)str;
	
	long x = *p << 7;
	
	while (_len-- >= 0)
		x = (1000003*x) ^ *p++;
	
	x ^= (_slen-1);

	return (x == -1)? -2 : x;
}

char* cbcstr2c(cbc_String src, char* dst){
	memcpy(dst, src->_buf, src->_len);
	return dst;
}

static inline cbc_String _cbc_String_wrap(cbc_char* str, cbc_var len){
	cbc_String ret = (cbc_String)cbc_alloc(cbc_String___size__);
	cbc_String___sysinit__(ret);
	ret->_buf = str;
	ret->_len = len;
	ret->_hash = -1;
	return ret;
}

static cbc_var _cbc_String_type[3] = {
	CBC_STRING_ID,
	CBC_OBJECT_ID,
	NULL
};

static struct cbc_String_Class_struct _cbc_String___class__ = {
	.__type__ = _cbc_String_type,
	.__getitem__ = &cbc_Object___getitem__,
	.__setitem__ = &cbc_Object___setitem__,
	.__callmethod__ = &cbc_Object___callmethod__,
	.__end__ = &cbc_String___end__,
	.__hash__ = &cbc_String_hash,
	.__cmp__ = &cbc_String_cmp,
	.getCString = &cbc_String_getCString,
	.len = &cbc_String_len,
	.span = &cbc_String_span,
	.pbrk = &cbc_String_pbrk,
	.rfindChar = &cbc_String_rfindChar,
	.rfind = &cbc_String_rfind,
	.find = &cbc_String_find,
	.exists = &cbc_String_exists,
	.charExists = &cbc_String_charExists,
	.copy = &cbc_String_copy,
	.substr = &cbc_String_substr,
	.get = &cbc_String_get,
	.cat = &cbc_String_cat,
	.capitalize = &cbc_String_capitalize,
	.count = &cbc_String_count,
	.endswith = &cbc_String_endswith,
	.startswith = &cbc_String_startswith,
	.expandTabs = &cbc_String_expandTabs,
	.isAlphaNumeric = &cbc_String_isAlphaNumeric,
	.isAlpha = &cbc_String_isAlpha,
	.isNumeric = &cbc_String_isNumeric,
	.isHexadecimal = &cbc_String_isHexadecimal,
	.isFloat = &cbc_String_isFloat,
	.isBinary = &cbc_String_isBinary,
	.isOctal = &cbc_String_isOctal,
	.isLower = &cbc_String_isLower,
	.isUpper = &cbc_String_isUpper,
	.isWhitespace = &cbc_String_isWhitespace,
	.ljust = &cbc_String_ljust,
	.rjust = &cbc_String_rjust,
	.lower = &cbc_String_lower,
	.upper = &cbc_String_upper,
	.swapcase = &cbc_String_swapcase,
	.replace = &cbc_String_replace,
	.rstrip = &cbc_String_rstrip,
	.rstripWhitespace = &cbc_String_rstripWhitespace,
	.lstrip = &cbc_String_lstrip,
	.lstripWhitespace = &cbc_String_lstripWhitespace,
	.strip = &cbc_String_strip,
	.stripWhitespace = &cbc_String_stripWhitespace
};

cbc_var* cbc_String___type__ = _cbc_String_type;
cbc_var cbc_String___size__ = sizeof(cbc_String_struct);

cbc_String cbc_String___new__(const char* c_str){
	cbc_String self = (cbc_String)cbc_alloc(sizeof(cbc_String_struct));
	cbc_var exception = NULL;
	cbc_try{
		cbc_String___init__(self, c_str);
	}
	cbc_catch(exception){
		cbc_dealloc(self);
		cbc_throw(exception);
	}
	return self;
}

cbc_var cbc_String___init__(cbc_String self, const char* c_str){
	cbc_String___sysinit__(self);
	cbc_String___usrinit__(self, c_str);
	return self;
}

static cbc_var _cbc_String___getclass__(cbc_var id){
	switch((size_t)id){
		case 0:
		case CBC_STRING_ID:
		case CBC_OBJECT_ID: return &_cbc_String___class__;
		default: cbc_throw(cbc_CastError___new__(CBC_STRING_ID, id)); break;
	}
	return NULL;
}

cbc_var cbc_String___sysinit__(cbc_String self){
	self->__getclass__ = &_cbc_String___getclass__;
	return self;
}

cbc_var cbc_String___usrinit__(cbc_String self, const char* c_str){
	self->_len = strlen(c_str);
	self->_buf = CBC_NEW(char, self->_len+1);
	self->_hash = -1;
	strncpy(self->_buf, c_str, self->_len);
	self->_buf[self->_len] = 0;
	return self;
}

cbc_var cbc_String___end__(cbc_String self){
	cbc_dealloc(self->_buf);
	return self;
}

cbc_var cbc_String_getCString(cbc_String self){
	return (cbc_var)(self->_buf);
}


cbc_var cbc_String_hash(cbc_String self){
	return (self->_hash != -1)? (cbc_var)(self->_hash) : (cbc_var)strhash(self->_buf);
}

cbc_var cbc_String_len(cbc_String self){
	return (cbc_var)(self->_len);
}

cbc_var cbc_String_cmp(cbc_String self, cbc_String other){
	return (cbc_var)strncmp(self->_buf, other->_buf, self->_len);
}

cbc_var cbc_String_span(cbc_String self, cbc_String Chars){
	cbc_String_Class cls = self->__getclass__(0);
	int i;
	for (i=0; i<self->_len; i++){
		if (cls->findChar(Chars, *(self->_buf+i), 0)){
			return (cbc_var)i;
		}
	}
	return (cbc_var)(self->_len);
}

cbc_String cbc_String_pbrk(cbc_String self, cbc_String chars){
	cbc_String_Class cls = self->__getclass__(0);
	int i;
	for (i=0; i<self->_len; i++){
		if (cls->findChar(chars, *(self->_buf+i), 0)){
			return cbc_String___new__(self->_buf+i);
		}
	}
	return cbc_getNone();
}

cbc_var cbc_String_rfindChar(cbc_String self, cbc_var search, cbc_var pos){
	if (pos > self->_len){
		pos = self->_len-1;
	}
	int i;
	for (i=pos; i>=0; i--){
		if ((char)(*(self->_buf+i)) == (char)search)
			return (cbc_var)i;
	}
	return cbc_String_npos;
}

cbc_var cbc_String_findChar(cbc_String self, cbc_var search, cbc_var pos){
	if ((int)pos < 0)
		pos = 0;
	int i;
	for (i=(int)pos; i<self->_len; i++){
		if ((char)(*(self->_buf+i)) == (char)search)
			return (cbc_var)i;
	}
	return cbc_String_npos;
}

cbc_var cbc_String_rfind(cbc_String self, cbc_var search, cbc_var pos){
	if ((int)pos > self->_len)
		pos = self->_len-1;
	size_t slen = strlen(search);
	int i=(int)pos; for(; i>= 0; i--){
		if (strncmp(self->_buf+i, search, slen) == 0)
			return i;
	}
	return cbc_String_npos;
}

cbc_var cbc_String_find(cbc_String self, cbc_var search, cbc_var pos){
	if ((size_t)pos >= self->_len)
		pos = 0;
	size_t slen = strlen(search);
	int i=(int)pos; for(; i<self->_len; i++){
		if (strncmp(self->_buf+i, search, slen) == 0)
			return i;
	}
	return cbc_String_npos;
}

cbc_var cbc_String_exists(cbc_String self, cbc_var search){
	cbc_String_Class cls = self->__getclass__(CBC_STRING_ID);
	return cls->find(self, search, cbc_String_npos) < cbc_String_npos;
}

cbc_var cbc_String_charExists(cbc_String self, cbc_var search){
	cbc_String_Class cls = self->__getclass__(CBC_STRING_ID);
	return cls->findChar(self, search, cbc_String_npos) < cbc_String_npos;
}

cbc_String cbc_String_copy(cbc_String self){
	return cbc_String___new__(self->_buf);
}

cbc_String cbc_String_substr(cbc_String self, cbc_var start, cbc_var end){
	if ((size_t)start >= self->_len)
		start = 0;
	if ((size_t)end >= self->_len)
		end = self->_len-1;
	size_t newSize = (size_t)end-(size_t)start;
	return _cbc_String_wrap(strndup(self->_buf+(size_t)start, newSize), newSize);
}

cbc_var cbc_String_get(cbc_String self, cbc_var pos){
	if ((size_t)pos > self->_len)
		return 0;
	return *(self->_buf+(size_t)pos);
}

cbc_String cbc_String_cat(cbc_String self, cbc_var append){
	size_t newSize = self->_len + strlen(append) + 1;
	cbc_char* newStr = CBC_NEW(cbc_char, newSize);
	strcpy(newStr, self->_buf);
	strcpy(newStr+self->_len, append);
	return _cbc_String_wrap(newStr, newSize);
}

cbc_String cbc_String_capitalize(cbc_String self){
	cbc_char* newStr = (cbc_char*)strdup(self->_buf);
	if (*(newStr) >= 'a' && *(newStr) <= 'z')
		*(newStr) -= 0x20;
	return _cbc_String_wrap(newStr, self->_len);
}

cbc_var cbc_String_count(cbc_String self, cbc_var str){
	size_t cont = 0;
	size_t slen = strlen(str);
	int i=0; for (; i<self->_len; i++){
		if (strncmp(self->_buf, str, slen) == 0){
			cont++;
			i += slen;
		}
	}
	return cont;
}

cbc_var cbc_String_endswith(cbc_String self, cbc_var str){
	size_t slen = strlen(str);
	size_t offset = self->_len-slen-1;
	if (offset > self->_len)
		return cbc_false;
	return strncmp(self->_buf+offset, str, slen) == 0;
}

cbc_var cbc_String_startswith(cbc_String self, cbc_var str){
	return strncmp(self->_buf, str, strlen(str)) == 0;
}

cbc_String cbc_String_expandTabs(cbc_String self, cbc_var tabsize){
	cbc_String_Class cls = self->__getclass__(CBC_STRING_ID);
	size_t tabs = cls->count(self, "\t");
	size_t newSize = (self->_len-tabs)+(tabs*(size_t)tabsize);
	cbc_char* newStr = CBC_NEW(cbc_char, newSize);
	size_t i=0; for(; i<self->_len; i++){
		if (*(self->_buf+i) == '\t'){
			int j=0; for (; j<tabsize; j++){
				*(newStr++) = ' ';
			}
		}
		else{
			*(newStr++) = *(self->_buf+i);
		}
	}
	return _cbc_String_wrap(newStr, newSize);
}

cbc_var cbc_String_isAlphaNumeric(cbc_String self){
	size_t i=0; for(; i<self->_len; i++){
		char c = *(self->_buf+i);
		if (!IS_ALPHANUMERIC(c) && !IS_WHITESPACE(c))
			return cbc_false;
	}
	return cbc_true;
}

cbc_var cbc_String_isAlpha(cbc_String self){
	size_t i=0; for(; i<self->_len; i++){
		char c = *(self->_buf+i);
		if (!IS_ALPHA(c) && !IS_WHITESPACE(c))
			return cbc_false;
	}
	return cbc_true;
}

cbc_var cbc_String_isNumeric(cbc_String self){
	size_t i=0; for(; i<self->_len; i++){
		char c = *(self->_buf+i);
		if (!IS_NUMERIC(c) && !IS_WHITESPACE(c))
			return cbc_false;
	}
	return cbc_true;
}

cbc_var cbc_String_isHexadecimal(cbc_String self){
	cbc_String_Class cls = self->__getclass__(CBC_STRING_ID);
	size_t start = 0;
	size_t end = self->_len;
	if (cls->startswith(self, "0x"))
		start = 2;
	if (cls->endswith(self, "h"))
		end--;
	size_t i=start; for (; i<end; i++){
		char c = *(self->_buf+i);
		if (c < 'a' || c > 'f' || c < 'A' || c > 'F' || !IS_NUMERIC(c))
			return cbc_false;
	}
	return cbc_true;
}

cbc_var cbc_String_isFloat(cbc_String self){
	size_t points = 0;
	size_t i=0; for(; i<self->_len; i++){
		char c = *(self->_buf+i);
		if (!IS_NUMERIC(c)){
			if (c == '.')
				points++;
			else return cbc_false;
		}
	}
	return points==1;
}

cbc_var cbc_String_isBinary(cbc_String self){
	cbc_String_Class cls = self->__getclass__(CBC_STRING_ID);
	size_t i = 0;
	if (cls->startswith(self, "0b"))
		i = 2;
	for (; i<self->_len; i++){
		size_t c = (size_t)(*(self->_buf+i)-'0');
		if (c>1) return cbc_false;
	}
	return  cbc_true;
}

cbc_var cbc_String_isOctal(cbc_String self){
	if (self->_len < 2 || *(self->_buf) != '0')
		return cbc_false;
	size_t i = 1;
	if (*(self->_buf+1) == 'o')
		i = 2;
	for (; i<self->_len; i++){
		char c = *(self->_buf+i);
		if (c < '0' || c > '7')
			return cbc_false;
	}
	return cbc_true;
}

cbc_var cbc_String_isLower(cbc_String self){
	size_t i = 0; for(; i<self->_len; i++){
		char c = *(self->_buf+i);
		if (c < 'a' || c > 'z'){
			if (!IS_WHITESPACE(c) && !IS_NUMERIC(c))
				return cbc_false;
		}
	}
	return cbc_true;
}

cbc_var cbc_String_isUpper(cbc_String self){
	size_t i = 0; for(; i<self->_len; i++){
		char c = *(self->_buf+i);
		if (c < 'A' || c > 'Z'){
			if (!IS_WHITESPACE(c) && !IS_NUMERIC(c))
				return cbc_false;
		}
	}
	return cbc_true;
}

cbc_var cbc_String_isWhitespace(cbc_String self){
	size_t i = 0; for(; i<self->_len; i++){
		char c = *(self->_buf+i);
		if (!IS_WHITESPACE(c))
			return cbc_false;
	}
	return cbc_true;
}

cbc_String cbc_String_ljust(cbc_String self, cbc_var width, cbc_var fill){
	size_t newSize = self->_len+(size_t)width;
	cbc_char* newStr = CBC_NEW(cbc_char, newSize);
	int i=0; for(; i<width; i++)
		*(newStr+i) = (cbc_char)fill;
	strncpy(newStr+(size_t)width, self->_buf, self->_len);
	return _cbc_String_wrap(newStr, newSize);
}

cbc_String cbc_String_rjust(cbc_String self, cbc_var width, cbc_var fill){
	size_t newSize = self->_len+(size_t)width;
	cbc_char* newStr = CBC_NEW(cbc_char, newSize);
	strncpy(newStr, self->_buf, self->_len);
	int i=self->_len; for(; i<newSize; i++)
		*(newStr+i) = (cbc_char)fill;
	*(newStr+newSize) = 0;
	return _cbc_String_wrap(newStr, newSize);
}

cbc_String cbc_String_lower(cbc_String self){
	cbc_char* newStr = strndup(self->_buf, self->_len);
	int i=0; for (;i<self->_len; i++){
		char c = *(newStr+i);
		if (c>='A' && c<='Z')
			*(newStr+i) += 0x20;
	}
	return _cbc_String_wrap(newStr, self->_len);
}

cbc_String cbc_String_upper(cbc_String self){
	cbc_char* newStr = strndup(self->_buf, self->_len);
	int i=0; for (;i<self->_len; i++){
		char c = *(newStr+i);
		if (c>='a' && c<='z')
			*(newStr+i) -= 0x20;
	}
	return _cbc_String_wrap(newStr, self->_len);
}

cbc_String cbc_String_swapcase(cbc_String self){
	cbc_char* newStr = strndup(self->_buf, self->_len);
	int i=0; for (;i<self->_len; i++){
		char c = *(newStr+i);
		if (c>='A' && c<='Z')
			*(newStr+i) += 0x20;
		else if (c>='a' && c<='z')
			*(newStr+i) -= 0x20;
	}
	return _cbc_String_wrap(newStr, self->_len);
}

cbc_String cbc_String_replace(cbc_String self, cbc_var oldstr, cbc_var newstr){
	cbc_String_Class cls = self->__getclass__(CBC_STRING_ID);
	size_t oslen = strlen(oldstr);
	size_t nslen = strlen(newstr);
	size_t occurences = cls->count(self, oldstr);
	size_t newSize = (self->_len-(occurences*oslen)) + occurences*nslen;
	
	cbc_char* newStr = CBC_NEW(cbc_char, newSize);
	int i=0; while(i<self->_len){
		if (strncmp(self->_buf+i, oldstr, oslen) == 0){
			strncpy(newStr+i, newstr, nslen);
			i += oslen;
		}
		else{
			*(newStr+i) = *(self->_buf+i);
			i++;
		}
	}
	return _cbc_String_wrap(newStr, newSize);
}

cbc_String cbc_String_rstrip(cbc_String self, cbc_var remove){
	cbc_String_struct rem; cbc_String___sysinit__(&rem);
	rem._buf = remove; rem._len = strlen(remove); rem._hash = -1;
	
	int i=self->_len-1; for(; i>=0; i--){
		if (!cbc_String_charExists(&rem, *(self->_buf+i)))
			break;
	}
	cbc_char* newStr = CBC_NEW(cbc_char, i);
	return _cbc_String_wrap(newStr, i);
}

cbc_String cbc_String_rstripWhitespace(cbc_String self){
	return cbc_String_rstrip(self, "\t \r\n");
}

cbc_String cbc_String_lstrip(cbc_String self, cbc_var remove){
	cbc_String_struct rem; cbc_String___sysinit__(&rem);
	rem._buf = remove; rem._len = strlen(remove); rem._hash = -1;
	
	int i=0; for(; i<self->_len; i++){
		if (!cbc_String_charExists(&rem, *(self->_buf+i)))
			break;
	}
	cbc_char* newStr = CBC_NEW(cbc_char, self->_len-i);
	return _cbc_String_wrap(newStr, self->_len-i);
}

cbc_String cbc_String_lstripWhitespace(cbc_String self){
	return cbc_String_lstrip(self, "\t \r\n");
}

cbc_String cbc_String_strip(cbc_String self, cbc_var remove){
	cbc_String aux = cbc_String_lstrip(self, remove);
	cbc_String ret = cbc_String_rstrip(aux, remove);
	cbc_destroyObject(aux);
	return ret;
}

cbc_String cbc_String_stripWhitespace(cbc_String self){
	return cbc_String_strip(self, "\t \r\n");
}
