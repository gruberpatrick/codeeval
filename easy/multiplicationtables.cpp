#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]){

	for(int index_inner = 1; index_inner <= 12; index_inner++){
		for(int index_outer = 1; index_outer <= 12; index_outer++){
			if(index_outer > 1)
				std::cout << std::setw(4);
			std::cout << (index_inner * index_outer);
		}
		std::cout << std::endl;
	}

	return 0;

}
