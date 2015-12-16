#pragma once

#include <GLFW/glfw3.h>
#define ALLOWED_KEYS 512
#define ALLOWED_MBUTTONS 32

namespace inspix {
	namespace input {
		class Input {
		private:
			bool keys[ALLOWED_KEYS];
			bool mouseButtons[ALLOWED_MBUTTONS];
			double mouseX, mouseY;
		public:
			Input(GLFWwindow* window);
			virtual ~Input();
			bool isKeyPressed(int keycode) const;
			bool isMouseButtonPressed(int button) const; 
			double getMouseX() const;
			double getMouseY() const;
		private:
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		}; 
	}
}