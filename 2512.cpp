//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, m;
//
//long long total;
//int mid;
//
//vector<int> v;
//bool check()
//{
//	total = 0;
//	for (int i = 0; i < n; i++)
//	{
//		total += min(v[i], mid);
//		
//	}
//
//	return total <= m;
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	int r = 0;
//	int l = 1;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		int num;
//		cin >> num;
//		v.push_back(num);
//		r = r < num ? num : r;
//	}
//	cin >> m;
//	int result = 0;
//	while (l <= r)
//	{
//		mid = (l + r) / 2;
//		if (check())
//		{
//			result = mid;
//			l = mid+1;
//		}
//		else
//		{
//			r = mid - 1;
//		}
//	}
//	cout << result;
//
//}