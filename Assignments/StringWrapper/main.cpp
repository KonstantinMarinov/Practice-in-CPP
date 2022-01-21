#include "InputParser.h"
#include "StringWrapper.h"

void desciption() {
	std::cout << "You are an employee of a company called Stringify." << std::endl; 
	std::cout << "One of your coworkers went a holiday 2 days before releasing the final version of the project." << std::endl;
	std::cout << "He mentioned something about a StringWrapper class not being implemented." << std::endl;
	std::cout << "Input: " << std::endl;
	std::cout << "- First read a string" << std::endl;
	std::cout << "- Second read a single UTF - 8 char" << std::endl;
	std::cout << "- Last read a 32bit integer " << std::endl;
	std::cout << "Output:" << std::endl;
	std::cout << "- Print the Base string with appended C char N number of times." << std::endl;
}

int main() {

  desciption();
  const Input input = readInput();
  const StringWrapper first(input.line);
  const StringWrapper second(input.letter, input.repetitions);

  StringWrapper third;
  third.append((first.getContent()).append(second.getContent()));
  third.printContent();

  return 0;
}

