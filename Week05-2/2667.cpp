#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
int house[26][26];
bool visited[26][26];

int dx[4] = { 0 , 0 , -1 , 1 }; 
int dy[4] = { 1 , -1 , 0 , 0 };

int cnt;
int dfs(int y, int x)
{
	
	visited[y][x] = false;
	for (int i = 0; i < 4; i++)
	{
		int new_y = y + dy[i];
		int new_x = x + dx[i];
		
		if (new_y > 0 && new_y <= n && new_x > 0 && new_x <= n)
		{
			if (house[new_y][new_x] == 1 && visited[new_y][new_x])
			{
				dfs(new_y, new_x);
				cnt++;
				
			}
			
		}
		
	}
	return cnt;
}
int main()
{
	string str;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 1; j <= n; j++)
		{
			house[i][j] = str[j - 1] - '0';
			if ((str[j - 1] - '0') == 1)
			{
				visited[i][j] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j])
			{
				cnt = 1;
				v.push_back(dfs(i, j));
			}
		}
	}
	int len = v.size();
	cout << len << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < len; i++)
	{
		cout << v[i]<<"\n";
	}
}