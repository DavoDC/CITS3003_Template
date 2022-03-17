attribute vec4 vertices1;
attribute vec4 vertices2;
uniform float time;

void main()
{
    float s =  0.5*(1.0+sin(0.001*time));
    gl_Position = mix(vertices1, vertices2, s);
}
