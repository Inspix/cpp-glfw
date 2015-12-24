#include "batchrenderer.h"

namespace inspix {
	namespace graphics {
		BatchRenderer::BatchRenderer() {
			m_Vao.bind();
			glGenBuffers(1, &m_VertexDataBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, m_VertexDataBuffer);
			glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

			m_Vao.addPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_DATA_SIZE,(const GLvoid*)offsetof(VertexData,vertex));
			m_Vao.addPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, VERTEX_DATA_SIZE, (const GLvoid*)offsetof(VertexData,color));

			glBindBuffer(GL_ARRAY_BUFFER, 0);

			GLuint* indecies = new GLuint[INDEX_COUNT];
			
			GLuint offset = 0;
			for (int i = 0; i < INDEX_COUNT; i+=6)
			{
				indecies[i	  ] = offset;
				indecies[i + 1] = offset + 1;
				indecies[i + 2] = offset + 2;
				indecies[i + 3] = offset + 2;
				indecies[i + 4] = offset + 3;
				indecies[i + 5] = offset;
				offset += 4;
			}
			m_IBO = new IndexBuffer(indecies,INDEX_COUNT);
			m_Vao.unbind();

		}
		BatchRenderer::~BatchRenderer() {
			delete m_IBO;
			glDeleteBuffers(1, &m_VertexDataBuffer);
		}

		void BatchRenderer::submit(const Drawable2D* drawable) {

			const math::Vec3f& pos = drawable->getPosition();
			const math::Vec2f& size = drawable->getSize();
			const Color& color = drawable->getColor();

			m_BufferPointer->vertex = pos;
			m_BufferPointer->color = color;

			m_BufferPointer++;

			m_BufferPointer->vertex = math::Vec3f(pos.x,pos.y + size.y,0);
			m_BufferPointer->color = color;

			m_BufferPointer++;

			m_BufferPointer->vertex = math::Vec3f(pos.x + size.x, pos.y + size.y, 0);
			m_BufferPointer->color = color;

			m_BufferPointer++;

			m_BufferPointer->vertex = math::Vec3f(pos.x + size.x, pos.y, 0);
			m_BufferPointer->color = color;
			m_BufferPointer++;


			m_CurrentIndexCount += 6;
		}
		void BatchRenderer::render() {
			m_Vao.bind();
			m_IBO->bind();

			glDrawElements(GL_TRIANGLES, m_CurrentIndexCount, GL_UNSIGNED_INT, NULL);

			m_IBO->unbind();
			m_Vao.unbind();
			m_CurrentIndexCount = 0;
		}
		void BatchRenderer::begin() {
			glBindBuffer(GL_ARRAY_BUFFER, m_VertexDataBuffer);
			m_BufferPointer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

		}
		void BatchRenderer::end() {
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			render();
		}
	}
}