#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#include <sstream>
using namespace std;

vector<int> insertion_sort_1(vector<int> vec)//STL插入排序
{
	for (vector<int>::iterator iter1 = vec.begin() + 1; iter1 != vec.end(); ++iter1)
	{
		vector<int>::iterator iter2 = iter1 - 1;
		while (*iter1 < *iter2)
		{
			swap(*iter1, *iter2);
			if (iter2 != vec.begin())
			{
				iter1 = iter2;
				iter2 = iter1 - 1;
			}
		}
	}
	return vec;
}

vector<int> insertion_sort_2(vector<int> vec)//普通插入排序
{
	for (int i = 1; i != vec.size(); ++i)
	{
		while (vec[i] < vec[i - 1])
		{
			int a = vec[i - 1];
			vec[i - 1] = vec[i];
			vec[i] = a;
			if (i != 1)
				i -= 1;
		}
	}
	return vec;
}