#pragma once

#include <graphics/window.h>

namespace inspix {

	class Application {
	protected:
		graphics::Window* window;
	public:
		Application(const unsigned int width, const unsigned int height, char* title);
		~Application();
		
		virtual void run();
	protected:
		virtual void render();
		virtual void update();
		virtual void init();
		inline input::Input* getInput() const { return window->getInput(); };
	};
}