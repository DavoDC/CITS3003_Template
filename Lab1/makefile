#! /usr/bin/make
#
# CONFIGURED BY DAVID
# FOR LINUX ONLY

#-----------------------------------------------------------------------------
### VARIABLES
#-----------------------------------------------------------------------------

# Convert between .NULL and .exe
.NULL: .exe

# CPP files
SOURCES = $(wildcard *.cpp)

# Header files
HEADERS = $(wildcard *.h)

# Targets/Programs
TARGETS = $(basename $(SOURCES))


# Points to the downloaded lab files (Added by David)
COMM = ../LAB_DWL

# The Init Shader location in the lab files (Edited by David)
INIT_SHADER = $(COMM)/Common/InitShader.o


### Library locations

# The location of libraries on new Ubuntu (Edited by David)
LIB = /usr/lib/x86_64-linux-gnu/

# Get paths to GLUT, OpenGL and Windowing libraries
LDLIBS = $(LIB)/libglut.so $(LIB)/libGL.so.1 -lXmu $(LIB)/libX11.so -lm


### C++ Compiler options

# Do not make position independent executable (Added by David)
CXXOPTS += -no-pie

# Include header files from lab files (Edited by David)
CXXINCS = -I$(COMM)/include

# Combine compiler options
CXXFLAGS = $(CXXOPTS) $(CXXDEFS) $(CXXINCS)

# Combine linker flags
LDFLAGS = $(LDOPTS) $(LDDIRS) $(LDLIBS)


### Define extra un-needed files as 'dirt'
DIRT = $(wildcard *.o *.i *~ */*~ *.log)



#-----------------------------------------------------------------------------
### RULES
#-----------------------------------------------------------------------------

# Phony rule where target is not a file
.PHONY: Makefile

# By default, make all targets
default all: $(TARGETS)
$(TARGETS): $(INIT_SHADER)

# Compile all CPP files with CPP and linker flags/options
%: %.cpp
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

%.i: %.cpp
	$(CXX) -E $(CXXFLAGS) $< | uniq > $@


### Commmands
# Clean by removing 'dirt' files
clean:
	$(RM) $(DIRT)

# Remove targets
rmtargets:
	$(RM) $(TARGETS)

# Clobber by cleaning and removing targets
clobber: clean rmtargets
