#include "quaternion.h"
#include "mat4.h"
namespace inspix {
	namespace math {

		/* CONSTRUCTORS */
		Quaternion::Quaternion()
			: x(0.f),
			y(0.f),
			z(0.f),
			w(1.f) 
		{}

		Quaternion::Quaternion(float val) {
			x = y = z = w = val;
		}

		Quaternion::Quaternion(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Quaternion::Quaternion(const Vec3f& xyz, float scalar) {
			this->xyz = xyz;
			this->scalar = scalar;
		}

		Quaternion::Quaternion(const Vec4f& values) {
			this->xyz = values.xyz();
			this->scalar = values.w;
		}

		/* OPERATIONS */
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
						
			float _x = w * other.x + x * other.w - y * other.z + z * other.y;
			float _y = w * other.y + x * other.z + y * other.w - z * other.x;
			float _z = w * other.z - x * other.y + y * other.x + z * other.w;
			float _w = w * other.w - x * other.x - y * other.y - z * other.z;

			x = _x;
			y = _y;
			z = _z;
			w = _w;

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

		/* Static methods */

		Quaternion Quaternion::rotation(float degrees, const Vec3f& unitVec) {
			float angle = toRadians(degrees) * 0.5f;
			return Quaternion(unitVec * sin(angle), cos(angle));
		}
		
		Vec3f Quaternion::rotateVec(const Quaternion& q, const Vec3f& vec)
		{
			
			float tmpX = q.w * vec.x + q.y * vec.z - q.z * vec.y;
			float tmpY = q.w * vec.y + q.z * vec.x - q.x * vec.z;
			float tmpZ = q.w * vec.z + q.x * vec.y - q.y * vec.x;
			float tmpW = q.x * vec.x + q.y * vec.y + q.z * vec.z;
			return Vec3f(
				tmpW * q.x + tmpX * q.w - tmpY * q.z + tmpZ * q.y,
				tmpW * q.y + tmpY * q.w - tmpZ * q.x + tmpX * q.z,
				tmpW * q.z + tmpZ * q.w - tmpX * q.y + tmpY * q.x
				);
		}

		Quaternion Quaternion::normalized(const Quaternion& q) {
			Quaternion result = q;
			result.normalize();

			return result;
		}

		/* CONVERTIONS */

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

		Mat4 Quaternion::toMatrix4() const {
			float xx = x * x;
			float xy = x * y;
			float xz = x * z;
			float xw = x * w;

			float yy = y * y;
			float yz = y * z;
			float yw = y * w;

			float zz = z * z;
			float zw = z * w;

			Mat4 res = Mat4::identity();

			res.get(0, 0) = 1 - 2 * (yy + zz);
			res.get(0, 1) = 2 * (xy - zw);
			res.get(0, 2) = 2 * (xz + yw);

			res.get(1, 0) = 2 * (xy + zw);
			res.get(1, 1) = 1 - 2 * (xx + zz);
			res.get(1, 2) = 2 * (yz - xw);

			res.get(2, 0) = 2 * (xz - yw);
			res.get(2, 1) = 2 * (yz + xw);
			res.get(2, 2) = 1 - 2 * (xx + yy);						
			
			return res;
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