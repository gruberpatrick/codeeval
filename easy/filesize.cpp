#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	stream.seekg(0, stream.end);

	int bytes = stream.tellg();
	std::cout << bytes << std::endl;

	stream.close();

	return 0;
}
