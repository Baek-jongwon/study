#include <iostream> // X


using namespace std;

int n , num;
int value[40] = {0,1,};

int fibonacci(int number)
{
	if (number == 0 || number == 1)
		return value[number];
	else if(value[number]==0)
	{
		value[number] = fibonacci(number - 1) + fibonacci(number - 2);
	}
	return value[number];
}


int main()
{
	cin >> n;
	while (n--)
	{
		cin >> num;
		if (num == 0)
		{
			cout << "1 0\n";
		}
		else if (num == 1)
		{
			cout << "0 1\n";
		}
		else {
			fibonacci(num);
			cout << value[num-1] << " " << value[num]<< "\n";
		}
	}
}