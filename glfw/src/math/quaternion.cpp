#include "quaternion.h"

namespace inspix {
	namespace math {

		Quaternion::Quaternion()
			: x(0.f),
			y(0.f),
			z(0.f),
			w(0.f) 
		{}

		Quaternion::Quaternion(const float& val) {
			x = y = z = w = val;
		}

		Quaternion::Quaternion(const Vec3f& xyz, const float& scalar) {
			this->xyz = xyz;
			this->scalar = scalar;
		}

		Quaternion::Quaternion(const Vec4f& values) {
			this->xyz = values.xyz();
			this->scalar = values.w;
		}

		Quaternion& Quaternion::add(const Quaternion& other) {
			xyz += other.xyz;
			w += other.w;

			return *this;
		}

		Quaternion& Quaternion::sub(const Quaternion& other) {
			xyz -= other.xyz;
			w -= other.w;

			return *this;
		}

		Quaternion& Quaternion::mul(const Quaternion& other) {
			Quaternion result;
			Vec3f xyz_ = w * other.xyz + other.w * xyz + cross(xyz, other.xyz);
			float w_ = w*other.w + xyz.dot(other.xyz);
			xyz = xyz_;
			w = w_;
			return *this;
		}

		Quaternion& Quaternion::mul(const float& scalar) {
			xyz *= scalar;
			w *= scalar;
			return *this;
		}

		Quaternion& Quaternion::div(const float& scalar) {
			xyz /= scalar;
			w /= scalar;
			return *this;
		}

		float Quaternion::dot(const Quaternion& other) const {
			return xyz.dot(other.xyz) + w * other.w;
		}

		float Quaternion::lengthSquared() const {
			return dot(*this);
		}

		float Quaternion::length() const {
			return sqrt(lengthSquared());
		}

		Quaternion Quaternion::conjugate() const {
			return Quaternion(-xyz, w);
		}

		Quaternion& Quaternion::normalize() {
			float l = length();
			xyz /= l;
			w /= l;
			return *this;
		}

		std::ostream& operator<<(std::ostream& os,const Quaternion& q) {
			os << "Quaternion[" << q.x << ", " <<
				q.y << ", " <<
				q.z << ", " <<
				q.w << "]";
			return os;
		}

	}
}