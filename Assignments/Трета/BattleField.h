#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H
#include <memory>
#include <vector>
#include "Hero.h"
class BattleField {
public:
	void createHeroes();
	void createSpells();
	void startBattle();
	void printWinner(const std::unique_ptr<Hero>& character);
private:
	std::vector<std::unique_ptr<Hero>> _heroes;
	 
};
#endif // !BATTLEFIELD_H

