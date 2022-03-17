#version 150

in vec4 vPosition;

// LINUX ONLY

void
main()
{
    gl_Position = vPosition;
}
