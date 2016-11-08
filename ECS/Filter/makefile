FILES = Filter.cpp
_DEPS = Entity Component ECSMacros
MESSAGE = Compiling filter ..

DEPS = $(patsubst %,-I../%,$(_DEPS))

CC = gcc
CFLAGS  = -g -Wall -c

.SILENT: all clean

all :	$(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) $(DEPS) $(FILES)

clean: 
	-rm *.o


