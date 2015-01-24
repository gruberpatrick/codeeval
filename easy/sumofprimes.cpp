#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

int main(int argc, char *argv[]){

	int prime_range = 1000;
	int counter = 1;
	std::vector<unsigned int> primes;
	primes.push_back(2);
	for(unsigned int index = 3; counter < prime_range; index++){
		bool found_prime = true;
		for(unsigned int index_inner = 0; index_inner < primes.size(); index_inner++){
			if((index % primes[index_inner]) == 0){
				found_prime = false;
				break;
			}
		}
		if(found_prime){
			primes.push_back(index);
			counter++;
		}
	}

	int sum = 0;
	for(unsigned int index = 0; index < primes.size(); index++){
		sum += primes[index];
	}

	std::cout << sum << std::endl;

	return 0;

}
