#include <input/input.h>

#include <iostream>

namespace inspix {
	namespace input {
		Input::Input(GLFWwindow* window) :
			mouseX(0),mouseY(0)
		{
			for (int i = 0; i < ALLOWED_KEYS; i++)
			{
				keys[i] = false;
			}
			for (int i = 0; i < ALLOWED_MBUTTONS; i++)
			{
				mouseButtons[i] = false;
			}

			glfwSetCursorPosCallback(window, cursor_position_callback);
			glfwSetKeyCallback(window, key_callback);
			glfwSetMouseButtonCallback(window, mouse_button_callback);
		}

		Input::~Input() {
			std::cout << "Input deleted" << std::endl;
		}

		bool Input::isKeyPressed(int keycode) const {
			return keys[keycode];
		}

		bool Input::isMouseButtonPressed(int button) const {
			return mouseButtons[button];
		}

		double Input::getMouseX() const {
			return mouseX;
		}

		double Input::getMouseY() const {
			return mouseY;
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			input->keys[key] = action != GLFW_RELEASE;
			std::cout << "key callback called" << std::endl;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			input->mouseX = xpos;
			input->mouseY = ypos;
		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			input->mouseButtons[button] = action != GLFW_RELEASE;
		}
	}
}