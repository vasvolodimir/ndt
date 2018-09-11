SRCS = 	src/tools.c\
	src/ether.c\
	src/ip.c\
	src/iface.c\
	src/main.c

OBJS = $(SRCS:.c=.o) 

TARGET = ndt
CC = gcc
CFLAGS = -g -Wall
PREFIX = /usr/local/bin
BIN = ./bin
INCLUDE = -I include/ #From some reasons this shit doesn't work


all: $(TARGET)

clean:
	rm -rf $(OBJS)

install:
	sudo install $(BIN)/$(TARGET) $(PREFIX)
	rm -Rf $(BIN)/$(TARGET)
	ln -s $(PREFIX)/$(TARGET)
	mv $(TARGET) $(BIN)

distclean:
	sudo rm -rf $(PREFIX)/$(TARGET)
	sudo rm -rf $(BIN)/$(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDE) -o $(TARGET) $(OBJS); 
