#include "application.h"

namespace inspix {
	
	Application::Application(const unsigned int width, const unsigned int height, char* title)
	{
		window = new graphics::Window(title, width, height);		
	}

	Application::~Application() {
		delete window;
	}

	void Application::init() {

	}
	void Application::render() {
		window->clear();
	}
	void Application::update() {

		window->update();
	}

	void Application::run() {
		while (!window->isClosing()) {
			update();
			render();
		}
	}
}