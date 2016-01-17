#pragma once

#include "math/types.h"
#include "math/quaternion.h"

namespace inspix {
	namespace graphics {
		struct Transform {
			math::Vec3f position;
			math::Quaternion orientation;
			math::Vec3f scale = math::Vec3f{ 1,1,1 };
			static Transform Identity;
			
		};
		// TODO: FIX ME
	/*	
		Transform operator * (const Transform& parent, const Transform& local) {
			Transform world;

			world.position = parent.position + (parent.orientation * (parent.scale * local.position));
			world.orientation = parent.orientation * local.orientation;
			world.scale = parent.scale * (parent.orientation.xyz * local.scale);

			return world;
		}

		// TODO: FIX ME
		Transform operator/(const Transform& world, const Transform& parent)
		{
			Transform ls;

			const math::Quaternion psConjugate = parent.orientation.conjugate();

			ls.position = psConjugate * (world.position - parent.position) / parent.scale;
			ls.orientation = psConjugate * world.orientation;
			ls.scale = psConjugate * (world.scale / parent.scale);

			return ls;
		}*/
	}
}