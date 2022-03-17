#! /usr/bin/make

.NULL: .exe

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
TARGETS = $(basename $(SOURCES))

INIT_SHADER = ../../Common/InitShader.o

# Linux (default)
LDLIBS = -lglut -lGL -lXmu -lX11  -lm

# Windows (cygwin) - may need work
ifeq "$(OS)" "Windows_NT"
CXXOPTS = -mno-cygwin -mwin32
CXXDEFS = -DFREEGLUT_STATIC -DGLEW_STATIC
LDDIRS = -L../../lib/windows
LDLIBS = -lfreeglut -lopengl32 -lgdi32 -lwinmm
#LDLIBS = -lfreeglut -lglew32 -lopengl32 -lgdi32 -lwinmm
endif

CXXINCS = -I../../include
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
