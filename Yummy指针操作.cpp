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
	
	//指针操作
	char food[] = "Yummy";
	char *ptr;

	ptr = food + strlen(food);
	while (--ptr >= food)
		puts(ptr);

	system("pause");
	return 0;
}