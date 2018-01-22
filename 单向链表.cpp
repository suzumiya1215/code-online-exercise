// 单向链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<iterator>
#include <iomanip>
using namespace std;

template<typename t_num>
class singly_linked_list
{
private:
	struct node
	{
		t_num data;
		node* next;
		node(t_num num_cin) :data(num_cin) , next(NULL) {}
	};

	node *head;


public:
	singly_linked_list();
	~singly_linked_list() 
	{
		node *p = head;
		while (p)
		{
			node *q = p->next;
			delete p;
			p = q;
		}
	};

	void node_add(t_num num_cin);
	void node_delete(t_num num_cin);
	node* node_find(t_num num_cin)
	{
		node *p = head;
		for (; p; p = p->next)
		{
			if (p->next->data == num_cin)
				break;
		}
		return p;
	};
	void node_ergodic();

};

template<typename t_num>
singly_linked_list<t_num>::singly_linked_list()
{
	head = new node(0);
};

//template<typename t_num>
//singly_linked_list<t_num>::~singly_linked_list()
//{
//	node *p = head;
//	while (p)
//	{
//		node *q = p->next;
//		delete p;
//		p = q;
//	}
//}

template<typename t_num>
void singly_linked_list<t_num>::node_add(t_num num_cin)
{
	node *p = new node(num_cin);
	p->next = head->next;
	head->next = p;
};

template<typename t_num>
void singly_linked_list<t_num>::node_delete(t_num num_cin)
{
	node *p = node_find(num_cin);
	node *q = p->next;
	p->next = p->next->next;
	delete q;
};


//template<typename t_num>
//node* singly_linked_list<t_num>::node_find(t_num num_cin)
//{
//	node *p = head;
//	for (; p; p = p->next)
//	{
//		if (p->next->data == num_cin)
//			break;
//	}
//	return p;
//};

template<typename t_num>
void singly_linked_list<t_num>::node_ergodic()
{
	for (node *p = head->next; p; p=p->next)
		cout << p->data << setw(4);
};



int main()
{
	singly_linked_list<int> sll;
	sll.node_add(1);
	sll.node_add(2);
	sll.node_add(3);
	sll.node_add(4);
	sll.node_delete(2);
	sll.node_ergodic();

	system("pause");
	return 0;
}


















//参考代码
//http://www.voidcn.com/article/p-aaugrcuw-bkz.html

class list
{
public:
	list() { create_list(); }
	~list() { clear(); }

	void create_list();
	void insert(const int& d);
	void insert_post(const int& d , const int&d1);
	void erase(const int& d);
	void updata(const int& d , const int&d1);
	void reverse();
	void print();
private:
	struct node
	{
		int data;
		node *next;
		node(const int& d) :data(d) , next(NULL) {}
	};
	node *head;

	void clear()
	{
		node *p = head;
		while (p)
		{
			node *q = p->next;
			delete p;
			p = q;
		}
	}

	node *find(const int& d)
	{
		node  *p = head;
		for (; p; p = p->next)
		{
			if (p->next->data == d)
				break;
		}
		return p;
	}

};

void list::create_list()
{
	head = new node(0);
}

void list::insert(const int& d)
{
	node *p = new node(d);
	p->next = head->next;
	head->next = p;
}

void list::print()
{
	for (node *p = head->next; p; p = p->next)
	{
		cout << p->data << endl;
	}
}

void list::insert_post(const int& d , const int& d1)
{
	node *p = find(d);
	node *q = new node(d1);
	q->next = p->next;
	p->next = q;
}

void list::erase(const int& d)
{
	node *p = find(d);
	node *q = p->next;
	p->next = p->next->next;
	delete q;
}

void list::updata(const int& d , const int& d1)
{
	node *p = find(d);
	p->next->data = d1;
}

void list::reverse()
{
	node *p = head->next;
	node *q = head->next->next;
	node *m = head->next->next->next;

	while (m)
	{
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}

	q->next = p;
	head->next = q;

}



