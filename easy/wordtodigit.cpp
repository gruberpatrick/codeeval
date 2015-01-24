#include <iostream>
#include <fstream>
#include <map>

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	std::map<std::string, char> hash_map;
	hash_map["zero"] = '0';
	hash_map["one"] = '1';
	hash_map["two"] = '2';
	hash_map["three"] = '3';
	hash_map["four"] = '4';
	hash_map["five"] = '5';
	hash_map["six"] = '6';
	hash_map["seven"] = '7';
	hash_map["eight"] = '8';
	hash_map["nine"] = '9';

	while(getline(stream, line)){
		std::size_t start_semicolon = 0;
		std::size_t end_semicolon = line.find(";", start_semicolon);
		while((end_semicolon = line.find(";", start_semicolon)) < line.length()){
			//std::cout << line.substr(start_semicolon, end_semicolon - start_semicolon) << " - ";
			std::cout << hash_map[line.substr(start_semicolon, end_semicolon - start_semicolon)];
			start_semicolon = end_semicolon + 1;
			end_semicolon = line.find(";", start_semicolon);
		}
		std::cout << hash_map[line.substr(start_semicolon)] << std::endl;
	}

	return 0;
}
