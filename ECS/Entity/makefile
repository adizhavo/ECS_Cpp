DEPS = -I$(COMP_DEPS) -I$(MACRO_DEPS) -I$(SYSTOB_DEPS) -I$(EMATCH_DEPS)
FILES = Entity.hpp Entity.cpp
MESSAGE = Compiling entity ..

COMP_DEPS = ../Component
MACRO_DEPS = ../ECSMacros
SYSTOB_DEPS = ../Systems
EMATCH_DEPS = ../EntityMatcher

CC = gcc
CFLAGS  = -g -Wall

comp : $(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) -c $(DEPS) $(FILES)

clean: 
	-rm *.o