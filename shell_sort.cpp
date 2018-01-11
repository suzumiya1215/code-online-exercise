#include"stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<iterator>
using namespace std;

template<typename t_num>
class sort
{
public:
	stack<int> sta_increment(int s);//增量序列
	vector<t_num> insertion_sort_4(vector<t_num> vec_cin , int k);
	vector<t_num> shell_sort(vector<t_num> vec_cin);
};


template<typename t_num>
stack<int> sort<t_num>::sta_increment(int s)
{
	stack<int> sta_num;
	sta_num.emplace(1);
	for (int k = 1 , i; k != s / 2; ++k)
	{
		i = pow(2 , k) + 1;
		if (i <= s)
			sta_num.emplace(i);
		else
			break;
	}
	return sta_num;
}

//增量*k
template<typename t_num>
vector<t_num> sort<t_num>::insertion_sort_4(vector<t_num> vec_cin , int k)
{
	int k_max = vec_cin.size() / k;
	t_num num;
	for (int i = 1; i != k_max; ++i)
	{
		num = vec_cin.at(i*k);
		for (int j = i - 1; j >= 0; j--)
		{
			if (num < vec_cin.at(j*k))
			{
				vec_cin.at((j+1) *k) = vec_cin.at(j*k);
				vec_cin.at(j*k) = num;
			}
			else
				break;
		}
	}
	return vec_cin;
}

template<typename t_num>
vector<t_num> sort<t_num>::shell_sort(vector<t_num> vec_cin)
{
	if (vec_cin.empty())
		return vec_cin;
	else if (vec_cin.size() > 0 && vec_cin.size() < 3)
	{
		insertion_sort_4(vec_cin,1);
		return vec_cin;
	}
	else
	{
		//增量序列
		stack<int> sta_incre_big = sta_increment(vec_cin.size());
		if (sta_incre_big.top() == vec_cin.size())
			sta_incre_big.pop();
		while (!sta_incre_big.empty())
		{
			stack<int> sta_incre_small = sta_increment(sta_incre_big.top());
			while (!sta_incre_small.empty())
			{
				//等距插入排序
				int now_incre_num = sta_incre_small.top();
				vec_cin=insertion_sort_4(vec_cin , now_incre_num);
				sta_incre_small.pop();
			}
			sta_incre_big.pop();
		}

		return vec_cin;
	}
}