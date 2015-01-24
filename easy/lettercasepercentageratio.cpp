#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		float uppercase_count = 0.00;
		float lowercase_count = 0.00;

		for(unsigned int index = 0; index < line.length(); index++){
			int ascii = static_cast<int>(line[index]);
			if(ascii >= 65 && ascii <= 90){
				uppercase_count++;
			}else if(ascii >= 97 && ascii <= 122){
				lowercase_count++;
			}
		}

		float lowercase_ratio = ((lowercase_count / (uppercase_count + lowercase_count)) * 10000.00) / 100.00;
		float uppercase_ratio = ((uppercase_count / (uppercase_count + lowercase_count)) * 10000.00) / 100.00;

		printf("lowercase: %3.2f uppercase: %3.2f\n", lowercase_ratio, uppercase_ratio);

	}

	return 0;

}
