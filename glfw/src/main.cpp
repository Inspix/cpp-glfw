#include <graphics/shader.h>
#include <graphics/window.h>
#include <input/input.h>
#include <utils/FileUtils.h>

using namespace inspix;
using namespace graphics;

int main(char** args, int argc) {
	
	Window window("OpenGL Testing Project", 960, 540);
	
	glewInit();

	ShaderProgram shader("shaders/retro.vert", "shaders/retro.frag");


//	std::cout << shader << std::endl;
	glClearColor(0.0f, 0.0f, 0.8f, 1);

	input::Input* input = window.getInput();

	glUseProgram(shader.getId());
	float rotate = 1.0f;
	while (!window.isClosing()) {
		window.clear();

		std::cout << "X: " << input->getMouseX() << " Y:" << input->getMouseY() << std::endl;


		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.0, 0.5);
		glVertex2f(0.5, 0.5);
		glEnd();

		window.update();
	}

	return 0;
}