#version 150

in  vec3 vPosition;
in  vec3 vColor;
out vec4 color;

uniform mat2 multipliers;

void
main()
{
  // Load in values as is
  gl_Position = vec4(vPosition, 1); 

  // Rotate about Y by altering X,Z
  gl_Position.xz = multipliers * gl_Position.xz;  


   // Set color
   color = vec4( vColor, 1.0 );
}
