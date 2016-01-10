#pragma once

#include "types.h"

namespace inspix {
	namespace math {

		struct Quaternion {
			union {
				float data[4];
				struct {
					float x;
					float y;
					float z;
					float w;
				};
				struct {
					Vec3f xyz;
					float scalar;
				};
			};

			Quaternion();
			Quaternion(const float& val);
			Quaternion(const Vec3f& xyz, const float& scalar);
			Quaternion(const Vec4f& values);

			Quaternion& add(const Quaternion& other);
			Quaternion& sub(const Quaternion& other);
			Quaternion& div(const float& scalar);
			Quaternion& mul(const Quaternion& other);
			Quaternion& mul(const float& scalar);
			friend Quaternion operator-(Quaternion lhs, const Quaternion& rhs) {
				return lhs.sub(rhs);
			}

			friend Quaternion operator+(Quaternion lhs, const Quaternion& rhs) {
				return lhs.add(rhs);
			}

			friend Quaternion operator/(Quaternion lhs, const float& scalar) {
				return lhs.div(scalar);
			}

			friend Quaternion operator*(Quaternion lhs, const Quaternion& rhs) {
				return lhs.mul(rhs);
			}

			float dot(const Quaternion& other) const;
			float lengthSquared() const;
			float length() const;
			
			Quaternion conjugate() const;
			Quaternion& normalize();

			friend std::ostream& operator << (std::ostream& os, const Quaternion& q);
			
		};


	}
}