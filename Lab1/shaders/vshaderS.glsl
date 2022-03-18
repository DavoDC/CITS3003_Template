#version 150
// This is a shader preprocessor flag meaning 'GLSL version 1.50'.

// ############ The Vertex Shader ############
// Based on vshader21.glsl, works on Mac and Linux.
// Does per-vertex operations.
// Each vertex invokes an execution of the vertex shader. 
// Each execution of the vertex shader must output a position for the vertex.

// The current vertex coming in from the application program
in vec4 vPosition;

// The main function
void
main()
{
    // gl_Position is an inbuilt variable that represents the current vertex's position.
    // It must be set for the shader to be valid.
    gl_Position = vPosition;
}
