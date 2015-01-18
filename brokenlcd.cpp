/*

Calculating the Result with be binary & operator

1 = [2,3] 								-> 0110000 = 48
2 = [1,2,4,5,7]						-> 1101101 = 109
3 = [1,2,3,4,7]						-> 1111001 = 121
4 = [2,3,6,7]							-> 0110011 = 51
5 = [1,3,4,6,7]						-> 1011011 = 91
6 = [1,4,5,6,7]						-> 1001111 = 79
7 = [1,2,3]								-> 1110000 = 112
8 = [1,2,3,4,5,6,7]				-> 1111111 = 127
9 = [1,2,3,4,6,7]					-> 1111011 = 123
0 = [1,2,3,4,5,6]					-> 1111110 = 126

1011101 = 93
1110100 = 116

116 & 48 = 48 -> 1
93 & 48 = 16 -> 0

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>

void parseBinaryStrings(std::vector<std::string> &binary, std::string &line){
	unsigned int symb_occurence = line.find(" ");
	while(symb_occurence < line.length()){
		binary.push_back(line.substr(0, symb_occurence));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(" ");
	}
	if(line != "")
		binary.push_back(line);
}

int binaryToDecimal(std::string binary){
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

std::string checkLCD(std::vector<std::string> &binary, std::map<std::string, int> &reference, std::string &check){

	unsigned int lcd_index = 0;
	for(unsigned int index = 0; index < check.length(); index++){

		std::string binary_string = binary[lcd_index].substr(0, binary[lcd_index].length() - 1);
		std::string dot = binary[lcd_index].substr(binary[lcd_index].length() - 1);

		//std::cout << binary_string << ":" << dot << " - " << check.substr(index, 1) << std::endl;

		if(check.substr(index, 1) == "."){
			lcd_index--;
		}else if( (check.substr(index, 1) != "." && ((binaryToDecimal(binary_string) & reference[check.substr(index, 1)]) != reference[check.substr(index, 1)])) || (index + 1 < check.length() && check.substr(index + 1, 1) == "." && dot == "0") ){
			index--;
		}
		if(lcd_index + 1 < binary.size())
			lcd_index++;
		else
			return "0";

	}

	return "1";

}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	std::map<std::string, int> reference;
	reference["0"] = 126;
	reference["1"] = 48;
	reference["2"] = 109;
	reference["3"] = 121;
	reference["4"] = 51;
	reference["5"] = 91;
	reference["6"] = 79;
	reference["7"] = 112;
	reference["8"] = 127;
	reference["9"] = 123;

	while(getline(stream, line)){

		int position = line.find(";");

		std::string lcd = line.substr(0, position);
		std::string check = line.substr(position + 1);
		std::vector<std::string> binary;
		parseBinaryStrings(binary, lcd);

		std::cout << checkLCD(binary, reference, check) << std::endl;

	}

	return 0;

}
