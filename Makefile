# define the C/C++ compiler to use
CC = clang++

# define any compile-time flags
CFLAGS = -std=c++17 -Wall -O3 -MMD
# CFLAGS = -std=c++17 -Wall -Og -g -MMD # Use these flags for debugging

# define any directories containing header files other than /usr/include
#
# add this for gtk3 support: `pkg-config --cflags gtk+-3.0`
INCLUDES =

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS =

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
#
#   add this for gtk3 support: `pkg-config --libs gtk+-3.0`
LIBS =

# define the C source files
SOURCES=$(wildcard src/*/*.cc)   # list of all .cc files in the current directory

# define the C object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SOURCES
# with the .o suffix
#
OBJECTS = ${SOURCES:.cc=.o}  # .o files depend upon .cc files with same names
DEPENDS=${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file

# define the executable file
MAIN = watopoly

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

-include ${DEPENDS}

.PHONY: depend clean

all: $(MAIN)
	@echo $(MAIN) successfully compiled using the $(CC) compiler

$(MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
#
%.o: %.cc
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm ${OBJECTS} ${DEPENDS} ${MAIN}

# DO NOT DELETE THIS LINE -- make depend needs it

