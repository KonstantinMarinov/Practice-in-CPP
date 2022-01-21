#include "BattleField.h"

void desciption() {
	std::cout << "Time for some classics! What else if not the father of all hack n slash RPGs?" << std::endl;
	std::cout << "Dive in the world of Diablo where the mighty Barbarian is stuck in a deadly battle versus the swift Amazon." << std::endl;
	std::cout << "Input: " << std::endl;
	std::cout << "- The first 1st and 2nd rows of data representing the VitalData for each Hero." << std::endl;
	std::cout << "- Each of those rows represents the hero health, maxMana and manaRegenRate in that order." << std::endl;
	std::cout << "- Example: 120(health) 50(maxMana) 8(manaRegenRate) " << std::endl;
	std::cout << "- The 3rd and 4th rows of data represents the Barbarian spells." << std::endl;
	std::cout << "- The 3rd row is his weaker spell - spellName and spellDamage " << std::endl;
	std::cout << "- The 4th row is his stronger spell - spellName , spellDamage  and spellManaCost" << std::endl;
	std::cout << "- Example: Bash 40(weak spell) or Heavy Strike 40 20(strong spell)" << std::endl;
	std::cout << "- The 5th and 6th rows of data represents the Amazon spells that follow the same logic as the spells above." << std::endl;
	std::cout << "Output:" << std::endl;
	std::cout << "- The results from the battle." << std::endl;
}

int main() {
  desciption();
  BattleField battleField;
  battleField.createHeroes();
  battleField.createSpells();
  battleField.startBattle();

  return EXIT_SUCCESS;
}
