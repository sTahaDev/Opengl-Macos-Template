#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>

#include "shaderprogram.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


float deger = 0.0f;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE)
        glfwTerminate();
    if (key == GLFW_KEY_LEFT)
    {
        deger -= 0.01;
    }
    if (key == GLFW_KEY_RIGHT)
    {
        deger += 0.01;
    }
}

unsigned int VBO;
unsigned int VAO;



int main(int argc, char **argv)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int windowWidth = 800;
    int windowHeight = 600;

    float vertices[] = {
    (float)windowWidth/2.0f, (float)windowHeight*(2.0f/3.0f), 0.0f,
    (float)windowHeight*(1.0f/3.0f), (float)windowHeight/2.0f, 0.0f,
    (float)windowHeight*(2.0f/3.0f), (float)windowHeight/2.0f, 0.0f};

    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, "Simple Window", nullptr, nullptr);

    if (window == nullptr)
    {
        const char *error_str;
        glfwGetError(&error_str);
        std::cout << "Failed to create window, error: " << error_str << '\n';

        return EXIT_FAILURE;
    }
    
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    ShaderProgram program;

    program.attachShader("../shaders/simplevs.glsl", GL_VERTEX_SHADER);
    program.attachShader("../shaders/simplefs.glsl", GL_FRAGMENT_SHADER);
    program.link();

    unsigned int projectionMatrixLoc = program.addUniform("projectionMatrix");
    
    //unsigned int projectionMatrixLoc = glGetUniformLocation(programId, "projectionMatrix");
    glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)windowWidth, 0.0f, (float)windowHeight, -1.0f, 1.0f);

    program.use();
    glUniformMatrix4fv(projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // vertex array object oluşturuluyor
    glGenVertexArrays(1, &VAO);
    // vertex buffer object oluşuruluyor
    glGenBuffers(1, &VBO);

    // vertex array object aktif edildi.
    glBindVertexArray(VAO);
    // vertex buffer nesnesi aktif edildi.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // vertex buffer'a nokta bilgileri ytollanıyor
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // gönderilen vertex'e ait özellikler etiketleniyor
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    // özellik  etiket i aktif ediliyor.
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.52f, 0.52f, 0.52f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // çizimde kullanılacak olan program nesnesi aktif ediliyor
        program.use();

        // çizimde kullanılacak olan Vertex array object aktif ediliyor
        glBindVertexArray(VAO);
        // çizim komutu gönderiliyor
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
