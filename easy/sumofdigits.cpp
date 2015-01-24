#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		unsigned int sum = 0;
		for(unsigned int index = 0; index < line.length(); index++){
			sum += std::atoi(line.substr(index, 1).c_str());
		}

		std::cout << sum << std::endl;

	}

	return 0;
}
