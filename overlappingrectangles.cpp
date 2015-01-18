#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

void parseNumbers(std::vector<int> &numbers, std::string line){
	unsigned int symb_occurence = line.find(",");
	while(symb_occurence < line.length()){
		numbers.push_back(std::atoi(line.substr(0, symb_occurence + 1).c_str()));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(",");
	}
	if(line != "")
		numbers.push_back(std::atoi(line.c_str()));
}

bool checkOverlapping(std::vector<int> &numbers){

	std::vector<std::pair<int, int>> a = {std::pair<int, int>(numbers[0], numbers[1]), std::pair<int, int>(numbers[2], numbers[1]), std::pair<int, int>(numbers[0], numbers[3]), std::pair<int, int>(numbers[2], numbers[3])};
	std::vector<std::pair<int, int>> b = {std::pair<int, int>(numbers[4], numbers[5]), std::pair<int, int>(numbers[6], numbers[5]), std::pair<int, int>(numbers[4], numbers[7]), std::pair<int, int>(numbers[6], numbers[7])};

	for(unsigned int index = 0; index < b.size(); index++){
		if(b[index].second <= a[0].second && b[index].first <= a[3].first && b[index].second >= a[3].second && b[index].first >= a[0].first)
			return true;
		/*else if(b[index].second == a[0].second && (index == 0 || index == 1))
			return true;
		else if(b[index].first == a[3].first && (index == 1 || index == 3))
			return true;
		else if(b[index].second == a[3].second && (index == 3 || index == 2))
			return true;
		else if(b[index].first == a[0].first && (index == 2 || index == 0))
			return true;*/
	}

	for(unsigned int index = 0; index < a.size(); index++){
		if(a[index].second <= b[0].second && a[index].first <= b[3].first && a[index].second >= b[3].second && a[index].first >= b[0].first)
			return true;
		/*else if(a[index].second == b[0].second && (index == 0 || index == 1))
			return true;
		else if(a[index].first == b[3].first && (index == 1 || index == 3))
			return true;
		else if(a[index].second == b[3].second && (index == 2 || index == 3))
			return true;
		else if(a[index].first == b[0].first && (index == 0 || index == 2))
			return true;*/
	}

	return false;

}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		std::vector<int> numbers;

		parseNumbers(numbers, line);
		if(checkOverlapping(numbers))
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;

	}

	return 0;
}
