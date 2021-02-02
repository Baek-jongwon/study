#include <iostream>
#include <algorithm>

using namespace std;


bool compare(char &a, char &b)
{
	return a >b;
}


int main()
{

	string str;
	cin >> str;
	sort(str.begin() , str.end() , compare);
	cout << str;


}