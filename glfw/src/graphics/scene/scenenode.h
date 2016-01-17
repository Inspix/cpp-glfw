#pragma once

#include "graphics/transform.h"
#include <vector>
#include <memory>

namespace inspix {
	namespace graphics {

		class SceneNode {
		public:
			SceneNode();
			~SceneNode();
			void update(float delta);
			void render(const Transform& t = Transform::Identity);

			SceneNode& addChild(std::unique_ptr<SceneNode> node);
			std::unique_ptr<SceneNode> detachChild(const SceneNode& node);
			inline SceneNode* getParent() const {
				return m_parent;
			} 
			Transform& getGlobal();
			inline Transform& getLocal() {
				return m_local;
			}
		protected:
			SceneNode* m_parent;
			std::vector<std::unique_ptr<SceneNode>> m_children;
			Transform m_local;
			virtual void renderCurrent(const Transform& t){}
			void renderChildren(const Transform& t);

			virtual void updateCurrent(float delta){}
			void updateChildren(float delta);
		};

	}
}