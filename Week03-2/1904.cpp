//#include <iostream>
//
//#define max_ 1000001
//using namespace std;
//
//int n;
//long long d[1000001];
//
//int main()
//{
//	cin >> n;
//
//	d[1] = 1;
//	d[2] = 2;
//	for (int i = 3; i < max_; i++)
//	{
//		d[i] = (d[i - 1] + d[i - 2])%15746;
//	}
//
//	cout << d[n];
//
//}