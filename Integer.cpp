#include "Integer.h"

Integer::Integer()
{
	integer = 0;
}

Integer::Integer(int i)
{
	integer = i;
}

Integer::Integer(Integer& I)
{
	integer = I.getInteger();
}

Integer& Integer::operator=(Integer& I)
{
	this->integer = I.getInteger();
	return *this;
}

Integer& Integer::operator=(int i)
{
	this->integer = i;
	return *this;
}

bool Integer::operator==(Integer I)
{
	if (this->integer == I.getInteger())
		return true;
	else
		return false;
}

bool Integer::operator==(int i)
{
	if (this->integer == i)
		return true;
	else
		return false;
}

bool Integer::operator!=(Integer I)
{
	if (this->integer == I.getInteger())
		return false;
	else
		return true;
}

bool Integer::operator>(Integer I)
{
	if (this->integer > I.getInteger())
		return true;
	else
		return false;
}

bool Integer::operator>=(Integer I)
{
	if (this->integer >= I.getInteger())
		return true;
	else
		return false;
}

bool Integer::operator<(Integer I)
{
	if (this->integer < I.getInteger())
		return true;
	else
		return false;
}

bool Integer::operator<=(Integer I)
{
	if (this->integer <= I.getInteger())
		return true;
	else
		return false;
}

ostream& operator << (ostream& os, Integer& I)
{
	os << I.getInteger();
	return os;
}

int Integer::getInteger()
{
	return this->integer;
}

Integer::~Integer()
{

}





