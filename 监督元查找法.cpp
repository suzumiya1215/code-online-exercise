#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#include <sstream>
using namespace std;

int main(void)
{
	
	//监督元查找法
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,0 };
	vector<int>::iterator iter = vec.begin();
	for (;; ++iter)
	{
		if (*iter == 0)
			break;
	}

	if(iter!=vec.end())
		cout << "查找元素成功" << endl;


	int vec[] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (;;++i)
	{
		if (vec[i] == 0)
			break;
	}

	if (i != 9)
		cout << "查找元素成功" << endl;
	
	system("pause");
	return 0;
}