#pragma once

#include "../drawables/drawable2d.h"

namespace inspix {
	namespace graphics {

		class Renderer2D {
		protected:
			
		public:
			virtual void submit(const Drawable2D* drawable) = 0;
			virtual void render() = 0;
			virtual void begin() {};
			virtual void end() {};


		};

	}
}