#version 330 core

in vec2 vTexCoords;
in vec3 vFragPos;
in vec3 vNormal;
in vec3 vView;
out vec4 color;


uniform sampler2D texture_diffuse1;
uniform vec3 color_diffuse;
uniform vec3 color_ambiant;
uniform vec3 color_specular;
uniform float shininess;

uniform vec3 lightPos;
uniform vec3 lightColor;

uniform int hasTexture;


void main()
{

    vec3 colorD = color_diffuse;

    //this should be in the scene :)
    vec3 colorA = vec3(1.0f, 1.0f, 1.0f);
    vec4 colorS = vec4(color_specular, 1.0f);
    // TO ADD IN THE LIGHT CLASS : floats about a point light
    float constant = 1.0f;
    float linear = 0.09f;
    float quadratic = 0.032f;

    float distance    = length(lightPos - vFragPos);
    float attenuation = 1.0f / (constant + linear * distance +
                                quadratic * (distance * distance));




    vec4 result;
    if(hasTexture==1){
        result = vec4(texture(texture_diffuse1, vTexCoords));
    }
    else{
        result = vec4(colorD,1);
    }

    //diffuse lightning
    vec4 lightColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(lightPos - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diff * lightColor;

    //specular stuff

    float specularStrength = 0.5;
    vec3 viewDir = normalize(vView - vFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec4 specular = specularStrength * spec * colorS;

    vec4 ambiant = vec4(colorA, 1.0f);

    //end calculations
    result *= attenuation;
    ambiant *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    result = result * (diffuse + specular + ambiant);

    color = result;
}