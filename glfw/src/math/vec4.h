#pragma once

#include <iostream>
#include <sstream>
namespace inspix {
	namespace math {

		struct Vec4 {

			/*union { float x; float r; };
			union { float y; float g; };
			union { float z; float b; };
			union { float w; float a; };*/

			union {
				float values[4];
				struct {
					float x, y, z, w;
				};
				struct {
					float r, g, b, a;
				};
			};


			Vec4() = default;
			Vec4(const float& value);
			Vec4(const float& x, const float& y,const float& z, const float& w);

			Vec4& add(const Vec4& other);
			Vec4& sub(const Vec4& other);
			Vec4& mul(const Vec4& other);
			Vec4& mul(const float& other);
			Vec4& div(const Vec4& other);
			Vec4& div(const float& other);

			Vec4& operator+=(const Vec4& other);
			Vec4& operator-=(const Vec4& other);
			Vec4& operator*=(const Vec4& other);
			Vec4& operator/=(const Vec4& other);
			Vec4& operator*=(const float& scalar);
			Vec4& operator/=(const float& scalar);

			friend Vec4 operator+(Vec4 left, const Vec4& right);
			friend Vec4 operator-(Vec4 left, const Vec4& right);
			friend Vec4 operator*(Vec4 left, const Vec4& right);
			friend Vec4 operator/(Vec4 left, const Vec4& right);

			friend bool operator==(const Vec4& left, const Vec4& other);
			friend bool operator!=(const Vec4& left, const Vec4& other);

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vec4& vec);


		};

	}
}