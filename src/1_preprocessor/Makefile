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
POSTSRC=main.pp.c
OBJS=main.o
EXEC=main


# Build executable
# ================

release: CCFLAGS+=-DNDEBUG
release: $(EXEC)

debug: CCFLAGS+=-g
debug: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< 


# Generate preprocessor output
# ============================

release_pp: CCFLAGS+=-DNDEBUG -E
release_pp: $(POSTSRC)

debug_pp: CCFLAGS+=-E
debug_pp: $(POSTSRC)

%.pp.c: %.c
	$(CC) $(CCFLAGS) $< > $@


# Clean files
# ===========

clean:
	$(RM) *.pp.c *.o *.so *.a $(EXEC)
	