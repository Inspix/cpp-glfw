#pragma once

#include "renderer.h"

namespace inspix {
	namespace graphics {

		class BatchRenderer : public Renderer2D {
		private:
			GLuint m_VertexData;
			IndexBuffer m_IBO;
			std::vector<const Drawable2D*> drawables;
		public:
			BatchRenderer();
			~BatchRenderer();

			void submit(const Drawable2D* drawable) override;
			void render() override;
			void begin();
			void end();

		};

	}
}