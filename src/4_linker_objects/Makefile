# Help
# ====

all: help

help:
	@echo Commands:
	@echo '   Print help:        make help'
	@echo '   Clean folder:      make clean'
	@echo '   Compile:           make compile'
	@echo '   Build std:         make std'
	@echo '   Build basics:      make basic'


# Variables
# =========

CC=gcc


# Compile
# =======

compile: calculator_std.o calculator_basic.o main.o

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

std: calculator_std.o main.o
	$(CC) -o main_std calculator_std.o main.o

basic: calculator_basic.o main.o
	$(CC) -o main_basic calculator_basic.o main.o


# Clean files
# ===========

clean:
	$(RM) -f *.o *.so *.a main_basic main_std
