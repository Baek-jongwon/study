#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool visited[200];

void dfs(int node, vector<int> v[]) {

	visited[node] = true;

	for (int i = 0; i < v[node].size(); i++)
	{
		int next_node = v[node][i];
		if (!visited[next_node]) {
			dfs(next_node, v);
		}
	}
}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int size = computers.size();
	vector<int> v[size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != j) {
				if (computers[i][j] == 1)
				{
					v[i].push_back(j);
				}
			}
		}
	}


	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i]) {
			dfs(i, v);
			cnt++;
		}

	}
	answer = cnt;



	return answer;
}