/*
#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;
    SetupMesh();
}


void Mesh::Draw(Shader &shader)
{
    shader.Use();
    bool hasDiffuse = false;
    bool hasSpecular = false;
    int i = 0;
    for (i; i < textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        if (textures[i].Type == DIFFUSE)
        {
            shader.SetInt("material.diffuse", i);
            hasDiffuse = true;
        }
        else if (textures[i].Type == SPECULAR)
        {
            shader.SetInt("material.specular", i);
            hasSpecular = true;
        }
        glBindTexture(GL_TEXTURE_2D, textures[i].ID);
    }
    glActiveTexture(++i);

    // give white pixel texture if no diffuse map
    if (!hasDiffuse)
    {
        unsigned int whitePxl;
        glGenTextures(1, &whitePxl);
        glBindTexture(GL_TEXTURE_2D, whitePxl);
        unsigned char data[] = {255, 255, 255};
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        shader.SetInt("material.diffuse", i);
        glActiveTexture(++i);
    }
    // give black pixel texture if no specular map
    if (!hasSpecular)
    {
        unsigned int blackPxl;
        glGenTextures(1, &blackPxl);
        glBindTexture(GL_TEXTURE_2D, blackPxl);
        unsigned char data[] = {0, 0, 0};
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        shader.SetInt("material.specular", i);
    }
    glActiveTexture(0);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::SetupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Normal));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, TexCoord));

    glBindVertexArray(0);
}
*/
