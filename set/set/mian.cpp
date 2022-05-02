#include "set.h"

int main(){

	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	set<int> s(array, 10);
	s.viewSetElem();

	set<int> s2(s);
	s2.deleteElemByIndex(1);
	s2.deleteElem(2);
	s2.viewSetElem();


	/*s.sortAsc();
	s.viewSetElem();

	s.sortDsc();
	s.viewSetElem();

	s.addElem(100);
	s.viewSetElem();

	s.deleteElem(100);
	s.viewSetElem();

	s.deleteElemByIndex(3);
	s.viewSetElem();

	set<int> s1(s);
	s.viewSetElem();

	set<int> s2 = s1;
	s2.viewSetElem();

	s2.clearSet();
	s2.viewSetElem();

	cout<<s1.length()<<endl;
	cout << s.getElem(1) << endl;
	cout << s.getMaxElem() << endl;
	cout << s.getMinElem() << endl;*/

	/*int *a;
	a = s.toArray();

	set<int> s3(a, 10);
	s3.viewSetElem();
	if (s3.equals(s))
	{
	cout << "s3 equals s" << endl;
	}
	if (s2 == s)
	{
	cout << "s2 equals s";
	}
	else
	{
	cout << "s2 do not equals s" << endl;
	}


	if (s2.belongsTo(s))
	{
	cout << "s2 belongs to s,s2 is a subset of s." << endl;
	}
	else
	{
	cout << "s2 does not belong to s" << endl;
	}


	set<int> c;
	IntersectionSet<int>(s, s2, c);
	c.viewSetElem();

	unionSet<int>(s, s2, c);
	c.viewSetElem();

	s2.addElem(100);
	diffSet<int>(s, s2, c);
	c.viewSetElem();

	s.addElem(100);
	complementSet<int>(s, s2, c);
	c.viewSetElem();*/





	return 0;
}