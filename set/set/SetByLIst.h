#pragma once
#include <iostream>  //��������������⺯����ͷ�ļ�
using namespace std;
template <class T>
struct Node
{
	T data;
	Node<T> *next;  //�˴�<T>Ҳ����ʡ��
};

template <class T>
class LinkList
{
public:
	LinkList();  //����ֻ��ͷ���Ŀ�����
	LinkList(T a[], int n);  //������n��Ԫ�صĵ�����
	~LinkList();             //��������
	int Length();          //������ĳ���
	T Get(int i);           //ȡ�������е�i������Ԫ��ֵ
	int Locate(T x);       //��������ֵΪx��Ԫ�����
	void Insert(int i, T x);   //�ڵ������е�i��λ�ò���Ԫ��ֵΪx�Ľ��
	T Delete(int i);        //�ڵ�������ɾ����i�����
	void PrintList();           //������������������������Ԫ��
private:
	Node<T> *first;  //�������ͷָ��
};
/*
*ǰ������������������
*��    �룺��
*��    �ܣ�����һ��������
*��    ������
*��������������һ��������
*/
template <class T>
LinkList<T>::LinkList()
{
	first = new Node<T>; first->next = NULL;
}
/*
*ǰ������������������
*��    �룺˳�����Ϣ��������ʽa[],��������n
*��    �ܣ�������a[]��Ԫ�ؽ�Ϊ����Ϊn�ĵ�����
*��    ������
*��������������һ��������
*/

template <class T>
LinkList<T>::LinkList(T a[], int n)
{
	first = new Node<T>;   //����ͷ���
	Node<T> *r, *s;
	r = first;          //βָ���ʼ��
	for (int i = 0; i < n; i++)
	{
		s = new Node<T>; s->data = a[i];  //Ϊÿ������Ԫ�ؽ���һ�����
		r->next = s; r = s;      //���뵽�ն˽��֮��
	}
	r->next = NULL;    //����������ϣ����ն˽���ָ�����ÿ�
}


/*
*ǰ����������
*��    �룺��
*��    �ܣ���
*��    ������
*������������
*/
template <class T>
LinkList<T>::~LinkList()
{
	cout << "~LinkList()" << Length() << endl;

	Node<T> *q;
	while (first != NULL)
	{
		q = first;//cout<<q->data<<endl;
		first = first->next;
		delete q;
	}
}
/*
*ǰ�����������������
*��    �룺��ѯԪ��λ��i
*��    �ܣ���λ����λ��Ϊi��Ԫ�ز����ֵ
*��    ������ѯԪ�ص�ֵ
*������������������
*/
template <class T>
T LinkList<T>::Get(int i)
{
	Node<T> *p; int j;
	p = first->next;  j = 1;  //��p=first;  j=0;
	while (p && j < i)
	{
		p = p->next;       //����ָ��p����
		j++;
	}
	if (!p) throw "λ��";
	else return p->data;
}

/*
*ǰ�����������������
*��    �룺��ѯԪ��ֵx
*��    �ܣ���ֵ����ֵ��Ԫ�ز����λ��
*��    ������ѯԪ�ص�λ��
*������������������
*/
template <class T>
int LinkList<T>::Locate(T x)
{
	Node<T> *p; int j;
	p = first->next; j = 1;
	while (p){
		if (p->data == x)    return j;
		else
		{
			p = p->next;
			j++;
		}
	}
	return 0;
}

/*
*ǰ�����������������
*��    �룺����Ԫ��x,����λ��i
*��    �ܣ���Ԫ��x���뵽��������λ��i��
*��    ������
*���������������������Ԫ��
*/
template <class T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T> *p; int j;
	p = first; j = 0;    //����ָ��p��ʼ��
	while (p && j < i - 1)
	{
		p = p->next;   //����ָ��p����
		j++;
	}
	if (!p) throw "λ��";
	else {
		Node<T> *s;
		s = new Node<T>;
		s->data = x;  //���ڴ�����һ�����s����������Ϊx
		s->next = p->next;       //�����s���뵽���p֮��
		p->next = s;
	}
}

