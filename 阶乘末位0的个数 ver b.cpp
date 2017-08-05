#include<iostream>
using namespace std;

int main()
{
	int a = 0;
	while (cin >> a)
	{
		int count = 0;
		while (a)
		{
			count += a / 5;
			//n每次除以5,即相当于被除数每次乘以5
			a /= 5;
		}
		cout<<count<<endl;
	}

	system("pause");
	return 0;
}

int calculate(int n)
{
	int count = 0;
	while (n)
	{
		count += n / 5;
		//n每次除以5,即相当于被除数每次乘以5
		n /= 5;
	}
	return count;
}