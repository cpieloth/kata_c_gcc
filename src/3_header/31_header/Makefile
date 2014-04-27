# Help
# ====

all: help

help:
	@echo Commands:
	@echo '   Print help:        make help'
	@echo '   Clean folder:      make clean'
	@echo '   Build:             make build'
	@echo '   Build & Link:      make build_link'
	@echo '   Generate preprocessor code of ...'
	@echo '         main:          make cpp'


# Variables
# =========

CC=gcc


# Compile
# =======

compile: main.o

%.o: %.c
	$(CC) $(CCFLAGS) -c $<
	
%: %.o
	$(CC) -o $@ $<
	

# Build (error)
# =============

build: main.o main


# Build & Link
# ============

build_link: calculator.o main.o calculator

calculator: calculator.o main.o
	$(CC) -o $@ main.o calculator.o


# Generate preprocessor output
# ============================

cpp: CCFLAGS+=-DNDEBUG -E
cpp: main.cpp.c

%.cpp.c: %.c
	$(CC) $(CCFLAGS) $< > $@


# Clean files
# ===========

clean:
	$(RM) *.cpp.c *.o *.so *.a main calculator
	