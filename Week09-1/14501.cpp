#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > v(16);
int N;
bool Select[16];
int maxx = 0;
int cal(int day)
{
	if (day == N+1)
	{
		int ret = 0;
		for (int i = 1; i <= N; i++)
		{
			if (Select[i])
			{
				ret += v[i].second;
			}
		}
		return ret;
	}
	else {

		for (int i = N; i > 0; i--)
		{
			if (Select[i])
			{
				if (i + v[i].first>N)
				{
					Select[i] = false;
				}
			}
		}
		int ret = 0;
		for (int i = 1; i <= N; i++)
		{
			if (Select[i])
			{
				ret += v[i].second;
			}
		}
		return ret;
	}
	
}


void dfs(int idx, int count)
{
	
	if (count >= N+1)
	{
		int total = cal(count);
		maxx = maxx < total ? total : maxx;
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		
		int date = i + v[i].first;
		
		Select[i] = true;
		dfs(date,  date);
		Select[i] = false;
	}

}


int main()
{
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		int T, P;
		cin >> T >> P;
		
		v[i].first = T;
		v[i].second = P;
		
	}

	
	dfs(1,0);

	cout << maxx;

}