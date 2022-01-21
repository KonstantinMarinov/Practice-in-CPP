#include <iostream>
#include <string>

#include "CommandExecutor.h"

void desciption() {
	std::cout << "The world is hungry for gaming consoles!" << std::endl;
	std::cout << "It is your time to shine." << std::endl;
	std::cout << "You decide to open a hardware console store and sell all of those how new PlayStations and Xboxes." << std::endl;
	std::cout << "Input: " << std::endl;
	std::cout << "- First read the number of commands that you want to run in the store." << std::endl;
	std::cout << "- Second read the specific commands in the following example format:" << std::endl;
	std::cout << "- 0 1 200 200 " << std::endl;
	std::cout << "- The first number is the type of command. " << std::endl;
	std::cout << "- The second number is the type of console. 1 - Xbox, 0 - PlayStation. " << std::endl;
	std::cout << "- The third number is the price of the console. " << std::endl;
	std::cout << "- The third number is the quality of the console. " << std::endl;
	std::cout << "Commands map: 0 - add, 1 - remove, 2 - sort by price, 3 sort by quality, 4 - print data" << std::endl;
	std::cout << "Quality and price numbers are added only for command 1." << std::endl;
	std::cout << "Output:" << std::endl;
	std::cout << "- The results from the commands." << std::endl;
}

int main() {
  desciption();
  int commands = 0;
  std::string input;

  std::cin >> commands;
  std::cin.ignore();

  CommandExecutor commandExecutor;

  for (int i = 0; i < commands; ++i) {
    getline(std::cin, input);
    commandExecutor.extractCommand(input);
  }

  return 0;
}
