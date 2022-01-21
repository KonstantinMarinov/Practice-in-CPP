#include"InputParser.h"
#include<iostream>

Input readInput() {
	std::string line;
	char letter;
	int repetitions;
	std::cin >> line >> letter >> repetitions;
	Input temp;
	temp.letter = letter;
	temp.line = line;
	temp.repetitions = repetitions;
	return temp;
}

