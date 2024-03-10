#include<bits/stdc++.h>
using namespace std;
int row, col, Round;
#define For(i, a, b) for(int i = a; i <= b; i ++)
struct Cell
{
	bool state;
	int x, y;
	int size;
};

Cell C[1005][1005];

void CountCell(Cell &p)
{
	int cnt = 0;
	int x = p.x;
	int y = p.y;
	For(i, -1, 1)
	{
		For(j, -1, 1)
		{
			if(C[x + i][y + j].state)
			{
				cnt ++;
			}
		}
	}
	if(C[x][y].state) cnt --;
	p.size = cnt;
}

void Update()
{
	For(i, 1, row)
	{
		For(j, 1, col)
		{
			if(C[i][j].size == 3)
			{
				C[i][j].state = 1;
			}
			else
			{
				if(C[i][j].state && C[i][j].size == 2)
				{
					C[i][j].state = 1;
				}
				else
				{
					C[i][j].state = 0;
				}
			}
		}
	}
}

void OutPut()
{
	For(i, 1, row)
	{
		For(j, 1, col)
		{
			if(C[i][j].state)
			{
				cout << 1 << ' ';
			}
			else
			{
				cout << 0 << ' ';
			}
		}
		cout << endl;
	}
}

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> row >> col >> Round;
	For(i, 1, row)
	{
		For(j, 1, col)
		{
			int State;
			cin >> State;
			C[i][j].state = State;
			C[i][j].x = i;
			C[i][j].y = j;
		}
	}
	while(Round --)
	{
		For(i, 1, row)
		{
			For(j, 1, col)
			{
				CountCell(C[i][j]);
			}
		}
		Update();
		OutPut();
		cout << endl;
	}
}


