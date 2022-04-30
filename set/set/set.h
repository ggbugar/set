#pragma once

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T> *next;  //<T>Ҳ����ʡ��
};
/*
�������ʣ�
1.ȷ����
2.������
3.������
*/


template <typename T>
class set
{
public:
	set();//�޲ι��캯��
	set(T data[], int n);
	set(const set& s);//�������캯��
	set& operator=(const set& s)
	{
		//���ظ�ֵ�����
		if (first->next!=NULL)
		{
			this->clearSet();
		}

		first = new Node<T>;
		first->next = NULL;
		if (!(s.first.next))//sΪ�ռ���
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
					temp->next = NULL;//βָ�����ÿ�
					first->next = temp;
				}
				else
				{
					temp->next = first->next;//ͷ�巨
					first->next = temp;
				}
			}
		}
		return *this;
	}
	~set();//��������
	
	
	bool clearSet();//��ռ���Ԫ��
	bool isEmpty();//�жϼ����Ƿ�Ϊ��
	int length();//���ؼ���Ԫ�ظ���


	void viewSetElem();//�鿴��������Ԫ��
	T getElem(int i);//���ص�i��Ԫ��
	
	
	bool addElem(T data);//
	bool deleteElem(T data);//
	bool deleteElem();

	bool searchElem(T data);//
	bool updateElem(T oldValue, T newValue);//delete then add
	


	bool unionSet(const set<T>& s);//
	friend set& unionSet(const set<T>& s1,const set<T>& s2);//
	friend bool unionSet(const set<T>& a, const set<T>& b, const set<T>& c);//
	


	T getMaxElem();//�������Ԫ��
	T getMinElem();//������СԪ��
	bool sortAsc();
	bool sortDsc();
	T* toArray();//ת��Ϊ���飬����һ������
	//void forEach();

public:
	Node<T> *first;//�������ͷָ��	
};

/*
��������
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
	//����һ���ռ���
	first = new Node<T>;
	first->next = NULL;
}

template <typename T>
set<T>::set(T data[], int n){
	//���������Ԫ�ظ�������n��Ԫ�صļ���
	//��δ�����ظ�Ԫ��
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
{	//�������캯��
	first = new Node<T>;
	first->next = NULL;
	if (!(s.first.next))//sΪ�ռ���
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
				temp->next = NULL;//βָ�����ÿ�
				first->next = temp;
			}
			else
			{
				temp->next = first->next;//ͷ�巨
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
��������
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





