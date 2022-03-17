attribute vec2 vPosition;
attribute vec2 vTexCoord;

varying vec2 texCoord;

void main()
{
    gl_Position = vec4(vPosition, 0.0, 1.0);
    texCoord = vTexCoord;
}
