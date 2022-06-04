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
	Node<T> *head;//A head node that does not hold data elements	
public:
	set();//constructor with no parameter
	set(T data[], int n);//construct set with a array
	set(const set& s);//copy constructor,you can init a set by copying another set
	set& operator=(const set& s)
	{	//overload the = operator
		if (head->next!=NULL)
		{
			this->clearSet();
		}

		head = new Node<T>;
		head->next = NULL;
		if (!(s.head->next))//if s is a empty set.
		{
			head->next = NULL;
		}
		else
		{
			Node<T> *stemp = s.head;
			while (stemp->next)
			{
				stemp = stemp->next;
				Node<T> *temp = new Node<T>;
				temp->data = stemp->data;
				temp->next = NULL;
				if (head->next == NULL)
				{
					head->next = temp;
				}
				else
				{
					temp->next = head->next;//head insert
					head->next = temp;
				}
			}
		}
		return *this;
	}
	bool operator==(set s)
	{	//overload the = operator
		if (this->size() != s.size())
			return false;

		Node<T> *temp = this->head;
		Node<T> *stemp = s.head;
		while (temp->next)
		{
			temp = temp->next;
			stemp = s.head;
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
	Node<T>* getHead();//get the head node 
	void setHead(Node<T>* head);//set the head node
	//basic operations
	bool clearSet();//clear the set,left empty set.
	bool isEmpty();//judge weather the set is a empty set
	int size();//return the number of elements in the set
	void viewSetElem();//view set's all elements
	T getElem(int i);//return the no.i element
	T getFirst();//get the first element of the set
	T getLast();//get the last element of the set
	
	//add delete search update
	bool addElem(T data);//add a element
	void addElem(T data[], int n);//add element with a array.
	bool deleteElem(T data);//delete a element
	T deleteElemByIndex(int index);//delete a element by index,return the element deleted
	bool searchElem(T data);//check whether the element in the set
	void updateElem(T oldValue, T newValue);//update the set's element
	void updateElemByIndex(int index, T newValue);//update the no.i element

	//additional operations
	bool isValidIndex(int index);//judge whether a index is valid or not,the valid index range from 1 to this.size()
	int indexOf(T e);//return the index of the element e passed in
	void erase(int begin, int end);//delete the element between index i and index ,j:[i,j] which will delete j-i+1 elements 
	void eraseNElem(int begin, int n);//delete n elements from begin to begin+n;[begin,begin+n)
	void eraseFirst();//delete the head element of the set
	void eraseLast();//delete the last element of the set
	T getMaxElem();//return the biggest one
	T getMinElem();//return the smallest one
	bool sortAsc();//sort the set in ascending order
	bool sortDsc();//sort the set in descending order
	T* toArray();//converse the set into a array,return the array
	void toArray(T* arr);//converse the set into a array,copy it to the arr.
	
	//set operations:
	//contains,equals searchElem(T data)
	bool contains(T e);//the relationship of "U contains e,e belongs to U"
	//belong to
	bool belongsTo(set<T> s);//"belongs to" ;a subset of
	//intersection set of a set
	friend void intersectionSet(set<T> a, set<T> b, set<T>& c);//intersection:c = a ^ b
	//union set of a set
	extern friend void unionSet(set<T> a, set<T> b, set<T>& c);//union set:c = a U b
	//intersection set of a set
	extern friend void diffSet(set<T> a, set<T> b, set<T>& c);//Difference set:c = a - b
	//complement set of a set
	extern friend void complementSet(set<T> u, set<T> s, set<T>& c);//Difference set:c = U - s
	
};

template <typename T>
Node<T>* set<T>::getHead(){
	//return the set's head pointer
	if (head)
		return head;
	else
		return NULL;
}

template <typename T>
void set<T>::setHead(Node<T>* head){
	//set the set's head pointer
	Node<T>* temp = head;
	head = head;
	delete temp;
}

template <typename T>
set<T>::set(){
	//create a empty set
	head = new Node<T>;
	head->next = NULL;
}

template <typename T>
set<T>::set(T data[], int n)
{	//data[]:data array.
	//n:the number of elements in the array.
	//pass a array(data) and the array's size(n) to create a set. 
	//the set will automatically check repeat elements.
	head = new Node<T>;//init the head node.
	head->next = NULL;
	bool checkRepeat = false;
	Node<T>* check;
	for (int i = 0; i < n; i++){
		//check weather there has repeated element.
		checkRepeat = false;
		check = head;
		while (check->next){
			check = check->next;
			if (data[i]==check->data){
				checkRepeat = true;
				break;
			}
		}
		if (checkRepeat){
			checkRepeat = false;
			continue;
		}
		//add non-repetitive element to the list
		Node<T>* temp = new Node<T>;
		temp->next = NULL;
		temp->data = data[i];

		if (head->next == NULL){
			head->next = temp;
		}
		else{
			temp->next = head->next;
			head->next = temp;
		}
	}
}

template <typename T>
set<T>::set(const set& s)
{	//copy constructor
	//copy a set to init the new set
	head = new Node<T>;
	head->next = NULL;
	if (!(s.head->next)){//if the set to be copied is empty
		head->next = NULL;
	}
	else
	{
		Node<T> *stemp = s.head;
		while (stemp->next)
		{
			stemp = stemp->next;
			Node<T> *temp = new Node<T>;
			temp->data = stemp->data;
			temp->next = NULL;//set the end of pointer field NULL.
			if (head->next == NULL){
				head->next = temp;
			}
			else{
				temp->next = head->next;//head insert
				head->next = temp;
			}
		}
	}
}

template <typename T>
bool set<T>::equals(set<T> s){	
	//Compares whether two sets are equal.if yes return true,else return false.
	if (this->size() != s.size())
		return false;
	//create temp pointer
	Node<T> *temp = this->head;
	Node<T> *stemp = s.head;
	//for each element of this set,find the same element in s,if not return false,else continue.
	while (temp->next){
		temp = temp->next;
		stemp = s.head;
		while (stemp->next){
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
set<T>::~set(){	
	//the destructor 
	//free memories.
	Node<T> *temp;
	while (head->next){
		temp = head->next;
		head->next = temp->next;
		delete temp;
	}
	delete head;
}

template <typename T>
bool set<T>::clearSet()
{	//clear the set,make it an empty set
	//if clear the set successfully return true,else return false
	if (this->isEmpty())
		return true;
	Node<T>* temp;
	while (head->next){
		temp = head->next;
		head->next = temp->next;
		delete temp;
	}
	if (head->next == NULL)
		return true;
	else
		return false;
}

template <typename T>
bool set<T>::isEmpty()
{	//judge whether the set is empty.
	//if the set is a empty set return true,else return false.
	if (this->head->next == NULL)
		return true;
	else
		return false;
}

template <typename T>
int set<T>::size()
{	//count how many elements in the set.
	//return the number:count
	int count = 0;
	Node<T>* temp;
	temp = head->next;
	while (temp){
		count++;
		temp = temp->next;
	}
	return count;
}

template <typename T>
void set<T>::viewSetElem(){	
	//this function is used for viewing the set's element.
	//I use it to test all the functions.
	//this requires the stream operator << overloaded.
	if (this->isEmpty()){
		cout << "the set is empty." << endl;
		return;
	}
	Node<T> *temp = head;
	while (temp->next != NULL){
		temp = temp->next;
		cout << temp->data << " ";
	}
	cout << endl;
}

template <typename T>
T set<T>::getElem(int i){	
	//i:the index of element you want to get,range from 1 to this.size()
	//get the element's value by passing the index of the element.
	//return the value of element at position i.

	//check weather the i passed in is legal.
	if (i<1 || i>this->size())
		exit(0);
	Node<T>* temp = head;
	while (i > 0){
		temp = temp->next;
		i--;
	}
	return temp->data;
}

template <typename T>
T set<T>::getFirst(){
	//get the first element of the set
	if (head->next){
		return head->next->data;
	}
	else{
		return NULL;
	}
}

template <typename T>
T set<T>::getLast(){
	//get the last element of the set
	Node<T> *temp = head;
	if (temp->next){
		while (temp->next){
			temp = temp->next;
		}
		return temp->data;
	}
	return NULL;
}

template <typename T>
bool set<T>::addElem(T data){	
	//data:the element which you are going to add to the set.
	//if add the data successfully return true,else return false.
	//check if there is repeated element.
	if (this->searchElem(data))
		return true;
	//create a new node to storage the data.
	Node<T> *temp = new Node<T>;
	temp->data = data;
	//add the node to set.
	temp->next = head->next;
	this->head->next = temp;
	return true;
}

template <typename T>
void set<T>::addElem(T data[], int n)
{	//add elements to the set with a array.
	for (int i = 0; i < n; i++){
		//remove duplicate elements
		if (this->searchElem(data[i]))
			continue;
		//add non-repetitive element to the list
		Node<T>* temp = new Node<T>;
		temp->next = NULL;
		temp->data = data[i];
		//insert elements
		if (head->next == NULL){
			head->next = temp;
		}
		else{
			temp->next = head->next;
			head->next = temp;
		}
	}
}

template <typename T>
bool set<T>::deleteElem(T data){	
	//delete element
	//pass the element data to be deleted
	//if the set is empty or the set do not contain the element or delete the element return true,else return fasle.
	if (this->isEmpty())
		return true;
	if (!(this->searchElem(data)))
		return true;
	//find the element's previous node temp
	Node<T> *temp = head;
	while (temp->next){
		if (data == temp->next->data)
			break;
		temp = temp->next;
	}
	//delete the element
	Node<T> *t = temp->next;
	temp->next = t->next;
	delete t;
	if (!this->searchElem(data))
		return true;
	else
		return false;
}

template <typename T>
T set<T>::deleteElemByIndex(int index)
{	//pass the index to delete the element in the position.
	//the index range from 1 to this.size()
	//return the element deleted
	if (index<1 || index>this->size())
		exit(0);
	if (this->isEmpty())
		return NULL;
	//find the element's previous node
	Node<T> *temp = head;
	while (--index != 0){
		temp = temp->next;
	}
	//get the data
	T data = temp->next->data;
	//delete the element node
	Node<T> *t = temp->next;
	temp->next = t->next;
	delete t;
	return data;
}

template <typename T>
bool set<T>::searchElem(T data){	
	//judge whether the data in the set or not.
	//if yes return true,else return false.
	if (isEmpty())
		return false;
	Node<T> *temp = head;
	while (temp->next){
		temp = temp->next;
		if (data == temp->data)
			return true;
	}
	return false;
}

template <typename T>
void set<T>::updateElem(T oldValue, T newValue){	
	//update the set's element.
	if (this->isEmpty())
		return;
	Node<T> *temp = head->next;
	while (oldValue != temp->data&&temp->next != NULL){
		temp = temp->next;
	}
	if (oldValue == temp->data){
		temp->data = newValue;
	}
	else if (oldValue != temp->data){//oldValue not exist
		return;
	}
}

template <typename T>
void set<T>::updateElemByIndex(int index, T newValue){	
	//update the element at position index
	if (index<1 || index>this->size())//Index Out of Bounds
		return;
	if (this->isEmpty())//
		return;
	Node<T> *temp = head;
	do
	{
		temp = temp->next;
		index--;
	} while (index != 0);
	temp->data = newValue;
}

template <typename T>
bool set<T>::isValidIndex(int index){
	//judge whether a index is valid or not,the valid index range from 1 to this.size()
	return index >= 1 && index <= this->size();
}

template <typename T>
int set<T>::indexOf(T e){
	//return the index of the element e passed in
	if (!searchElem(e))
		return -1;
	int index = 0;
	Node<T> *temp = head;
	do 
	{
		temp = temp->next;
		index++;
	} while (e!=temp->data);
	return index;
}

template <typename T>
void set<T>::erase(int begin, int end){
	//delete the element int [begin,end]
	if (begin<1 || begin>this->size() || end<1 || end>this->size())
		return;
	if (end < begin)
		return;
	if (end==begin){
		this->deleteElemByIndex(begin);
		return;
	}
	int count = 0;
	Node<T>* temp = head;
	while (temp->next){
		count++;
		if (count == begin)
			break;
		temp = temp->next;
	}
	while (count++<=end){
		Node<T>* t = temp->next;
		temp->next = t->next;
		delete t;
	}
}

template <typename T>
void set<T>::eraseNElem(int begin, int n)
{	//Delete n elements starting from position index.
	//begin range from 1 to this.size()-n
	if (begin<1||n>this->size()||begin+n>this->size())
		return;
	int count = 0;
	Node<T>* temp = head;
	while (temp->next){
		count++;
		if (count == begin)
			break;
		temp = temp->next;
	}

	while (count++ <= begin+n-1){
		Node<T>* t = temp->next;
		temp->next = t->next;
		delete t;
	}
}

template <typename T>
void set<T>::eraseFirst(){
	//delete the head element
	if (this->isEmpty())
		return;
	Node<T> *temp = head->next;
	head->next = temp->next;
	delete temp;
}

template <typename T>
void set<T>::eraseLast(){	
	//delete the last element
	if (this->isEmpty())
		return;
	Node<T> *temp = head;
	while (temp->next->next){
		temp = temp->next;
	}
	Node<T> *todel = temp->next;
	temp->next = NULL;
	delete todel;
}

template <typename T>
T set<T>::getMaxElem(){
	//return the biggest element of the set.
	//this function requires the operator < for the element overloaded.
	if (this->isEmpty())
		return NULL;
	Node<T> *temp = head->next;
	T max = temp->data;
	while (temp->next){
		temp = temp->next;
		max = temp->data < max ? max : temp->data;
	}
	return max;
}

template <typename T>
T set<T>::getMinElem(){
	//return the smallest element of the set.
	//this function requires the operator < for the element overloaded.
	if (this->isEmpty())
		exit(0);
	Node<T> *temp = head->next;
	T min = temp->data;
	while (temp->next){
		temp = temp->next;
		min = min<temp->data ? min : temp->data;
	}
	return min;
}

template <typename T>
bool set<T>::sortAsc(){
	//sort the set in ascending order
	//this function requires the operator < for the element overloaded.
	if (this->isEmpty())
		return true;
	//sort the set's elements by Bubble sort
	Node<T> *i = head->next;
	while (i&&i->next){
		Node<T> *j = i->next;
		while (j){
			if (j->data < i->data){	
				//swap
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
bool set<T>::sortDsc(){
	//sort the set in descending order
	//this function requires the operator < for the element overloaded.
	if (this->isEmpty())
		return true;
	//sort the set's elements by Bubble sort
	Node<T> *i = head->next;
	while (i&&i->next){
		Node<T> *j = i->next;
		while (j){
			if (i->data < j->data){	
				//swap
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
T* set<T>::toArray(){
	//return a array which storage all the elements in the set.
	if (this->isEmpty())
		return NULL;

	T* array = new T[this->size()];
	Node<T> *temp = this->head->next;
	for (int i = 0; i < this->size(); i++){
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
	arr = new T[this->size()];
	Node<T> *temp = this->head->next;
	for (int i = 0; i < this->size(); i++){
		arr[i] = temp->data;
		temp = temp->next;
	}
}

template <typename T>
bool set<T>::contains(T e){
	//judge whether the set contains the element e
	if (isEmpty())
		return false;
	Node<T> *temp = head;
	while (temp->next){
		temp = temp->next;
		if (e == temp->data)
			return true;
	}
	return false;
}

template <typename T>
bool set<T>::belongsTo(set<T> s){
	//represent the relationship of belong to and included in.
	//if the set belongs to s return true,else return false.
	if (this->size() > s.size())
		return false;

	Node<T> *temp = this->head;
	Node<T> *stemp = s.head;
	while (temp->next){
		temp = temp->next;
		stemp = s.head;
		while (stemp->next){
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
void intersectionSet(set<T> a, set<T> b, set<T>& c){	
	//c=a^b
	//call:Intersection<T>(s,b,c)
	//you must add<T>,the T is the type of the data in the set
	if (a.isEmpty()||b.isEmpty()){
		c.clearSet();
		return;
	}
	if (a.equals(b)){
		c = a;
		return;
	}

	if (!c.isEmpty()){
		c.clearSet();
	}
	Node<T> *temp = a.getHead();
	while (temp->next){
		temp = temp->next;
		if (b.searchElem(temp->data)){
			c.addElem(temp->data);
		}
	}
}

template <typename T>
void unionSet(set<T> a, set<T> b, set<T>& c){	
	//c=a U b
	//call:unionSet<T>(s,b,c)
	//you must add<T>,the T is the type of the data in the set
	if (a.isEmpty()||a.equals(b)){
		c = b;
		return;
	}
	if (b.isEmpty()){
		c = b;
		return;
	}

	c = a;
	Node<T>* temp = b.getHead();
	while (temp->next){
		temp = temp->next;
		if (!c.searchElem(temp->data)){
			c.addElem(temp->data);
		}
	}
}

template <typename T>
void diffSet(set<T> a, set<T> b, set<T>& c){
	//c=a -b
	//call:diffSet<T>(a,b,c)
	//you must add<T>,the T is the type of the data in the set
	if (a.isEmpty()){
		c.clearSet();
		return;
	}
	if (b.isEmpty()){
		c = a;
		return;
	}

	c = a;
	Node<T>* temp = b.getHead();
	while (temp->next){
		temp = temp->next;
		if (c.searchElem(temp->data)){
			c.deleteElem(temp->data);
		}
	}
}

template <typename T>
void complementSet(set<T> u, set<T> s, set<T>& c){
	//c=u -s
	//call:complementSet<T>(u,s,c)
	//you must add<T>,the T is the type of the data in the set
	//c is the complement of s with respect to u
	if (!s.belongsTo(u)||u.isEmpty()){
		exit(0);
	}
	if (s.isEmpty()){
		c = u;
		return;
	}
	c = u;
	Node<T>* temp = s.getHead();
	while (temp->next){
		temp = temp->next;
		if (u.searchElem(temp->data)){
			c.deleteElem(temp->data);
		}
	}
}


