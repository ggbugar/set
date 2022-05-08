#pragma once
#include <stdbool.h>
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T> *next;
};

template <typename T>
class set
{
private:
	Node<T> *first;//the head of the list.	
public:
	set();//constructor with no parameter
	set(T data[], int n);//construct set with a array
	set(const set& s);//copy constructor
	set& operator=(const set& s)
	{	//overload the = operator
		if (first->next!=NULL)
		{
			this->clearSet();
		}

		first = new Node<T>;
		first->next = NULL;
		if (!(s.first->next))//if s is a empty set.
		{
			first->next = NULL;
		}
		else
		{
			Node<T> *stemp = s.first;
			while (stemp->next)
			{
				stemp = stemp->next;
				Node<T> *temp = new Node<T>;
				temp->data = stemp->data;
				temp->next = NULL;
				if (first->next == NULL)
				{
					first->next = temp;
				}
				else
				{
					temp->next = first->next;//head insert
					first->next = temp;
				}
			}
		}
		return *this;
	}
	bool operator==(set s)
	{	//overload the = operator
		if (this->length() != s.length())
			return false;

		Node<T> *temp = this->first;
		Node<T> *stemp = s.first;
		while (temp->next)
		{
			temp = temp->next;
			stemp = s.first;
			while (stemp->next)
			{
				stemp = stemp->next;
				if (temp->data == stemp->data)
					break;
			}
			if (temp->data != stemp->data)
				return false;
		}
		return true;
	}
	bool equals(set<T> s);//equal the operator ==
	~set();//destructor
	Node<T>* getFirst();//get the first node 
	void setFirst(Node<T>* head);//set the first node
	
	//basic operations
	bool clearSet();//clear the set,left empty set.
	bool isEmpty();//judge weather the set is a empty set
	int length();//return the number of elements in the set
	void viewSetElem();//view set's all elements
	T getElem(int i);//return the no.i element

	//add delete search update
	bool addElem(T data);//add a element
	void addElem(T data[], int n);//add element with a array.
	bool deleteElem(T data);//delete a element
	void deleteElemByIndex(int index);//delete a element by index
	bool searchElem(T data);//check whether the element in the set
	void updateElem(T oldValue, T newValue);//update the set's element
	void updateElemByIndex(int index, T newValue);//update the no.i element

	//additional operations
	void erase(int begin, int end);//delete the element between index i and index ,j:[i,j] which will delete j-i+1 elements 
	void eraseNElem(int begin, int n);//delete n elements from begin to begin+n;[begin,begin+n)
	void eraseFirst();//delete the first element of the set
	void eraseLast();//delete the last element of the set
	T getMaxElem();//return the biggest one
	T getMinElem();//return the smallest one
	bool sortAsc();//sort the set in ascending order
	bool sortDsc();//sort the set in descending order
	T* toArray();//converse the set into a array,return the array
	void toArray(T* arr);//converse the set into a array,copy it to the arr.

	//set operations:
	//belong to
	bool belongsTo(set<T> s);//"belongs to" ;a subset of
	//intersection set of a set
	friend void IntersectionSet(set<T> a, set<T> b, set<T>& c);//intersection:c = a ^ b
	//union set of a set
	extern friend void unionSet(set<T> a, set<T> b, set<T>& c);//union set:c = a U b
	//intersection set of a set
	extern friend void diffSet(set<T> a, set<T> b, set<T>& c);//Difference set:c = a - b
	//complement set of a set
	extern friend void complementSet(set<T> u, set<T> s, set<T>& c);//Difference set:c = U - s
	
};

template <typename T>
Node<T>* set<T>::getFirst()
{
	if (first)
		return first;
	else
		return NULL;
}

template <typename T>
void set<T>::setFirst(Node<T>* head)
{
	Node<T>* temp = first;
	first = head;
	delete temp;
}

template <typename T>
set<T>::set(){
	//create a empty set
	first = new Node<T>;
	first->next = NULL;
}

template <typename T>
set<T>::set(T data[], int n)
{	//data[]:data array.
	//n:the number of elements in the array.
	//pass a array(data) and the array's length(n) to create a set. 
	//the set will automatically check repeat elements.
	first = new Node<T>;//init the head node.
	first->next = NULL;
	bool checkRepeat = false;
	Node<T>* check;
	for (int i = 0; i < n; i++)
	{
		//check weather there has repeated element.
		checkRepeat = false;
		check = first;
		while (check->next)
		{
			check = check->next;
			if (data[i]==check->data)
			{
				checkRepeat = true;
				break;
			}
		}
		if (checkRepeat)
		{
			checkRepeat = false;
			continue;
		}
		//add non-repetitive element to the list
		Node<T>* temp = new Node<T>;
		temp->next = NULL;
		temp->data = data[i];

		if (first->next == NULL)
		{
			first->next = temp;
		}
		else
		{
			temp->next = first->next;
			first->next = temp;
		}
	}
}

