#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <cmath>
#include <map>
#include <vector>

#include <glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "Shader.h"
#include "Camera.h"
#include "Model.h"

void processInput(GLFWwindow *window);
void didChangeSize(GLFWwindow* window, int width, int height);
void didChangeMousePosition(GLFWwindow* window, double xPos, double yPos);
void didChangeScrollValue(GLFWwindow* window, double xOffset, double yOffset);

float cube_vertices[] = {
    // float3 position, float2 texCoord, float3 normal
    // front
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
    // back
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
    // left
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
    // right
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
    // bottom
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
    // top
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f
};

glm::vec3 cubesPositions[] = {
    glm::vec3(0.0f, 0.0f, -2.0f),
    glm::vec3(2.0f, 0.0f, -1.0f),
    glm::vec3(-2.0f, 1.0f, -2.0f),
    glm::vec3(1.0f, 3.0f, -12.0f),
    glm::vec3(-3.0f, -4.0f, -6.0f),
    glm::vec3(4.0f, -1.0f, -6.0f),
    glm::vec3(-5.0f, 2.0f, -8.0f),
};

glm::vec3 lightCubePosition = glm::vec3(1.5f, 0.6f, 0.4f);
glm::vec3 ambientLight = glm::vec3(0.1f, 0.4f, 0.3f);
glm::vec3 lightColor = glm::vec3(0.9f, 0.5f, 0.4f);

float mixValue = 0.2f;
int SCR_WIDTH = 1280;
int SCR_HEIGHT = 720;

float deltaTime = 0.0f;
float lastTime = 0.0f;

// ---- CAMERA ----
Camera camera(glm::vec3(0.0f, 1.0f, 3.0f));

float lastX = SCR_WIDTH/2.0f, lastY = SCR_HEIGHT/2.0f;
bool isFirstMouseUpdate = true;

// ---- FONTS ----
struct Character
{
    unsigned int textureID;
    glm::ivec2 size;
    glm::ivec2 bearing;
    unsigned int advance;
};
std::map<char, Character> characters;

int main()
{
    glfwInit();

    // set OpenGL version to 3.3 core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);


    // Setup callbakcs
    glfwSetFramebufferSizeCallback(window, didChangeSize);
    glfwSetCursorPosCallback(window, didChangeMousePosition);
    glfwSetScrollCallback(window, didChangeScrollValue);

    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    stbi_set_flip_vertically_on_load(true);

    Shader basicShader("src/basic_vertex.vs", "src/basic_fragment.fs");
    Shader lightShader("src/light_vertex.vs", "src/light_fragment.fs");

    // ---- Free Type --- (font loading)

    FT_Library ft;
    if (FT_Init_FreeType(&ft))
    {
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        return -1;
    }

    FT_Face face;
    if (FT_New_Face(ft, "./fonts/NotoMono-Regular.ttf", 0, &face))
    {
        std::cout << "ERROR::FREETYPE: failed to load font" << std::endl;
        return -1;
    }

    FT_Set_Pixel_Sizes(face, 0, 48);
    if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
    {
        std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
        return -1;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    for (unsigned char c = 0; c < 128; c++)
    {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYPE: Failed to load glyph" << std::endl;
            continue;
        }

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        Character character = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            face->glyph->advance.x
        };
        characters.insert(std::pair<char, Character>(c, character));
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    // ---- SETUP ONCE ----

    unsigned int cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glBindVertexArray(cubeVAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    Model ourModel("assets/backpack/backpack.obj");

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // ---- RENDER LOOP ----
    while(!glfwWindowShouldClose(window))
    {
        float currentTime = (float)glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        processInput(window);

        glClearColor(ambientLight.x, ambientLight.y, ambientLight.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        basicShader.Use();
        glm::mat4 projection = glm::perspective(glm::radians(camera.Fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        basicShader.SetMat4("projection", projection);
        basicShader.SetMat4("view", view);

        basicShader.SetFloat("time", (float)glfwGetTime());
        basicShader.SetFloat3("cameraPos", camera.Position);
        basicShader.SetFloat3("lightColor", lightColor);
        basicShader.SetFloat3("lightPos", lightCubePosition);
        basicShader.SetFloat3("material.ambient", ambientLight);
        basicShader.SetFloat3("material.color", 1.0f, 1.0f, 1.0f);
        basicShader.SetFloat("material.shininess", 128.0f);

        // DRAW MODELS
        for (int i = 0; i < 7; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubesPositions[i]);
            model = glm::rotate(model, cos((float)i * 4.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, cos((float)i * 20.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));

            basicShader.SetMat4("model", model);
            ourModel.Draw(basicShader);
        }

        // DRAW LIGHT CUBE
        //lightCubePosition.x = sin((float)glfwGetTime()) * 10.0f;
        //lightCubePosition.z = -4.0f + cos((float)glfwGetTime()) * 10.0f;
        lightShader.Use();
        glm::mat4 lightModel = glm::mat4(1.0f);
        lightModel = glm::translate(lightModel, lightCubePosition);
        lightModel = glm::scale(lightModel, glm::vec3(0.2f));
        lightShader.SetMat4("model", lightModel);
        lightShader.SetMat4("view", view);
        lightShader.SetMat4("projection", projection);
        lightShader.SetFloat3("color", lightColor);

        glBindVertexArray(lightCubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // END RENDERING
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    int rMove = 0;
    int fMove = 0;
    int uMove = 0;
    bool running = false;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        fMove += 1;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        rMove -= 1;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        fMove -= 1;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        rMove += 1;
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        uMove -= 1;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        uMove += 1;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        running = true;


    camera.ProcessMovement(rMove, fMove, uMove, running, deltaTime);
}

// ---- GLFW CALLBACKS ----

void didChangeSize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void didChangeMousePosition(GLFWwindow* window, double xPos, double yPos)
{
    if (isFirstMouseUpdate)
    {
        lastX = xPos;
        lastY = yPos;
        isFirstMouseUpdate = false;
    }

    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos; // reversed since y coordinates range from bottom to top
    lastX = xPos;
    lastY = yPos;

    camera.ProcessRotation(xOffset, yOffset);
}

void didChangeScrollValue(GLFWwindow* window, double xOffset, double yOffset)
{
    camera.ProcessScroll((float)yOffset);
}

#endif // MAIN_H_INCLUDED

