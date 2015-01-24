#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

void parseNumbers(std::vector<int> &numbers, std::string &line){

	unsigned int symb_occurence = line.find(",");
	while(symb_occurence < line.length()){

		int number = std::atof(line.substr(0, symb_occurence + 1).c_str());

		if(std::find(numbers.begin(), numbers.end(), number) == numbers.end())
			numbers.push_back(number);

		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(",");

	}

	if(line != ""){
		int number = std::atof(line.c_str());
		if(std::find(numbers.begin(), numbers.end(), number) == numbers.end())
			numbers.push_back(number);
	}

}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;
	while(getline(stream, line)){

		std::vector<int> numbers;
		parseNumbers(numbers, line);

		for(unsigned int index = 0; index < numbers.size(); index++){
			if(index > 0)
				std::cout << ",";
			std::cout << numbers[index];
		}

		std::cout << std::endl;

	}

	return 0;

}
