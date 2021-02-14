//#include <iostream>
//
//#define maxx 100001
//using namespace std;
//
//int buf[2][maxx] = {0,};
//int dp[2][maxx] = {0,};
//int n;
//
//int max(int a, int b)
//{
//	if (a > b) return a;
//	return b;
//}
//
//int main()
//{
//	cin >> n;
//
//	while (n--)
//	{
//		int num;
//		cin >> num;
//
//		for (int i = 0; i < num; i++)
//		{
//			cin >>	buf[0][i];
//		}
//		for (int j = 0; j < num; j++)
//		{
//			cin >> buf[1][j];
//		}
//		dp[0][0] = buf[0][0];
//		dp[1][0] = buf[1][0];
//		dp[0][1] = dp[1][0] + buf[0][1];
//		dp[1][1] = dp[0][0] + buf[1][1];
//
//		for (int i = 2; i < num; i++)
//		{
//			dp[0][i] = buf[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
//			dp[1][i] = buf[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
//		}
//		cout << max(dp[0][num - 1], dp[1][num - 1])<<"\n";
//
//
//	}
//
//}