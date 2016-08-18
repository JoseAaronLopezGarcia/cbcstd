CC = gcc
TARGET = main
C_FLAGS = -L ../ -I ../ -lcbcstd -lpthread -lrt
C_SRC = main.c

.PHONY: all

all:
	$(Q)make -C ../
	$(CC) $(C_SRC) $(C_FLAGS) -o $(TARGET)

clean:
	$(Q)make -C ../ clean
	$(Q)rm $(TARGET) *.o
