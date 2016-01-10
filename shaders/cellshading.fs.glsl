#version 330 core

struct Light{
    vec3 lightPos;
    vec3 lightColor;
};

struct dirLight{
    vec3 lightDir;
    vec3 lightColor;
};

in vec2 vTexCoords;
in vec3 vFragPos;
in vec3 vNormal;
in vec3 vView;
out vec4 color;

uniform sampler2D texture_diffuse1;
uniform vec3 color_diffuse;
//uniform vec3 color_ambiant;
uniform vec3 color_specular;
uniform float shininess;

uniform int nbPointLights;
uniform Light lights[100];
uniform dirLight myDirLight;

uniform int hasTexture;

//vec3 color_ambiant;

vec3 calcPointLight(Light light, vec3 normal, vec3 fragPos, vec3 viewDir){

    float constant = 1.0f;
    float linear = 0.09f;
    float quadratic = 0.032f;

    vec3 objectColor;
    if(hasTexture==1)
        objectColor = vec3(texture(texture_diffuse1, vTexCoords));
    else
        objectColor = color_diffuse;

    vec3 lightPos = light.lightPos;
    vec3 lightColor = light.lightColor;
    vec3 lightDir = normalize(lightPos - vFragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);

    //specular stuff

    float specularStrength = 0.5f;

    float distance    = length(lightPos - vFragPos);
    float attenuation = 1.0f / (constant + linear * distance +
                                quadratic * (distance * distance));

    //setting colors

    vec3 ambient  = lightColor * objectColor;
    vec3 diffuse  = lightColor * diff * objectColor;
    vec3 specular = spec * color_specular;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient+diffuse+specular);

}

vec3 CalcDirLight(dirLight light, vec3 normal, vec3 viewDir){

    vec3 objectColor;
    if(hasTexture==1)
        objectColor = vec3(texture(texture_diffuse1, vTexCoords));
    else
        objectColor = color_diffuse;


    vec3 lightDir = normalize(-light.lightDir);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    // Combine results
    vec3 ambient  = light.lightColor  * objectColor;
    vec3 diffuse  = light.lightColor  * diff * objectColor;
    vec3 specular = light.lightColor * spec * color_specular;
    return (ambient + diffuse + specular);
}


void main()
{
    //stuff for every light
    vec3 normal = normalize(vNormal);
    vec3 viewDir = normalize(vView - vFragPos);

    vec3 result = CalcDirLight(myDirLight, normal, viewDir);

    for(int i = 0; i < nbPointLights; i++)
        result += calcPointLight(lights[i], normal, vFragPos, viewDir);



    color = vec4(result, 1.0f);

    float luminance = (color.r + color.g + color.b) /3;
    if(luminance > 0.5){
        color.r = 0.7;
        color.g = 0.7;
        color.b = 0.7;
    }
    else {
        color.r = 0.3;
        color.g = 0.3;
        color.b = 0.3;
    }
}

