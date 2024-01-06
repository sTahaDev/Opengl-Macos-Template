#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>


int main(int argc, char **argv)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpengl", nullptr, nullptr);

    if (window == nullptr)
    {
        const char *error_str;
        glfwGetError(&error_str);
        std::cout << "Failed to create window, error: " << error_str << '\n';
        
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

 
    while (!glfwWindowShouldClose(window))
    {
           glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
