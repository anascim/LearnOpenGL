#ifndef SHADER_H
#define SHADER_H

#include <glad.h>
#include <glm/glm.hpp>

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Shader
{
    public:
        unsigned int ID;
        Shader(const char* vertexPath, const char* fragmentPath);
        void Use();
        void SetBool(const std::string &name, bool value) const;
        void SetInt(const std::string &name, int value) const;
        void SetFloat(const std::string &name, float value) const;
        void SetFloat2(const std::string &name, glm::vec2 value) const;
        void SetFloat2(const std::string &name, float v1, float v2) const;
        void SetFloat3(const std::string &name, glm::vec3 value) const;
        void SetFloat3(const std::string &name, float v1, float v2, float v3) const;
        void SetFloat4(const std::string &name, glm::vec4 value) const;
        void SetFloat4(const std::string &name, float v1, float v2, float v3, float v4) const;
        void SetMat4(const std::string &name, const glm::mat4 &mat) const;
};

#endif // SHADER_H
