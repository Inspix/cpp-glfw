#include <iostream>
#include <GLFW/glfw3.h>
#include <graphics/window.h>
#include <utils/FileUtils.h>

using namespace inspix;
using namespace graphics;

int main(char** args, int argc) {
	
	Window window("OpenGL Testing Project", 800, 600);

	std::cout << glGetString(GL_VERSION) << std::endl;

	std::string shader = utils::readFile("shaders/vertex.vert");

	std::cout << shader << std::endl;
	glClearColor(0.2f, 0.6f, 0.8f, 1);

	while (!window.isClosing()) {
		window.clear();
		window.update();
	}

	return 0;
}