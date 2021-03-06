#include "pch.h"
#include<memory>
#include <iostream>
using namespace std;


using data_type_01 = int;
using data_type_02 = int;

class data_structure										//数据结构
{
public:
	class linear_table										//线性表
	{
	public:
		class sequence_table;								//顺序表
		class linked_list									//链表
		{
		public:
			template<typename t_01>
			class list_node;								//结点类
			template<typename t_01>
			class singly_linked_list;						//带头结点单链表
			template<typename t_01>
			class circular_singly_linked_list;				//带头结点循环单链表
			class doubly_linked_list;						//双向链表
		};
	};
};

/**
 * @class	data_structure::linear_table::sequence_table
 *
 * @brief	顺序表
 *
 * @author	Suzumiya Haruhi
 * @date	2018/11/04 星期日	2018年11月4日16:18:17
 */

class data_structure::linear_table::sequence_table
{
protected:
	data_type_01		*data_list;											//数组
	int					max_size;											//最大元素个数
	int					now_size;											//当前元素个数
public:
	sequence_table(int max = 16);											//构造函数
	~sequence_table(void);													//析构函数
	int					size_data(void) const;								//取当前数据元素个数
	void				insert_data(const data_type_01& item, int i);		//插入
	data_type_01		delect_data(const int i);							//删除
	data_type_01		get_data(int i) const;								//取数据元素
	void				start_test();
};

data_structure::linear_table::sequence_table::sequence_table(int max)
{
	max_size = max;
	now_size = 0;
	data_list = new data_type_01[max_size];
}

data_structure::linear_table::sequence_table::~sequence_table(void)
{
	delete[] data_list;
}

int data_structure::linear_table::sequence_table::size_data(void) const
{
	return now_size;
}

void data_structure::linear_table::sequence_table::insert_data(const data_type_01 & item, int i)
{
	if (now_size == max_size)
	{
		cout << "顺序表已满，无法插入" << endl;
		exit(0);
	}
	else if (i<0 || i>now_size)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	else
	{
		for (int j = now_size; j > i; j--)
		{
			data_list[j] = data_list[j - 1];
		}
		data_list[i] = item;
		now_size++;
	}

}

data_type_01 data_structure::linear_table::sequence_table::delect_data(const int i)
{
	if (now_size == 0)
	{
		cout << "顺序表已空，无元素可删" << endl;
		exit(0);
	}
	else if (i<0 || i>now_size - 1)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	else
	{
		data_type_01 x = data_list[i];

		for (int j = i; j < now_size - 1; j++)
		{
			data_list[j] = data_list[j + 1];
		}
		now_size--;
		return x;
	}

}

data_type_01 data_structure::linear_table::sequence_table::get_data(int i) const
{
	if (i<0 || i>now_size - 1)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}

	return data_list[i];
}

void data_structure::linear_table::sequence_table::start_test()
{
	sequence_table(20);
	cout << "max_size = " << max_size << endl;
	cout << "size_data = " << size_data() << endl;
	insert_data(000, 0);
	insert_data(111, 1);
	insert_data(222, 2);
	insert_data(333, 3);
	insert_data(444, 4);
	insert_data(555, 5);
	insert_data(666, 6);
	insert_data(777, 7);
	cout << "size_data = " << size_data() << endl;
	cout << "get_data 4 = " << get_data(4) << endl;
	cout << "get_data 5 = " << get_data(5) << endl;
	delect_data(4);
	cout << "delect_data(4)" << endl;
	cout << "size_data = " << size_data() << endl;
	cout << "get_data 3 = " << get_data(3) << endl;
	cout << "get_data 4 = " << get_data(4) << endl;
	cout << "get_data 5 = " << get_data(5) << endl;
	cout << "get_data 6 = " << get_data(6) << endl;
	//cout << "get_data 7 = " << get_data(7) << endl;//i越界出错
	delect_data(3);
	cout << "delect_data(3)" << endl;
	cout << "get_data 2 = " << get_data(2) << endl;
	cout << "get_data 3 = " << get_data(3) << endl;
	cout << "get_data 4 = " << get_data(4) << endl;
	cout << "get_data 5 = " << get_data(5) << endl;
	//cout << "get_data 6 = " << get_data(6) << endl;//i越界出错
	cout << "size_data = " << size_data() << endl;


}

/**
 * @class	data_structure::linear_table::linked_list::link_node
 *
 * @brief	结点类
 *
 * @author	Suzumiya Haruhi
 * @date	2018/11/04 星期日	2018年11月4日18:33:46
 *
 * @tparam	t_01	Type of the 01.
 */

template<typename t_01>
class data_structure::linear_table::linked_list::list_node
{
	friend class singly_linked_list<t_01>;
	friend class circular_singly_linked_list<t_01>;

private:
	shared_ptr<list_node<t_01> >		next;
	t_01								data;
public:
	list_node(shared_ptr<list_node<t_01> > prt_next = NULL)						//定义头结点用
	{
		next = prt_next;
	}
	list_node(const t_01 & item, shared_ptr<list_node<t_01> > prt_next = NULL)	//定义其他结点用
	{
		data = item;
		next = prt_next;
	}
	~list_node(void) {};
};

