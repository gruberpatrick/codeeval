#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

void parseNumbers(std::vector<float> &numbers, std::string &line){
	unsigned int symb_occurence = line.find(" ");
	while(symb_occurence < line.length()){
		numbers.push_back(std::atof(line.substr(0, symb_occurence + 1).c_str()));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(" ");
	}
	if(line != "")
		numbers.push_back(std::atof(line.c_str()));
}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		std::vector<float> numbers;
		parseNumbers(numbers, line);
		std::sort(numbers.begin(), numbers.end());

		for(unsigned int index = 0; index < numbers.size(); index++){
			if(index > 0)
				std::cout << " ";
			printf("%3.3f", numbers[index]);
		}

		std::cout << std::endl;

	}

	return 0;
}
