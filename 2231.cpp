#include <iostream>
#include <string>
using namespace std;
int n, cnt, maxx;
int total;
string str;

void ctor()
{
	for (int i = n - maxx; i < n; i++)
	{
		total = i;
		string b;
		b = to_string(total);
		for (int j = 0; j < b.length(); j++)
		{
			total += b[j] - '0';
		}

		if (total == n)
		{
			cout << i;
			return;
		}
		
	}
	cout << "0";

}

int main()
{
	cin >> str;	n = stoi(str);
	cnt = str.length();
	
	if (cnt == 1)
	{
		maxx = 9;
	}
	else if (cnt == 2)
	{
		maxx = 18;
	}
	else if (cnt == 3)
	{
		maxx = 27;
	}
	else if (cnt == 4)
	{
		maxx = 36;
	}
	else if (cnt == 5)
	{
		maxx = 45;
	}
	else if (cnt == 6 || cnt ==7)
	{
		maxx = 54;
	}
	ctor();
	
}