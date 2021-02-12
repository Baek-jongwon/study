#include <iostream>

using namespace std;

int n;
int rect[1001];

int func(int number)
{
	if (number == 1) return 1;
	if (number == 2) return 2;

	if (rect[number] != 0)
	{
		return rect[number];
	}
	
	return	rect[number] = (func(number - 1) + func(number - 2))%10007;
	
	
}


int main()
{
	cin >> n;
	cout << func(n);
}