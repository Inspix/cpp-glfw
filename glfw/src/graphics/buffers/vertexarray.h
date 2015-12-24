#pragma once

#include <GL/glew.h>
#include "buffer.h"
#include <vector>

namespace inspix {
	namespace graphics {
		class VertexArray {
		private:
			GLuint m_ID;
			std::vector<const Buffer*> buffers;
			int pointers;
			bool bound;
		public:
			VertexArray();
			virtual ~VertexArray();

			void addBuffer(const Buffer* buffer, GLuint location, GLboolean normalized = GL_FALSE,GLsizei stride = 0, const void* pointer = (const void*)0);
			void addPointer(GLuint location, GLint size, GLenum type, GLboolean normalized = GL_FALSE, GLsizei stride = 0, const void* pointer = (const void*)0);
			void bind();
			void unbind();

		};
	}
}