#pragma once

#include "../drawables/drawable2d.h"

namespace inspix {
	namespace graphics {

		struct VertexData {
			math::Vec3f vertex;
			Color color;
		};

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