#include "buffer.h"
#include <iostream>

namespace inspix {
	namespace graphics {
		Buffer::Buffer(GLuint* data, GLsizei count, GLuint ccount) :
			m_ComponentCount(ccount)
		{
			glGenBuffers(1, &m_ID);
			glBindBuffer(GL_ARRAY_BUFFER, m_ID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLuint) , data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			dataType = GL_UNSIGNED_BYTE;
		}

		Buffer::Buffer(GLfloat* data, GLsizei count, GLuint ccount) :
			m_ComponentCount(ccount)
		{
			glGenBuffers(1, &m_ID);
			glBindBuffer(GL_ARRAY_BUFFER, m_ID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);		
			dataType = GL_FLOAT;
		}


		Buffer::~Buffer()
		{
			glDeleteBuffers(1, &m_ID);
		}

		void Buffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		}

		void Buffer::unbind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}


