#pragma once

#include "renderer.h"


#define RENDERER_VERTEX_DATA_SIZE sizeof(VertexData)

namespace inspix {
	namespace graphics {

		class BatchRenderer : public Renderer2D {
		private:
			GLuint m_VertexDataBuffer;
			IndexBuffer* m_IBO;
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