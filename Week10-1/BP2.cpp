#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int cnt;
int arr[10000000];
bool sosu(int num)
{
	if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++)  if (num%i == 0) return false;

	return true;
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void permutation(char data[], int depth, int n, int r)
{
	if (depth == r)
	{



		if (r == 1)
		{
			int value = data[0] - '0';
			if (sosu(value))
			{
				if (!arr[value])
				{
					arr[value] = 1;
					cnt++;
				}
			}
		}
		else {
			if (data[0] == '0') return;
			string s = "";
			for (int i = 0; i < r; i++)
			{
				s += data[i];
			}
			int value = stoi(s);
			if (sosu(value))
			{
				if (!arr[value])
				{
					arr[value] = 1;
					cnt++;
				}
			}
		}
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(data[depth], data[i]);
		permutation(data, depth + 1, n, r);
		swap(data[depth], data[i]);
	}

}




int solution(string numbers) {
	int answer = 0;
	int size = numbers.length();
	char number[size];
	for (int i = 0; i < size; i++)
	{
		number[i] = numbers[i];
	}

	cnt = 0;

	for (int i = 1; i <= size; i++)
	{
		permutation(number, 0, size, i);
	}

	answer = cnt;
	return answer;
}