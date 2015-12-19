#include "game.h"

Game::Game()
	: Application(960,540,"OpenGL Testing Ground")
{
	init();
}
Game::~Game() {
	delete m_Shader;
}

void Game::init() {
	glewInit();
	glEnable(GL_MULTISAMPLE);
	glClearColor(0.0f, 0.0f, 0.0f, 1);
	m_Input = window->getInput();
	m_Shader = new ShaderProgram("shaders/vertex.vert", "shaders/fragment.frag");
	glUseProgram(m_Shader->getId());
	m_ProjectionMatrix = math::Mat4::orthographic(0, 16, 0, 9, -10, 10);
	m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
}

void Game::update() {
	window->update();
	m_light.x = (float)(m_Input->getMouseX() * 16.0f / 960.0);
	m_light.y = (float)(9 - m_Input->getMouseY() * 9.0f / 540.0);

	updateInput();
}


void Game::updateInput() {

	if (m_Input->isKeyPressed(GLFW_KEY_KP_SUBTRACT))
	{
		m_Intensity -= 0.05f;
	}
	if (m_Input->isKeyPressed(GLFW_KEY_KP_ADD))
		m_Intensity += 0.05f;
	if (m_Input->isKeyPressed(GLFW_KEY_ESCAPE))
	{
		window->close();
	}
}

void Game::run(){

	Drawable2D sprite(Vec3(0, 0, 0), Vec2(16, 9), Vec4(1, 1, 1, 1), *m_Shader);
	Drawable2D sprite2(Vec3(2, 0, 0), Vec2(2, 2), Vec4(0.1f, 0.1f, 1, 1), *m_Shader);

	while (!window->isClosing()) {
		update();
		window->clear();


		m_Shader->setUniform2("light", m_light);
		m_Shader->setUniform1("intensity", m_Intensity);

		sprite.getVao()->bind();
		sprite.getIbo()->bind();
		m_Shader->setUniformMat4("ml_matrix", sprite.getTransform());
		glDrawElements(GL_TRIANGLES, sprite.getIbo()->getCount(), GL_UNSIGNED_INT, 0);

		sprite.getIbo()->unbind();
		sprite.getVao()->unbind();

		sprite2.getVao()->bind();
		sprite2.getIbo()->bind();
		m_Shader->setUniformMat4("ml_matrix", sprite2.getTransform());
		glDrawElements(GL_TRIANGLES, sprite2.getIbo()->getCount(), GL_UNSIGNED_INT, 0);

		sprite2.getIbo()->unbind();
		sprite2.getVao()->unbind();
	}
}