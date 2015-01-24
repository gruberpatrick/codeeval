#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>

unsigned int parseLetters(std::vector<std::string> &letters, std::string line){

	unsigned int symb_occurence = line.find(" ");
	while(symb_occurence < line.length()){
		letters.push_back(line.substr(0, symb_occurence + 1));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(" ");
	}

	if(line != "" || line != " ")
		return std::atoi(line.c_str());

	letters.erase(letters.end());
	return std::atoi(letters[letters.size() - 1].c_str());

}

int main(int argc, char *argv[]){
	std::ifstream stream(argv[1]);
	std::string line;
	while(getline(stream, line)){

		std::vector<std::string> letters;
		unsigned int index = parseLetters(letters, line);

		if(index > 0 && index <= letters.size())
			std::cout << letters[letters.size() - index] << std::endl;

	}
	return 0;
}
