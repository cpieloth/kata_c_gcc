# Help
# ====

all: help

help:
	@echo Commands:
	@echo '   Print help:        make help'
	@echo '   Clean folder:      make clean'
	@echo '   Compile:           make compile'
	@echo '   Build:             make build'


# Variables
# =========

CC=gcc


# Compile
# =======

compile: calculator.o algorithm.o main.o

%.o: %.c
	$(CC) $(CCFLAGS) -c $<
	

# Build
# =====

build: calculator.o algorithm.o main.o calculator

calculator: calculator.o algorithm.o main.o
	$(CC) -o $@ calculator.o algorithm.o main.o


# Clean files
# ===========

clean:
	$(RM) *.cpp.c *.o *.so *.a main calculator
	