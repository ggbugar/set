#pragma once

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T> *next;  //<T>也可以省略
};

/*
集合性质：
1.确定性
2.互异性
3.无序性
*/

template <typename T>
class set
{
public:
	Node<T> *first;//单链表的头指针	
public:
	set();//无参构造函数
	set(T data[], int n);//
	set(const set& s);//拷贝构造函数
	set& operator=(const set& s)
	{
		//重载赋值运算符
		if (first->next!=NULL)
		{
			this->clearSet();
		}

		first = new Node<T>;
		first->next = NULL;
		if (!(s.first->next))//s为空集合
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
				//temp->next = NULL;
				if (first->next == NULL)
				{
					temp->next = NULL;//尾指针域置空
					first->next = temp;
				}
				else
				{
					temp->next = first->next;//头插法
					first->next = temp;
				}
			}
		}
		return *this;
	}
	bool operator==(set s)
	{
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
	~set();//析构函数
	
	bool clearSet();//清空集合元素
	bool isEmpty();//判断集合是否为空
	int length();//返回集合元素个数

	void viewSetElem();//查看集合所有元素
	T getElem(int i);//返回第i个元素
	
	bool addElem(T data);//
	bool deleteElem(T data);//
	void deleteElemByIndex(int index);//

	void erase(int i, int j);//delete the element between index i and index ,j:[i,j),which will delete j-i elements 
	void eraseFirst();//delete the first element of the set
	void eraseLast();//delete the last element of the set

	bool searchElem(T data);//
	void updateElem(T oldValue, T newValue);//
	void updateElemByIndex(int index, T newValue);//
	
	bool equals(set<T> s);//"=="
	bool belongsTo(set<T> s);//"belongs to" ;a subset of

	//set operations:
	//intersection set of a set
	//void IntersectionSet(set<T> s);//intersection:this = this ^ s
	friend void IntersectionSet(set<T> a, set<T> b, set<T>& c);//intersection:c = a ^ b
	friend set& IntersectionSet(set<T> s1, set<T> s2);//intersection:s = s1 ^ s2
	//union set of a set
	//void unionSet(set<T> s);//union set:this = this U s
	extern friend void unionSet(set<T> a, set<T> b, set<T>& c);//union set:c = a U b
	friend set& unionSet(set<T> s1, set<T> s2);//union set:s = s1 U s2
	//intersection set of a set
	//void diffSet(set<T> s);//Difference sett:this = this - s
	extern friend void diffSet(set<T> a, set<T> b, set<T>& c);//Difference set:c = a - b
	friend set& diffSet(set<T> s1, set<T> s2);//Difference set:s = s1 - s2
	//complement set of a set
	//set<T> complementSet(set<T> u);//complement set:this = U - this
	extern friend void complementSet(set<T> u, set<T> s, set<T>& c);//Difference cset:c = U - s
	friend set& complementSet(set<T> u, set<T> s);//Difference set: = u - s

	T getMaxElem();//返回最大元素
	T getMinElem();//返回最小元素
	bool sortAsc();//sort the set 
	bool sortDsc();//sort the set
	T* toArray();//转换为数组，返回一个数组
	void toArray(T* arr);//

};



template <typename T>
bool set<T>::isEmpty()
{
	if (this->first->next == NULL)
		return true;
	else
		return false;
}

template <typename T>
bool set<T>::clearSet()
{
	if (this->isEmpty())
		return true;
	Node<T>* temp;
	while (first->next)
	{
		temp = first->next;
		first->next = temp->next;
		delete temp;
	}
	return true;
}

template <typename T>
int set<T>::length()
{
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
{
	Node<T> *temp=first;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		cout << temp->data<<" ";
	}
	cout << endl;
}

template <typename T>
T set<T>::getElem(int i)
{
	if (i<1 || i>this->length())
		return NULL;
	Node<T>* temp = first;
	while (i>0)
	{
		temp = temp->next;
		i--;
	}
	return temp->data;
}

