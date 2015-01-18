#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

void parseNumbers(std::vector<int> &letters, std::string line){
	unsigned int symb_occurence = line.find(" ");
	while(symb_occurence < line.length()){
		letters.push_back(std::atoi(line.substr(0, symb_occurence + 1).c_str()));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(" ");
	}
	if(line != "")
		letters.push_back(std::atoi(line.c_str()));
}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		int split_position = line.find("|");
		std::string hash = line.substr(0, split_position);
		std::vector<int> numbers;
		parseNumbers(numbers, line.substr(split_position + 2));

		for(unsigned int index = 0; index < numbers.size(); index++){
			std::cout << hash.substr(numbers[index] - 1, 1);
		}
		std::cout << std::endl;

	}

	return 0;
}
