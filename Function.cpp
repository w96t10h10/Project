#include <iostream>
#include "Node.h"
#include "Function.h"
//#include <windows.h>
#include<fstream>
#include <string>
#include <vector>

using namespace std;

SinglyList::SinglyList() {
	head = NULL;//head
	CNN = NULL;
	char fileName[] = "123.txt";
	fstream file;
	file.open(fileName, ios::in);
	allDataLine = CountLines(fileName);
	cout << "test allDataLine :" << allDataLine << endl;//test
	int j = 0;
	for (int i = 0; i < allDataLine; i++) {
		string temp;
		getline(file, temp);
		string lineStr = temp;
		vector<string>lineSplitStr = split(lineStr);
		AddressNode* currNode = head;
		if (i != 0) {
			currNode = CNN;
		}
		AddressNode* newNode = new AddressNode;
		newNode->LineNum = i + 1;
		newNode->Title = lineSplitStr[0];
		newNode->Surname = lineSplitStr[1];
		newNode->GivenName = lineSplitStr[2];
		newNode->Gender = lineSplitStr[3];
		newNode->Birthday = lineSplitStr[4];
		newNode->StreetAddress = lineSplitStr[5];
		newNode->City = lineSplitStr[6];
		newNode->StateFull = lineSplitStr[7];
		newNode->ZipCode = lineSplitStr[8];
		newNode->CountryFull = lineSplitStr[9];
		newNode->TelephotoCountryCode = lineSplitStr[10];
		newNode->TelephotoNumber = lineSplitStr[11];
		newNode->EmailAddress = lineSplitStr[12];
		newNode->Occupation = lineSplitStr[13];
		newNode->Company = lineSplitStr[14];
		if (i == 0) {
			newNode->next = head;
			head = newNode;
			CNN = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
			CNN = newNode;
		}
		cout << i << endl;
	}
	file.close();
	//displayAllList();
}
SinglyList::~SinglyList() {
	AddressNode* currNode = head;
	AddressNode* nextNode = NULL;
	while (currNode != NULL) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}
void SinglyList::inputNewData() {// insert the new data
	int dataNum;
	cout << "Input how many data do you add" << endl;
	cin >> dataNum;// how many data you want to input
	for (int i = 1; i <= dataNum; i++) {
		int currIndex = 1;
		AddressNode* currNode = head;
		if (i != 0) {
			currNode = CNN;
		}
		AddressNode* newNode = new AddressNode;
		cout << "Input the title of the new data (if the data need space, use' _ '!)" << endl;
		newNode->LineNum = allDataLine;//the sum of data line
		newNode->LineNum++;
		cout << "Title: ";
		cin >> newNode->Title;
		cout << "Surname: ";
		cin >> newNode->Surname;
		cout << "GivenName: ";
		cin >> newNode->GivenName;
		cout << "Gender: ";
		cin >> newNode->Gender;
		cout << "Birthday: ";
		cin >> newNode->Birthday;
		cout << "StreetAddress: ";
		cin >> newNode->StreetAddress;
		cout << "City: ";
		cin >> newNode->City;
		cout << "StateFull: ";
		cin >> newNode->StateFull;
		cout << "ZipCode: ";
		cin >> newNode->ZipCode;
		cout << "CountryFull: ";
		cin >> newNode->CountryFull;
		cout << "TelephotoCountryCode: ";
		cin >> newNode->TelephotoCountryCode;
		cout << "TelephotoNumber: ";
		cin >> newNode->TelephotoNumber;
		cout << "EmailAddress: ";
		cin >> newNode->EmailAddress;
		cout << "Occupation: ";
		cin >> newNode->Occupation;
		cout << "Company: ";
		cin >> newNode->Company;
		if (allDataLine == 0) {
			newNode->next = head;
			head = newNode;
			CNN = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
			CNN = newNode;
		}
		fstream writefile;
		char fileName[] = "123.txt";//make sure the file name is inFile
		writefile.open(fileName, ios::app);
		writefile << "\n" << newNode->Title << "\t" << newNode->Surname << "\t" << newNode->GivenName << "\t" << newNode->Gender << "\t" << newNode->Birthday << "\t" << newNode->StreetAddress << "\t" << newNode->City << "\t" <<
			newNode->StateFull << "\t" << newNode->ZipCode << "\t" << newNode->CountryFull << "\t" << newNode->TelephotoCountryCode << "\t" << newNode->TelephotoNumber << "\t" << newNode->EmailAddress << "\t" << newNode->Occupation << "\t" <<
			newNode->Company;//
		allDataLine++;
		writefile.close();
		cout << "Finish insert"<<endl;
	}
}
// insertNode inserts a new node at position "index"
AddressNode* SinglyList::insertNodeP1(int index, AddressNode* currNode)
{
	if (index < 0)
		return NULL;
	if (index > 0 && currNode == NULL)
		return NULL;
	AddressNode* newNode = new AddressNode;
	return newNode;
}
void SinglyList::displayAllList() {// can display num of new data
	int num = 0;
	AddressNode* currNode = head;
	while (currNode != NULL) {
		cout << currNode->LineNum << ". " << currNode->Title << " " << currNode->Surname << " " << currNode->GivenName << " " << currNode->Gender << " " << currNode->Birthday << " " << currNode->StreetAddress << " " << currNode->City << " " << currNode->StateFull << " " << currNode->ZipCode << " " << currNode->CountryFull << " " << currNode->TelephotoCountryCode << " " <<
			currNode->TelephotoNumber << " " << currNode->EmailAddress << " " << currNode->Occupation << " " << currNode->Company << " " << endl;
		currNode = currNode->next;
		num++;
	}
	cout << "Number of nodes in the list: " << num << endl;
}//

