example1 should show a spinning cube that has some grid patterns mapped
onto the faces of the cube.

I tried to fix the problem in example2 but had not have enough time.
The problem seemed to come from the fragment shader. I inserted the line
  #extension GL_NV_shadow_samplers_cube : enable
into fshader72.glsl but it didn't help.

example3 should compile and run. However, all I could see was a large
blank window.

I think we should ignore example2.cpp and example3.cpp in this directory.
There was no comment from the original author on the code in this two
files so I believe that they were incomplete code that should not be
included in the directory.

Du Huynh
March 2016
