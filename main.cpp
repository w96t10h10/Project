#include <iostream>
#include <fstream>
#include <string>
#include "Function.h"
#include "Node.h"
using namespace std;

void read() {

	ifstream is("123.txt", ifstream::binary);

	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		char * buffer = new char[length];

		std::cout << "Reading " << length << " characters... ";
		// read data as a block:
		is.read(buffer, length);

		if (is)
			std::cout << "all characters read successfully.";
		else
			std::cout << "error: only " << is.gcount() << " could be read";
		is.close();

		// ...buffer contains the entire file...

		delete[] buffer;
	}
}
/*
int homepage() {
	int input;
	do {
		cout << "" << endl;
		cout << "         Electronic Address Book         " << endl;
		cout << "=========================================" << endl;
		cout << " " << endl;
		cout << "1. Insert a new record" << endl;
		cout << "2. Insert a batch of records" << endl;
		cout << "3. Modify an excisting record" << endl;
		cout << "4. Delete an excisting record" << endl;
		cout << "5. Search for a record" << endl;
		cout << "6. Print all entries" << endl;
		cout << "" << endl;
		cout << "------------------------------------------" << endl;
		cout << "Please choose:" << endl;
		cin >> input;
	} while (input > 6 || input < 1);
	return input;
}
int Page(int x, SinglyList t1) {
	while (x < 6 || x>0) {
		switch (x)
		{
		case 1: {
			int choice1;
			cout << "         Electronic Address Book         " << endl;
			cout << "=========================================" << endl;
			cout << "" << endl;
			cout << "1. Insert a new record" << endl;
			cout << "2. Homepage" << endl;
			cout << "--" << endl;
			cout << "Please enter:" << endl;
			cin >> choice1;
			if (choice1 == 1) {
				t1.inputNewData();

			}
			else if (choice1 == 2) {
				return homepage();
			}
			system("pause");
			break;
		}
		case 2: {
			int choice2;
			cout << "         Electronic Address Book         " << endl;
			cout << "=========================================" << endl;
			cout << "" << endl;
			cout << "1. Insert a branch of record" << endl;
			cout << "2. Homepage" << endl;
			cout << "--" << endl;
			cin >> choice2;
			if (choice2 == 1) {
				t1.inputNewData();
			}
			else if (choice2 == 2) {
				return homepage();
			}
			system("cls");
			system("pause");
			break;
		}
		case 3: {
			int choice3;
			cout << "         Electronic Address Book         " << endl;
			cout << "=========================================" << endl;
			cout << "" << endl;
			cout << "1. Modify an excisting record" << endl;
			cout << "2. Homepage" << endl;
			cout << "--" << endl;
			cin >> choice3;
			if (choice3 == 1) {
				t1.modifyAddressData();
			}
			else if (choice3 == 2) {
				return homepage();
			}
			system("cls");
			system("pause");
			break;
		}
		case 4: {
			int choice4;
			cout << "         Electronic Address Book         " << endl;
			cout << "=========================================" << endl;
			cout << "" << endl;
			cout << "1. Delete an excisting record" << endl;
			cout << "2. Homepage" << endl;
			cout << "--" << endl;
			cin >> choice4;
			if (choice4 == 1) {
				t1.deleteAddressData();


			}
			else if (choice4 == 2) {
				return homepage();
			}
			system("cls");
			system("pause");
			break;
		}
		case 5: {
			int choice5;
			cout << "         Electronic Address Book         " << endl;
			cout << "=========================================" << endl;
			cout << "" << endl;
			cout << "1. Search for a record" << endl;
			cout << "2. Homepage" << endl;
			cout << "--" << endl;
			cin >> choice5;
			if (choice5 == 1) {
				t1.searchAddressData();
			}
			else if (choice5 == 2) {
				return homepage();
			}
			system("cls");
			system("pause");
			break;
		}
		case 6: {
			int choice6;
			cout << "         Electronic Address Book         " << endl;
			cout << "=========================================" << endl;
			cout << "" << endl;
			cout << "1. Print all entries" << endl;
			cout << "2. Homepage" << endl;
			cout << "--" << endl;
			cin >> choice6;
			if (choice6 == 1) {
				t1.displayAllList();
			}
			else if (choice6 == 2) {
				return homepage();
			}
			system("cls");
			system("pause");
			break;
		}
				return 0;
				if (x > 6 || x < 0) {
					cout << "Wrong input number!" << endl;
				}
				return 0;
		}
	}
}
/*
int main() {
	SinglyList t1;
	int option;
	do {
		read();
		option = homepage();
		system("cls");
		Page(option, t1);
		system("cls");
		homepage();
		Page(option, t1);
		system("cls");
	} while (!option);
	system("pause");
	return 0;
}*/


void insertRecord(SinglyList t1){
    int choice;
    do{

        cout << "         Electronic Address Book         " << endl;
        cout << "=========================================" << endl;
        cout << "" << endl;
        cout << "1. Insert a new record" << endl;
        cout << "2. Homepage" << endl;
        cout << "--" << endl;
        cout << "Please enter:" << endl;
        cin >> choice;
        if (choice == 1) {
            t1.inputNewData();
        }else{
            cout << "invalid option" << endl;
        }
    }while(choice !=2);
}

void printRecord(SinglyList t1){
    int choice;
    do{
        cout << "         Electronic Address Book         " << endl;
        cout << "=========================================" << endl;
        cout << "" << endl;
        cout << "1. Print all entries" << endl;
        cout << "2. Homepage" << endl;
        cout << "--" << endl;
        cin >> choice;
        if (choice == 1) {
            t1.displayAllList();
        }else{
            cout << "invalid option" << endl;
        }
    }while(choice !=2);
}

int main(){
    int input;
    SinglyList t1;
    read();
    do{
        cout << "" << endl;
        cout << "         Electronic Address Book         " << endl;
        cout << "=========================================" << endl;
        cout << " " << endl;
        cout << "1. Insert a new record" << endl;
        cout << "2. Insert a batch of records" << endl;
        cout << "3. Modify an excisting record" << endl;
        cout << "4. Delete an excisting record" << endl;
        cout << "5. Search for a record" << endl;
        cout << "6. Print all entries" << endl;
        cout << "7. exit" << endl;
        cout << "" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please choose:" << endl;
        cin >> input;
        switch (input){
            case 1:
                insertRecord(t1);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printRecord(t1);
                break;
            default:
                break;

        }
    }while(input != 7);
    return 0;
}