void SinglyList::searchAddressData() {//search data use word
	int N = allDataLine;
	string searchTag;//user need to give what keyword they want to use to search data, such as us title or surmane
	int systemcore = 0;
	cout << "Please input the keyword for searing :";
	cin >> searchTag;
	cout << "What is the Keyword Type?(1 is Surname , 2 is GivenNan , 3 is City , 4 is ZipCode , 5 is TelephotoNumber , 6 is EmailAddress .";
	cin >> systemcore;
	//user need to give what keyword they want to use to search data, such as us title or surmane
	AddressNode* currNode = head;
	cout << "the search data in order to :" << endl;
	for (int i = 0; i < N; i++) {
		switch (systemcore) {
		case 1: {
			if (searchCore1(searchTag, currNode)) {//core1 means use Surname to search data
				cout << currNode->LineNum << "" << currNode->Title << " " << currNode->Surname << " " << currNode->GivenName << " " << currNode->Gender << " " << currNode->Birthday << " " << currNode->StreetAddress << " " << currNode->City << " " << currNode->StateFull << " " << currNode->ZipCode << " " << currNode->CountryFull << " " << currNode->TelephotoCountryCode << " " <<
					currNode->TelephotoNumber << " " << currNode->EmailAddress << " " << currNode->Occupation << " " << currNode->Company << " " << endl;
			}
			currNode = currNode->next;
			break;
		}
		case 2: {
			if (searchCore2(searchTag, currNode)) {//core1 means use GivenNan to search data
				cout << currNode->LineNum << "" << currNode->Title << " " << currNode->Surname << " " << currNode->GivenName << " " << currNode->Gender << " " << currNode->Birthday << " " << currNode->StreetAddress << " " << currNode->City << " " << currNode->StateFull << " " << currNode->ZipCode << " " << currNode->CountryFull << " " << currNode->TelephotoCountryCode << " " <<
					currNode->TelephotoNumber << " " << currNode->EmailAddress << " " << currNode->Occupation << " " << currNode->Company << " " << endl;
			}
			currNode = currNode->next;
			break;
		}
		case 3: {
			if (searchCore3(searchTag, currNode)) {//core1 means use City to search data
				cout << currNode->LineNum << "" << currNode->Title << " " << currNode->Surname << " " << currNode->GivenName << " " << currNode->Gender << " " << currNode->Birthday << " " << currNode->StreetAddress << " " << currNode->City << " " << currNode->StateFull << " " << currNode->ZipCode << " " << currNode->CountryFull << " " << currNode->TelephotoCountryCode << " " <<
					currNode->TelephotoNumber << " " << currNode->EmailAddress << " " << currNode->Occupation << " " << currNode->Company << " " << endl;
			}
			currNode = currNode->next;
			break;
		}
		case 4: {
			if (searchCore4(searchTag, currNode)) {//core1 means use ZipCode to search data
				cout << currNode->LineNum << "" << currNode->Title << " " << currNode->Surname << " " << currNode->GivenName << " " << currNode->Gender << " " << currNode->Birthday << " " << currNode->StreetAddress << " " << currNode->City << " " << currNode->StateFull << " " << currNode->ZipCode << " " << currNode->CountryFull << " " << currNode->TelephotoCountryCode << " " <<
					currNode->TelephotoNumber << " " << currNode->EmailAddress << " " << currNode->Occupation << " " << currNode->Company << " " << endl;
			}
			currNode = currNode->next;
			break;
		}
		case 5: {
			if (searchCore5(searchTag, currNode)) {//core1 means use TelephotoNumber to search data
				cout << currNode->LineNum << "" << currNode->Title << " " << currNode->Surname << " " << currNode->GivenName << " " << currNode->Gender << " " << currNode->Birthday << " " << currNode->StreetAddress << " " << currNode->City << " " << currNode->StateFull << " " << currNode->ZipCode << " " << currNode->CountryFull << " " << currNode->TelephotoCountryCode << " " <<
					currNode->TelephotoNumber << " " << currNode->EmailAddress << " " << currNode->Occupation << " " << currNode->Company << " " << endl;
			}
			currNode = currNode->next;
			break;
		}
		case 6: {
			if (searchCore6(searchTag, currNode)) {//core1 means use EmailAddress to search data
				cout << currNode->LineNum << "" << currNode->Title << " " << currNode->Surname << " " << currNode->GivenName << " " << currNode->Gender << " " << currNode->Birthday << " " << currNode->StreetAddress << " " << currNode->City << " " << currNode->StateFull << " " << currNode->ZipCode << " " << currNode->CountryFull << " " << currNode->TelephotoCountryCode << " " <<
					currNode->TelephotoNumber << " " << currNode->EmailAddress << " " << currNode->Occupation << " " << currNode->Company << " " << endl;
			}
			currNode = currNode->next;
			break;
		}
				if (systemcore > 6 || systemcore < 0) {
					cout << "Wrong input number!" << endl;
				}
				system("pause");
		}
	}
	system("pause");
}

