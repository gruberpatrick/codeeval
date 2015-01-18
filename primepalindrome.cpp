#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

int main(int argc, char *argv[]){

	unsigned int prime_range = 1000;
	std::vector<unsigned int> primes;
	primes.push_back(2);
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
		}
	}

	for(unsigned int index = primes.size() - 1; index >= 0; index--){
		std::string palindrome_check = std::to_string(primes[index]);
		std::string palindrome_inverse(palindrome_check.rbegin(), palindrome_check.rend());
		if(palindrome_check == palindrome_inverse){
			std::cout << primes[index] << std::endl;
			return 0;
		}
	}


	return 0;

}
