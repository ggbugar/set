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
	set();//无参构造函数
	set(T data[], int n);
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
		if (!(s.first.next))//s为空集合
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
	~set();//析构函数
	
	
	bool clearSet();//清空集合元素
	bool isEmpty();//判断集合是否为空
	int length();//返回集合元素个数


	void viewSetElem();//查看集合所有元素
	T getElem(int i);//返回第i个元素
	
	
	bool addElem(T data);//
	bool deleteElem(T data);//
	bool deleteElem();

	bool searchElem(T data);//
	bool updateElem(T oldValue, T newValue);//delete then add
	


	bool unionSet(const set<T>& s);//
	friend set& unionSet(const set<T>& s1,const set<T>& s2);//
	friend bool unionSet(const set<T>& a, const set<T>& b, const set<T>& c);//
	


	T getMaxElem();//返回最大元素
	T getMinElem();//返回最小元素
	bool sortAsc();
	bool sortDsc();
	T* toArray();//转换为数组，返回一个数组
	//void forEach();

public:
	Node<T> *first;//单链表的头指针	
};

/*
基本操作
*/
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
	while (temp->next)
	{
		temp = temp->next;
		cout << temp->data<<" ";
	}
}

template <typename T>
T set<T>::getElem(int i)
{
	if (i<1 || i>this.length())
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
		exit(error);
	Node<T> temp=first->next;
	T max = temp.data;
	while (temp.next)
	{
		temp = temp.next;
		max = max > temp.data ? max : temp.data;
	}
	return max;
}

template <typename T>
T set<T>::getMinElem()
{
	if (this->isEmpty())
		exit(error);
	Node<T> temp = first->next;
	T min = temp.data;
	while (temp.next)
	{
		temp = temp.next;
		min = max < temp.data ? max : temp.data;
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
		exit(error);

	T* array = new T[this->length()];
	Node<T> temp = this->first->next;
	for (int i = 0; i < this.length();i++)
	{
		array[i] = temp.data;
		temp = temp.next;
	}
	return array;
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
		temp->data = data[i];
		temp->next = NULL;
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
	if (!(s.first.next))//s为空集合
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
	Node<T> *temp = first;
	do 
	{
		temp = first->next;
		delete first;
		first = temp;
	} while (first->next);
}

/*
基本操作
*/
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

	Node<T> *temp=first;
	while (temp->next&&temp->next->data!=data)
	{
		temp = temp->next;
	}

	if (data == temp->next->data)
	{
		Node<T> *t = temp->next;
		temp->next = t->next;
		delete t;
		return true;
	}
	else
		return true;
}


template <typename T>
bool set<T>::searchElem(T data)
{
	if (isEmpty())
		return false;
	Node<T> *temp = first;
	while (temp->next&&temp->next->data!=data)
	{
		temp = temp->next;
	}
	if (data == temp->next->data)
		return true;
	else
		return false;
}


template <typename T>
bool set<T>::updateElem(T oldValue, T newValue)
{


}





