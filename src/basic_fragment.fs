/*
#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{
    FragColor = texture(texture_diffuse1, TexCoords);
}
*/
#version 330 core

in vec2 TexCoord;
in vec3 Normal;
in vec3 WorldPos;

out vec4 FragColor;

// Camera
uniform vec3 cameraPos;

// Light
uniform vec3 lightColor;
uniform vec3 lightPos;

// Material
struct Material
{
    vec3 ambient;
    sampler2D diffuse;
    sampler2D specular;
    vec3 color;
    float shininess;
};
uniform Material material;

void main()
{
    vec3 ambient = material.ambient * vec3(texture(material.diffuse, TexCoord));

    vec3 lightDir = normalize(WorldPos - lightPos);
    float nDotL = max(dot(Normal, -lightDir), 0.0f);
    vec3 diffuse = nDotL * vec3(texture(material.diffuse, TexCoord)) * lightColor/2;

    vec3 reflection = normalize(reflect(lightDir, Normal));
    vec3 camDir = normalize(cameraPos - WorldPos);
    float vDotR = max(dot(camDir, reflection), 0.0f);
    vec3 specular = vec3(pow(vDotR, material.shininess)) * lightColor/2;

    vec3 color = (ambient + diffuse + specular) * material.color;
    FragColor = vec4(color, 1.0f);
}
