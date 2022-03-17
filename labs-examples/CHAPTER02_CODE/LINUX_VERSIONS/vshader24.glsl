#version 150

in  vec3 vPosition;
in  vec3 vColor;
out vec4 color;

void
main()
{
    gl_Position = vec4(vPosition, 1.0);
    color = vec4( vColor, 1.0 );
}
