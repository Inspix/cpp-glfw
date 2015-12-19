#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <input/input.h>

namespace inspix {
	namespace graphics {
		class Window
		{

		private:
			GLFWwindow* m_Window;
			unsigned int m_Width, m_Height;
			char* m_Title;
			input::Input* m_Input;
		public:
			Window(char* title, const unsigned int width, const unsigned int height);
			virtual ~Window();

			input::Input* getInput() const { return m_Input; }
			void close() const { glfwSetWindowShouldClose(m_Window, 1); };
			void clear() const;
			void update();			
			bool isClosing() const {
				return glfwWindowShouldClose(m_Window) == 1;
			}
		};
	}
}


