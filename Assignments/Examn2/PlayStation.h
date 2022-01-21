#ifndef PLAYSTATION_H
#define PLAYSTATION_H
#include"Console.h"
class PlayStation : public Console {
public:
	PlayStation(int cena, int kachestvo, int pokolenie) :Console(cena, kachestvo), generation(pokolenie) {};
	int generation;	
};
#endif // !PLAYSTATION_H

