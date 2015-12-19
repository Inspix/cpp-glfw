#pragma once

#include "math/maths.h"
#include "graphics/shader.h"
#include "graphics/buffers/vertexarray.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexBuffer.h"

namespace inspix {
	namespace graphics {
		
		class Drawable2D {
		protected:
			static GLuint indicies[6];
			math::Vec4 m_Color;
			math::Mat4 m_Transform;

			ShaderProgram& m_Shader;
			
			VertexArray* m_Vao;
			IndexBuffer* m_Ibo;
		public:
			math::Vec3 Position;
			math::Vec2 Size;
			float Rotation;

			Drawable2D(const math::Vec3& position, const math::Vec2& size, const math::Vec4 color, ShaderProgram& shader);
			virtual ~Drawable2D();

			void recalculateTransform();
			inline const VertexArray* getVao() const { return m_Vao; }
			inline const IndexBuffer* getIbo() const { return m_Ibo; }
			inline const math::Vec4& getColor() const { return m_Color; }
			inline const math::Mat4& getTransform() const { return m_Transform; }
			inline ShaderProgram& getShader() const { return m_Shader; }
		};


	}
}