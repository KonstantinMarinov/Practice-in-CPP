#ifndef STRING_WRAPPER_H
#define STRING_WRAPPER_H
#include<string>
#include<iostream>
#include<algorithm>
class StringWrapper {
	std::string outputline;
	std::string line = " ";
	char letter = ' ';
	int repetitions = 0;
public:

	StringWrapper(std::string line) : line(line) {
		
	};
	StringWrapper(char letter, int repetitions) : letter(letter), repetitions(repetitions) {
		
	};
	StringWrapper() {};

	StringWrapper getContent() const {
		return *this;
	}
	StringWrapper append(StringWrapper r) {
		if (r.repetitions != 0) {
			std::string temp = " ";
			temp[0] = r.letter;
			for (int i = 0; i < r.repetitions; i++) {
				this->line+=temp;
			}
		}
		else {
			this->line = r.line;
		}
		return *this;
	}
	void printContent() {
		std::cout << this->line;
	}
	
	

};

#endif