/**
 * @class	data_structure::linear_table::linked_list::singly_linked_list
 *
 * @brief	带头结点单链表
 *
 * @author	Suzumiya Haruhi
 * @date	2018/11/04 星期日	2018年11月6日12:52:05
 *
 * @tparam	t_01	Type of the 01.
 */

template<typename t_01>
class data_structure::linear_table::linked_list::singly_linked_list
{
private:
	shared_ptr<list_node<t_01> >		head;									//头指针
	int									now_size;								//当前元素个数

	shared_ptr<list_node<t_01> >		index(int i)							//定位
	{
		if (i<-1 || i>now_size - 1)
		{
			cout << "参数i越界出错" << endl;
			exit(0);
		}
		else if (i == -1)
		{
			return head;
		}
		else
		{
			shared_ptr<list_node<t_01> > p = head->next;
			int j = 0;
			while (p && j < i)
			{
				p = p->next;
				j++;
			}

			return p;
		}
	};
public:
	singly_linked_list(void);													//构造函数
	~singly_linked_list(void);													//析构函数

	int									data_size(void) const;					//取当前元素个数
	void								data_insert(const t_01 & item, int i);	//插入
	t_01								data_delete(int i);						//删除
	t_01								data_get(int i);						//取数据元素
	void								start_test();
};



//template<typename t_01>
//shared_ptr<list_node<t_01> > data_structure::linear_table::linked_list::singly_linked_list<t_01>::index(int i)
//{
// 
//}

template<typename t_01>
data_structure::linear_table::linked_list::singly_linked_list<t_01>::singly_linked_list(void)
{
	head = make_shared<list_node<t_01> >();
	now_size = 0;
}

template<typename t_01>
data_structure::linear_table::linked_list::singly_linked_list<t_01>::~singly_linked_list(void)
{
	shared_ptr<list_node<t_01> > p, q;
	p = head;
	while (p)//not null
	{
		q = p;
		p = p->next;
	}
	now_size = 0;
	head = NULL;
}

template<typename t_01>
int data_structure::linear_table::linked_list::singly_linked_list<t_01>::data_size(void) const
{
	return now_size;
}

template<typename t_01>
void data_structure::linear_table::linked_list::singly_linked_list<t_01>::data_insert(const t_01 & item, int i)
{
	if (i<0 || i>now_size)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	else
	{
		shared_ptr<list_node<t_01> > p = index(i - 1);
		shared_ptr<list_node<t_01> > q = make_shared<list_node<t_01> >(item, p->next);
		p->next = q;
		now_size++;
	}
}

template<typename t_01>
t_01 data_structure::linear_table::linked_list::singly_linked_list<t_01>::data_delete(int i)
{
	if (now_size == 0)
	{
		cout << "单链表已空，无元素可删" << endl;
		exit(0);
	}
	else if (i<0 || i>now_size - 1)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	else
	{
		shared_ptr<list_node<t_01> > p = index(i - 1);
		shared_ptr<list_node<t_01> > q = index(i);

		t_01 i_data = q->data;
		p->next = p->next->next;

		now_size--;

		return i_data;
	}

}

template<typename t_01>
t_01 data_structure::linear_table::linked_list::singly_linked_list<t_01>::data_get(int i)
{
	if (i<0 || i>now_size - 1)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	else
	{
		return index(i)->data;
	}

}

template<typename t_01>
void data_structure::linear_table::linked_list::singly_linked_list<t_01>::start_test()
{
	singly_linked_list();
	cout << "data_size() = " << data_size() << endl;
	data_insert(000, 0);
	data_insert(111, 1);
	data_insert(222, 2);
	data_insert(333, 3);
	data_insert(444, 4);
	data_insert(555, 5);
	data_insert(666, 6);
	data_insert(777, 7);
	cout << "data_size() = " << data_size() << endl;
	data_delete(3);
	cout << "data_delete(3)" << endl;
	cout << "data_size() = " << data_size() << endl;
	cout << "data_get(0) = " << data_get(0) << endl;
	cout << "data_get(1) = " << data_get(1) << endl;
	cout << "data_get(2) = " << data_get(2) << endl;
	cout << "data_get(3) = " << data_get(3) << endl;
	cout << "data_get(4) = " << data_get(4) << endl;
	cout << "data_get(5) = " << data_get(5) << endl;
	cout << "data_get(6) = " << data_get(6) << endl;
	cout << "data_get(7) = " << data_get(7) << endl;//i越界出错

}

