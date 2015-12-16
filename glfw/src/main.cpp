#include <graphics/shader.h>
#include <graphics/window.h>
#include <utils/FileUtils.h>

using namespace inspix;
using namespace graphics;

int main(char** args, int argc) {
	
	Window window("OpenGL Testing Project", 800, 600);
	
	glewInit();

	ShaderProgram shader("shaders/vertex.vert", "shaders/fragment.frag");

//	std::cout << shader << std::endl;
	glClearColor(0.2f, 0.6f, 0.8f, 1);

	while (!window.isClosing()) {
		window.clear();
		window.update();
	}

	return 0;
}