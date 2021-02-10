#include <iostream>
#include <string>

using namespace std;

string str[8] = { "R" , "L" ,"B","T","RT","LT","RB","LB" };
int delta_X[8] = { 1 , -1 , 0, 0 , 1 ,-1,1,-1 };
int delta_Y[8] = { 0 , 0 , -1 , 1 ,1,1,-1,-1 };
int n , king_x ,king_y, stone_x,stone_y;
string king, stone;
int main() 
{
	cin >> king >> stone >> n;

	king_x = king[0] - 'A' + 1;
	king_y = king[1] - '0';
	stone_x = stone[0] - 'A' + 1;
	stone_y = stone[1] - '0';


	while (n--)
	{
		string dir;
		cin >> dir;
		for (int i = 0; i < 8; i++)
		{
			if (dir == str[i])
			{
				int temp_x = king_x+delta_X[i];
				int temp_y = king_y+delta_Y[i];
				if (temp_x <= 0 || temp_x >= 9 || temp_y <= 0 || temp_y >= 9) break;

				if (temp_x == stone_x && temp_y == stone_y)
				{
					int temp_s_x = stone_x + delta_X[i];
					int temp_s_y = stone_y + delta_Y[i];

					if (temp_s_x <= 0 || temp_s_x >= 9 || temp_s_y <= 0 || temp_s_y >= 9) break;
					stone_x += delta_X[i];
					stone_y += delta_Y[i];
				}
				king_x += delta_X[i];
				king_y += delta_Y[i];

			}
		}
	}
	cout << char(king_x - 1 +'A') << king_y<<"\n";
	cout << char(stone_x - 1 + 'A') << stone_y << "\n";
}