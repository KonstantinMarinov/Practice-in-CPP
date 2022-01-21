#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "Hero.h"
class Barbarian : public Hero {
private:
	std::string silenSpell;
	int silenSpellDmg;
	std::string slabSpell;
	int slabSpellDmg;
	int strongSpellManaCost;
	int turnCounter = 1;
public:
	Barbarian(VitalData importantData) :Hero() {
		this->_vitalData = importantData;
		this->_name = "Barbarian";
	};
	void readSpellFromInput(SpellType castType) {
		std::string input;
		getline(std::cin, input);
		std::istringstream inputStream(input);
		switch (castType)

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
	int castSpell() {
		if (_vitalData.currMana >= strongSpellManaCost) {
			this->_vitalData.currMana -= strongSpellManaCost;
			std::cout << "Barbarian casting " << silenSpell << " for " << strongSpellManaCost << " mana" << std::endl;
			return silenSpellDmg;
		}
		else {
			std::cout << "Barbarian casting " << slabSpell << " for " << 0 << " mana" << std::endl;
			return slabSpellDmg;
		}
	};
	void takeDamage(int dmg) {
		if (turnCounter % 3 == 0) {
			this->_vitalData.health -= dmg / 2;
			std::cout << "Barbarian took " << dmg / 2 << " damage and is left with " << _vitalData.health << " health" << std::endl;
		}
		else {
			this->_vitalData.health -= dmg;
			std::cout << "Barbarian took " << dmg << " damage and is left with " << _vitalData.health << " health" << std::endl;
		}
		this->turnCounter++;
	};
	void regenerate() {
		this->_vitalData.currMana += _vitalData.manaRegenRate;

		int regainedMana = _vitalData.manaRegenRate;
		if (_vitalData.currMana > _vitalData.maxMana) {
			this->_vitalData.currMana = _vitalData.maxMana;

		}
		std::cout << "Barbarian regained " << regainedMana << " mana for up to " << _vitalData.currMana << std::endl;

	};
	bool isDead() const {
		if (_vitalData.health <= 0) {
			return true;
		}
		else {
			return false;
		}
	};
};
#endif // !BARBARIAN_H

