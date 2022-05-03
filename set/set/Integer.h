#pragma once
class Integer
{
public:
	Integer();
	Integer(int i);
	Integer(const Integer& I);
	Integer& operator=(Integer& I);
	bool operator==(Integer I);
	bool operator!=(Integer I);
	bool operator>(Integer I);
	bool operator>=(Integer I);
	bool operator<(Integer I);
	bool operator<=(Integer I);
	int getInteger();
	~Integer();

private:
	int integer;
};

