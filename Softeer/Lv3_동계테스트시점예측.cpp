#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int N, M;
int m_map[101][101];
int m_visited[101][101];
int day;
int dx[4] = { 1,0,-1,0 };//동
int dy[4] = { 0,1,0,-1 };


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

	// 바깥 공기 표시하기 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int cy = i;
			int cx = j;

			if (m_map[cy][cx] == 1) continue;

			for (int d = 0; d < 4; d++)
			{
				int ny = cy + dy[d];
				int nx = cx + dx[d];

				if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) continue;

				if (m_map[ny][nx] == 1)
				{
					m_map[cy][cx] = 2; // 바깥공기 
				}

			}
		}

	}

	// 바깥 공기와 인접한 치즈 구하기 

	while (!icePos.empty())
	{
		queue <pair<int, int>> iceCnt;
		for (int i = 0; i < icePos.size(); i++)
		{
			int cy = icePos[i].first;
			int cx = icePos[i].second;
			int cnt = 0;

			for (int d = 0; d < 4; d++)
			{
				int ny = cy + dy[d];
				int nx = cx + dx[d];

				if (ny<0 || nx<0 || ny>N - 1 || nx>M - 1) continue;

				if (m_map[ny][nx] == 2)
				{
					cnt++;
				}

			}

			if (cnt > 1)
			{
				iceCnt.push({ cy,cx });
			}
		}

		while (!iceCnt.empty())
		{
			m_map[iceCnt.front().first][iceCnt.front().second] = 0;
			iceCnt.pop();
		}

		day++;

		icePos.clear();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (m_map[i][j] == 1)
				{
					icePos.push_back({ i,j });

				}

			}

		}



	}

	cout << day << endl;

	return 0;
}