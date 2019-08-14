SRCS:=$(wildcard *.c)
CPP_OBJS:=$(patsubst %.c,%.o,$(SRCS))
TARGET:=main.exe
CC:=gcc
CFLAGS:= -g -Wall
all:$(TARGET)
$(TARGET): $(CPP_OBJS)
	$(CC) $^ -o $@ $(CFLAGS)
%.o:%.cc
	$(CC) -c -o $@ $< $(CFLAGS)
.PHONY:clean
clean:
	rm $(TARGET)