bool SinglyList::searchCore1(string searchTag, AddressNode * currNode)//use Surname to search data
{
	string searchTemp;
	searchTemp = searchTag;
	if (searchTemp == currNode->Surname) {
		return true;
	}
	else {
		return false;
	}
}

bool SinglyList::searchCore2(string searchTag, AddressNode * currNode)//use GivenNan to search data
{
	string searchTemp;
	searchTemp = searchTag;
	if (searchTemp == currNode->GivenName) {
		return  true;
	}
	else {
		return false;
	}
}

bool SinglyList::searchCore3(string searchTag, AddressNode * currNode)//use City to search data
{
	string searchTemp;
	searchTemp = searchTag;
	if (searchTemp == currNode->City) {
		return  true;
	}
	else {
		return false;
	}
}

bool SinglyList::searchCore4(string searchTag, AddressNode * currNode)//use City to search data
{
	string searchTemp;
	searchTemp = searchTag;
	if (searchTemp == currNode->ZipCode) {
		return  true;
	}
	else {
		return false;
	}
}

bool SinglyList::searchCore5(string searchTag, AddressNode * currNode)//use City to search data
{
	string searchTemp;
	searchTemp = searchTag;
	if (searchTemp == currNode->TelephotoNumber) {
		return  true;
	}
	else {
		return false;
	}
}

bool SinglyList::searchCore6(string searchTag, AddressNode * currNode)//use City to search data
{
	string searchTemp;
	searchTemp = searchTag;
	if (searchTemp == currNode->EmailAddress) {
		return  true;
	}
	else {
		return false;
	}
}

void SinglyList::deleteAddressData() {//the double x must be the index in the node you want to Delete!,please use searchAddressData to find x; x is a index call LineNum in the node!
	int runtime;//how many data you want to delete
	cout << "How many data do you want to delete ?" << endl;
	cin >> runtime;
	for (int i = 1; i <= runtime; i++) {
		int x;
		cout << "Please input the number of the Data you want to delete (You must be know the number of your Data which you want to delete :";
		cin >> x;
		AddressNode* prevNode = NULL;
		AddressNode* currNode = head;
		while (currNode && currNode->LineNum != x)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
		
			cout << "Finish, the data is alreadly deleted.";
			}

		}
		allDataLine--;
		//cout << "test delete" << endl;//test test
		//displayAllList();
		reSaveFile();
	}
	
}

