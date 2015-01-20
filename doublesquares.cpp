#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

int getCombinations(unsigned int number){

	int solutions = 0;
	for(unsigned int i = 0; i <= round(std::sqrt(number)); i++){
		unsigned int res = std::sqrt(number - (i*i));
		if((res*res) + (i*i) == number && res > i){
			solutions++;
		}
	}

	return solutions;

}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	getline(stream, line);
	int counter = std::atoi(line.c_str());

	while(getline(stream, line) && counter >= 0){

		unsigned int number = std::atoi(line.c_str());
		std::cout << getCombinations(number) << std::endl;
		counter--;

	}

	return 0;

}
