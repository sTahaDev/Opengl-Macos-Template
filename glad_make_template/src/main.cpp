#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>

// vertex shader kaynak kodu
char *vssource =
    "#version 330 core\n                                    \
 layout (location = 0) in vec3 inPosition;              \
 void main()                                            \    
 {                                                      \
    gl_Position = vec4(inPosition, 1.0);                \
 }";
// fragment shader kaynak kodu
char *fssource =
    "#version 330 core\n                                    \
 out vec4 fragColor;                                    \
 void main()                                            \    
 {                                                      \
    fragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);           \
 }";

// noktalara ait koordinat bilgileri.
float vertices[] = {
    -0.6f, -0.6f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

unsigned int programId;

int main(int argc, char **argv)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "Simple Window", nullptr, nullptr);

    if (window == nullptr)
    {
        const char *error_str;
        glfwGetError(&error_str);
        std::cout << "Failed to create window, error: " << error_str << '\n';
        
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // Shaderları Oluşturma ve Programa Yükleme
    programId = glCreateProgram();

    unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderId, 1, &vssource, NULL);
    glCompileShader(vertexShaderId);

    unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderId, 1, &fssource, NULL);
    glCompileShader(fragmentShaderId);

    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);

    glLinkProgram(programId);

    // Vertex Buffer Object ve Array Object
    unsigned int VBO;
    unsigned int VAO;

    glGenBuffers(1, &VBO);      // Oluştur
    glGenVertexArrays(1, &VAO); // Oluştur

    glBindVertexArray(VAO);             // Vertex Array i aktif etme
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Buffer ı Aktif Etme

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Kopyalama

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *)0);

    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.52f, 0.52f, 0.52f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(programId);
        glBindVertexArray(VAO);
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
