#ifndef STORE_H
#define STORE_H
#include <vector>
#include <memory>
#include "PlayStation.h"
#include "Defines.h"
class Store {
private:
	std::vector<std::unique_ptr< Console>> typBox;
	std::vector<std::unique_ptr< PlayStation>> hubavStation;
public:
	void addPs(int cena, int kachestvo, int pokolenie) {
		std::cout << "Adding: PS with generation " << pokolenie << ", price: " << cena << ", quality: " << kachestvo << std::endl;
		this->hubavStation.push_back(
			std::unique_ptr<PlayStation>(new PlayStation(cena, kachestvo, pokolenie)));
	};
	void addXbox(int cena, int  kachestvo) {
		std::cout << "Adding: Xbox with price: " << cena << ", quality: " << kachestvo << std::endl;
		this->typBox.push_back(
			std::unique_ptr<Console>(new Console(cena, kachestvo)));
	};
	void remove(ConsoleType tipKonzola) {
		switch (tipKonzola)
		{
		case ConsoleType::PS:
			std::cout << "Removing: PS with generation " << this->hubavStation.back()->generation << ", price: " << this->hubavStation.back()->getPrice() << ", quality: " << this->hubavStation.back()->getQuality() << std::endl;
			this->hubavStation.pop_back();
			break;
		case ConsoleType::XBOX:
			std::cout << "Removing: Xbox with price: " << this->typBox.back()->getPrice() << ", quality: " << this->typBox.back()->getQuality() << std::endl;
			this->typBox.pop_back();
			break;
		default:
			break;
		}
	};
	void sortByPrice(ConsoleType tipKonzola) {
		switch (tipKonzola)
		{
		case ConsoleType::PS:
			std::cout << "Sorting all PS by price" << std::endl;
			for (int k = 0; k < this->hubavStation.size(); k++) {
				for (int p = 0; p < this->hubavStation.size() - k - 1; p++) {
					if (this->hubavStation[p]->getPrice() < this->hubavStation[p + 1]->getPrice()) {
						std::swap(hubavStation[p], hubavStation[p + 1]);
					}
				}
			}
			break;
		case ConsoleType::XBOX:
			std::cout << "Sorting all Xbox by price" << std::endl;
			for (int k = 0; k < this->typBox.size(); k++) {
				for (int p = 0; p < this->typBox.size() - k - 1; p++) {
					if (this->typBox[p]->getPrice() < this->typBox[p + 1]->getPrice()) {
						std::swap(typBox[p], typBox[p + 1]);
					}
				}
			}
			break;
		default:
			break;
		}
	};
	void sortByQuality(ConsoleType tipKonzola) {
		switch (tipKonzola)
		{
		case ConsoleType::PS:
			std::cout << "Sorting all PS by quality" << std::endl;
			for (int k = 0; k < this->hubavStation.size(); k++) {
				for (int p = 0; p < this->hubavStation.size() - k - 1; p++) {
					if (this->hubavStation[p]->getQuality() < this->hubavStation[p + 1]->getQuality()) {
						std::swap(hubavStation[p], hubavStation[p + 1]);
					}
				}
			}
			break;
		case ConsoleType::XBOX:
			std::cout << "Sorting all Xbox by quality" << std::endl;
			for (int k = 0; k < this->typBox.size(); k++) {
				for (int p = 0; p < this->typBox.size() - k - 1; p++) {
					if (this->typBox[p]->getQuality() < this->typBox[p + 1]->getQuality()) {
						std::swap(typBox[p], typBox[p + 1]);
					}
				}
			}
			break;
		default:
			break;
		}
	};
	void print(ConsoleType tipKonzola) {
		switch (tipKonzola)
		{
		case ConsoleType::PS:
			std::cout << "Printing all PS data" << std::endl;
			for (int i = 0; i < this->hubavStation.size(); i++) {
				std::cout << "PS with generation " << this->hubavStation[i]->generation << ", price: "
					<< this->hubavStation[i]->getPrice() << ", quality: " << this->hubavStation[i]->getQuality() << std::endl;

			}
			break;
		case ConsoleType::XBOX:
			std::cout << "Printing all Xbox data" << std::endl;
			for (int k = 0; k < this->typBox.size(); k++) {
				std::cout << "Xbox with price: "
					<< this->typBox[k]->getPrice() << ", quality: " << this->typBox[k]->getQuality() << std::endl;

			}
			break;
		default:
			break;
		}
	};
};
#endif // !STORE_H

