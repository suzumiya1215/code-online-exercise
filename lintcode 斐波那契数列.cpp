#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int a = 0, b = 0;
	while (cin >> a)
	{
		if (a == 1)
			cout << 0 << endl;
		else if (a == 2)
			cout << 1 << endl;
		else if (a > 1)
		{
			vector<int> vec;
			vec.push_back(0);
			vec.push_back(1);
			for (int i = 1; i != a - 1; ++i)
			{
				b = vec[i] + vec[i - 1];
				vec.push_back(b);
			}
			cout << vec[a - 1] << endl;
		}
	}
	system("pause");
	return 0;
}