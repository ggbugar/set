#pragma once
#include <iostream>
using namespace std;
class Integer
{
public:
	Integer();
	Integer(int i);
	Integer(Integer& I);
	Integer& operator=(Integer& I);
	Integer& operator=(int i);
	bool operator==(Integer I);
	bool operator==(int i);
	bool operator!=(Integer I);
	bool operator>(Integer I);
	bool operator>=(Integer I);
	bool operator<(Integer I);
	bool operator<=(Integer I);

	friend ostream& operator << (ostream& os, Integer& I);

	int getInteger();
	~Integer();

private:
	int integer;
};

