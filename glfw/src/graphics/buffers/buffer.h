#pragma once

#include <GL/glew.h>

namespace inspix {
	namespace graphics {

		class Buffer
		{
		private:
			GLuint m_ID;
			GLuint m_ComponentCount;
			GLenum dataType;
		public:
			Buffer(GLuint* data, GLsizei count, GLuint ccount);
			Buffer(GLfloat* data, GLsizei count, GLuint ccount);
			virtual ~Buffer();

			const GLenum& getDataType() const { return dataType; }
			GLuint getComponentCount() const { return m_ComponentCount; }
			void bind() const;
			void unbind() const;
		};
	}
}



