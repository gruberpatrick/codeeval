#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void checkVector(std::vector<std::string>& longest_words, std::string &word, unsigned int specification){
	if(longest_words.size() == 0){
		longest_words.push_back(word);
	}else{
		for(unsigned int index = 0; index < longest_words.size(); index++){
			if(longest_words[index].length() < word.length()){
				longest_words.insert(longest_words.begin() + index, word);
				return;
			}
		}
		longest_words.push_back(word);
	}
}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	unsigned int specification = 0;
	getline(stream, line);
	specification = static_cast<int>(line[0]) - 48;

	std::vector<std::string> longest_words;

	while(getline(stream, line)){
		checkVector(longest_words, line, specification);
	}

	for(unsigned int index = 0; index < specification; index++){
		std::cout << longest_words[index] << std::endl;
	}

	return 0;

}
