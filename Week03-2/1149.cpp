//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int h[1001][3];
//int cost_r, cost_g, cost_b;
//int main()
//{
//	cin >> n;
//	h[0][0] = 0;
//	h[1][0] = 0;
//	h[2][0] = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> cost_r >> cost_g >> cost_b;
//
//		h[i][0] = cost_r + min(h[i - 1][1], h[i - 1][2]);
//		h[i][1] = cost_g + min(h[i - 1][0], h[i - 1][2]);
//		h[i][2] = cost_b + min(h[i - 1][0], h[i - 1][1]);
//
//		
//	}
//
//	cout << min(h[n][0], min(h[n][1],h[n][2]));
//}