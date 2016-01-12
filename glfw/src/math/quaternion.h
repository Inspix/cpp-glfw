#pragma once

#include "types.h"

namespace inspix {
	namespace math {
		struct Mat4;
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


			/* CONSTRUCTORS */
			Quaternion();
			Quaternion(float val);
			Quaternion(float x, float y, float z, float w);
			Quaternion(const Vec3f& xyz, float scalar);
			Quaternion(const Vec4f& values);

			/* OPERATIONS */
			Quaternion& add(const Quaternion& other);
			Quaternion& sub(const Quaternion& other);
			Quaternion& div(const float& scalar);
			Quaternion& mul(const Quaternion& other);
			Quaternion& mul(const float& scalar);

			/* Static methods */
			static Quaternion rotation(float degrees, const Vec3f& unitVec);
			static Quaternion rotation(const Vec3f& unitVec1, const Vec3f& unitVec2);
			static Quaternion normalized(const Quaternion& q);
			static Vec3f rotateVec(const Quaternion& q,const Vec3f& vec);

			/* CONVERTIONS */
			float dot(const Quaternion& other) const;
			float lengthSquared() const;
			float length() const;

			Quaternion conjugate() const;
			Quaternion& normalize();
			Mat4 toMatrix4() const;

			/* OPERATORS */
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


			friend std::ostream& operator << (std::ostream& os, const Quaternion& q);
			
		};

		

	}
}