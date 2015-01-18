#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

void parseLine(std::vector<int> &triangle, std::string &line){
	unsigned int position = line.find(" ");
	while(position < line.length()){
		//std::cout << std::atoi(line.substr(0, position).c_str()) << " ";
		triangle.push_back(std::atoi(line.substr(0, position).c_str()));
		line = line.substr(position + 1);
		position = line.find(" ");
	}
	if(line != "")
		triangle.push_back(std::atoi(line.c_str()));
}

int calculateSum(std::vector<int> &triangle, int lines){
	int space = triangle.size() - 1;
	for(int lines_index = lines; lines_index >= 0; lines_index--){
		for(int rows_index = 0; rows_index < lines_index; rows_index++){
			//std::cout << triangle[space] << " + " << triangle[space - (lines + 1)] << " = " << std::endl;
			//std::cout << triangle[space - 1] << " + " << triangle[(space - 1) - lines] << " = " << std::endl;

			int res = std::max(triangle[space] + triangle[space - (lines + 1)], triangle[space - 1] + triangle[(space - 1) - lines]);
			triangle[(space - 1) - lines] = res;
			//std::cout << res << std::endl;

			space--;
		}
		space--;
		lines--;
	}
	return triangle[0];
}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;
	std::vector<int> triangle;

	int lines = -1;
	while(getline(stream, line)){
		parseLine(triangle, line);
		lines++;
	}

	std::cout << calculateSum(triangle, lines) << std::endl;

	return 0;

}
