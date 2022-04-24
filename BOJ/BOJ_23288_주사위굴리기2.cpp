
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 23288. 주사위 굴리기2

int n, m, x, y, k, cnt = 0;
int board[21][21];
int scoreMap[21][21];
queue <int> command;
int dice[7] = { 0,1,2,3,4,5,6 };
// 동 1 서 2 북 3 남 4
int dx[4] = { 1,-1,0,0, };
int dy[4] = { 0,0,-1,1, };

void Up()
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


int calScore(int y, int x)
{
	if (scoreMap[y][x] > 0) return scoreMap[y][x];

	int moveCnt = 1; //C 이동할수있는 칸의수
	int num = board[y][x]; // 정수 B
	int checkNum = 777;

	queue <pair<int, int>> find;
	find.push({ y,x });
	scoreMap[y][x] = checkNum;

	while (!find.empty())
	{
		int cx = find.front().second;
		int cy = find.front().first;
		find.pop();

		for (int d = 0; d < 4; d++)
		{
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1) continue;
			if (board[ny][nx] == num && scoreMap[ny][nx] == 0)
			{
				moveCnt++;
				find.push({ ny,nx });
				scoreMap[ny][nx] = checkNum;
			}
		}
	}
	//return (moveCnt * num);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (scoreMap[i][j] == checkNum)
			{
				scoreMap[i][j] = moveCnt * num;
			}
		}
	}
	return scoreMap[y][x];
}
int getDir(int y, int x, int dir)
{
	int diceA = dice[6];
	//cout << "주사위 밑면" << diceA << endl;
	int boardB = board[y][x];//calScore( y,  x);
	int ansDir = 0;
	if (diceA > boardB)
	{
		switch (dir)
		{
		case 1:
			ansDir = 4; break; //Down();
		case 2:
			ansDir = 3; break; // Up(); 
		case 3:
			ansDir = 1; break; //Right();
		case 4:
			ansDir = 2; break;//Left();
		}
	}
	else if (diceA < boardB)
	{
		switch (dir)
		{
		case 1:
			ansDir = 3; break; //Up(); 
		case 2:
			ansDir = 4; break; //Down();
		case 3:
			ansDir = 2; break; //Left();
		case 4:
			ansDir = 1; break; //Right();
		}
	}
	else {
		ansDir = dir;
	}

	return ansDir;
}

int moveDice(int y, int x, int tryCnt)
{
	int sum = 0;
	while (!command.empty())
	{
		int cmd = command.front();
		command.pop();
		//cout << "pos y, x: " << y << " " << x << endl;
		if (tryCnt < k)
		{
			tryCnt++;
			switch (cmd)
			{
			case 1: // 동
				if (x + 1 < m)
				{
					Right();
					x++;
					sum += calScore(y, x);
					command.push(getDir(y, x, 1));
				}
				else {
					Left();
					x--;
					sum += calScore(y, x);
					command.push(getDir(y, x, 2));
				}
				break;
			case 2: // 서
				if (x - 1 >= 0)
				{
					Left();
					x--;
					sum += calScore(y, x);
					command.push(getDir(y, x, 2));

				}
				else {
					Right();
					x++;
					sum += calScore(y, x);
					command.push(getDir(y, x, 1));
				}
				break;
			case 3: // 북
				if (y - 1 >= 0)
				{
					Up();
					y--;
					sum += calScore(y, x);
					command.push(getDir(y, x, 3));
				}
				else {
					Down();
					y++;
					sum += calScore(y, x);
					command.push(getDir(y, x, 4));
				}
				break;
			case 4: //남
				if (y + 1 < n)
				{
					Down();
					y++;
					sum += calScore(y, x);
					command.push(getDir(y, x, 4));
				}
				else {
					Up();
					y--;
					sum += calScore(y, x);
					command.push(getDir(y, x, 3));
				}
				break;
			}
		}

	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	//cout<<calScore(0, 1);
	command.push(1);
	// 동 1 서 2 북 3 남 4

	cout << moveDice(0, 0, 0) << endl;

	return 0;
}