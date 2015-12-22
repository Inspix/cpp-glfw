#pragma once
#include <deque>
#include "renderer.h"

namespace inspix {
	namespace graphics {

		class SimpleRenderer2D : public Renderer2D
		{
		private:
			std::deque<const Drawable2D*> m_Drawables;
			ShaderProgram& m_Shader;
		public:
			SimpleRenderer2D(ShaderProgram& shader);
			virtual ~SimpleRenderer2D();

			void submit(const Drawable2D* drawable) override;
			void render() override;
		};

	}
}

