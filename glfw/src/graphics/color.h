#pragma once


#include "math/maths.h"

namespace inspix {
	namespace graphics {

		struct Color {		

			enum Type
			{
				RGBA,ABGR,ARGB,BGRA
			};

			union {
				struct {
					unsigned char r, g, b, a;
				};
				unsigned int abgr;
			};
			Color();
			Color(unsigned char gray);
			Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
			Color(unsigned int value,Type type = RGBA);
			Color(const math::uVec4c& color);
			Color(const math::Vec4f& color);

			void set(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
			void set(unsigned int value, Type type = RGBA);
			void set(math::Vec4f color);
			void set(math::uVec4c color);
			math::Vec4f toFloatVec() const { return math::Vec4f(1.0f / r, 1.0f / g, 1.0f / b, 1.0f / a); }

			inline unsigned int toRGBA() const { return ABGRToRGBA(this->abgr); }
			inline unsigned int toARGB() const { return ABGRToARGB(this->abgr); }
			inline unsigned int toBGRA() const { return ABGRToBGRA(this->abgr); }

			static void extractChangels(unsigned char& dr, unsigned char& dg, unsigned char& db, unsigned char& da, unsigned int value, Type type = RGBA);
			
			static math::uVec4c toUCharVec(const unsigned int color, Type type = RGBA);
			static math::Vec4f toFloatVec(const unsigned int color, Type type = RGBA);				
			static unsigned int RGBAToARGB(unsigned int value);
			static unsigned int RGBAToABGR(unsigned int value);
			static unsigned int RGBAToBGRA(unsigned int value);

			static unsigned int ABGRToRGBA(unsigned int value);
			static unsigned int ABGRToARGB(unsigned int value);
			static unsigned int ABGRToBGRA(unsigned int value);

			static unsigned int ARGBToRGBA(unsigned int value);
			static unsigned int ARGBToABGR(unsigned int value);
			static unsigned int ARGBToBGRA(unsigned int value);

			static unsigned int BGRAToRGBA(unsigned int value);
			static unsigned int BGRAToABGR(unsigned int value);
			static unsigned int BGRAToARGB(unsigned int value);


			std::string ToString();

			friend std::ostream& operator<<(std::ostream& stream, const Color& color);

		};

	}
}