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
				keysPrev[i] = false;
				keysOnce[i] = false;
			}
			for (int i = 0; i < ALLOWED_MBUTTONS; i++)
			{
				mouseButtons[i] = false;
				mouseButtonsPrev[i] = false;
				mouseButtonsOnce[i] = false;
			}

			glfwSetCursorPosCallback(window, cursor_position_callback);
			glfwSetKeyCallback(window, key_callback);
			glfwSetMouseButtonCallback(window, mouse_button_callback);
		}

		Input::~Input() {
			std::cout << "Input deleted" << std::endl;
		}

		bool Input::isKeyDown(int keycode) const {
			if (keycode > ALLOWED_KEYS)
			{
				return false;
			}
			return keys[keycode];
		}

		bool Input::isKeyPressed(int keycode) const {
			if (keycode > ALLOWED_KEYS)
			{
				return false;
			}
			return keysOnce[keycode];
		}

		bool Input::isMouseButtonDown(int button) const {
			if (button >= ALLOWED_MBUTTONS)
			{
				return false;
			}
			return mouseButtons[button];
		}

		bool Input::isMouseButtonPressed(int button) const {
			if (button >= ALLOWED_MBUTTONS)
			{
				return false;
			}
			return mouseButtonsOnce[button];
		}

		double Input::getMouseX() const {
			return m_mousepos.x;
		}

		double Input::getMouseY() const {
			return m_mousepos.y;	
		}

		void Input::update() {
			for (int i = 0; i < ALLOWED_KEYS; i++)
			{
				keysOnce[i] = keys[i] && !keysPrev[i];
			}

			for (int i = 0; i < ALLOWED_MBUTTONS; i++)
			{
				mouseButtonsOnce[i] = mouseButtons[i] && !mouseButtonsPrev[i];
			}
			std::copy(&keys[0], &keys[0] + sizeof(keys), keysPrev);
			std::copy(&mouseButtons[0], &mouseButtons[0] + sizeof(mouseButtons), mouseButtonsPrev);
			//memcpy(keysPrev, keys, ALLOWED_KEYS);
			//memcpy(mouseButtonsPrev, mouseButtons, ALLOWED_MBUTTONS);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			input->keys[key] = action == GLFW_PRESS;
			std::cout << "key callback called" << std::endl;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			input->m_mousepos.x = (float)xpos;
			input->m_mousepos.y = (float)ypos;
		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			Input* input = (Input*)glfwGetWindowUserPointer(window);
			input->mouseButtons[button] = action != GLFW_RELEASE;
		}
	}
}