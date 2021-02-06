#include <iostream>
#include <string>
using namespace std;

int n ,series=0, cnt=666;
string str;
int main()
{

	cin >> n;

	while (1)
	{
		str = to_string(cnt);
		int check_size = str.length() - 2;
		for (int i = 0; i < check_size; i++)
		{
			if (str[i] == '6' &&str[i + 1] == '6' &&str[i + 2] == '6')
			{
				series++;
				if (series == n)
				{
					cout << cnt << "\n";
					return 0;
				}
				break;
			}
		}
		cnt++;
	}
}