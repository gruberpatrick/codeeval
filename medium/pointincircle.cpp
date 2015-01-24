#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>



void parseValues(std::string &line, float &center_x, float &center_y, float &radius, float &point_x, float &point_y){

	line = line.substr(9);
	int position = line.find(",");
	center_x = std::atof(line.substr(0, position).c_str());

	line = line.substr(position + 2);
	position = line.find(")");
	center_y = std::atof(line.substr(0, position).c_str());

	line = line.substr(position + 11);
	position = line.find(";");
	radius = std::atof(line.substr(0, position).c_str());

	line = line.substr(position + 10);
	position = line.find(",");
	point_x = std::atof(line.substr(0, position).c_str());

	line = line.substr(position + 2);
	position = line.find(")");
	point_y = std::atof(line.substr(0, position).c_str());

}



bool checkPointInCircle(float &center_x, float &center_y, float &radius, float &point_x, float &point_y){

	float distance = std::pow((center_x - point_x), 2)  + std::pow((center_y - point_y), 2);
	radius = std::pow(radius, 2);

	if(distance <= radius)
		return true;
	return false;

}



int main(int argc, char *argv[]){

	std::ifstream stream(argv[1]);
	std::string line;
	while(getline(stream, line)){

		float center_x, center_y, radius, point_x, point_y;
		parseValues(line, center_x, center_y, radius, point_x, point_y);

		if(checkPointInCircle(center_x, center_y, radius, point_x, point_y)){
			std::cout << "true" << std::endl;
		}else{
			std::cout << "false" << std::endl;
		}

	}

	return 0;

}
