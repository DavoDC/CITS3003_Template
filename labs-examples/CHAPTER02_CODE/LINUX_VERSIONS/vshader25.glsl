#version 150 

uniform mat4  Proj;

in vec2 vPosition;

void
main()
{
    gl_Position = Proj * vec4(vPosition, 0.0, 1.0);
}