template <typename T>
set<T>::set(const set& s)
{	//copy constructor
	//copy a set to init the new set
	first = new Node<T>;
	first->next = NULL;
	if (!(s.first->next))//if the set to be copied is empty
	{
		first->next = NULL;
	}
	else
	{
		Node<T> *stemp = s.first;
		while (stemp->next)
		{
			stemp = stemp->next;
			Node<T> *temp = new Node<T>;
			temp->data = stemp->data;
			temp->next = NULL;//set the end of pointer field NULL.
			if (first->next == NULL)
			{
				first->next = temp;
			}
			else
			{
				temp->next = first->next;//head insert
				first->next = temp;
			}
		}
	}
}

template <typename T>
bool set<T>::equals(set<T> s)
{	//Compares whether two sets are equal.yes return true,else return false.

	if (this->length() != s.length())
		return false;

	Node<T> *temp = this->first;
	Node<T> *stemp = s.first;
	//for each element of this set,find the same element in s,if not return false,else continue.
	while (temp->next)
	{
		temp = temp->next;
		stemp = s.first;
		while (stemp->next)
		{
			stemp = stemp->next;
			if (temp->data == stemp->data)
				break;
		}
		if (temp->data != stemp->data)
			return false;
	}
	return true;
}

template <typename T>
set<T>::~set()
{	//the destructor 
	//free memories.
	Node<T> *temp;
	while (first->next)
	{
		temp = first->next;
		first->next = temp->next;
		delete temp;
	}
	delete first;
}

template <typename T>
bool set<T>::clearSet()
{	//clear the set,make it a empty set
	//if clear the set successfully return true,else return false
	if (this->isEmpty())
		return true;
	Node<T>* temp;
	while (first->next)
	{
		temp = first->next;
		first->next = temp->next;
		delete temp;
	}
	if (first->next == NULL)
		return true;
	else
		return false;
}

template <typename T>
bool set<T>::isEmpty()
{	//judge whether the set is empty.
	//if the set is a empty set return true,else return false.
	if (this->first->next == NULL)
		return true;
	else
		return false;
}

