#include <iostream>
#include <string>
#include <vector>

class I_hash {
public:
	std::vector<std::string> hashTable;
	std::vector<int> keyTable;
	int tableLength = hashTable.size();

	void Filler();
	int TableSize();
	std::string Search(int);
	void Remove(int);
	int Hashing(int);
	void Rehash();
	void Print();
	void MenUI();
};
