#include "vertexarray.h"

namespace inspix {
	namespace graphics {
		VertexArray::VertexArray() {

			glGenVertexArrays(1, &m_ID);
		}

		VertexArray::~VertexArray(){
			glDeleteVertexArrays(1, &m_ID);
			for (size_t i = 0; i < buffers.size(); i++)
			{
				delete buffers[i];
			}
		}

		void VertexArray::addBuffer(const Buffer* buffer, GLuint location, GLboolean normalized, GLsizei stride, const void* pointer) {
			buffers.push_back(buffer);
			bind();
			buffer->bind();
			addPointer(location, buffer->getComponentCount(), buffer->getDataType(), normalized, stride, pointer);
			buffer->unbind();
			unbind();			
		}

		void VertexArray::addPointer(GLuint location,GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) {
			bind();
			glEnableVertexAttribArray(location);
			glVertexAttribPointer(location, size, type, normalized, stride, pointer);
			unbind();
			pointers++;
		}

		void VertexArray::bind(){
			if (bound) return;
		
			glBindVertexArray(m_ID);
			bound = true;
		}

		void VertexArray::unbind() {
			if (!bound) return;
		
			glBindVertexArray(0);
			bound = false;
		}
	}
}