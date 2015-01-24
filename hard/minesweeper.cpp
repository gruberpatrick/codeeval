#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>



void parseNumbers(std::vector<int> &numbers, std::string line){

	unsigned int symb_occurence = line.find(",");
	while(symb_occurence < line.length()){
		numbers.push_back(std::atof(line.substr(0, symb_occurence + 1).c_str()));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(",");
	}

	if(line != "")
		numbers.push_back(std::atof(line.c_str()));
}



void parseField(int x_f, int y_f, std::vector< std::vector<std::string> > &field, std::string line){

	int c = 0;
	for(int y = 0; y < y_f; y++){
		field.push_back(std::vector<std::string>{ });
		for(int x = 0; x < x_f; x++){
			field[y].push_back(line.substr(c++, 1));
		}
	}

}



bool isAsterisk(int x_f, int y_f, std::vector< std::vector<std::string> > &field){

	if(field[y_f][x_f] == "*")
		return true;
	return false;

}



int getNeightborCount(int x_f, int y_f, std::vector< std::vector<std::string> > &field){

	int count = 0;

	if(x_f - 1 >= 0 && field[y_f][x_f - 1] == "*")
		count++;
	if(x_f + 1 < field[y_f].size() && field[y_f][x_f + 1] == "*")
		count++;
	if(y_f - 1 >= 0){
		if(field[y_f - 1][x_f] == "*")
			count++;
		if(x_f - 1 >= 0 && field[y_f - 1][x_f - 1] == "*")
			count++;
		if(x_f + 1 < field[y_f].size() && field[y_f - 1][x_f + 1] == "*")
			count++;
	}
	if(y_f + 1 < field.size()){
		if(field[y_f + 1][x_f] == "*")
			count++;
		if(x_f - 1 >= 0 && field[y_f + 1][x_f - 1] == "*")
			count++;
		if(x_f + 1 < field[y_f].size() && field[y_f + 1][x_f + 1] == "*")
			count++;
	}

	return count;

}



int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		std::vector<int> bound;
		std::vector< std::vector<std::string> > field;

		parseNumbers(bound, line.substr(0, line.find(";")));
		parseField(bound[1], bound[0], field, line.substr(line.find(";") + 1));

		for(int y = 0; y < bound[0]; y++){
			for(int x = 0; x < bound[1]; x++){
				if(!isAsterisk(x, y, field)){
					std::cout << getNeightborCount(x, y, field);
				}else{
					std::cout << "*";
				}
			}
		}

		std::cout << std::endl;

	}

	return 0;
}
