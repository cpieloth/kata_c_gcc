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
	

# Build std
# =========

std: CALC = calculator_std.o
std: clean calculator_std.o main.o calculator
	

# Build basics
# ============

basic: CALC = calculator_basic.o
basic: clean calculator_basic.o main.o calculator


# Build calculator
# ================

calculator: $(CALC) main.o
	$(CC) -o $@ $(CALC) main.o


# Clean files
# ===========

clean:
	$(RM) *.cpp.c *.o *.so *.a main calculator
	