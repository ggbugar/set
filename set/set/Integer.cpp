#include "Integer.h"

Integer::Integer()
{
	integer = 0;
}

Integer::Integer(int i)
{
	integer = i;
}

Integer::Integer(const Integer& I)
{
	integer = I.getInteger;
}

Integer& Integer::operator=(Integer& I)
{
	this->integer = I.getInteger();
}

bool Integer::operator==(Integer I)
{
	if (this->integer == I.getInteger())
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

int Integer::getInteger()
{
	return this->integer;
}

Integer::~Integer()
{

}
