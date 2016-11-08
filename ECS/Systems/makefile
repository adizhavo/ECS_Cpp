FILES = SystemObserver.hpp SystemObserver.cpp ReactiveSystem.hpp ReactiveSystem.cpp
_DEPS = Entity EntityMacther Filter Component ECSMacros
MESSAGE = Compiling systems ..

DEPS = $(patsubst %,-I../%,$(_DEPS))

CC = gcc
CFLAGS  = -g -Wall -c

.SILENT: all clean

all :	$(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) $(DEPS) $(FILES)

clean: 
	-rm *.o

