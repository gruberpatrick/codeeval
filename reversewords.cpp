#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		int position = line.find_last_of(" ");

		while(position > 0){
			std::cout << line.substr(position + 1) << " ";
			line = line.substr(0, position);
			position = line.find_last_of(" ");
		}

		if(line.length() > 0)
			std::cout << line << std::endl;

	}

	return 0;

}
