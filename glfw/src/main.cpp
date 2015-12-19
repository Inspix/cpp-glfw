#include <graphics/shader.h>
#include <graphics/window.h>
#include <input/input.h>
#include <utils/FileUtils.h>
#include "math/maths.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexBuffer.h"
#include "graphics/buffers/vertexarray.h"

using namespace inspix;
using namespace graphics;
using namespace math;

int main(int argc,char** argv) {
	
	Window window("OpenGL Testing Project", 960, 540);
	
	glewInit();

	ShaderProgram shader("shaders/vertex.vert", "shaders/fragment.frag");

	// Tests

	GLfloat verticies[] = {
		-8.0f , -4.5f, 0.0f,
		8.0f, -4.5f, 0.0f,
		8.0f, 4.5f, 0.0f,
		-8.0f , 4.5f, 0.0f,
		
		
	};

	GLuint indicies[] = {
		0,1,2,
		0,2,3
	};

	GLfloat colors[] = {
		0.3f,0.3f,0.3f,1,
		0.1f,0.5f,0.8f,1,
		0.8f,0.5f,0.1f,1,
		1.0f,0.3f,0.1f,1
	};

	Buffer vbo(verticies, 4 * 3, 3);
	Buffer cbo(colors, 4 * 4, 4);
	IndexBuffer ibo(indicies, 6);

	VertexArray vao;
	vao.addBuffer(vbo, 0);
	vao.addBuffer(cbo, 1);


	Mat4 pr_matrix = Mat4::orthographic(-16, 16, -9, 9, -10, 10);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1);
	Vec4 color1(1, 0, 0, 1);
	Vec4 color2(0, 1, 0, 1);

	input::Input* input = window.getInput();
	float lol = 0.5f;
	float increment = 1;
	glUseProgram(shader.getId());
	shader.setUniformMat4("pr_matrix", pr_matrix);
	Vec2 light(0);
	float intensity = 1;
	float rotate = 1.0f;
	while (!window.isClosing()) {
		window.clear();

		//std::cout << light << std::endl;
		shader.setUniform2("light", light);
		shader.setUniform1("intensity", intensity);

		vao.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", Mat4::translation(-8, -4.5f, 0));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, 0);
		ibo.unbind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", Mat4::translation(8, 4.5f, 0));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, 0);
		ibo.unbind();
		vao.unbind();

		window.update();		

		if (input->isKeyPressed(GLFW_KEY_KP_SUBTRACT))
		{
			intensity -= 0.05f;
		}
		if (input->isKeyPressed(GLFW_KEY_KP_ADD))
			intensity += 0.05f;
		if (input->isKeyPressed(GLFW_KEY_ESCAPE))
		{
			window.close();
		}
		light.x = (float)(-16.0f + input->getMouseX() * 32.0f/960.0);
		light.y = (float)(9 - input->getMouseY() * 18.0f / 540.0);

	}

	return 0;
}