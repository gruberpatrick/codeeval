#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

int fib(int number){

	if(number == 0 || number == 1)
		return number;

	return fib(number - 1) + fib(number - 2);
	
}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;
	while(getline(stream, line)){

		int number = std::atoi(line.c_str());
		std::cout << fib(number) << std::endl;

	}

	return 0;

}
