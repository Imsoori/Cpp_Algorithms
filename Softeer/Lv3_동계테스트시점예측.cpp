#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int N, M;
int m_map[101][101];
int m_visited[101][101];
int day;
int dx[4] = { 1,0,-1,0 };//µ¿
int dy[4] = { 0,1,0,-1 };

void bfs(int y, int x)
{
	queue <pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) continue;

			if (m_map[ny][nx] == 0 && m_visited[ny][nx] == 0)
			{
				m_visited[ny][nx] = 1;
				q.push({ ny,nx });
			}

		}
	}

}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector <pair<int, int>> icePos;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> m_map[i][j];

			if (m_map[i][j])
			{
				icePos.push_back({ i,j });
			}
		}
	}

	m_visited[1][1] = 1;

	//¹Ù±ù°ø±â bfs
	bfs(1, 1);

	int cy, cx, cnt, ny, nx;
	while (!icePos.empty())
	{
		queue <pair<int, int>> iceCnt;
		for (int i = 0; i < icePos.size(); i++)
		{
			cy = icePos[i].first;
			cx = icePos[i].second;
			cnt = 0;

			for (int d = 0; d < 4; d++)
			{
				ny = cy + dy[d];
				nx = cx + dx[d];

				if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) continue;

				if (m_visited[ny][nx] == 1)
				{
					cnt++;

					if (cnt > 1)
					{
						m_map[cy][cx] = 0;
						iceCnt.push({ cy,cx });
						//continue;
					}
				}

			}
		}

		icePos.clear();

		while (!iceCnt.empty())
		{
			int y = iceCnt.front().first;
			int x = iceCnt.front().second;
			iceCnt.pop();

			m_visited[y][x] = 1;
			bfs(y, x);
		}

		day++;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (m_map[i][j])
				{
					icePos.push_back({ i,j });
				}
			}
		}
	}

	cout << day << endl;

	return 0;
}