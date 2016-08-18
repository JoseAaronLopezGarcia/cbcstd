CC = gcc
AR = ar
TARGET = libcbcstd.a
C_FLAGS = -lpthread -lrt -I ./
C_SRC = cbcstd.c \
		cbc_memmgr.c \
		cbc_threadmgr.c \
		cbc_exceptionmgr.c  \
		cbc_stacktrace.c \
		types/cbc_object.c \
		types/cbc_string.c \
		types/cbc_threading.c \
		types/cbc_exception.c \
		collections/cbc_list.c \
		collections/cbc_linkedlist.c \
		collections/cbc_staticarray.c \
		collections/cbc_dynamicarray.c \
		collections/cbc_binarytree.c \
		collections/cbc_hashmap.c \
		exceptions/cbc_fpu_exception.c \
		exceptions/cbc_invalid_exception.c \
		exceptions/cbc_invalid_pointer.c \
		exceptions/cbc_out_of_mem.c \
		exceptions/cbc_cast_error.c \
		exceptions/cbc_system_error.c \
		exceptions/cbc_system_exit.c

.PHONY: all

all:
	$(CC) $(C_FLAGS) -c $(C_SRC)
	$(AR) -rcs $(TARGET) *.o

clean:
	$(Q)rm $(TARGET) *.o