template <typename T>
T set<T>::getMaxElem()
{
	if (this->isEmpty())
		exit(0);
	Node<T> *temp=first->next;
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
{
	if (this->isEmpty())
		exit(0);
	Node<T> *temp = first->next;
	T min = temp->data;
	while (temp->next)
	{
		temp = temp->next;
		min = min < temp->data ? min : temp->data;
	}
	return min;
}

template <typename T>
bool set<T>::sortAsc()
{
	if (this->isEmpty())
		exit(0);

	Node<T> *i = first->next;
	while (i&&i->next)
	{
		Node<T> *j = i->next;
		while (j)
		{
			if (j->data<i->data)
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
{
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
{
	if (this->isEmpty())
		return NULL;

	T* array = new T[this->length()];
	Node<T> *temp = this->first->next;
	for (int i = 0; i < this->length();i++)
	{
		array[i] = temp->data;
		temp = temp->next;
	}
	return array;
}

template <typename T>
void set<T>::toArray(T* arr)
{
	if (this->isEmpty())
		return;
	delete[] arr;
	arr = new T[this->length()];
	Node<T> *temp = this->first->next;
	for (int i = 0; i < this->length(); i++)
	{
		array[i] = temp->data;
		temp = temp->next;
	}
}

template <typename T>
set<T>::set(){
	//建立一个空集合
	first = new Node<T>;
	first->next = NULL;
}

template <typename T>
set<T>::set(T data[], int n){
	//传入数组和元素个数则建立n个元素的集合
	//尚未考虑重复元素
	first = new Node<T>;
	first->next = NULL;
	for (int i = 0; i < n;i++)
	{
		
		Node<T>* temp = new Node<T>;
		temp->next = NULL;
		temp->data = data[i];

		if (first->next==NULL)
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
{	//拷贝构造函数
	first = new Node<T>;
	first->next = NULL;
	if (!(s.first->next))//s为空集合
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
			//temp->next = NULL;
			if (first->next==NULL)
			{
				temp->next = NULL;//尾指针域置空
				first->next = temp;
			}
			else
			{
				temp->next = first->next;//头插法
				first->next = temp;
			}
		}
	}
}

template <typename T>
set<T>::~set(){
	//
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
bool set<T>::addElem(T data)
{
	Node<T> *temp = new Node<T>;
	temp->data = data;

	temp->next = first->next;
	this->first->next = temp;
	return true;
}

template <typename T>
bool set<T>::deleteElem(T data)
{
	if (this->isEmpty())
		return true;
	if (!(this->searchElem(data)))
		return true;

	Node<T> *temp=first;
	while (temp->next)
	{
		if (data == temp->next->data)
			break;
		temp = temp->next;
	}
		Node<T> *t = temp->next;
		temp->next = t->next;
		delete t;
		return true;
}

template <typename T>
void set<T>::deleteElemByIndex(int index)
{
	if (index<1 || index>this->length())
		return;
	if (this->isEmpty())
		return ;
	
	Node<T> *temp = first;
	while (--index!=0)
	{
		temp = temp->next;
	}
	Node<T> *t = temp->next;
	temp->next = t->next;
	delete t;
}

template <typename T>
bool set<T>::searchElem(T data)
{	//
	if (isEmpty())
		return false;
	Node<T> *temp = first;
	while (temp->next)
	{
		temp = temp->next;
		if (data==temp->data)
			return true;
	}
	return false;
}

template <typename T>
void set<T>::updateElem(T oldValue, T newValue)
{
	if (this->isEmpty())
		return;
	Node<T> *temp = first->next;
	while (oldValue!=temp->data&&temp->next!=NULL)
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
{
	if (index<1 || index>this->length())//Index Out of Bounds
		return;
	if (this->isEmpty())//
		return;
	Node<T> *temp = first;
	do 
	{
		temp = temp->next;
		index--;
	} while (index!=0);
	temp->data = newValue;
}

template <typename T>
bool set<T>::equals(set<T> s)
{
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

template <typename T>
bool set<T>::belongsTo(set<T> s)
{
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
{	//call:Intersection<T>(s,b,c)
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
	Node<T> *temp = a.first;
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
{	//call:unionSet<T>(s,b,c)
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
	Node<T>* temp = b.first;
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
{	//call:diffSet<T>(a,b,c)
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
	Node<T>* temp = b.first;
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
{	//call:complementSet<T>(u,s,c)
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
	Node<T>* temp = s.first;
	while (temp->next)
	{
		temp = temp->next;
		if (u.searchElem(temp->data))
		{
			c.deleteElem(temp->data);
		}
	}
}


