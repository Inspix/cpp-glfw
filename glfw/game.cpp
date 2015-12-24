#include "game.h"
#include "utils/timer.h"

Game::Game()
	: Application(960,540,"OpenGL Testing Ground")
{
	init();
}
Game::~Game() {
	delete m_Shader;
	delete renderer;
}

void Game::init() {
	glewInit();
	glEnable(GL_MULTISAMPLE);
	glClearColor(0.0f, 0.0f, 0.0f, 1);
	m_Input = window->getInput();
	m_Shader = new ShaderProgram("shaders/vertex.vert", "shaders/fragment.frag");
	renderer = new SimpleRenderer2D(*m_Shader);
	renderer2 = new BatchRenderer();
	glUseProgram(m_Shader->getId());
	m_ProjectionMatrix = math::Mat4::orthographic(-16, 16, -9, 9, -10, 10);
	m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
}

void Game::update() {
	window->update();
	m_light.x = (float)(m_Input->getMouseX() * 32.0f / 960.0 - 16.0f);
	m_light.y = (float)(9 - m_Input->getMouseY() * 18.0f / 540.0);

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

	srand(time(NULL));

	std::vector<const Drawable2D*> drawables;

	
	for (float y = -9.0; y < 9.0; y+= 0.20f)
	{
		for (float x = -16.0; x < 16.0; x+= 0.20f)
		{
			const Drawable2D* current = new Drawable2D(Vec3f(x, y, 0), Vec2f(0.19f, 0.19f), Color(rand() % 256, rand() % 256, rand() % 256, 255));
			drawables.push_back(current);
		}
	}

	Drawable2D* positionTest = new Drawable2D(Vec3f(0, 0, 0), Vec2f(4, 4), Color(0x2020ffffu));
	std::cout << sizeof(Drawable2D) * drawables.size() << std::endl;
	drawables.push_back(positionTest);
	TimerS timer;
	timer.run();
	int frames = 0;
	
	while (!window->isClosing()) {
		update();
		window->clear();

		glUseProgram(m_Shader->getId());
		m_Shader->setUniform2("light", m_light);
		m_Shader->setUniform1("intensity", m_Intensity);
		positionTest->Rotation = (float)(glfwGetTime());
		positionTest->Size = (cos(glfwGetTime()) * 3) * Vec2f(1);
		positionTest->recalculateTransform();
		renderer2->begin();

		for (size_t i = 0; i < drawables.size(); i++)
		{
			renderer2->submit(drawables[i]);
		}		
		renderer2->end();
		//renderer->render();
		frames++;

		if (timer.getElapsed() >= 1)
		{
			std::cout << "FPS: " << std::dec << frames << std::endl;
			timer.reset();
			frames = 0;
			
		}
	}

	for (size_t i = 0; i < drawables.size(); i++)
	{
		delete drawables[i];
	}
}