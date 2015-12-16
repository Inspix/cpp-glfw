#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace inspix {
	namespace graphics {
		class Window
		{

		private:
			GLFWwindow* m_Window;
			unsigned int m_Width, m_Height;
			char* m_Title;

		public:
			Window(char* title, const unsigned int width, const unsigned int height);
			virtual ~Window();

			void clear() const;
			void update();

			bool isClosing() const {
				return glfwWindowShouldClose(m_Window) == 1;
			}
		};
	}
}


