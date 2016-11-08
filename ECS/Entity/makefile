FILES = Entity.hpp Entity.cpp
_DEPS = Systems Component ECSMacros EntityMatcher
MESSAGE = Compiling entity ..

DEPS = $(patsubst %,-I../%,$(_DEPS))

CC = gcc
CFLAGS  = -g -Wall -c

.SILENT: all clean

all :	$(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) $(DEPS) $(FILES)

clean: 
	-rm *.o


