#version 330 core

in vec2 TexCoord;
in vec3 Normal;
in vec3 WorldPos;

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;
uniform float ambientStrength;
uniform float diffuseStrength;

void main()
{
    float ambient = ambientStrength;

    vec3 lightDir = normalize(WorldPos - lightPos);
    float nDotL = max(dot(Normal, -lightDir), 0.0f);
    float diffuse = nDotL * diffuseStrength;

    vec3 reflection = reflect(lightDir, Normal);
    vec3 camDir = normalize(cameraPos - WorldPos);
    float specular = pow(max(dot(camDir, reflection), 0.0f), 32.0f);

    vec3 color = (ambient + diffuse + specular) * objectColor * lightColor;
    FragColor = vec4(color, 1.0f);
}
