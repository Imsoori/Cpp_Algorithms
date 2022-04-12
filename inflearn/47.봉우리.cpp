#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maze[51][51];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int mount = 0;
//47. 봉우리

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf_s("%d", &maze[i][j]);
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			bool check = false;
			for (int k = 0; k < 4; k++)
			{
				if (maze[i][j] <= maze[i + dx[k]][j + dy[k]])
				{
					check = true;
					break;
				}
				/*else {
					check = false;
					break;
				}*/
			}

			if (!check) {
				mount++;
				//printf("%d %d: %d\n", i, j, maze[i][j]);
			}
		}

	}

	printf("%d\n", mount);

	return 0;
}


