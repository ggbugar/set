//#include "set.h"
////functions test
//void main(){
	//cout << "functions test:" << endl;
	////set();//constructor with no parameter
	//set<int> s1;
	//cout << "s1:"; s1.viewSetElem();
	////set(T data[], int n);//construct set with a array
	//int arr[12] = { 1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9, 10 };
	//set<int> s2(arr, 12);
	//cout << "s2:"; s2.viewSetElem();
	////set(const set& s);//copy constructor
	//set<int> s3(s2);
	//cout << "s3:"; s3.viewSetElem();
	////set& operator=(const set& s);
	//set<int>s4 = s1;
	//cout << "s4:"; s4.viewSetElem();
	////bool operator==(set s);
	//if (s2 == s1)//false
	//cout << "s2==s1" << endl;
	//else
	//cout << "s2!=s1" << endl;
	//if (s2 == s3)//true
	//cout << "s2==s3" << endl;
	//else
	//cout << "s2!=s3" << endl;
	////bool equals(set<T> s);//equal the operator ==
	//if (s2.equals(s1))//false
	//cout << "s2 equals s1" << endl;
	//else
	//cout << "s2 does not equal s1" << endl;
	//if (s2.equals(s3))//true
	//cout << "s2 equals s3" << endl;
	//else
	//cout << "s2 does not equal s3" << endl;
	////bool isEmpty();//judge weather the set is a empty set
	//if (s1.isEmpty())//true
	//cout << "s1 is a empty set." << endl;
	//else
	//cout << "s1 is not empty." << endl;
	//if (s2.isEmpty())//false
	//cout << "s2 is a empty set." << endl;
	//else
	//cout << "s2 is not empty." << endl;
	////bool clearSet();//clear the set,left empty set.
	//s2.clearSet();
	//if (s2.isEmpty())//false
	//cout << "s2 is a empty set." << endl;
	//else
	//cout << "s2 isn't a empty set." << endl;
	////int size();//return the number of elements in the set
	//cout << "s3 has " << s3.size() << " elements" << endl;
	////T getElem(int i);//return the no.i element
	//cout << "s3:";
	//for (int i = 1; i <= s3.size(); i++)
	//{
	//	cout << s3.getElem(i) << " ";
	//}
	//cout << endl;
	////T getFirst();get the first element of the set
	////T getLast();get the last element of the set
	//cout << "s3:";
	//cout << "s3.getFirst():" << s3.getFirst() << endl;
	//cout << "s3:";
	//cout << "s3.getLast():" << s3.getLast() << endl;
	////void viewSetElem();//view set's all elements
	//cout << "s1:"; s1.viewSetElem();
	////bool addElem(T data);//add a element
	//s1.addElem(1);
	//cout << "s1:"; s1.viewSetElem();
	////void addElem(T data[], int n);//add element with a array.
	//s1.addElem(arr, 12);
	//cout << "s1:"; s1.viewSetElem();
	////bool deleteElem(T data);//delete a element
	//s1.deleteElem(1);
	//cout << "s1:"; s1.viewSetElem();
	////T deleteElemByIndex(int index);//delete a element by index
	//s1.deleteElemByIndex(9);
	//cout << "s1:"; s1.viewSetElem();
	////bool searchElem(T data);//check whether the element in the set
	//if (s1.searchElem(5))//true
	//cout << "the 5 is in the set s1" << endl;
	//else
	//cout << "the 5 isn't in the set s1" << endl;
	//if (s1.searchElem(100))//false
	//cout << "the 100 is in the set s1" << endl;
	//else
	//cout << "the 100 isn't in the set s1" << endl;
	////void updateElem(T oldValue, T newValue);//update the set's element
	//cout << "s3:"; s3.viewSetElem();
	//s3.updateElem(1, 100);
	//cout << "s3:"; s3.viewSetElem();
	////void updateElemByIndex(int index, T newValue);//update the no.i element
	//s3.updateElemByIndex(10, 1000);
	//cout << "s3:"; s3.viewSetElem();
	//
	//bool isValidIndex(int index);//judge whether a index is valid or not,the valid index range from 1 to this.size()
	//if (s3.isValidIndex(100))
	//cout << "s3:100 is a valid index for s3" << endl;
	//else
	//cout << "s3:100 is not a valid index for s3" << endl;
	////int indexOf(T e);//return the index of the element e passed in
	//cout << "s3:the index of 9 is:" << s3.indexOf(9) << endl;
	////void erase(int begin, int end);//delete the element between index i and index ,j:[i,j] which will delete j-i+1 elements 
	//s3.erase(1, 3);
	//cout << "s3:"; s3.viewSetElem();
	////void eraseNElem(int begin, int n);//delete n elements from begin to begin+n;[begin,begin+n)
	//s3.eraseNElem(3, 3);
	//cout << "s3:"; s3.viewSetElem();
	////void eraseFirst();//delete the head element of the set
	//s3.eraseFirst();
	//cout << "s3:"; s3.viewSetElem();
	////void eraseLast();//delete the last element of the set
	//s3.eraseLast();
	//cout << "s3:"; s3.viewSetElem();
	//
	//int ano_arr[15] = { 1, -7, 100, 45, 23, 666, 3, 77, 9, 2, 34, 6, 89, -23, 65 };
	//set<int> s5(ano_arr, 15);
	//cout << "s5:"; s5.viewSetElem();
	//
	////T getMaxElem();//return the biggest one
	////T getMinElem();//return the smallest one
	//cout << "max element of s5 is:" << s5.getMaxElem() << endl;
	//cout << "min element of s5 is:" << s5.getMinElem() << endl;
	////bool sortAsc();//sort the set in ascending order
	//s5.sortAsc();
	//cout << "s5 sorted by ascending order:"; s5.viewSetElem();
	////T* toArray();//converse the set into a array,return the array
	//int* toarr = s5.toArray();
	//cout << "toarr:";
	//for (int i = 0; i < s5.size(); i++)
	//{
	//	cout << toarr[i] << " ";
	//}
	//cout << endl;
	////bool sortDsc();//sort the set in descending order
	//s5.sortDsc();
	//cout << "s5 sorted by descending order:"; s5.viewSetElem();
	////void toArray(T* arr);//converse the set into a array,copy it to the arr.
	//s5.toArray(toarr);
	//cout << "toarr:";
	//for (int i = 0; i < s5.size(); i++)
	//{
	//	cout << toarr[i] << " ";
	//}
	//cout << endl;
	////define some set to test set operations functions
	//int u[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//set<int> U(u, 10);
	//cout << "U:"; U.viewSetElem();
	//int a[7] = { 1, 3, 4, 6, 7, 8, 9 };
	//set<int> A(a, 7);
	//cout << "A:"; A.viewSetElem();
	//int b[6] = { 1, 2, 3, 4, 5, 6 };
	//set<int> B(b, 6);
	//cout << "B:"; B.viewSetElem();
	//set<int> C;
	//cout << "C:"; C.viewSetElem();
	////bool contains(T e);
	//if (A.contains(2))
	//cout << "A contains 2" << endl;
	//else
	//cout << "A does not contain 2" << endl;
	////bool belongsTo(set<T> s);
	//if (B.belongsTo(U))//true
	//cout << "B belongs to U." << endl;
	//else
	//cout << "B does not belong to U." << endl;
	//if (B.belongsTo(A))//false
	//cout << "B belongs to A." << endl;
	//else
	//cout << "B does not belong to A." << endl;
	////friend void intersectionSet(set<T> a, set<T> b, set<T>& c);//intersection:c = a ^ b
	//intersectionSet<int>(A, B, C);
	//cout << "the intersection set of A and B:"; C.viewSetElem();
	////extern friend void unionSet(set<T> a, set<T> b, set<T>& c);//union set:c = a U b
	//unionSet<int>(A, B, C);
	//cout << "the union set of A and B:"; C.viewSetElem();
	////extern friend void diffSet(set<T> a, set<T> b, set<T>& c);//Difference set:c = a - b
	//diffSet<int>(A, B, C);
	//cout << "the difference set of A and B(A-B):"; C.viewSetElem();
	//diffSet<int>(B, A, C);
	//cout << "the difference set of B and A(B-A):"; C.viewSetElem();
	////extern friend void complementSet(set<T> u, set<T> s, set<T>& c);//Difference set:c = U - s
	//complementSet<int>(U, A, C);
	//cout << "the complement of A with respect to U:"; C.viewSetElem();
	//complementSet<int>(U, B, C);
	//cout << "the complement of B with respect to U:"; C.viewSetElem();
//
//}