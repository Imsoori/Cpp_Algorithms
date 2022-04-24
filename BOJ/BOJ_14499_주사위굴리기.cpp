
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//14499. 주사위 굴리기

int n, m, x, y, k;
int board[21][21];
queue <int> command;
int dice[7];


void UP()
{
	int tmp = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[6];
	dice[6] = dice[2];
	dice[2] = tmp;
}

void Down()
{
	int tmp = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[6];
	dice[6] = dice[5];
	dice[5] = tmp;
}

void Left()
{
	int tmp = dice[1];
	dice[1] = dice[3];
	dice[3] = dice[6];
	dice[6] = dice[4];
	dice[4] = tmp;
}

void Right()
{
	int tmp = dice[1];
	dice[1] = dice[4];
	dice[4] = dice[6];
	dice[6] = dice[3];
	dice[3] = tmp;

}

void changeMap(int y, int x)
{
	if (board[y][x] == 0)
	{
		board[y][x] = dice[6];
	}
	else {
		dice[6] = board[y][x];
		board[y][x] = 0;
	}
	cout << dice[1] << endl;
}

void moveDice(int y, int x)
{
	while (!command.empty())
	{
		int cmd = command.front();
		command.pop();

		switch (cmd)
		{
		case 1: // 동
			if (x + 1 < m)
			{
				Right();
				x++;
				changeMap(y, x);
			}
			break;
		case 2: // 서
			if (x - 1 >= 0)
			{
				Left();
				x--;
				changeMap(y, x);
			}
			break;
		case 3: // 북
			if (y - 1 >= 0)
			{
				UP();
				y--;
				changeMap(y, x);
			}
			break;
		case 4: //남
			if (y + 1 < n)
			{
				Down();
				y++;
				changeMap(y, x);
			}
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int tmp;

	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		command.push(tmp);

	}

	moveDice(y, x);

	return 0;
}