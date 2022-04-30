#include "set.h"



int main(){

	int array[10] = { 1, 2, 3, 4, 5, 67, 8, 9, 10 };
	set<int> s(array, 10);
	s.sortAsc();
	s.viewSetElem();

	s.sortDsc();
	s.viewSetElem();
	
	
	return 0;

	
}