/*
*ǰ�����������������
*��    �룺��
*��    �ܣ������������
*��    ������������
*������������������
*/
template <class T>
int LinkList<T>::Length()
{
	Node <T> *p = first->next;
	int i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}
/*
*ǰ�����������������
*��    �룺Ҫɾ��Ԫ��λ��i
*��    �ܣ�ɾ����������λ��Ϊi��Ԫ��
*��    ������
*����������������ɾ��Ԫ��
*/
template <class T>
T LinkList<T>::Delete(int i)
{
	Node<T> *p; int j;
	p = first; j = 0;  //����ָ��p��ʼ��
	while (p && j < i - 1)  //���ҵ�i-1�����
	{
		p = p->next;
		j++;
	}
	if (!p || !p->next) throw "λ��";  //���p�����ڻ���p�ĺ�̽�㲻����
	else {
		Node<T> *q; int x;
		q = p->next; x = q->data;  //�ݴ汻ɾ���
		p->next = q->next;  //ժ��
		delete q;
		return x;
	}
}
/*
*ǰ�����������������
*��    �룺��
*��    �ܣ����������
*��    �����������Ԫ��
*������������������
*/
template <class T>
void LinkList<T>::PrintList()
{
	Node<T> *p;
	p = first->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//LinkListMain.cpp
template <typename T>
void Unionset(LinkList <T> &a, LinkList <T> &b){//right
	//�ı���a
	T temp;
	for (int i = 1; i <= b.Length(); i++)
	{
		temp = b.Get(i);
		if (!a.Locate(temp))a.Insert(a.Length() + 1, temp);
	}
}
template <typename T>
void Unionset1(LinkList <T> a, LinkList <T> b){
	//wrong: _CrtIsValidHeapPointer
	//��Ϊ��������ʱa��b������
	T temp;
	for (int i = 1; i <= b.Length(); i++)
	{
		temp = b.Get(i);
		if (!a.Locate(temp))a.Insert(a.Length() + 1, temp);
	}
}
template <typename T>
LinkList <T> Unionset2(LinkList <T> a, LinkList <T> b){
	//wrong: _CrtIsValidHeapPointer
	//��Ϊ��������ʱa��b������
	T temp;
	for (int i = 1; i <= b.Length(); i++)
	{
		temp = b.Get(i);
		if (!a.Locate(temp))a.Insert(a.Length() + 1, temp);
	}
	return a;
}
template <typename T>
void UnionSet(LinkList<T>&C, LinkList<T>&A, LinkList<T>&B)
//A��B=C
{
	//LinkList<T> C;
	T temp;
	int i;
	for (i = 1; i <= A.Length(); i++)
	{
		temp = A.Get(i);
		C.Insert(C.Length() + 1, temp);
	}
	for (i = 1; i <= B.Length(); i++)
	{
		temp = B.Get(i);
		if (!A.Locate(temp))C.Insert(C.Length() + 1, temp);
	}
	//return C;

}
template <typename T>
void IntersectionSet(LinkList<T>&C, LinkList<T>&A, LinkList<T>&B)
//A��B=C
{
	//LinkList<T> C;
	T temp;
	int i;

	for (i = 1; i <= B.Length(); i++)
	{
		temp = B.Get(i);
		if (A.Locate(temp))C.Insert(C.Length() + 1, temp);
	}
	//return C;
}
template <typename T>
void IntersectionSet1(LinkList<T>&A, LinkList<T>&B)
//A��B=A
{
	//LinkList<T> C;
	T temp;
	int i;

	for (i = 1; i <= A.Length(); i++)
	{
		temp = A.Get(i);
		if (B.Locate(temp) == 0){ A.Delete(i); i--; }
	}
	//return C;
}
template <typename T>
void  DifferenceSet(LinkList<T>&C, LinkList<T>&A, LinkList<T>&B)
//A-B=c
{
	//LinkList<T> C;
	T temp;
	int i;

	for (i = 1; i <= A.Length(); i++)
	{
		temp = A.Get(i);
		C.Insert(C.Length() + 1, temp);
	}
	for (i = 1; i <= B.Length(); i++)
	{
		temp = B.Get(i);
		if (A.Locate(temp) != 0){
			int pos = C.Locate(temp);
			C.Delete(pos);
		}
	}
	//return C;
}

