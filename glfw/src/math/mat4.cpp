#include "mat4.h"

namespace inspix {
	namespace math {

		Mat4::Mat4() {
			for (int i = 0; i < 16; i++)
			{
				elements[i] = 0.0f;
			}
		}

		Mat4::Mat4(float diagonalValue) :
			Mat4()
		{
			elements[0] = diagonalValue; // 1 column 1 row
			elements[5] = diagonalValue; // 2 column 2 row
			elements[10] = diagonalValue; // 3 column 3 row
			elements[15] = diagonalValue; // 4 column 4 row
		}

		Mat4 Mat4::identity() {
			return Mat4(1.0f);
		}

		Mat4& Mat4::mul(const Mat4& other) {


			float temp[16];
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int z = 0; z < 4; z++)
					{
						sum += elements[x + z * 4] * other.elements[z + y * 4];
					}
					temp[x + y * 4] = sum;
				}
			}

			memcpy(elements, temp, sizeof(temp));
			return *this;
		}


		Vec3f Mat4::mul(const Vec3f& other) {
			return Vec3f(
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z
				);
		}

		Vec3f operator*(Mat4 left, const Vec3f& right) {
			return left.mul(right);
		}

		Mat4& Mat4::operator*=(const Mat4& other) {
			return mul(other);
		}
		Mat4 operator*(Mat4 left, const Mat4& right) {
			return left.mul(right);
		}

		float Mat4::operator[](size_t index) const {
			return elements[index];
		}

		float& Mat4::operator[](size_t index) {
			return elements[index];
		}

		float Mat4::get(size_t row, size_t col) const {
			return elements[4 * row + col];
		}
		float& Mat4::get(size_t row, size_t col) {
			return elements[4 * row + col];
		}

		// TODO: Test
		Mat4 Mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
			Mat4 result = identity();

			result.elements[0] = 2 / (right - left);
			result.elements[5] = 2 / (top - bottom);
			result.elements[10] = -2 / (far - near);
			result.elements[12] = -(right + left) / (right - left);
			result.elements[13] = -(top + bottom) / (top - bottom);
			result.elements[14] = -(far + near) / (far - near);

			return result;
		}

		Mat4 Mat4::perspective(float fov, float ratio, float near, float far) {
			Mat4 result;

			float range = near - far;
			float halfFovTan = tanf(toRadians(fov / 2.0f));


			result.elements[0] = 1.0f / (halfFovTan * ratio);
			result.elements[5] = 1.0f / halfFovTan;
			result.elements[10] = (-near - far) / range;
			result.elements[11] = 1.0f;
			result.elements[14] = 2.0f * near * far / range;
			return result;
		}

		Mat4 Mat4::translation(float x, float y, float z) {
			Mat4 result = identity();
			result.elements[12] = x;
			result.elements[13] = y;
			result.elements[14] = z;
			return result;

		}

		Mat4 Mat4::translation(const Vec3f& vector) {
			return translation(vector.x, vector.y, vector.z);
		}		

		Mat4 Mat4::rotation(float angle, float x, float y, float z) {
			Mat4 result;

			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);

			result.elements[0] = x * (1 - c) + c;
			result.elements[1] = x * y * (1.0f - c) + z * s;
			result.elements[2] = x * z * (1.0f - c) - y * s;

			result.elements[4] = x * y * (1.0f - c) - z * s;
			result.elements[5] = y * (1.0f - c) + c;
			result.elements[6] = y * z * (1.0f - c) + x * s;

			result.elements[8] = x * z * (1.0f - c) + y * s;
			result.elements[9] = y * z * (1.0f - c) - x * s;
			result.elements[10] = z * (1.0f - c) + c;
			result.elements[15] = 1.0f;

			return result;
		}
		/*
		Mat4 Mat4::rotation(const Quaternion& q, const Vec3f& point) {
			Mat4 res = identity();
			float sqw = q.w*q.w;
			float sqx = q.x*q.x;
			float sqy = q.y*q.y;
			float sqz = q.z*q.z;
			res.m00 = sqx - sqy - sqz + sqw;
			res.m11 = -sqx + sqy - sqz + sqw;
			res.m22 = -sqx - sqy + sqz + sqw;

			float tmp1 = q.x*q.y;
			float tmp2 = q.z*q.w;
			res.m01 = 2.0 * (tmp1 + tmp2);
			res.m10 = 2.0 * (tmp1 - tmp2);

			tmp1 = q.x*q.z;
			tmp2 = q.y*q.w;
			res.m02 = 2.0 * (tmp1 - tmp2);
			res.m20 = 2.0 * (tmp1 + tmp2);

			tmp1 = q.y*q.z;
			tmp2 = q.x*q.w;
			res.m12 = 2.0 * (tmp1 + tmp2);
			res.m21 = 2.0 * (tmp1 - tmp2);

		
			float a1 = point.x;
			float a2 = point.y;
			float a3 = point.z;
			res.m03 = a1 - a1 * res.m00 - a2 * res.m01 - a3 * res.m02;
			res.m13 = a2 - a1 * res.m10 - a2 * res.m11 - a3 * res.m12;
			res.m23 = a3 - a1 * res.m20 - a2 * res.m21 - a3 * res.m22;
			res.m30 = 0.f;
			res.m31 = 0.f;
			res.m32 = 0.f;
			res.m33 = 1.0;
			return res;
		}
		*/
		Mat4 Mat4::rotation(float angle, const Vec3f& axis) {
			return rotation(angle, axis.x, axis.y, axis.z);
		}

		Mat4 Mat4::rotation(const Vec4f& values) {
			return rotation(values.x, values.y, values.z, values.w);
		}

		Mat4 Mat4::scale(float x, float y, float z) {
			Mat4 result = identity();
			result.elements[0] = x;
			result.elements[5] = y;
			result.elements[10] = z;
			return result;
		}

		Mat4 Mat4::scale(float x, const Vec2f& yz) {
			return scale(x, yz.x, yz.y);
		}
		Mat4 Mat4::scale(const Vec2f& xy, float z) {
			return scale(xy.x, xy.y,z);
		}

		Mat4 Mat4::scale(const Vec3f& values) {			
			return scale(values.x,values.y,values.z);
		}

		std::string Mat4::ToString() const{
			std::ostringstream ss;
			ss << "Mat4 represetnation" << std::endl;
			for (int i = -1; i < 4; i++)
			{

				for (int j = -1; j < 4; j++)
				{
					if (i < 0)
					{
						if (j < 0)
						{
							ss << "  | ";
						}
						else {
							ss << "  " << std::left << std::setw(9) << j + 1;
						}
						continue;
					}


					if (j < 0)
					{						
						ss  << i + 1 << " | ";
					}
					else {
						int element = i + j * 4;
						ss << std::setw(2) << element << ": " << std::left << std::setw(7)  << elements[element];
					}
				}
				if (i == -1)
				{
					ss << std::endl;
					ss << std::setw(32) << std::setfill('-') << "-";
					ss << std::setfill(' ');
				}
				ss << std::endl;
			}
			return ss.str();
		}

		std::ostream& operator << (std::ostream& os, const Mat4& mat){
			os << mat.ToString();
			return os;
		}

	}
}