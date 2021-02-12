#include <iostream>

using namespace std;

int n;
long long pn[91];

long long pn_cal(int number)
{
	if (number == 1 ||number ==2) return 1;

	if (pn[number] != 0) return pn[number];

	return pn[number] = pn_cal(number - 1) + pn_cal(number - 2);
}


int main()
{
	cin >> n;
	cout << pn_cal(n);
}