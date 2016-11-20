CC = g++
CFLAGS = -g -Wall -c -std=c++11
SLIB = ar rcs

SRC_DIRS = ./src
INC_DIRS = ./include
EXP_DIRS = ./examples
OBJ_DIRS = ./obj
LIB_DIRS = ./lib
TST_DIRS = ./tests

SLIB_NAME = libecs.a

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
INCS := $(shell find $(INC_DIRS) -name *.hpp)
EXPS := $(shell find $(EXP_DIRS) -name *.hpp)
OBJS := $(notdir $(SRCS:.cpp=.o))

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

.SILENT: all example clean test

all: $(SRCS)
	@echo \\033[33mStarting compilation of files in $(SRC_DIRS)\\033""
	$(CC) $(CFLAGS) $(INC_FLAGS) $(SRCS)
	@echo \\033[32mCompilation finished\\033""
	@echo \\033[33mStart building the static library\\033""
	$(SLIB) $(SLIB_NAME) $(OBJS)
	@mkdir -p $(LIB_DIRS)
	@mv $(SLIB_NAME) $(LIB_DIRS)
	@echo \\033[32mBuild finished with contents:\\033""
	@ar -t $(LIB_DIRS)/$(SLIB_NAME)
	@-rm *.o

example: $(EXPS) 
	@echo \\033[33mStarting compilation in $(EXP_DIRS)\\033""
	$(CC) $(CFLAGS) $(INC_FLAGS) $(EXPS)
	@echo \\033[32mCompilation finished\\033""

test :
	@$(TST_DIRS)/test entity filter entityMatcher systems

.PHONY: clean

clean:
	@echo \\033[31mStarting cleaning..\\033""
	-rm *.o
	cd $(EXP_DIRS) -rm *.o
	@echo \\033[31mCleaning finished\\033""
