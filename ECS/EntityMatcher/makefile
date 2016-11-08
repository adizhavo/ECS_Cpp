DEPS = -I$(FILTER_DEPS) -I$(MACRO_DEPS)
FILES = EntityMatcher.hpp EntityMatcher.cpp
MESSAGE = Compiling entity matcher ..

FILTER_DEPS = ../Filter
MACRO_DEPS = ../ECSMacros

CC = gcc
CFLAGS  = -g -Wall

comp : $(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) -c $(DEPS) $(FILES)

clean: 
	-rm *.o