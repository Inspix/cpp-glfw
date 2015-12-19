#include <graphics/shader.h>
#include <graphics/window.h>
#include <input/input.h>
#include <utils/FileUtils.h>
#include "math/maths.h"

using namespace inspix;
using namespace graphics;
using namespace math;

int main(int argc,char** argv) {
	
	Window window("OpenGL Testing Project", 960, 540);
	
	glewInit();

	ShaderProgram shader("shaders/vertex.vert", "shaders/fragment.frag");

	// Tests
#if 0 
	Vec2 empty;
	Vec2 constructor(5.4f, 4.3f);
	Vec2 addition = Vec2(0.5f, 1.5f) + Vec2(1.5f, 2.5f);
	Vec2 substraction = Vec2(2.5f, 2.5f) - Vec2(2.0f, 2.0f);
	Vec2 multiplication = Vec2(5.0f, 5.0f) * Vec2(2.0f, 3.0f);
	Vec2 division = Vec2(5.0f, 2.0f) / Vec2(2.0f, 3.0f);
	bool equality = Vec2(2) == Vec2(2, 2);
	bool inequality = Vec2(3) != Vec2(3, 3);
	std::cout << empty << std::endl;
	std::cout << constructor << std::endl;
	std::cout << addition << std::endl;
	std::cout << substraction << std::endl;
	std::cout << multiplication << std::endl;
	std::cout << division << std::endl;
	std::cout << equality << std::endl;
	std::cout << inequality << std::endl;

	std::cout << "Vec2[5.4, 4.3] = Method chaining add 2/divide by 2/multiply by 3" << constructor.add(Vec2(2, 2)).div(2).mul(3) << std::endl;

	Vec3 v3empty;
	Vec3 v3constructor(5,4,3);
	Vec3 v3addition = Vec3(1, 1, 1) + Vec3(3, 3, 3);
	Vec3 v3substraction = Vec3(5, 5, 5) - Vec3(2, 2, 2);
	Vec3 v3multiplication = Vec3(5, 5, 5) * Vec3(2, 2, 2);
	Vec3 v3division = Vec3(5, 5, 5) / Vec3(2, 2, 2);

	std::cout << v3empty << std::endl;
	std::cout << v3constructor << std::endl;
	std::cout << v3addition << std::endl;
	std::cout << v3substraction << std::endl;
	std::cout << v3multiplication << std::endl;
	std::cout << v3division << std::endl;
	std::cout << "Vec3[5, 4, 3] = Method chaining add 2/divide by 2/multiply by 3" << v3constructor.add(Vec3(2)).div(2).mul(3) << std::endl;
	v3empty.r = 5;
	std::cout << "!!!!!!!!! " << v3empty.x << std::endl;
	Vec4 v4empty;
	Vec4 v4constructor(5);
	Vec4 v4addition = Vec4(1, 1, 1, 2.5f) + Vec4(3, 3, 3,1.3f);
	Vec4 v4substraction = Vec4(5, 5, 5,3.4f) - Vec4(2, 2, 2, 3.4f);
	Vec4 v4multiplication = Vec4(5, 5, 5,3.5) * Vec4(2, 2, 2, 5);
	Vec4 v4division = Vec4(5, 5, 5, 5) / Vec4(5, 4, 3, 2);

	std::cout << v4empty << std::endl;
	std::cout << v4constructor << std::endl;
	std::cout << v4addition << std::endl;
	std::cout << v4substraction << std::endl;
	std::cout << v4multiplication << std::endl;
	std::cout << v4division << std::endl;
	std::cout << "Vec4[5, 5, 5, 5] = Method chaining add 2/divide by 2/multiply by 3" << v4constructor.add(Vec4(2)).div(2).mul(3) << std::endl;
#endif

	Vec4 test(0);

	test.r = 5;

	std::cout << &test.r << std::endl;
	std::cout << &test.x << std::endl;
	std::cout << "array : " << &test.values[0] << std::endl;

	GLfloat verticies[] = {
		-8.0f , -4.5f, 0.0f,
		8.0f, -4.5f, 0.0f,
		8.0f, 4.5f, 0.0f,
		8.0f, 4.5f, 0.0f,
		-8.0f , 4.5f, 0.0f,
		-8.0f , -4.5f, 0.0f
		
		
	};

	std::unordered_map<std::string, GLint> map;
	map["test"] = 1;

	std::cout << map["a"] << " " << map["test"] << std::endl;

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Mat4 pr_matrix = Mat4::orthographic(-16, 16, -9, 9, -10, 10);
	Mat4 rot_matrix = Mat4::rotation(25.0f, 0.0f, 0.0f, 1.0f);
	
	glClearColor(0.0f, 0.0f, 0.8f, 1);

	input::Input* input = window.getInput();
	float lol = 0.5f;
	float increment = 1;
	glUseProgram(shader.getId());
	shader.setUniformMat4("pr_matrix", pr_matrix);
	shader.setUniformMat4("vw_matrix", rot_matrix);
	float rotate = 1.0f;
	while (!window.isClosing()) {
		window.clear();

		//std::cout << "X: " << input->getMouseX() << " Y:" << input->getMouseY() << std::endl;
		//std::cout << lol << std::endl;
		//clamp(lol, 0, 1000, increment);
		//increment++;

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	}

	return 0;
}