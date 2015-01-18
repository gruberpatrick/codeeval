#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

void printPrimes(unsigned int prime_range){
	std::vector<unsigned int> primes;
	if(prime_range >= 2){
		primes.push_back(2);
		std::cout << 2;
	}
	for(unsigned int index = 3; index <= prime_range; index++){
		bool found_prime = true;
		for(unsigned int index_inner = 0; index_inner < primes.size(); index_inner++){
			if((index % primes[index_inner]) == 0){
				found_prime = false;
				break;
			}
		}
		if(found_prime){
			primes.push_back(index);
			std::cout << "," << index;
		}
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){
		printPrimes(std::atoi(line.c_str()));
	}

	return 0;

}
