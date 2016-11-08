DEPS = -I$(COMP_DEPS) -I$(MACRO_DEPS) -I$(SYSTOB_DEPS) -I$(EMATCH_DEPS) -I$(FILT_DEPS) -I$(ENT_DEPS) -I$(SYST_DEPS) 
FILES = ExampleComponents.hpp SampleReactiveSystem.hpp
MESSAGE = Compiling examples ..

COMP_DEPS = ../Component
MACRO_DEPS = ../ECSMacros
EMATCH_DEPS = ../EntityMatcher
FILT_DEPS = ../Filter
ENT_DEPS = ../Entity
SYST_DEPS = ../Systems

CC = gcc
CFLAGS  = -g -Wall

comp : $(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) -c $(DEPS) $(FILES)

clean: 
	-rm *.o