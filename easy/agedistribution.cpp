#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

void determineCategory(int &age){

	if(age >= 0 && age <= 2)
		std::cout << "Still in Mama's arms" << std::endl;
	else if(age == 3 || age == 4)
		std::cout << "Preschool Maniac" << std::endl;
	else if(age >= 5 && age <= 11)
		std::cout << "Elementary school" << std::endl;
	else if(age >= 12 && age <= 14)
		std::cout << "Middle school" << std::endl;
	else if(age >= 15 && age <= 18)
		std::cout << "High school" << std::endl;
	else if(age >= 19 && age <= 22)
		std::cout << "College" << std::endl;
	else if(age >= 23 && age <= 65)
		std::cout << "Working for the man" << std::endl;
	else if(age >= 66 && age <= 100)
		std::cout << "The Golden Years" << std::endl;
	else
		std::cout << "This program is for humans" << std::endl;

}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;
	while(getline(stream, line)){

		int age = std::atoi(line.c_str());
		determineCategory(age);

	}

	return 0;

}
