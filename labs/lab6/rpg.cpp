#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>

int sampleValue(const std::vector<int>& values)
{
	return values[std::rand() % values.size()];
}

void loadWeaponData(std::ifstream& weaponFile, 
	std::map<std::string, std::vector<int> >& weapons)
{
	std::string word;
	int value = 0;
	while (weaponFile >> word && weaponFile >> value)
	{
		// TODO
	}
}

int getWeaponDamage(const std::string& word, 
	std::map<std::string, std::vector<int> >& weapons)
{
	// TODO
}

void processBattle(std::ifstream& battleFile, 
	std::map<std::string, std::vector<int> >& weapons)
{
	std::string word;
	while (battleFile >> word)
	{
		std::cout << word << " " << getWeaponDamage(word, weapons) << std::endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cerr << "./search weapon.txt battle.txt" << std::endl;
		return 1;
	}

	std::ifstream weaponFile(argv[1]);
	std::ifstream battleFile(argv[2]);

	if (!weaponFile.is_open() || !battleFile.is_open())
	{
		std::cerr << "Files failed to open" << std::endl;
		return 1;
	}

	std::srand(578);

	std::map<std::string, std::vector<int>> weapons;
	loadWeaponData(weaponFile, weapons);
	processBattle(battleFile, weapons);

	weaponFile.close();
	battleFile.close();
	return 0;
}