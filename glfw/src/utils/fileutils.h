#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace inspix {
	namespace utils {

		std::string readFile(const char* filepath) {
			std::string result;
			std::ifstream file;
			file.open(filepath);

			if (file.is_open())
			{
				std::string line;
				while (std::getline(file, line)) {
					result.append(line);
					result.append(1, '\n');
				}
				file.close();
			}
			else {
				std::cout << "File " << filepath << " not found" << std::endl;
			}

			return result;

		}

	}
}