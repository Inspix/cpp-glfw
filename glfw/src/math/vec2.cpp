#include "math/vec2.h"

namespace inspix {
	namespace math {

		Vec2::Vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		Vec2::Vec2(const float& value) {
			x = value;
			y = value;
		}

		Vec2::Vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		Vec2& Vec2::add(const Vec2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
		Vec2& Vec2::sub(const Vec2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		Vec2& Vec2::mul(const Vec2& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}
		Vec2& Vec2::div(const Vec2& other) {
			x /= other.x;
			y /= other.y;
			return *this;
		}
		Vec2& Vec2::mul(const float& scalar) {
			x *= scalar;
			y *= scalar;
			return *this;
		}
		Vec2& Vec2::div(const float& scalar) {
			x /= scalar;
			y /= scalar;
			return *this;
		}		

		Vec2& Vec2::operator+=(const Vec2 & other)
		{
			return add(other);
		}

		Vec2& Vec2::operator-=(const Vec2& other) {
			return sub(other);
		}

		Vec2& Vec2::operator*=(const Vec2& other) {
			return mul(other);
		}

		Vec2& Vec2::operator/=(const Vec2& other) {
			return div(other);
		}

		Vec2& Vec2::operator*=(const float& scalar) {
			return mul(scalar);
		}

		Vec2& Vec2::operator/=(const float& scalar) {
			return div(scalar);
		}

		Vec2 operator+(Vec2 left, const Vec2& right) {
			return left.add(right);
		}

		Vec2 operator-(Vec2 left, const Vec2& right) {
			return left.sub(right);
		}

		Vec2 operator*(Vec2 left, const Vec2& right) {
			return left.mul(right);
		}

		Vec2 operator/(Vec2 left, const Vec2& right) {
			return left.div(right);
		}

		bool operator==(const Vec2& left, const Vec2& other) {
			return left.x == other.x && left.y == other.y;
		}

		bool operator!=(const Vec2& left, const Vec2& other) {
			return !(left == other);
		}

		std::string Vec2::ToString() const
		{
			std::ostringstream ss;
			ss << *this;
			return ss.str();			
		}

		std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
			stream << "Vec2[" << vec.x << ", " << vec.y << "]";
			return stream;
		}
	}
}