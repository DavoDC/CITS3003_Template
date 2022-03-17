# Makefile for the CITS3003 lab exercises running on the Mac
#
# Du Huynh
# March 2016

GCC_OPTIONS=-w -I ../../include
GL_OPTIONS=-framework OpenGL -framework GLUT 
OPTIONS=$(GCC_OPTIONS) $(GL_OPTIONS)

SHADER = InitShader.o
SHADER_SRC = ../../Common/InitShader.cpp
PROGRAMS = example1 example2 example3 example4
DIRT = $(wildcard *.o *.i *~ */*~ *.log)

RM = /bin/rm

# -------------------- rules for building programs --------------------

default all: $(PROGRAMS)

$(PROGRAMS): $(SHADER)

$(SHADER): $(SHADER_SRC)
	g++ -c $(SHADER_SRC) $(OPTIONS)

%: %.cpp
	g++ $@.cpp $(OPTIONS) $(SHADER) -o $@

# -------------------- rules for cleaning up files that can be rebuilt --------------------

clean:
	$(RM) $(DIRT)

rmtargets:
	$(RM) $(PROGRAMS)

clobber: clean rmtargets
