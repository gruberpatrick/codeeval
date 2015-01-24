#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		for(unsigned int index = 0; index < line.length(); index++){
			int ascii = static_cast<int>((char)line[index]);
			if(ascii >= 65 && ascii <= 90)
				ascii += 32;
			std::cout << (char)ascii;
		}
		std::cout << std::endl;

	}

	return 0;

}
