#pragma once

#include <GLFW/glfw3.h>
#include "math/maths.h"
#define ALLOWED_KEYS 512
#define ALLOWED_MBUTTONS 32

namespace inspix {
	namespace input {
		class Input {
		private:
			bool keys[ALLOWED_KEYS];
			bool keysPrev[ALLOWED_KEYS];
			bool keysOnce[ALLOWED_KEYS];
			bool mouseButtons[ALLOWED_MBUTTONS];
			bool mouseButtonsPrev[ALLOWED_MBUTTONS];
			bool mouseButtonsOnce[ALLOWED_MBUTTONS];

			math::Vec2f m_mousepos;
			double mouseX, mouseY;
		public:
			Input(GLFWwindow* window);
			virtual ~Input();
			bool isKeyDown(int keycode) const;
			bool isKeyPressed(int keycode) const;
			bool isMouseButtonDown(int button) const;
			bool isMouseButtonPressed(int button) const; 
			void update();
			const math::Vec2f& getMousePos() const { return m_mousepos; }
			double getMouseX() const;
			double getMouseY() const;
		private:
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		}; 
	}
}