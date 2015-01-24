#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

void parseLetters(std::vector<int> &letters, std::string &line){
	unsigned int symb_occurence = line.find(" ");
	while(symb_occurence < line.length()){
		letters.push_back(std::atoi(line.substr(0, symb_occurence + 1).c_str()));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(" ");
	}
	letters.push_back(std::atoi(line.c_str()));
}

std::string getWord(std::vector<int> &letters, int start_index){
	std::string result = "";
	for(int index = start_index; letters[index] != 32 && index >= 0; index--){
		result = (char)letters[index] + result;
	}
	return result;
}

bool foundWord(std::vector<int> &letters, unsigned int word_length, std::string &last_letter){
	// find spaces
	std::vector<int> spaces;
	for(unsigned int index = 0; index < letters.size(); index++){
		if(letters[index] == 32)
			spaces.push_back(index);
	}
	// find last_letter before space (2 occurences) and parse Words
	std::vector<std::string> words;
	for(unsigned int index = 0; index < spaces.size(); index++){
		if(letters[spaces[index] - 1] == static_cast<int>(last_letter[0]))
			words.push_back(getWord(letters, spaces[index] - 1));
	}
	if(words.size() < 2)
		return false;
	// check word length
	for(std::vector<std::string>::iterator it = words.begin(); it != words.end();){
		if((*it).length() != word_length)
			it = words.erase(it);
		else
			it++;
	}
	if(words.size() < 2)
		return false;

	for(unsigned int outer_index = 0; outer_index < words.size(); outer_index++){
		for(unsigned int inner_index = outer_index + 1; inner_index < words.size(); inner_index++){
			if(words[outer_index] == words[inner_index])
				return true;
		}
	}

	return false;
}

void printResult(std::vector<int> &letters){
	for(unsigned int index = 0; index < letters.size(); index++){
		std::cout << (char)letters[index];
	}
	std::cout << std::endl;
}

void encryptMessage(std::vector<int> &letters, int word_length, std::string &last_letter){
	for(int shift = 0; shift <= 127; shift++){
		for(unsigned int index = 0; index < letters.size(); index++){
			if((letters[index] + 1) <= 127)
				letters[index] += 1;
			else
				letters.at(index) = letters[index] - 127;
		}
		if(foundWord(letters, word_length, last_letter)){
			printResult(letters);
			return;
		}
	}
}

int main(int argc, char *argv[]){
	std::ifstream stream(argv[1]);
	std::string line;
	while(getline(stream, line)){
		// parse first values
		int symb_occurence = line.find("|");
		unsigned int word_length = std::atoi(line.substr(0, symb_occurence).c_str());
		line = line.substr(symb_occurence + 2);
		symb_occurence = line.find("|");
		std::string last_letter = line.substr(0, symb_occurence - 1);
		line = line.substr(symb_occurence + 2);
		// parse text
		std::vector<int> letters;
		parseLetters(letters, line);
		encryptMessage(letters, word_length, last_letter);
		return 0;
	}
	return 0;
}
