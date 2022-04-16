#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 75 최대 수입 스케줄

struct Info {
	int cost;
	int day;

	Info(int a, int b)
	{
		cost = a;
		day = b;
	}

	bool operator<(const Info tmp)const {
		return day > tmp.day;
	}
};





int main()
{
	int n;
	int a, b;
	int maxDay = -2147000000;
	int ans = 0;

	vector <Info> v;
	priority_queue <int> pq;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &a, &b);
		v.push_back(Info(a, b));
		if (b > maxDay) maxDay = b;
	}


	sort(v.begin(), v.end());

	//for (Info x:v)
	//{
	//	printf("%d %d\n", x.cost, x.day);
	//}
	int j = 0;

	for (int i = maxDay; i > 0; i--)
	{
		for (; j < n; j++)
		{
			if (v[j].day < i) break;
			pq.push(v[j].cost);
		}
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}


	printf("%d\n", ans);

	return 0;
}