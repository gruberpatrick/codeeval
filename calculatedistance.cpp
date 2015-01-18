#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

int calculateDistance(std::string &first_vector, std::string &second_vector){

	int first_position = first_vector.find(", ");
	int second_position = second_vector.find(", ");

	int a_squared = std::atoi(first_vector.substr(0, first_position).c_str()) - std::atoi(second_vector.substr(0, second_position).c_str());
	int b_squared = std::atoi(first_vector.substr(first_position + 2).c_str()) - std::atoi(second_vector.substr(second_position + 2).c_str());

	if(a_squared < 0)
		a_squared *= -1;

	if(b_squared < 0)
		b_squared += -1;

	return std::sqrt((a_squared * a_squared) + (b_squared * b_squared));

}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){
		int vectors_position = line.find(") (");
		std::string first_vector = line.substr(1, vectors_position - 1);
		std::string second_vector = line.substr(vectors_position + 3, line.length() - (vectors_position + 4));
		std::cout << calculateDistance(first_vector, second_vector) << std::endl;
	}

	return 0;

}
