DEPS = -I$(COMP_DEPS) -I$(MACRO_DEPS) -I$(SYSTOB_DEPS) -I$(EMATCH_DEPS) -I$(FILT_DEPS) -I$(ENT_DEPS) 
FILES = SystemObserver.hpp SystemObserver.cpp ReactiveSystem.hpp ReactiveSystem.cpp
MESSAGE = Compiling systems ..

COMP_DEPS = ../Component
MACRO_DEPS = ../ECSMacros
EMATCH_DEPS = ../EntityMatcher
FILT_DEPS = ../Filter
ENT_DEPS = ../Entity

CC = gcc
CFLAGS  = -g -Wall

comp : $(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) -c $(DEPS) $(FILES)

clean: 
	-rm *.o