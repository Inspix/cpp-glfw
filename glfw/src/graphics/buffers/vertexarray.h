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
		public:
			VertexArray();
			virtual ~VertexArray();

			void addBuffer(const Buffer* buffer, GLuint location, GLboolean normalized = GL_FALSE);
			
			void bind() const;
			void unbind() const;

		};
	}
}