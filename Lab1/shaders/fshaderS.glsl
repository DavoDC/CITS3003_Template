#version 150
// This is a shader preprocessor flag meaning 'GLSL version 1.50'.

// ############ The Fragment Shader ############
// Based on Mac fshader21.glsl, but works on Linux too.
// Does per-fragment operations.
// Each fragment invokes an execution of the fragment shader. 
// Each execution of the fragment shader must output a color for the fragment.




// The main function
void
main(void)
{
    // gl_FragColor is an inbuilt variable that represents the current fragment's color.
    // It must be set for the shader to be valid.
    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}



