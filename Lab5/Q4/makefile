#! /usr/bin/make
# CONFIGURED BY DAVID

.NULL: .exe

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
TARGETS = $(basename $(SOURCES))

# Common location (DC)
COMM = ../../LAB_DWL

#Init_Shader location
INIT_SHADER = $(COMM)/Common/InitShader.o

# Library locations
LIB = /usr/lib/x86_64-linux-gnu/
LDLIBS = $(LIB)/libglut.so $(LIB)/libGL.so.1 -lXmu $(LIB)/libX11.so -lm

CXXOPTS += -no-pie
CXXINCS = -I$(COMM)/include
CXXFLAGS = $(CXXOPTS) $(CXXDEFS) $(CXXINCS)
LDFLAGS = $(LDOPTS) $(LDDIRS) $(LDLIBS)

DIRT = $(wildcard *.o *.i *~ */*~ *.log)

#-----------------------------------------------------------------------------

.PHONY: Makefile

default all: $(TARGETS)

$(TARGETS): $(INIT_SHADER)

%: %.cpp
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

#-----------------------------------------------------------------------------

%.i: %.cpp
	$(CXX) -E $(CXXFLAGS) $< | uniq > $@

#-----------------------------------------------------------------------------

clean:
	$(RM) $(DIRT)

rmtargets:
	$(RM) $(TARGETS)

clobber: clean rmtargets
