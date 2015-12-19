#pragma once

#include <GL/glew.h>

namespace inspix {
	namespace graphics {
		class IndexBuffer {
		private:
			GLuint m_ID;
			GLuint m_Count;
		public:
			IndexBuffer(GLuint* data, GLuint count);
			virtual ~IndexBuffer();

			GLuint getCount() const { return m_Count; }
			void bind() const;
			void unbind() const;
		};
	}
}