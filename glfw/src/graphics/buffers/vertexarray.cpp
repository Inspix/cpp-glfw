#include "vertexarray.h"

namespace inspix {
	namespace graphics {
		VertexArray::VertexArray() {

			glGenVertexArrays(1, &m_ID);
		}

		VertexArray::~VertexArray(){}

		void VertexArray::addBuffer(const Buffer& buffer, GLuint location, GLboolean normalized) {
			bind();
			buffer.bind();
			glEnableVertexAttribArray(location);
			glVertexAttribPointer(location, buffer.getComponentCount(), buffer.getDataType(), normalized, 0, 0);
			buffer.unbind();
			unbind();			
		}

		void VertexArray::bind() const {
			glBindVertexArray(m_ID);
		}

		void VertexArray::unbind() const {
			glBindVertexArray(0);
		}
	}
}