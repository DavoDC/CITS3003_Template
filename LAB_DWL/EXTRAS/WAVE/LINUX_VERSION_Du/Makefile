GCC_OPTIONS=-Wall -pedantic -I ../../../include
GL_OPTIONS=-lGL -lglut 
OPTIONS=$(GCC_OPTIONS) $(GL_OPTIONS)

.DEFAULT: wave

wave: wave.cpp vmesh.glsl fmesh.glsl
	g++ $@.cpp ../../../Common/InitShader.o $(OPTIONS) -o $@  

