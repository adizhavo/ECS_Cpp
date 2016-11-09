CC = gcc
CFLAGS  = -g -Wall -c

SRC_DIRS = ./src
INC_DIRS = ./include

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)

INCS := $(shell find $(INC_DIRS) -name *.hpp)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

.SILENT: all clean

all: $(SRCS)
	@echo \\033[33mCOMPILATION STARTED..\\033[0m""
	$(CC) $(CFLAGS) $(INC_FLAGS) $(SRCS)
	@echo \\033[32mCOMPILATION FINISHED\\033[0m""

.PHONY: clean

clean:
	@echo \\033[31mCLEANING STARTED..\\033[0m""
	-rm *.o
	@echo \\033[31mCLEANING FINISHED\\033[0m""
