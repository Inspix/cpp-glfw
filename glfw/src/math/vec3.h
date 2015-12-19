#pragma once

#include <iostream>
#include <sstream>
namespace inspix {
	namespace math {

		struct Vec3 {

			union {
				float values[3];
				struct {
					float x, y, z;
				};
				struct {
					float r, g, b;
				};
			};


			Vec3();
			Vec3(const float& value);
			Vec3(const float& x, const float& y, const float& z);

			Vec3& add(const Vec3& other);
			Vec3& sub(const Vec3& other);
			Vec3& mul(const Vec3& other);
			Vec3& mul(const float& other);
			Vec3& div(const Vec3& other);
			Vec3& div(const float& other);
			void set(const float& x, const float& y, const float& z);

			Vec3& operator+=(const Vec3& other);
			Vec3& operator-=(const Vec3& other);
			Vec3& operator*=(const Vec3& other);
			Vec3& operator/=(const Vec3& other);
			Vec3& operator*=(const float& scalar);
			Vec3& operator/=(const float& scalar);

			friend Vec3 operator+(Vec3 left, const Vec3& right);
			friend Vec3 operator-(Vec3 left, const Vec3& right);
			friend Vec3 operator*(Vec3 left, const Vec3& right);
			friend Vec3 operator/(Vec3 left, const Vec3& right);

			friend bool operator==(const Vec3& left, const Vec3& other);
			friend bool operator!=(const Vec3& left, const Vec3& other);

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vec3& vec);


		};

	}
}