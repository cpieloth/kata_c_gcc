# Help
# ====

all: help

help:
	@echo Commands:
	@echo '   Print help:             make help'
	@echo '   Clean folder:           make clean'
	@echo '   Build (no debug log):   make release'
	@echo '   Build (with debug log): make debug'
	@echo '   Code after preprocessor ...'
	@echo '      no debug log:        make release_pp'
	@echo '      with debug log:      make debug_pp'


# Variables
# =========

CC=gcc
PPSRC=preprocessor.pp.c
OBJS=preprocessor.o
EXEC=preprocessor


# Build executable
# ================

release: CFLAGS+=-DNDEBUG
release: $(EXEC)

debug: CFLAGS+=-g
debug: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<


# Generate preprocessor output
# ============================

release_pp: CFLAGS+=-DNDEBUG -E
release_pp: $(PPSRC)

debug_pp: CFLAGS+=-E
debug_pp: $(PPSRC)

%.pp.c: %.c
	$(CC) $(CFLAGS) $< > $@


# Clean files
# ===========

clean:
	$(RM) *.pp.c *.o *.so *.a $(EXEC) preprocessor1 preprocessor2
