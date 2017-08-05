#include<iostream>
using namespace std;

int main()
{
	int a = 0;
	while (cin >> a)
	{
		if (a < 0)
			cout << "a<0" << endl;
		if (a >= 0 && a < 5)
			cout << "0" << endl;
		if (a > 4)
		{
			int b = 0;
			for (int i = 1; i <= a; ++i)
			{
				int c = i;
				while (c % 5 == 0)
				{
					++b;
					c /= 5;
				}
			}
			cout << b << endl;
		}
	}
	
	system("pause");
	return 0;
}