#ifndef FUNCTION_H
#define FUNCTION_H
#include "Node.h"
#include <vector>

class SinglyList
{
private:
	AddressNode* head; // a pointer to the first node in the list
	AddressNode* CNN;
public:
	int allDataLine;
	SinglyList();	// constructor
	~SinglyList();	// destructor
	void inputNewData();
	AddressNode* insertNodeP1(int index, AddressNode* currNode);
	void displayAllList();
	void searchAddressData();
	bool searchCore1(string searchTag, AddressNode * currNode);
	bool searchCore2(string searchTag, AddressNode * currNode);
	bool searchCore3(string searchTag, AddressNode * currNode);
	bool searchCore4(string searchTag, AddressNode * currNode);
	bool searchCore5(string searchTag, AddressNode * currNode);
	bool searchCore6(string searchTag, AddressNode * currNode);
	void deleteAddressData();
	void modifyAddressData();
	void reSaveFile();
	int CountLines(char *fileName);
	string ReadFile(int line, int allDataLine, char *fileName);
	vector<string> split(string str);
};

#endif