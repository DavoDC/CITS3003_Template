# Makefile for the CITS3003 lab exercises running on the Mac
#
# Du Huynh
# March 2016

GCC_OPTIONS=-w -I ../../include
GL_OPTIONS=-framework OpenGL -framework GLUT 
OPTIONS=$(GCC_OPTIONS) $(GL_OPTIONS)

SHADER = InitShader.o
SHADER_SRC = ../../Common/InitShader.cpp
PROGRAMS = append_example_a2 append_example_a3 append_example_a4 \
	append_example_a5 append_example_a6 append_example_a7 \
	append_example_a8 append_example_a9 append_example_a10 

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
	$(RM) -f $(DIRT)

rmtargets:
	$(RM) -f $(PROGRAMS)

clobber: clean rmtargets
