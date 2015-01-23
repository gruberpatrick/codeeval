#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>



struct Tuple{
	int values[2];
};



void parseLine(int errors, std::string pattern, std::string line, std::map<std::string, Tuple> &occurence){

	int errors_fixed = errors;
	unsigned int pattern_length = pattern.length();

	while(line.length() >= pattern_length){
		std::string check = line.substr(0, pattern_length);

		for(unsigned int index = 0; index < check.length(); index++){
			if(check.substr(index, 1) != pattern.substr(index, 1))
				errors_fixed--;
		}

		//std::cout << check << " : " << (errors - errors_fixed) << std::endl;

		int position = occurence.count(check);
		if(errors_fixed >= 0 && position == 0){
			Tuple value = {(errors - errors_fixed), 1};
			occurence[check] = value;
		}else if(errors_fixed >= 0 && position >= 0){
			occurence[check].values[1]++;
		}

		line = line.substr(1);
		errors_fixed = errors;
	}

}



int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;
	while(getline(stream, line)){

		// occurence
		std::map<std::string, Tuple> occurence;

		// pattern, error, line
		int position = line.find(" ");
		std::string pattern = line.substr(0, position);
		line = line.substr(position + 1);
		position = line.find(" ");
		int errors = std::atoi(line.substr(0, position).c_str());
		line = line.substr(position + 1);

		parseLine(errors, pattern, line, occurence);
		if(occurence.size() == 0){
			std::cout << "No match" << std::endl;
			continue;
		}

		typedef std::map<std::string, Tuple>::iterator it;
		bool first = true;
		for(int index = 0; index <= errors; index++){
			for(it iterator = occurence.begin(); iterator != occurence.end(); iterator++){
				if(iterator->second.values[0] == index){
					for(int jdex = 0; jdex < iterator->second.values[1]; jdex++){
						if(!first)
							std::cout << " ";
						else
							first = false;
						std::cout << iterator->first << ":" << iterator->second.values[0] << ":" << iterator->second.values[1];
					}
				}
			}
		}
		std::cout << std::endl;

	}

	return 0;

}
