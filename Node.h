#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class AddressNode
{
public:
	int LineNum;// the index number, but difficult to use
	string Title;
	string Surname;
	string GivenName;
	string Gender;
	string Birthday;
	string StreetAddress;
	string City;
	string StateFull;
	string ZipCode;
	string CountryFull;
	string TelephotoCountryCode;
	string TelephotoNumber;
	string EmailAddress;
	string Occupation;
	string Company;

	AddressNode* next;
};
#endif#pragma once
