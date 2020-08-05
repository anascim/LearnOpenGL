#version 330 core

in vec2 TexCoord;
in vec3 Normal;
in vec4 WorldPos;

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform float ambientIntensity;
uniform float diffuseIntensity;

void main()
{
    float ambient = ambientIntensity;
    vec3 lightDirection = normalize(vec3(WorldPos) - lightPos);
    float diffuse = max(dot(Normal, -lightDirection), 0.0f) * diffuseIntensity;
    vec3 color = (ambient + diffuse) * objectColor * lightColor;
    FragColor = vec4(color, 1.0f);
}
