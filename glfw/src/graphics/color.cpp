#include "color.h"

namespace inspix {
	namespace graphics {
		
		Color::Color() : Color(0xff000000) {}

		Color::Color(unsigned char gray) : Color(gray,gray,gray,255) {}

		Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) 
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		Color::Color(unsigned int value, Type type) 
		{
			switch (type) {
			case RGBA:
				this->abgr = RGBAToABGR(value);
				break;
			case ARGB :
				this->abgr = ARGBToABGR(value);
				break;
			case BGRA :
				this->abgr = BGRAToABGR(value);
				break;
			default:
				this->abgr = value;
			}
		}

		Color::Color(const math::uVec4c& color) : Color(color.x, color.y, color.z, color.w) {}

		Color::Color(const math::Vec4f& color) 
		{

			float cr = clamp(0, 1, color.r);
			float cg = clamp(0, 1, color.g);
			float cb = clamp(0, 1, color.b);
			float ca = clamp(0, 1, color.a);
			this->r = (unsigned char)(cr * 255.0f);
			this->g = (unsigned char)(cg * 255.0f);
			this->b = (unsigned char)(cb * 255.0f);
			this->a = (unsigned char)(ca * 255.0f);
		}

		void Color::extractChangels(unsigned char& dr, unsigned char& dg, unsigned char& db, unsigned char& da, unsigned int value, Type type) {
			switch (type) {
			case RGBA:
				dr = (value & 0xff000000U) >> 24;
				dg = (value & 0xff0000U) >> 16;
				db = (value & 0xff00U) >> 8;
				da = (value & 0xff0U);
				break;
			case BGRA:
				db = (value & 0xff000000U) >> 24;
				dg = (value & 0xff0000U) >> 16;
				dr = (value & 0xff00U) >> 8;
				da = (value & 0xff0U);
				break;
			case ABGR:
				da = (value & 0xff000000U) >> 24;
				db = (value & 0xff0000U) >> 16;
				dg = (value & 0xff00U) >> 8;
				dr = (value & 0xff0U);
				break;
			case ARGB:
				da = (value & 0xff000000U) >> 24;
				dr = (value & 0xff0000U) >> 16;
				dg = (value & 0xff00U) >> 8;
				db = (value & 0xff0U);
				break;
			default:
				std::cout << "Invalid Color::Type" << std::endl;
				break;
			}
		}

		math::Vec4f Color::toFloatVec(const unsigned int color, Type type) {
			unsigned char er, eg, eb, ea;
			extractChangels(er, eg, eb, ea,color,type);

			return math::Vec4f(er / 255.0f, eg / 255.0f, eb / 255.0f, ea / 255.0f);
		}

		math::uVec4c Color::toUCharVec(const unsigned int color, Type type) {
			unsigned char er, eg, eb, ea;
			extractChangels(er, eg, eb, ea, color, type);

			return math::uVec4c(er, eg , eb , ea);
		}

		unsigned int Color::RGBAToARGB(unsigned int value){
			
			return
				((value & 0xFF000000) >> 8) | // _R__
				((value & 0xFF0000) >> 8) | // _RG_
				((value & 0xFF00) >> 8) | // _RGB
				((value & 0xFF) << 24); // ARGB


		}
		unsigned int Color::RGBAToABGR(unsigned int value){
			return
				((value & 0xFF000000) >> 24) | // ___R
				((value & 0xFF0000) >> 8) | // __GR
				((value & 0xFF00) << 8) | // _BGR
				((value & 0xFF) << 24); // ABGR
		}
		unsigned int Color::RGBAToBGRA(unsigned int value){
			return
				((value & 0xFF000000) >> 16) | // __R_
				((value & 0xFF0000)) | // _GR_
				((value & 0xFF00) << 16) | // BGR_
				((value & 0xFF)); // BGRA
		}

		unsigned int Color::ABGRToRGBA(unsigned int value){
			return
				((value & 0xFF000000) >> 24) | // ___A
				((value & 0xFF0000) >> 8) | // __BA
				((value & 0xFF00) << 8) | // _GBA
				((value & 0xFF) << 24); // RGBA
		}
		unsigned int Color::ABGRToARGB(unsigned int value){
			return
				((value & 0xFF000000)) | // A___
				((value & 0xFF0000) >> 16) | // A__B
				((value & 0xFF00)) | // A_GB
				((value & 0xFF) << 16); // ARGB
		}
		unsigned int Color::ABGRToBGRA(unsigned int value){
			return
				((value & 0xFF000000) >> 24) | // ___A
				((value & 0xFF0000) << 8) | // B__A
				((value & 0xFF00) << 8) | // BG_A
				((value & 0xFF) << 8); // BGRA
		}

		unsigned int Color::ARGBToRGBA(unsigned int value){
			return
				((value & 0xFF000000) >> 24) | // ___A
				((value & 0xFF0000) << 8) | // R__A
				((value & 0xFF00) << 8) | // RG_A
				((value & 0xFF) << 8); // RGBA
		}
		unsigned int Color::ARGBToABGR(unsigned int value){
			return
				((value & 0xFF000000)) | // A___
				((value & 0xFF0000) >> 16) | // A__R
				((value & 0xFF00)) | // A_GR
				((value & 0xFF) << 16); // ABGR
		}
		unsigned int Color::ARGBToBGRA(unsigned int value){
			return
				((value & 0xFF000000) >> 24) | // ___A
				((value & 0xFF0000) >> 8) | // __RA
				((value & 0xFF00) << 8) | // _GRA
				((value & 0xFF) << 24); // BGRA
		}

		unsigned int Color::BGRAToRGBA(unsigned int value){
			return
				((value & 0xFF000000) >> 16) | // __B_
				((value & 0xFF0000)) | // _GB_
				((value & 0xFF00) << 16) | // RGB_
				((value & 0xFF)); // RGBA
		}
		unsigned int Color::BGRAToABGR(unsigned int value){// TODO:
			return
				((value & 0xFF000000) >> 8) | // _B__
				((value & 0xFF0000) >> 8) | // _BG_
				((value & 0xFF00) >> 8) | // _BGR
				((value & 0xFF) << 24); // ABGR
		}
		unsigned int Color::BGRAToARGB(unsigned int value){// TODO:
			return
				((value & 0xFF000000) >> 24) | // ___B
				((value & 0xFF0000) >> 8) | // __GB
				((value & 0xFF00) << 8) | // _RGB
				((value & 0xFF) << 24); // ARGB
		}


		std::string Color::ToString() {
			std::ostringstream ss;
			ss << *this;
			return ss.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Color& color) {
				stream << "Color[" << std::dec << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ", " << (int)color.a << "]" << std::endl;
				stream << "Hex(RGBA)[" << std::setfill('0') << std:: setw(8) << std::hex << ((color.r << 24) | (color.g  << 16) | (color.b << 8 ) | color.a) << "]";
				return stream;
		}
	}
}