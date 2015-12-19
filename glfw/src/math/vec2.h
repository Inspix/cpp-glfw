#pragma once

#include <iostream>
#include <sstream>
namespace inspix {
	namespace math {

		struct Vec2 {

			union {
				float values[2];
				struct {
					float x, y;
				};
			};


			Vec2();
			Vec2(const float& value);
			Vec2(const float& x, const float& y);

			Vec2& add(const Vec2& other);
			Vec2& sub(const Vec2& other);
			Vec2& mul(const Vec2& other);
			Vec2& mul(const float& other);
			Vec2& div(const Vec2& other);
			Vec2& div(const float& other);

			Vec2& operator+=(const Vec2& other);
			Vec2& operator-=(const Vec2& other);
			Vec2& operator*=(const Vec2& other);
			Vec2& operator/=(const Vec2& other);
			Vec2& operator*=(const float& scalar);
			Vec2& operator/=(const float& scalar);

			friend Vec2 operator+(Vec2 left, const Vec2& right);
			friend Vec2 operator-(Vec2 left, const Vec2& right);
			friend Vec2 operator*(Vec2 left, const Vec2& right);
			friend Vec2 operator/(Vec2 left, const Vec2& right);

			friend bool operator==(const Vec2& left, const Vec2& other);
			friend bool operator!=(const Vec2& left, const Vec2& other);

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec);


		};

	}
}