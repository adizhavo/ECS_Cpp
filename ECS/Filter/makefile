DEPS = -I$(ENT_DEPS) -I$(MACRO_DEPS) -I$(COMP_DEPS)
FILES = Filter.hpp Filter.cpp
MESSAGE = Compiling filter ..

MACRO_DEPS = ../ECSMacros
ENT_DEPS = ../Entity
COMP_DEPS = ../Component

CC = gcc
CFLAGS  = -g -Wall

comp : $(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) -c $(DEPS) $(FILES)

clean: 
	-rm *.o