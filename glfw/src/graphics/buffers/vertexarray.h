#pragma once

#include <GL/glew.h>
#include "buffer.h"

namespace inspix {
	namespace graphics {
		class VertexArray {
		private:
			GLuint m_ID;
		public:
			VertexArray();
			virtual ~VertexArray();

			void addBuffer(const Buffer& buffer, GLuint location);
			
			void bind() const;
			void unbind() const;

		};
	}
}