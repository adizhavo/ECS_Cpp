CC = gcc
CFLAGS  = -g -Wall -c -std=c++11

SRC_DIRS = ./src
INC_DIRS = ./include
EXP_DIRS = ./examples

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
INCS := $(shell find $(INC_DIRS) -name *.hpp)
EXPS := $(shell find $(EXP_DIRS) -name *.hpp)

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

.SILENT: all example clean

all: $(SRCS)
	@echo \\033[33mCOMPILING FILES in $(SRC_DIRS)\\033""
	@echo \\033[34mCOMPILING INCLUDES dir: $(INC_DIRS)\\034""
	$(CC) $(CFLAGS) $(INC_FLAGS) $(SRCS)
	@echo \\033[32mCOMPILATION FINISHED\\033""

example: $(EXPS) 
	@echo \\033[33mCOMPILING EXAMPLES in $(EXP_DIRS)\\033""
	$(CC) $(CFLAGS) $(INC_FLAGS) $(EXPS)
	@echo \\033[32mCOMPILATION FINISHED..\\033""

.PHONY: clean

clean:
	@echo \\033[31mCLEANING STARTED..\\033""
	-rm *.o
	cd $(EXP_DIRS) -rm *.o
	@echo \\033[31mCLEANING FINISHED\\033""
