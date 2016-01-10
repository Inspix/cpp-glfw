#include "game.h"
#include "graphics/color.h"


int main(int argc,char** argv) {	
#if 0
	Color chars(50, 50, 50, 155);
	Color gray((ubyte)100);
	Color vec(math::uVec4c(125, 125, 125, 255));
	Color clampTest(math::Vec4f(1.5f, -0.5f, 0.1f, 1.0f));
	Color hex(0xffddeeffu);

	unsigned char r, g, b, a;
	Color::extractChangels(r, g, b, a, 0xffddeeaaU);

	Vec2f te;
	std::cout << te << std::endl;

	Vec3f test;
	std::cout << test << std::endl;

	Vec4f toFloatVector = Color::toFloatVec(0xffeeddff);
	uVec4c toCharVector = Color::toUCharVec(0xffeeddffU);
	std::cout << "To float vector" << toFloatVector << std::endl;
	std::cout << "To float vector" << toCharVector << std::endl;
	std::cout << "Extracted RGBA :" << std::dec << (int)r << "," << (int)g << "," << (int)b << "," << (int)a << std::endl;

	std::cout << "Clamp Test: 1.5f -0.5f 0.1f 1.0f:" << clampTest << std::endl;
	std::cout << "Chars : " << chars << std::endl;
	std::cout << "Gray : " << gray << std::endl;
	std::cout << "Vec : " << vec << std::endl;
	std::cout << "hex : " << hex << std::endl;

	unsigned int rgba = 0xffddeeccU;
	std::cout << "     RGBA:" << std::hex << rgba << std::endl;
	unsigned int abgr = Color::RGBAToABGR(rgba);
	std::cout << "RGBA:ABGR:" << std::hex << abgr << std::endl;
	unsigned int bgra = Color::RGBAToBGRA(rgba);
	std::cout << "RGBA:BGRA:" << std::hex << bgra << std::endl;
	unsigned int argb = Color::RGBAToARGB(rgba);
	std::cout << "RGBA:ARGB:" << std::hex << argb << std::endl << std::endl;
		
	std::cout << "     ABGR:" << std::hex << abgr << std::endl;
	argb = Color::ABGRToARGB(abgr);
	std::cout << "ABGR:ARGB:" << std::hex << argb << std::endl;
	bgra = Color::ABGRToBGRA(abgr);
	std::cout << "ABGR:BGRA:" << std::hex << bgra << std::endl;
	rgba = Color::ABGRToRGBA(abgr);
	std::cout << "ABGR:RGBA:" << std::hex << rgba << std::endl << std::endl;

	std::cout << "     ARGB:" << std::hex << argb << std::endl;
	rgba = Color::ARGBToRGBA(argb);
	std::cout << "ARGBToRGBA:" << std::hex << rgba << std::endl;
	abgr = Color::ARGBToABGR(argb);
	std::cout << "ARGBToABGR:" << std::hex << abgr << std::endl;
	bgra = Color::ARGBToBGRA(argb);
	std::cout << "ARGBToBGRA:" << std::hex << bgra << std::endl << std::endl;

	std::cout << "     BGRA:" << std::hex << bgra << std::endl;
	rgba = Color::BGRAToRGBA(bgra);
	std::cout << "BGRAToRGBA:" << std::hex << rgba << std::endl;
	argb = Color::BGRAToARGB(bgra);
	std::cout << "BGRAToARGB:" << std::hex << argb << std::endl;
	abgr = Color::BGRAToABGR(bgra);
	std::cout << "BGRAToABGR:" << std::hex << abgr << std::endl << std::endl;
#endif

	Game().run();
	_CrtDumpMemoryLeaks();
	return 0;
}