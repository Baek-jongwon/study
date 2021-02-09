#include <iostream>
#include <string>
using namespace std;

string king, stone , direction;
int n,x_1,y_1,x_2,y_2;
int king_x, king_y;
int stone_x, stone_y;
string chess_[8][8] ={{"A8","B8","C8","D8","E8","F8","G8","H8" },
					{"A7","B7","C7","D7","E7","F7","G7","H7" },
					{"A6","B6","C6","D6","E6","F6","G6","H6" },
					{"A5","B5","C5","D5","E5","F5","G5","H5" },
					{"A4","B4","C4","D4","E4","F4","G4","H4" },
					{"A3","B3","C3","D3","E3","F3","G3","H3" },
					{"A2","B2","C2","D2","E2","F2","G2","H2" },
					{"A1","B1","C1","D1","E1","F1","G1","H1" },
					};
int move(string pos , int i , int j)
{
	int x=i, y=j;
	if (pos == "R")
	{
		x++;
	}
	else if (pos == "L")
	{
		x--;
	}
	else if (pos == "B")
	{
		y++;
	}
	else if (pos == "T")
	{
		y--;
	}
	else if (pos == "RT")
	{
		x++;
		y--;
	}
	else if (pos == "LT")
	{
		x--;
		y--;
	}
	else if (pos == "RB")
	{
		x++;
		y++;
	}
	else if (pos == "LB")
	{
		x--;
		y++;
	}
	
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
	{
		return x, y;
	}
	else
	{
		return i, j;
	}
}


int main()
{
	
	
	cin >> king >> stone >> n;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chess_[i][j] == king)
			{
				king_x = j;
				king_y = i;
			}
			if (chess_[i][j] == stone)
			{
				stone_x = j;
				stone_y = i;
			}
			
		}
	}
	

	while (n--)
	{
		cin >> direction;
		x_1 = king_x;
		y_1 = king_y;
		x_2 = stone_x;
		y_2 = stone_y;

		king_x, king_y = move(direction, king_x, king_y);
		if (king_x == stone_x && king_y == stone_y)
		{
			stone_x, stone_y = move(direction, stone_x, stone_y);
			if (((x_1 == king_x || y_1 == king_y) && (x_2 != stone_x || y_2 != stone_y)))
			{
				stone_x = x_2;
				stone_y = y_2;
			}
			else if (((x_1 != king_x || y_1 != king_y) && (x_2 == stone_x || y_2 == stone_y)))
			{
				king_x = x_1;
				king_y = y_1;
			}
		}
		
		


	}
	cout << chess_[king_y][king_x] << "\n";
	cout << chess_[stone_y][stone_x] << "\n";

}