# Help
# ====

all: help

help:
	@echo Commands:
	@echo '   Print help:     make help'
	@echo '   Clean folder:   make clean'
	@echo '   Compile:        make compile'
	@echo '   Build:          make build'


# Variables
# =========

CC=gcc


# Compile
# =======

compile: net/ftp.o net/http.o main.o

%.o: %.c
	$(CC) $(CCFLAGS) -c $<
	

# Build
# =======

build: net/ftp.o net/http.o main.o main_net
	
main_net: net/ftp.o net/http.o main.o
	$(CC) -o $@ ftp.o http.o main.o


# Clean files
# ===========

clean:
	$(RM) *.cpp.c *.o *.so *.a main_net
	