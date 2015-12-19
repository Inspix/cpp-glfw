#pragma once

#include <GL/glew.h>

namespace inspix {
	namespace graphics {

		class Buffer
		{
		private:
			GLuint m_ID;
			GLuint m_ComponentCount;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint ccount);
			virtual ~Buffer();

			GLuint getComponentCount() const { return m_ComponentCount; }
			void bind() const;
			void unbind() const;
		};
	}
}



