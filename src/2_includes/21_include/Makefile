# Help
# ====

all: help

help:
	@echo Commands:
	@echo '   Print help:             make help'
	@echo '   Clean folder:           make clean'
	@echo '   Build main_a:           make a'
	@echo '   Build main_ab (error):  make ab'
	@echo '   Generate preprocessor code of ...'
	@echo '         main_a:           make a_cpp'
	@echo '         main_ab:          make ab_cpp'


# Variables
# =========

CC=gcc


# Build executable
# ================

a: main_a.o main_a
ab: main_ab.o main_ab
	
%.o: %.c
	$(CC) $(CCFLAGS) -c $<
	
%: %.o
	$(CC) -o $@ $<


# Generate preprocessor output
# ============================

a_cpp: CCFLAGS+=-DNDEBUG -E
a_cpp: main_a.cpp.c

ab_cpp: CCFLAGS+=-DNDEBUG -E
ab_cpp: main_ab.cpp.c

%.cpp.c: %.c
	$(CC) $(CCFLAGS) $< > $@


# Clean files
# ===========

clean:
	$(RM) *.cpp.c *.o *.so *.a main_a main_ab
	