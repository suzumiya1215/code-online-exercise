#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#include <sstream>
using namespace std;

vector<int> Bubble_Sort(vector<int>& nums)//冒泡排序失败
{

	bool again = false;
	int time = 1;
	while (!again)
	{
		again = true;
		for (vector<int>::iterator iter1 = nums.begin() + time; iter1 != nums.end(); ++iter1)
		{
			vector<int>::iterator iter2 = iter1 - 1;
			if (*iter1 < *iter2)
			{
				swap(*iter1, *iter2);
				again = false;
			}
		}
	}

	return nums;

}