/**
 * @class	data_structure::linear_table::linked_list::circular_singly_linked_list
 *
 * @brief	带头结点循环单链表。其结构与单链表差不多，区别在于：
 * 			1.  构造函数多了个head->next=head
 * 			2.  所有循环判断条件p->next!=NULL改为p->next!=head
 *
 * @author	Suzumiya Haruhi
 * @date	2018/11/06 星期二
 *
 * @tparam	t_01	Type of the 01.
 */

template<typename t_01>
class data_structure::linear_table::linked_list::circular_singly_linked_list
{
	//自己重写，不抄单链表
private:
	shared_ptr<list_node<t_01> >	head;						//头指针
	int								now_size;					//当前元素个数

	shared_ptr<list_node<t_01> >	index(int i)				//定位
	{
		if (i<-1 || i>now_size )
		{
			cout << "参数i越界出错" << endl;
			exit(0);
		}
		else if (i == -1|| i == now_size)
		{
			return head;
		}
		else
		{
			shared_ptr<list_node<t_01> > p = head->next;
			int j = 0;
			while (p && j < i)
			{
				p = p->next;
				j++;
			}

			return p;
		}
	}
public:
	circular_singly_linked_list(void) ;							//构造函数
	~circular_singly_linked_list(void);							//析构函数

	int								data_size();								//取当前元素个数
	void							data_insert(const t_01 & item, int i);		//插入
	t_01							data_delete(int i);							//删除
	t_01							data_get(int i);							//取数据元素
	void							start_test();

};

template<typename t_01>
data_structure::linear_table::linked_list::circular_singly_linked_list<t_01>::circular_singly_linked_list(void)
	:
	head(make_shared<list_node<t_01> >()),
	now_size(0)
{
	head->next=head;
}

template<typename t_01>
data_structure::linear_table::linked_list::circular_singly_linked_list<t_01>::~circular_singly_linked_list(void)
{
	shared_ptr<list_node<t_01> > p=head;
	while (p->next != head)
	{
		p = p->next;
	}

	now_size = 0;
	head = NULL;
}


template<typename t_01>
int data_structure::linear_table::linked_list::circular_singly_linked_list<t_01>::data_size()
{
	return now_size;
}

template<typename t_01>
void data_structure::linear_table::linked_list::circular_singly_linked_list<t_01>::data_insert(const t_01 & item, int i)
{
	if (i<0 || i>now_size)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	else
	{
		shared_ptr<list_node<t_01> > p = index(i - 1);
		shared_ptr<list_node<t_01> > q =make_shared<list_node<t_01> >(item,p->next);
		p->next = q;
		now_size++;
	}
}

template<typename t_01>
t_01 data_structure::linear_table::linked_list::circular_singly_linked_list<t_01>::data_delete(int i)
{
	if (now_size == 0)
	{
		cout << "循环单链表已空，无元素可删" << endl;
		exit(0);
	}
	else if (i<0 || i>now_size - 1)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	else
	{
		t_01 i_data = index(i)->data;
		shared_ptr<list_node<t_01> > p = index(i - 1);
		p->next = p->next->next;
		now_size--;
		return i_data;
	}
}

template<typename t_01>
t_01 data_structure::linear_table::linked_list::circular_singly_linked_list<t_01>::data_get(int i)
{
	if (i<-1 || i>now_size)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	else if (i == now_size)
	{
		return head->data;//修改到这里
	}
	else
	{
		return index(i)->data;
	}
}

template<typename t_01>
void data_structure::linear_table::linked_list::circular_singly_linked_list<t_01>::start_test()
{
	circular_singly_linked_list();
	cout << "data_size() = " << data_size() << endl;
	data_insert(000, 0);
	data_insert(111, 1);
	data_insert(222, 2);
	data_insert(333, 3);
	data_insert(444, 4);
	data_insert(555, 5);
	data_insert(666, 6);
	data_insert(777, 7);
	cout << "data_size() = " << data_size() << endl;
	data_delete(3);
	cout << "data_delete(3)" << endl;
	cout << "data_size() = " << data_size() << endl;
	cout << "data_get(0) = " << data_get(0) << endl;
	cout << "data_get(1) = " << data_get(1) << endl;
	cout << "data_get(2) = " << data_get(2) << endl;
	cout << "data_get(3) = " << data_get(3) << endl;
	cout << "data_get(4) = " << data_get(4) << endl;
	cout << "data_get(5) = " << data_get(5) << endl;
	cout << "data_get(6) = " << data_get(6) << endl;
	cout << "data_get(7) = " << data_get(7) << endl;//i越界出错
}


int main()
{
	data_structure::linear_table::sequence_table ds_lt_st;
	//ds_lt_st.start_test();
	data_structure::linear_table::linked_list::singly_linked_list<int> ds_lt_ll_sll;
	//ds_lt_ll_sll.start_test();
	data_structure::linear_table::linked_list::circular_singly_linked_list<int> ds_lt_ll_csll;
	ds_lt_ll_csll.start_test();

	return 0;
}