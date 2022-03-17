#version 150
#extension GL_NV_shadow_samplers_cube : enable 

in vec3 R;
uniform samplerCube texMap;
out vec4 fColor;

void main()
{
     vec4 texColor = textureCube(texMap, R);

    fColor = texColor;
}
