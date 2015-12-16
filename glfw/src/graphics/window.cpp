#include "window.h"

namespace inspix {
	namespace graphics {
		Window::Window(char* title, const unsigned int width, const unsigned int height) :
			m_Title(title), m_Width(width), m_Height(height)
		{
			if (!glfwInit())
			{
				std::cout << "GLFW Initialization failed" << std::endl;
				return;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window)
			{
				std::cout << "GLFW Window creation failed." << std::endl;
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(m_Window);
			m_Input = new input::Input(m_Window);
			glfwSetWindowUserPointer(m_Window, m_Input);
		}


		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}
	}

}


