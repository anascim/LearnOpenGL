/*
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;

void main()
{
    TexCoords = aTexCoords;
    vec3 newPos = aPos + vec3(sin(aPos.y * 10.0 + time*5.0)/20, 0.0, 0.0);
    gl_Position = projection * view * model * vec4(newPos, 1.0);
}
*/
#version 330 core
layout (location = 0) in vec3 aPos; // "a" for "attribute"
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 Normal;
out vec3 WorldPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
   TexCoord = aTexCoord;
   Normal = mat3(transpose(inverse(model))) * aNormal; // correction for world space
   WorldPos = vec3(model * vec4(aPos, 1.0));
   gl_Position = projection * view * model * vec4(aPos, 1.0);
}

