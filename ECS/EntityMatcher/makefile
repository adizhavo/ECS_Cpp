FILES = EntityMatcher.hpp EntityMatcher.cpp
_DEPS = Filter ECSMacros
MESSAGE = Compiling entity matcher ..

DEPS = $(patsubst %,-I../%,$(_DEPS))

CC = gcc
CFLAGS  = -g -Wall -c

.SILENT: all clean

all :	$(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) $(DEPS) $(FILES)

clean: 
	-rm *.o

