#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		std::map<int, int> letters;

		for(unsigned int index = 0; index < line.length(); index++){
			int ascii = static_cast<int>((char)line[index]);
			if(ascii >= 65 && ascii <= 90)
				ascii += 32;
			if(ascii >= 97 && ascii <= 122){
				if(letters.find(ascii) == letters.end())
					letters[ascii] = 1;
				else
					letters[ascii]++;
			}
		}

		int value = -26;
		for(unsigned int index_outer = 0; index_outer < letters.size(); index_outer++){
			int highest_value = 0;
			int highest_index = -1;
			for(unsigned int index_inner = 97; index_inner <= 122; index_inner++){
				if(letters[index_inner] > highest_value){
					highest_index = index_inner;
					highest_value = letters[index_inner];
				}
			}
			if(highest_index >= 0){
				//std::cout << (char)highest_index << ": " << letters[highest_index] << " - " ;
				letters[highest_index] *= value++;
				//std::cout << letters[highest_index] << std::endl;
			}
			//std::cout << "-----------------------------" << std::endl;
		}

		int sum = 0;
		for(unsigned int index = 97; index <= 122; index++){
			if(letters.find(index) != letters.end())
				sum += (letters[index] * -1);
		}
		std::cout << sum << std::endl;

	}

	return 0;

}
