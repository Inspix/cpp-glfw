#pragma once

#include "renderer.h"

namespace inspix {
	namespace graphics {

#define MAX_DRAWABLES			50000
#define VERTEX_DATA_SIZE		sizeof(VertexData)
#define DRAWABLE_SIZE			VERTEX_DATA_SIZE * 4
#define BUFFER_SIZE				MAX_DRAWABLES * DRAWABLE_SIZE
#define INDEX_COUNT				MAX_DRAWABLES * 6

		class BatchRenderer : public Renderer2D {
		private:
			GLuint m_VertexDataBuffer;
			GLuint m_VertexArray;
			VertexArray m_Vao;
			IndexBuffer* m_IBO;
			VertexData* m_BufferPointer;
			GLsizei m_CurrentIndexCount;
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