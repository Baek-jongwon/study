//#include <iostream>
//
//using namespace std;
//
//
//int main()
//{
//	int n;
//	bool triangle=false;
//	cin >> n;
//
//	int TriangleNum[45];
//
//	for (int i = 1; i <= 45; i++)
//	{
//		TriangleNum[i - 1] = i * (i + 1) / 2;
//	}
//	for(int a=0; a<n; a++)
//	{
//		int num;
//		cin >> num;
//		for (int i = 0; i < 45; i++)
//		{
//			for (int j = 0; j < 45; j++)
//			{
//				for (int k = 0; k < 45; k++)
//				{
//					if (TriangleNum[i] + TriangleNum[j] + TriangleNum[k] == num)
//					{
//						triangle = true;
//						
//					}
//					
//				}
//			}
//		}
//		if (triangle)
//		{
//			cout << "1\n";
//		}
//		else {
//			cout << "0\n";
//		}
//		triangle = false;
//	}
//
//
//
//}