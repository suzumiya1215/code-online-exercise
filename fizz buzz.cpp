#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n=0;
	cin >> n;
	vector<string> vec;
	for (int i = 1; i <= n; ++i)
	{
		if (i % 3 == 0 && i % 5 == 0)
			vec.push_back( "fizz buzz");
		else if (i % 3 == 0)
			vec.push_back("fizz");
		else if (i % 5 == 0)
			vec.push_back("buzz");
		else
			vec.push_back(to_string(i));
	}
	for (vector<string>::iterator iter=vec.begin();iter!=vec.end();++iter)
		cout << *iter << endl;

	system("pause");
	return 0;
}