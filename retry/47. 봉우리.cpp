#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

// 47. 봉우리 
int m_map[51][51];
int dy[4]{ 0,-1,0,1 };
int dx[4]{ 1,0,-1,0 };
int cnt, n;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &m_map[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			bool visited = false;

			for (int d = 0; d < 4; d++)
			{
				if (m_map[i][j] <= m_map[i + dy[d]][j + dx[d]])
				{
					visited = true;
					break;
				}
			}

			if (!visited)
			{
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;

}
