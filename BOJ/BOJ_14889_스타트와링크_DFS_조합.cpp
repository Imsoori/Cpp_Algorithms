#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


////14889. 스타트와 링크
int res = 2147000000;
int n;
int arr[22][22];
int visited[22];


int eachTeamScore(vector <int> v)
{
	int score = 0;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j) continue;

			score += arr[v[i]][v[j]];

		}
	}

	return score;
}


void compareTeam()
{
	vector <int> starter, linker;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
		{
			starter.push_back(i);
		}
		else {
			linker.push_back(i);
		}
	}

	int diff = abs(eachTeamScore(starter) - eachTeamScore(linker));

	res = min(diff, res);

}




void FindCase(int L, int cnt) //L: 기준점 cnt: 뽑을 원소의 갯수
{
	if (cnt == n / 2)
	{
		compareTeam();
		return;

	}
	else {
		for (int i = L; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				FindCase(i + 1, cnt + 1);
				visited[i] = 0;

			}
		}

	}
}



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	FindCase(1, 0);

	cout << res << endl;



	return 0;
}