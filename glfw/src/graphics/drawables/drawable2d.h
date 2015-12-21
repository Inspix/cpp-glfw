#pragma once

#include "graphics/shader.h"
#include "graphics/buffers/vertexarray.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexBuffer.h"

namespace inspix {
	namespace graphics {
		
		struct VertexData {
			math::Vec3f vertex;
			math::Vec4f color;
		};

		class Drawable2D {
		protected:
			static GLuint indicies[6];
			math::Vec4f m_Color;
			math::Mat4 m_Transform;
						
			VertexArray* m_Vao;
			IndexBuffer* m_Ibo;
		public:
			math::Vec3f Position;
			math::Vec2f Size;
			float Rotation;

			Drawable2D(const math::Vec3f& position, const math::Vec2f& size, const math::Vec4f color);
			virtual ~Drawable2D();

			void recalculateTransform();
			inline const VertexArray* getVao() const { return m_Vao; }
			inline const IndexBuffer* getIbo() const { return m_Ibo; }
			inline const math::Vec4f& getColor() const { return m_Color; }
			inline const math::Mat4& getTransform() const { return m_Transform; }

		};


	}
}