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
	@echo '         main_a:           make a_pp'
	@echo '         main_ab:          make ab_pp'


# Variables
# =========

CC=gcc


# Build executable
# ================

a: main_a.o main_a
ab: main_ab.o main_ab

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%: %.o
	$(CC) -o $@ $<


# Generate preprocessor output
# ============================

a_pp: CFLAGS+=-DNDEBUG -E
a_pp: main_a.pp.c

ab_pp: CFLAGS+=-DNDEBUG -E
ab_pp: main_ab.pp.c

%.pp.c: %.c
	$(CC) $(CFLAGS) $< > $@


# Clean files
# ===========

clean:
	$(RM) *.pp.c *.o *.so *.a main_a main_ab
