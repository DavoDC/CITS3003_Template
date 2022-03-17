varying  vec2 texCoord;

uniform sampler2D texture;
uniform float d;

void main() 
{ 
    gl_FragColor = (texture2D( texture, vec2(texCoord.x+d, texCoord.y)) +
                    texture2D( texture, vec2(texCoord.x, texCoord.y+d)) +
                    texture2D( texture, vec2(texCoord.x-d, texCoord.y)) +
                    texture2D( texture, vec2(texCoord.x, texCoord.y-d)))/4.0;
} 
