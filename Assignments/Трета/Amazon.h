#ifndef AMAZON_H
#define AMAZON_H
#include "Hero.h"
class Amazon : public Hero {
private:
	std::string silenSpell;
	int silenSpellDmg;
	std::string slabSpell;
	int slabSpellDmg;
	int strongSpellManaCost;
	int turnCounter = 1;
public:
	bool isDead() const {
		if (this->_vitalData.health <= 0) {
			return true;
		}
		else {
			return false;
		}
	};
	int castSpell() {
		int multiplayer = 0;

		if (this->_vitalData.currMana >= this->strongSpellManaCost) {
			this->_vitalData.currMana -= this->strongSpellManaCost;
			std::cout << "Amazon casting " << this->silenSpell << " for " << this->strongSpellManaCost << " mana" << std::endl;
			if (this->turnCounter % 2 == 0) {
				multiplayer = this->silenSpellDmg / 4;
			}
			return this->silenSpellDmg + multiplayer;
		}
		else {
			std::cout << "Amazon casting " << this->slabSpell << " for " << 0 << " mana" << std::endl;
			if (this->turnCounter % 2 == 0) {
				multiplayer = this->slabSpellDmg / 4;
			}
			return this->slabSpellDmg + multiplayer;
		}
	};
	Amazon(VitalData importantData) :Hero() {
		this->_vitalData = importantData;
		this->_name = "Amazon";
	};
	void readSpellFromInput(SpellType costType) {
		std::string input;
		getline(std::cin, input);
		std::istringstream inputStream(input);
		switch (costType)

		{
		case SpellType::Weak:
			inputStream >> this->slabSpell >> this->slabSpellDmg;
			break;
		case SpellType::Strong:
			inputStream >> this->silenSpell >> this->silenSpellDmg >> this->strongSpellManaCost;
			break;
		default:
			break;
		}
	};
	
	void takeDamage(int dmg) {
		this->_vitalData.health -= dmg;
		std::cout << "Amazon took " << dmg << " damage and is left with " << this->_vitalData.health << " health" << std::endl;
	};
	void regenerate() {
		this->_vitalData.currMana += this->_vitalData.manaRegenRate;
		this->turnCounter++;
		int regainedMana = _vitalData.manaRegenRate;
		if (this->_vitalData.currMana > this->_vitalData.maxMana) {
			this->_vitalData.currMana = this->_vitalData.maxMana;
		}
		std::cout << "Amazon regained " << regainedMana << " mana for up to " << _vitalData.currMana << std::endl;
	};
	
};




#endif // !AMAZON_H
