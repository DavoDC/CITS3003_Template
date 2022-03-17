uniform float time; /* in milliseconds */
attribute vec4 vPosition;
uniform mat4 ModelViewProjection;

void main()
{
    vec4 t = vPosition;
    t.y = 0.1*sin(0.001*time+5.0*vPosition.x)*sin(0.001*time+5.0*vPosition.z);
    gl_Position =  ModelViewProjection*t;
}
