#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;
	std::string binary = "";

	while(getline(stream, line)){

		unsigned int decimal = std::atoi(line.c_str());

		while(decimal >= 0){
			std::ostringstream convert;
			convert << (decimal % 2);
			binary = convert.str() + binary;
			decimal = floor(decimal / 2);
			if(decimal == 0)
				break;
		}

		std::cout << binary << std::endl;
		binary = "";

	}

	return 0;

}
