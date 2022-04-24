
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//21608. 상어 초등학교

struct Student {
	int id;
	int y, x;
	int lover[4];
};

struct Info {
	int c; //열
	int r; // 행
	int blanks = 0;
	int friends = 0;

	bool operator <(const Info& a)const {
		if (friends == a.friends)
		{
			if (blanks == a.blanks)
			{
				if (r == a.r) return c > a.c;
				else return r > a.r;
			}
			else return blanks < a.blanks;
		}
		else return friends < a.friends;
	}
};


int n;
int m_blank, m_friend;
int board[21][21];
int score[] = { 0,1,10,100,1000 };
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	vector <Student> students(n * n);

	for (int i = 0; i < n * n; i++)
	{
		cin >> students[i].id;
		for (int j = 0; j < 4; j++)
		{
			cin >> students[i].lover[j];
		}
	}

	//1. 자리 배치
	for (int a = 0; a < n * n; a++) // 각 학생별
	{
		priority_queue <Info> pq;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				if (board[i][j] == 0) {
					m_blank = 0, m_friend = 0;
					for (int d = 0; d < 4; d++)
					{
						int nx = j + dx[d];
						int ny = i + dy[d];
						if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;
						if (board[ny][nx] == 0) {
							m_blank++;
						}
						else {
							for (int f = 0; f < 4; f++)
							{
								if (board[ny][nx] == students[a].lover[f])
								{
									m_friend++;
									break;
								}
							}

						}
					}
					pq.push({ j,i,m_blank,m_friend });
				}

			}

		}
		if (!pq.empty())
		{
			int posX = pq.top().c;
			int posY = pq.top().r;

			board[posY][posX] = students[a].id;
			students[a].x = posX;
			students[a].y = posY;
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j]<<" ";
		}
		cout << endl;
	}*/

	//2. 만족도 점수 계산
	int ans = 0;
	for (int a = 0; a < n * n; a++)
	{
		int x = students[a].x;
		int y = students[a].y;

		int tmpScore = 0;
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;
			for (int k = 0; k < 4; k++)
			{
				if (students[a].lover[k] == board[ny][nx])
				{
					tmpScore++;
					break;
				}
			}
		}
		ans += score[tmpScore];

	}


	cout << ans << endl;

	return 0;
}