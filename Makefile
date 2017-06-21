# **********************************************************
# # *       This file has to stay inside the src folder      *
# # **********************************************************

# directories with files
INCDIR = .
OBJDIR = obj

PROGRAMNAME = calc_test

DEPS = calc.h calc_tests.h

CC=gcc
WRAP_FUNCTIONS = --wrap=pow
CFLAGS = -g -Wall -Wl,$(WRAP_FUNCTIONS) -I$(INCDIR)

LIBS = -lm -lcmocka

_OBJS = calc_tests.o calc.o
# Replace all filenames in objects with a relative path
OBJS = $(patsubst %, $(OBJDIR)/%, $(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGRAMNAME): $(OBJS) 
	$(CC) -o $@ $(CFLAGS) $^ $(LIBS)

clean:
	rm -f obj/*.o $(PROGRAMNAME) 
