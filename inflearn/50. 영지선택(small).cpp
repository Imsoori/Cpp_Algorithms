#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 50. 영지 선택
int m_map[51][51];
int m_h, m_w, h, w;
int cnt = -2147000000, sum = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	scanf("%d %d", &m_h, &m_w);

	for (int i = 0; i < m_h; i++)
		for (int j = 0; j < m_w; j++)
		{
			scanf("%d", &m_map[i][j]);
		}

	scanf("%d %d", &h, &w);


	for (int i = 0; i <= m_h - h; i++)
	{
		for (int j = 0; j <= m_w - w; j++)
		{
			sum = 0;
			for (int x = i; x < i + h; x++)
			{
				for (int y = j; y < j + w; y++)
				{
					sum += m_map[x][y];

				}
			}
			if (sum > cnt) {
				cnt = sum;
			}

		}
	}

	printf("%d\n", cnt);

	return 0;

}