void SinglyList::modifyAddressData() {
	int runtime;//how many data you want to delete
	cout << "How many data do you want to modify ?" << endl;
	cin >> runtime;
	for (int i = 1; i <= runtime; i++) {
		int x;
		cout << "Please input the number of the Data you want to modify (You must be know the number of your Data which you want to modify :";
		cin >> x;
		AddressNode* prevNode = NULL;
		AddressNode* currNode = head;
		while (currNode && currNode->LineNum != x)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;

				cout << "Finish, the data is alreadly deleted."<<endl;
			}

		}
		allDataLine--;
		//cout << "test delete" << endl;//test test
		//displayAllList();
		reSaveFile();
	}
	int dataNum;
	cout << "Input how many data do you add" << endl;
	cin >> dataNum;// how many data you want to input
	for (int i = 1; i <= dataNum; i++) {
		int currIndex = 1;
		AddressNode* currNode = head;
		if (i != 0) {
			currNode = CNN;
		}
		AddressNode* newNode = new AddressNode;
		cout << "Input the title of the new data (if the data need space, use' _ '!)" << endl;
		newNode->LineNum = allDataLine;//the sum of data line
		newNode->LineNum++;
		cout << "Title: ";
		cin >> newNode->Title;
		cout << "Surname: ";
		cin >> newNode->Surname;
		cout << "GivenName: ";
		cin >> newNode->GivenName;
		cout << "Gender: ";
		cin >> newNode->Gender;
		cout << "Birthday: ";
		cin >> newNode->Birthday;
		cout << "StreetAddress: ";
		cin >> newNode->StreetAddress;
		cout << "City: ";
		cin >> newNode->City;
		cout << "StateFull: ";
		cin >> newNode->StateFull;
		cout << "ZipCode: ";
		cin >> newNode->ZipCode;
		cout << "CountryFull: ";
		cin >> newNode->CountryFull;
		cout << "TelephotoCountryCode: ";
		cin >> newNode->TelephotoCountryCode;
		cout << "TelephotoNumber: ";
		cin >> newNode->TelephotoNumber;
		cout << "EmailAddress: ";
		cin >> newNode->EmailAddress;
		cout << "Occupation: ";
		cin >> newNode->Occupation;
		cout << "Company: ";
		cin >> newNode->Company;
		if (allDataLine == 0) {
			newNode->next = head;
			head = newNode;
			CNN = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
			CNN = newNode;
		}
		fstream writefile;
		char fileName[] = "123.txt";//make sure the file name is inFile
		writefile.open(fileName, ios::app);
		writefile << "\n" << newNode->Title << "\t" << newNode->Surname << "\t" << newNode->GivenName << "\t" << newNode->Gender << "\t" << newNode->Birthday << "\t" << newNode->StreetAddress << "\t" << newNode->City << "\t" <<
			newNode->StateFull << "\t" << newNode->ZipCode << "\t" << newNode->CountryFull << "\t" << newNode->TelephotoCountryCode << "\t" << newNode->TelephotoNumber << "\t" << newNode->EmailAddress << "\t" << newNode->Occupation << "\t" <<
			newNode->Company;//
		allDataLine++;
		writefile.close();
	}
}



void SinglyList::reSaveFile() {//save all the data in file again when you delete the node;
	fstream writefile;
	AddressNode* currNode = head;
	char fileName[] = "123.txt";
	writefile.open(fileName, ios::trunc);
	writefile.close();
	writefile.open(fileName, ios::out);
	while (currNode != NULL) {
		writefile << currNode->Title << "\t" << currNode->Surname << "\t" << currNode->GivenName << "\t" << currNode->Gender << "\t" << currNode->Birthday << "\t" << currNode->StreetAddress << "\t" << currNode->City << "\t" <<
			currNode->StateFull << "\t" << currNode->ZipCode << "\t" << currNode->CountryFull << "\t" << currNode->TelephotoCountryCode << "\t" << currNode->TelephotoNumber << "\t" << currNode->EmailAddress << "\t" << currNode->Occupation << "\t" <<
			currNode->Company;
		if (currNode->next != NULL) {
			writefile << "\n";
		}
		currNode = currNode->next;
	}
	writefile.close();
}

int SinglyList::CountLines(char *fileName) {//get how many data in the file
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(fileName, ios::in);//ios::in ????????????  
	if (ReadFile.fail())//??????:??0  
	{
		return 0;
	}
	else//????  
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			n++;
		}
		ReadFile.close();
		return n;
	}
}
string SinglyList::ReadFile(int line, int allDataLine, char *fileName) {//read file and get a list of Data to the string temp, then you can go to function split()
	int i = 0;
	string temp;
	fstream file;
	file.open(fileName, ios::in);
	while (getline(file, temp) && i<line)
	{
		i++;
	}
	file.close();
	return temp;
}
vector<string>SinglyList::split(string str) {//split different part of date of the temp to the vector reselt(vector is a class in c++ STL, like array)
	string::size_type pos;
	vector<string> result;
	string pattern = "\t";
	str += pattern;//??????????
	int size = str.size();
	for (int i = 0; i<size; i++)
	{
		pos = str.find(pattern, i);
		if (pos<size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

/*int main()//you only need to see the code upside
{
SinglyList t1;
int AllDataLine = t1.allDataLine;
//at1.searchAddressData(title, AllDataLine);
//t1.inputNewData();
t1.deleteAddressData();
system("pause");
}*/
