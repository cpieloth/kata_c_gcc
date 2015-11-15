# Help
# ====

all: help

help:
	@echo Commands:
	@echo '   Print help:        make help'
	@echo '   Clean folder:      make clean'
	@echo '   Compile:           make compile'
	@echo '   Executable:        make exec'


# Variables
# =========

CC=gcc

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) -o $@ $<

compile: main.o

exec: main.o calculator.o
	$(CC) -o main main.o calculator.o

clean:
	$(RM) *.o *.so main
