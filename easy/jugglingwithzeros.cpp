#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>

void parseDigits(std::vector<std::string> &letters, std::string &line){
	unsigned int symb_occurence = line.find(" ");
	while(symb_occurence < line.length()){
		letters.push_back(line.substr(0, symb_occurence));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(" ");
	}
	if(line != "")
		letters.push_back(line.c_str());
}

unsigned long long int binaryToDecimal(std::string binary){
	unsigned long long int decimal = 0;
	unsigned int count = 0;
	for(int index = binary.length() - 1; index >= 0; index--){
		if(binary[index] == '1'){
			decimal += std::pow(2, count);
		}
		count++;
	}
	return decimal;
}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		std::vector<std::string> digits;
		parseDigits(digits, line);
		std::string binary = "";
		for(unsigned int index = 0; index < digits.size(); index += 2){
			std::string digit = "1";
			if(digits[index].length() == 1)
				digit = "0";
			for(unsigned int replace_index = 0; replace_index < digits[index + 1].length(); replace_index++){
				binary += digit;
			}
		}

		std::cout << binaryToDecimal(binary) << std::endl;

	}

	return 0;

}
