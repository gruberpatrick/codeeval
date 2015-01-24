#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>



struct element_t{
	element_t *child1;
	element_t *child2;
	element_t *anchestor;
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



void searchPath(int number, element_t *tree, std::vector<int> &path){

	if(tree->value == number){
		while(tree->anchestor != 0){
			path.push_back(tree->value);
			tree = tree->anchestor;
		}
		path.push_back(tree->value);
		return;
	}

	if(tree->child1 != 0)
		searchPath(number, tree->child1, path);
	if(tree->child2 != 0)
		searchPath(number, tree->child2, path);

}



int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	// DEFINE TREE
	element_t *ten = new element_t;
	element_t *twentynine = new element_t;
	element_t *twenty = new element_t;
	element_t *three = new element_t;
	element_t *eight = new element_t;
	element_t *fiftytwo = new element_t;
	element_t *thirty = new element_t;
	ten->value = 10;
	ten->child1 = NULL;
	ten->child2 = NULL;
	ten->anchestor = twenty;
	twentynine->value = 29;
	twentynine->child1 = NULL;
	twentynine->child2 = NULL;
	twentynine->anchestor = twenty;
	twenty->value = 20;
	twenty->child1 = ten;
	twenty->child2 = twentynine;
	twenty->anchestor = eight;
	three->value = 3;
	three->child1 = NULL;
	three->child2 = NULL;
	three->anchestor = eight;
	eight->value = 8;
	eight->child1 = three;
	eight->child2 = twenty;
	eight->anchestor = thirty;
	fiftytwo->value = 52;
	fiftytwo->child1 = NULL;
	fiftytwo->child2 = NULL;
	fiftytwo->anchestor = thirty;
	thirty->value = 30;
	thirty->child1 = eight;
	thirty->child2 = fiftytwo;
	thirty->anchestor = NULL;

	while(getline(stream, line)){

		std::vector<int> numbers;
		parseNumbers(numbers, line);

		std::vector<int> path1;
		searchPath(numbers[1], thirty, path1);
		std::vector<int> path2;
		searchPath(numbers[0], thirty, path2);

		int value = 0;
		int index1 = path1.size() - 1;
		int index2 = path2.size() - 1;
		while(index1 >= 0 && index2 >= 0 && path1[index1] == path2[index2]){
			value = path1[index1];
			index1--;
			index2--;
		}

		std::cout << value << std::endl;

	}

	// FREE MEMORY OF TREE
	free(thirty);
	free(fiftytwo);
	free(eight);
	free(three);
	free(twenty);
	free(twentynine);
	free(ten);

	return 0;

}
