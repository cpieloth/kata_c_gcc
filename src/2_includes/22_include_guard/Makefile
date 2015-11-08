# Help
# ====

all: help

help:
	@echo Commands:
	@echo '   Print help:             make help'
	@echo '   Clean folder:           make clean'
	@echo '   Build main_ab:          make ab'
	@echo '   Generate preprocessor code of ...'
	@echo '         main_ab:          make ab_pp'


# Variables
# =========

CC=gcc


# Build executable
# ================

ab: main_ab.o main_ab

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%: %.o
	$(CC) -o $@ $<


# Generate preprocessor output
# ============================

ab_pp: CFLAGS+=-DNDEBUG -E
ab_pp: main_ab.pp.c

%.pp.c: %.c
	$(CC) $(CFLAGS) $< > $@


# Clean files
# ===========

clean:
	$(RM) *.pp.c *.o *.so *.a main_ab
