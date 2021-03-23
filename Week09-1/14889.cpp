#include <iostream>
#include <vector>

using namespace std;
bool people[20];
int stats[20][20];
int n;
int minn = 987654321;



int find_min()
{
	vector<int> start;
	vector<int> link;
	for (int i = 0; i < n; i++)
	{
		if (people[i]) start.push_back(i);
		else link.push_back(i);
	}
	int start_stats = 0;
	int link_stats = 0;
	for (int i = 0; i < start.size(); i++)
	{
		//cout << "start : " << start[i] << " link : " << link[i] << endl;
		for (int j = 0; j < start.size(); j++)
		{
			if (i != j)
			{
				start_stats += stats[start[i]][start[j]];
				link_stats += stats[link[i]][link[j]];
			}
		}
	}
	
	return abs(start_stats - link_stats);
}



void comb(int idx, int count)
{
	if (count == n / 2)
	{
		int num = find_min();
		minn = minn > num ? num : minn;
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (people[i]) continue;
		people[i] = true;
		comb(i, count + 1);
		people[i] = false;
	}

}


int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> stats[i][j];
		}
	}

	comb(0, 0);

	cout << minn;
}