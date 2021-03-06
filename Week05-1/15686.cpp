//결과: 시간초과 
// https://na982.tistory.com/?page=31 참고 하여 아래 항목 수정.
// 1. vector<pair<int,int>> 를 사용하지 않고 구조체 활용
// 2. cin, cout => scanf , printf 변경 
// 참고한 코드와 거의 유사하지만 시간초과 나는 이유??

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct POS {
	int y, x;
};
vector<POS > home, ch, pick;

int ret = 250000;
int n, m, type;

void dfs(int curr)
{
	if (pick.size() == m)
	{
		int c_minn = 0;
		for (int i = 0; i < home.size(); i++)
		{
			int minn = 250000;
			for (int j = 0; j < pick.size(); j++)
			{
				minn = min(minn, abs(home[i].y - pick[j].y) + abs(home[i].x - pick[j].x));

			}
			c_minn += minn;
		}

		if (ret > c_minn)
		{
			ret = c_minn;
		}

		return;
	}

	for (int i = curr; i < ch.size(); i++)
	{
		pick.push_back(ch[i]);
		dfs(curr + 1);
		pick.pop_back();
	}
}

int main()
{

	POS target;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &type);
			if (type == 1)
			{
				target.y = i; target.x = j;
				home.push_back(target);
			}
			if (type == 2)
			{
				target.y = i; target.x = j;
				ch.push_back(target);
			}
		}
	}
	dfs(0);

	printf("%d\n", ret);
	return 0;
}
