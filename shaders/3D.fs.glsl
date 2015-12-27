#version 330 core

in vec2 vTexCoords;
out vec4 color;

uniform sampler2D texture_diffuse1;
uniform vec3 color_diffuse;

uniform int hasTexture;


void main()
{   vec4 result;
    if(hasTexture==1){
        result = vec4(texture(texture_diffuse1, vTexCoords));
    }
    else{
        result = vec4(color_diffuse,1);
    }
    color = result;
}