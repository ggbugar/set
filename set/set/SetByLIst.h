#pragma once
#include <iostream>  //引用输入输出流库函数的头文件
using namespace std;
template <class T>
struct Node
{
	T data;
	Node<T> *next;  //此处<T>也可以省略
};

template <class T>
class LinkList
{
public:
	LinkList();  //建立只有头结点的空链表
	LinkList(T a[], int n);  //建立有n个元素的单链表
	~LinkList();             //析构函数
	int Length();          //求单链表的长度
	T Get(int i);           //取单链表中第i个结点的元素值
	int Locate(T x);       //求单链表中值为x的元素序号
	void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
	T Delete(int i);        //在单链表中删除第i个结点
	void PrintList();           //遍历单链表，按序号依次输出各元素
private:
	Node<T> *first;  //单链表的头指针
};
/*
*前置条件：单链表不存在
*输    入：无
*功    能：构建一个单链表
*输    出：无
*后置条件：构建一个单链表
*/
template <class T>
LinkList<T>::LinkList()
{
	first = new Node<T>; first->next = NULL;
}
/*
*前置条件：单链表不存在
*输    入：顺序表信息的数组形式a[],单链表长度n
*功    能：将数组a[]中元素建为长度为n的单链表
*输    出：无
*后置条件：构建一个单链表
*/

template <class T>
LinkList<T>::LinkList(T a[], int n)
{
	first = new Node<T>;   //生成头结点
	Node<T> *r, *s;
	r = first;          //尾指针初始化
	for (int i = 0; i < n; i++)
	{
		s = new Node<T>; s->data = a[i];  //为每个数组元素建立一个结点
		r->next = s; r = s;      //插入到终端结点之后
	}
	r->next = NULL;    //单链表建立完毕，将终端结点的指针域置空
}


/*
*前置条件：无
*输    入：无
*功    能：无
*输    出：无
*后置条件：无
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
*前置条件：单链表存在
*输    入：查询元素位置i
*功    能：按位查找位置为i的元素并输出值
*输    出：查询元素的值
*后置条件：单链表不变
*/
template <class T>
T LinkList<T>::Get(int i)
{
	Node<T> *p; int j;
	p = first->next;  j = 1;  //或p=first;  j=0;
	while (p && j < i)
	{
		p = p->next;       //工作指针p后移
		j++;
	}
	if (!p) throw "位置";
	else return p->data;
}

/*
*前置条件：单链表存在
*输    入：查询元素值x
*功    能：按值查找值的元素并输出位置
*输    出：查询元素的位置
*后置条件：单链表不变
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
*前置条件：单链表存在
*输    入：插入元素x,插入位置i
*功    能：将元素x插入到单链表中位置i处
*输    出：无
*后置条件：单链表插入新元素
*/
template <class T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T> *p; int j;
	p = first; j = 0;    //工作指针p初始化
	while (p && j < i - 1)
	{
		p = p->next;   //工作指针p后移
		j++;
	}
	if (!p) throw "位置";
	else {
		Node<T> *s;
		s = new Node<T>;
		s->data = x;  //向内存申请一个结点s，其数据域为x
		s->next = p->next;       //将结点s插入到结点p之后
		p->next = s;
	}
}

/*
*前置条件：单链表存在
*输    入：无
*功    能：输出单链表长度
*输    出：单链表长度
*后置条件：单链表不变
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
*前置条件：单链表存在
*输    入：要删除元素位置i
*功    能：删除单链表中位置为i的元素
*输    出：无
*后置条件：单链表删除元素
*/
template <class T>
T LinkList<T>::Delete(int i)
{
	Node<T> *p; int j;
	p = first; j = 0;  //工作指针p初始化
	while (p && j < i - 1)  //查找第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (!p || !p->next) throw "位置";  //结点p不存在或结点p的后继结点不存在
	else {
		Node<T> *q; int x;
		q = p->next; x = q->data;  //暂存被删结点
		p->next = q->next;  //摘链
		delete q;
		return x;
	}
}
/*
*前置条件：单链表存在
*输    入：无
*功    能：单链表遍历
*输    出：输出所有元素
*后置条件：单链表不变
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
	//改变了a
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
	//因为函数返回时a，b被析构
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
	//因为函数返回时a，b被析构
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
//A∪B=C
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
//A∩B=C
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
//A∩B=A
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

