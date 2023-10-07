#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800, 600, "Simple Window", nullptr, nullptr);

	if (window == nullptr) {
		std::cout << "Failed to create window!\n";
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glClearColor(0.52f, 0.52f, 0.52f, 1.0f);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return EXIT_SUCCESS;
}