FILES = ExampleComponents.hpp SampleReactiveSystem.hpp
_DEPS = Entity EntityMatcher Filter Systems Component ECSMacros
MESSAGE = Compiling examples ..

DEPS = $(patsubst %,-I../%,$(_DEPS))

CC = gcc
CFLAGS  = -g -Wall -c

.SILENT: all clean

all :	$(FILES)
	@echo $(MESSAGE)
	$(CC) $(CFLAGS) $(DEPS) $(FILES)

clean: 
	-rm *.o
