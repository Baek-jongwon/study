#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[100][100];
int n, l;
vector<int> v;

int check(vector<int> road)
{
	int total_road = 0;
	int before_road = 1;
	bool make_road = true;
	for (int i = 0; i < road.size()-1; i++)
	{
		if (road[i] == road[i + 1]) before_road++;
		else if (road[i] == road[i + 1] + 1)
		{
			bool part_check = true;
			if (i + l >= n) return total_road;
			for (int j = i + 1; j < i + l + 1; j++)
			{
				if (road[i+1] != road[j])
				{
					
					part_check = false;
					break;
				}
			}

			if (part_check)
			{
				before_road = 0;
				i = i + l - 1;
			}
			else {
				make_road = false;
				return total_road;
			}
		}
		else if (road[i] == road[i + 1] - 1)
		{
			if (before_road >= l)
			{
				before_road = 1;
			}
			else {
				make_road = false;
				return total_road;
			}
		}
		else if (abs(road[i] - road[i + 1]) >= 2) {
			make_road = false;
			return total_road;
		}


	}
	total_road++;
	
	return total_road;

}
int main()
{
	cin >> n >> l;

	int total = 0;
	for (int i = 0; i < n; i++)
	{
		v.clear();
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			v.push_back(map[i][j]);
		}
		total +=check(v);

	}
	for (int i = 0; i < n; i++)
	{
		v.clear();
		for (int j = 0; j < n; j++)
		{
			v.push_back(map[j][i]);
		}
		total += check(v);
	}
	cout << total << endl;



}
