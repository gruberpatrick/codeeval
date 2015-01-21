#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>



unsigned long long int getReverseNumber(unsigned long long int number){

	std::string value = std::to_string(number);
	std::string reversed = "";
	for(int index = value.length() - 1; index >= 0; index--){

		reversed += value.substr(index, 1);

	}
	return std::atoi(reversed.c_str());

}



bool isPalindrome(unsigned int number){
	unsigned int reversed_number = getReverseNumber(number);
	if(reversed_number == number)
		return true;
	return false;
}



int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		unsigned long long int number = std::atoi(line.c_str());
		int count = 0;
		while(!isPalindrome(number)){
			number = number + getReverseNumber(number);
			count++;
		}

		std::cout << count << " " << number << std::endl;

	}

	return 0;
}
