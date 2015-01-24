#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

int decimalToBinary(int &decimal){

	int result = 0;
	while(decimal >= 0){

		if(decimal % 2 == 1)
			result++;
		decimal = floor(decimal / 2);

		if(decimal == 0)
			break;

	}
	return result;

}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		int decimal = std::atoi(line.c_str());
		std::cout << decimalToBinary(decimal) << std::endl;

	}

	return 0;

}
