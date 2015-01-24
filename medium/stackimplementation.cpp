#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>



struct int_stack{
	int value;
	int_stack *previous;
};



void push(int_stack **stack, int value){

	if((*stack)->value == 0 && (*stack)->previous == 0){
		//std::cout << "FIRST:" << value << std::endl;
		(*stack)->value = value;
	}else{
		//std::cout << "ADD:" << value << std::endl;
		int_stack *temp = new int_stack;
		temp->value = value;
		temp->previous = (*stack);
		(*stack) = temp;
	}

}



int pop(int_stack **stack, bool &stop){

	int value = 0;
	if((*stack)->previous == 0 && (*stack)->value == 0){
		stop = true;
		return 0;
	}else if((*stack)->previous != 0){
		value = (*stack)->value;
		int_stack *temp = (*stack);
		(*stack) = (*stack)->previous;
		free(temp);
	}else{
		value = (*stack)->value;
		(*stack)->value = 0;
	}
	return value;

}



void parseNumbers(std::vector<int> &numbers, std::string line){

	unsigned int symb_occurence = line.find(" ");
	while(symb_occurence < line.length()){
		numbers.push_back(std::atoi(line.substr(0, symb_occurence + 1).c_str()));
		line = line.substr(symb_occurence + 1);
		symb_occurence = line.find(" ");
	}

	if(line != "")
		numbers.push_back(std::atoi(line.c_str()));

}



int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;

	while(getline(stream, line)){

		std::vector<int> numbers;
		parseNumbers(numbers, line);

		int_stack *stack = new int_stack;
		stack->value = 0;
		stack->previous = 0;

		for(unsigned int index = 0; index < numbers.size(); index++){
			push(&stack, numbers[index]);
		}

		bool stop = false;
		int c = 0;
		while(!stop){
			int value = pop(&stack, stop);
			if(c % 2 == 0 && !stop){
				if(c > 0)
					std::cout << " ";
				std::cout << value;
			}
			c++;
		}

		free(stack);
		std::cout << std::endl;

	}

	return 0;
}
