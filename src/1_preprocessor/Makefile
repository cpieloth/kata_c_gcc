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
	@echo '      no debug log:        make release_cpp'
	@echo '      with debug log:      make debug_cpp'


# Variables
# =========

CC=gcc
CPPSRC=preprocessor.cpp.c
OBJS=preprocessor.o
EXEC=preprocessor


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

release_cpp: CCFLAGS+=-DNDEBUG -E
release_cpp: $(CPPSRC)

debug_cpp: CCFLAGS+=-E
debug_cpp: $(CPPSRC)

%.cpp.c: %.c
	$(CC) $(CCFLAGS) $< > $@


# Clean files
# ===========

clean:
	$(RM) *.cpp.c *.o *.so *.a $(EXEC) preprocessor1 preprocessor2
	