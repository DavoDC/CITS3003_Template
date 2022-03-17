#version 150

in  vec3 vPosition;
in  vec3 vColor;
out vec4 color;

uniform mat4 xyzwMultipliers;

void
main()
{
   // Get vPosition with w value;
   vec4 vPos4 = vec4(vPosition, 1);

   // Set position as Mults * point
   gl_Position = xyzwMultipliers * vPos4;

   // Set color
   color = vec4( vColor, 1.0 );
}