template <typename T>
int set<T>::length()
{	//count how many elements in the set.
	//return the number:count
	int count = 0;
	Node<T>* temp;
	temp = first->next;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

template <typename T>
void set<T>::viewSetElem()
{	//this function is used for viewing the set's element.
	//I use it to test my functions.
	//this requires the << overloaded.
	if (this->isEmpty())
	{
		cout << "the set is empty." << endl;
		return;
	}
	Node<T> *temp = first;
	while (temp->next != NULL)
	{
		temp = temp->next;
		cout << temp->data << " ";
	}
	cout << endl;
}

template <typename T>
T set<T>::getElem(int i)
{	//i:the index of element you want to get.
	//get the element's value by passing the index of the element.
	//return the value of element at position i.

	//check weather the i passed in is legal.
	if (i<1 || i>this->length())
		exit(0);
	Node<T>* temp = first;
	while (i > 0)
	{
		temp = temp->next;
		i--;
	}
	return temp->data;
}

template <typename T>
bool set<T>::addElem(T data)
{	//data:the element which you are going to add to the set.
	//if add the data successfully return true,else return false.
	//check if there is repeated element.
	if (this->searchElem(data))
		return true;
	//create a new node to storage the data.
	Node<T> *temp = new Node<T>;
	temp->data = data;
	//add the node to set.
	temp->next = first->next;
	this->first->next = temp;
	return true;
}

template <typename T>
void set<T>::addElem(T data[], int n)
{	//add elements to the set with a set.
	for (int i = 0; i < n; i++)
	{
		//remove duplicate elements
		if (this->searchElem(data[i]))
			continue;
		//add non-repetitive element to the list
		Node<T>* temp = new Node<T>;
		temp->next = NULL;
		temp->data = data[i];

		if (first->next == NULL)
		{
			first->next = temp;
		}
		else
		{
			temp->next = first->next;
			first->next = temp;
		}
	}
}

template <typename T>
bool set<T>::deleteElem(T data)
{	//delete element
	//pass the element data to be deleted
	//if the set is empty or the set do not contain the element or delete the element return true,else return fasle.
	if (this->isEmpty())
		return true;
	if (!(this->searchElem(data)))
		return true;

	Node<T> *temp = first;
	while (temp->next)
	{
		if (data == temp->next->data)
			break;
		temp = temp->next;
	}
	Node<T> *t = temp->next;
	temp->next = t->next;
	delete t;
	if (!this->searchElem(data))
		return true;
	else
		return false;
	
}

template <typename T>
void set<T>::deleteElemByIndex(int index)
{	//pass the index to delete the element in the position.
	if (index<1 || index>this->length())
		exit(0);
	if (this->isEmpty())
		return;

	Node<T> *temp = first;
	while (--index != 0)
	{
		temp = temp->next;
	}
	Node<T> *t = temp->next;
	temp->next = t->next;
	delete t;
}

template <typename T>
bool set<T>::searchElem(T data)
{	//judge if the data in the set.
	//if yes return true,else return false.
	if (isEmpty())
		return false;
	Node<T> *temp = first;
	while (temp->next)
	{
		temp = temp->next;
		if (data == temp->data)
			return true;
	}
	return false;
}

template <typename T>
void set<T>::updateElem(T oldValue, T newValue)
{	//update the set's element.
	if (this->isEmpty())
		return;
	Node<T> *temp = first->next;
	while (oldValue != temp->data&&temp->next != NULL)
	{
		temp = temp->next;
	}
	if (oldValue == temp->data)
	{
		temp->data = newValue;
	}
	else if (oldValue != temp->data)//oldValue not exist
	{
		return;
	}
}

template <typename T>
void set<T>::updateElemByIndex(int index, T newValue)
{	//update the element at position index
	if (index<1 || index>this->length())//Index Out of Bounds
		return;
	if (this->isEmpty())//
		return;
	Node<T> *temp = first;
	do
	{
		temp = temp->next;
		index--;
	} while (index != 0);
	temp->data = newValue;
}

template <typename T>
void set<T>::erase(int begin, int end)
{	//delete the element int [begin,end]
	if (begin<1 || begin>this->length() || end<1 || end>this->length())
		return;
	if (end < begin)
		return;
	if (end==begin)
	{
		this->deleteElemByIndex(begin);
		return;
	}
	int count = 0;
	Node<T>* temp = first;
	while (temp->next)
	{
		count++;
		if (count == begin)
			break;
		temp = temp->next;
	}
	while (count++<=end)
	{
		Node<T>* t = temp->next;
		temp->next = t->next;
		delete t;
	}
}

template <typename T>
void set<T>::eraseNElem(int begin, int n)
{	//Delete n elements starting from position index.
	if (begin<1||n>this->length()||begin+n>this->length())
		return;
	int count = 0;
	Node<T>* temp = first;
	while (temp->next)
	{
		count++;
		if (count == begin)
			break;
		temp = temp->next;
	}

	while (count++ <= begin+n-1)
	{
		Node<T>* t = temp->next;
		temp->next = t->next;
		delete t;
	}
}

template <typename T>
void set<T>::eraseFirst()
{	//delete the first element
	if (this->isEmpty())
		return;
	Node<T> *temp = first->next;
	first->next = temp->next;
	delete temp;
}

template <typename T>
void set<T>::eraseLast()
{	//delete the last element
	if (this->isEmpty())
		return;
	Node<T> *temp = first;
	while (temp->next->next)
	{
		temp = temp->next;
	}
	Node<T> *todel = temp->next;
	temp->next = NULL;
	delete todel;
}

template <typename T>
T set<T>::getMaxElem()
{	//return the biggest element of the set.
	//this function requires the operator > for the element overloaded.
	if (this->isEmpty())
		exit(0);
	Node<T> *temp = first->next;
	T max = temp->data;
	while (temp->next)
	{
		temp = temp->next;
		max = max > temp->data ? max : temp->data;
	}
	return max;
}

template <typename T>
T set<T>::getMinElem()
{	//return the smallest element of the set.
	//this function requires the operator > for the element overloaded.
	if (this->isEmpty())
		exit(0);
	Node<T> *temp = first->next;
	T min = temp->data;
	while (temp->next)
	{
		temp = temp->next;
		min = temp->data>min ? min : temp->data;
	}
	return min;
}

template <typename T>
bool set<T>::sortAsc()
{	//sort the set in ascending order
	//this function requires the operator < for the element overloaded.
	if (this->isEmpty())
		exit(0);

	Node<T> *i = first->next;
	while (i&&i->next)
	{
		Node<T> *j = i->next;
		while (j)
		{
			if (j->data < i->data)
			{	//swap
				T temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
	return true;
}

template <typename T>
bool set<T>::sortDsc()
{	//sort the set in descending order
	//this function requires the operator < for the element overloaded.
	if (this->isEmpty())
		exit(0);

	Node<T> *i = first->next;
	while (i&&i->next)
	{
		Node<T> *j = i->next;
		while (j)
		{
			if (i->data < j->data)
			{	//swap
				T temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
	return true;
}

template <typename T>
T* set<T>::toArray()
{	//return a array which storage all the elements in the set.
	if (this->isEmpty())
		return NULL;

	T* array = new T[this->length()];
	Node<T> *temp = this->first->next;
	for (int i = 0; i < this->length(); i++)
	{
		array[i] = temp->data;
		temp = temp->next;
	}
	return array;
}

template <typename T>
void set<T>::toArray(T* arr)
{	//copy the array which storage all the elements in the set to arr.
	if (this->isEmpty())
		return;
	delete[] arr;
	arr = new T[this->length()];
	Node<T> *temp = this->first->next;
	for (int i = 0; i < this->length(); i++)
	{
		arr[i] = temp->data;
		temp = temp->next;
	}
}

template <typename T>
bool set<T>::belongsTo(set<T> s)
{	//represent the relationship of belong to.
	//if the set belongs to s return true,else return false.
	if (this->length() > s.length())
		return false;

	Node<T> *temp = this->first;
	Node<T> *stemp = s.first;
	while (temp->next)
	{
		temp = temp->next;
		stemp = s.first;
		while (stemp->next)
		{
			stemp = stemp->next;
			if (temp->data == stemp->data)
				break;
		}
		if (temp->data != stemp->data)
			return false;
	}
	return true;
}

template <typename T>
void IntersectionSet(set<T> a, set<T> b, set<T>& c)
{	//c=a^b
	//call:Intersection<T>(s,b,c)
	//you must add<T>,the T is the type of the data in the set
	if (a.isEmpty()||b.isEmpty())
	{
		c.clearSet();
		return;
	}
	if (a.equals(b))
	{
		c = a;
		return;
	}

	if (!c.isEmpty())
	{
		c.clearSet();
	}
	Node<T> *temp = a.getFirst();
	while (temp->next)
	{
		temp = temp->next;
		if (b.searchElem(temp->data))
		{
			c.addElem(temp->data);
		}
	}
}

template <typename T>
void unionSet(set<T> a, set<T> b, set<T>& c)
{	//c=a U b
	//call:unionSet<T>(s,b,c)
	//you must add<T>,the T is the type of the data in the set
	if (a.isEmpty()||a.equals(b))
	{
		c = b;
		return;
	}
	if (b.isEmpty())
	{
		c = b;
		return;
	}

	c = a;
	Node<T>* temp = b.getFirst();
	while (temp->next)
	{
		temp = temp->next;
		if (!c.searchElem(temp->data))
		{
			c.addElem(temp->data);
		}
	}
}

template <typename T>
void diffSet(set<T> a, set<T> b, set<T>& c)
{	//c=a -b
	//call:diffSet<T>(a,b,c)
	//you must add<T>,the T is the type of the data in the set
	if (a.isEmpty())
	{
		c.clearSet();
		return;
	}
	if (b.isEmpty())
	{
		c = a;
		return;
	}

	c = a;
	Node<T>* temp = b.getFirst();
	while (temp->next)
	{
		temp = temp->next;
		if (c.searchElem(temp->data))
		{
			c.deleteElem(temp->data);
		}
	}
}

template <typename T>
void complementSet(set<T> u, set<T> s, set<T>& c)
{	//c=u -s
	//call:complementSet<T>(u,s,c)
	//you must add<T>,the T is the type of the data in the set
	//c is the complement of s with respect to u
	if (!s.belongsTo(u)||u.isEmpty())
	{
		exit(0);
	}
	if (s.isEmpty())
	{
		c = u;
		return;
	}
	c = u;
	Node<T>* temp = s.getFirst();
	while (temp->next)
	{
		temp = temp->next;
		if (u.searchElem(temp->data))
		{
			c.deleteElem(temp->data);
		}
	}
}
