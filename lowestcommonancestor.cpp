#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>


struct element_t{
	struct element_t *child1;
	struct element_t *child2;
	int value;
};

void parseNumbers(std::vector<int> &numbers, std::string &line){
	unsigned int symb_occurence = line.find(" ");
	while(symb_occurence < line.length()){
		numbers.push_back(std::atoi(line.substr(0, symb_occurence + 1).c_str()));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(" ");
	}
	if(line != "")
		numbers.push_back(std::atoi(line.c_str()));
}

int searchCommon(int number1, int number2, element_t *tree, int lowest, int &level){

	if(tree->value == number1 || tree->value == number2)
		return lowest;

	std::cout << " -> " << tree->value << std::endl;
	if(tree->value < lowest)
		lowest = tree->value;

	if(tree->child1 == NULL || tree->child2 == NULL)
		return 0;

	int result1 = searchCommon(number1, number2, tree->child1, lowest, ++level);
	int level1 = level;
	int result2 = searchCommon(number1, number2, tree->child2, lowest, level);
	int level2 = level;

	if(level1 < level2)
		return result1;

	return result2;

}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	element_t *ten = {};
	ten->value = 10;
	ten->child1 = NULL;
	ten->child2 = NULL;
	element_t *twentynine = {};
	twentynine->value = 29;
	twentynine->child1 = NULL;
	twentynine->child2 = NULL;
	element_t *twenty = {};
	twenty->value = 20;
	twenty->child1 = ten;
	twenty->child2 = twentynine;
	element_t *three = {};
	three->value = 3;
	three->child1 = NULL;
	three->child2 = NULL;
	element_t *eight = {};
	eight->value = 8;
	eight->child1 = three;
	eight->child2 = twenty;
	element_t *fiftytwo = {};
	fiftytwo->value = 52;
	fiftytwo->child1 = NULL;
	fiftytwo->child2 = NULL;
	element_t *thirty = {};
	thirty->value = 30;
	thirty->child1 = eight;
	thirty->child2 = fiftytwo;

	while(getline(stream, line)){

		std::vector<int> numbers;
		parseNumbers(numbers, line);
		int level = 1;
		std::cout << searchCommon(numbers[0], numbers[1], thirty, thirty->value, level) << std::endl;

	}
	return 0;

}
