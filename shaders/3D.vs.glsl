#version 330 core

//Attributs
layout(location = 5) in vec3 aVertexPosition;
//its 5 because 0 is attribued to model thingie
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoords;

//Variables uniformes, matrices de transformations
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//Sorties du shader
//out vec3 vPosition_vs; //position du sommet transformée dans le view space
//out vec3 vNormal_vs; //normale du sommet transformée dans le view space
//out vec2 vTexCoords;

void main()
{
    //Coordonnées homogènes

    /*vec4 vertexNormal = vec4(aVertexNormal, 0);

    //Valeurs de sortie
    vPosition_vs = vec3(uMVMatrix * vertexPosition);
    vNormal_vs = vec3(uNormalMatrix * vertexNormal);
    vTexCoords = aVertexTexCoords;*/

    //Position projetée
    //gl_Position = projection * view * model * vec4(aVertexPosition.x, aVertexPosition.y, aVertexPosition.z, 1.0f);
    gl_Position = projection * view * model * vec4(aVertexPosition, 1.0f);
}
