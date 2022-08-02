#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<deque>
using namespace std;

// 20055. 컨베이어 벨트위의 로봇

deque <pair<bool, int>> dq;
int n, k, cntStep = 0;

void rotate()
{
	pair<bool, int> tmp = dq.back();
	dq.pop_back();
	dq.push_front(tmp);

	// 로봇 내리는 위치 도달 즉시 내림
	dq[n - 1].first = false;
}

void move()
{
	for (int i = n - 2; i >= 0; i--)
	{
		if (dq[i + 1].first == false && dq[i + 1].second > 0 && dq[i].first == true)
		{
			dq[i].first = false;
			dq[i + 1].first = true;
			dq[i + 1].second--;
		}
	}
	// 로봇 내리는 위치 도달 즉시 내림
	dq[n - 1].first = false;
}

void uploadRobot()
{

	if (dq.front().second > 0 && dq.front().first == false)
	{
		dq.front().first = true;
		dq.front().second--;

	}
}

int cntDurabilty()
{
	int endPoint = 0;

	for (auto itr : dq)
	{
		if (itr.second == 0)
		{
			endPoint++;
		}
	}

	return endPoint;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	scanf("%d %d", &n, &k);

	bool isRobot = false;
	int durability = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		scanf("%d", &durability);
		dq.push_back({ isRobot,durability });
	}

	while (true)
	{
		if (cntDurabilty() >= k) break;

		cntStep++;

		rotate();
		move();
		uploadRobot();


	}

	printf("%d\n", cntStep);

	return 0;

}