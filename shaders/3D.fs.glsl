#version 330 core

in vec3 position_fs;
out vec3 color;

//uniform sampler2D texture_diffuse1;

void main()
{
    //color = vec4(texture(texture_diffuse1, vTexCoords));
    color = vec3(1.0f, 0.0f, 0.0f);
}