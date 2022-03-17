attribute vec3 vPosition;
varying vec4 color;

void
main()
{
    gl_Position = vec4(vPosition, 1.0);
    color =
        vec4( ( 1.0 + vPosition.x ) / 2.0, ( 1.0 + vPosition.y ) / 2.0,
              ( 1.0 + vPosition.z ) / 2.0, 1.0 );
}
