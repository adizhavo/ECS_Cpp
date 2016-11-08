FILES = Component.hpp
MESSAGE = Compiling component ..

CC = gcc
CFLAGS  = -g -Wall -c

.SILENT: all clean

all :	$(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS)  $(FILES)

clean: 
	-rm *.o