#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

void parseNumbers(std::vector<int> &numbers, std::string &line){

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

		std::vector<int> numbers1;
		std::vector<int> numbers2;

		int position = line.find(" | ");
		std::string first = line.substr(0, position);
		std::string last = line.substr(position + 3);

		parseNumbers(numbers1, first);
		parseNumbers(numbers2, last);

		for(unsigned int index = 0; index < numbers1.size(); index++){
			if(index > 0)
				std::cout << " ";
			std::cout << (numbers1[index] * numbers2[index]);
		}
		std::cout << std::endl;

	}

	return 0;

}
