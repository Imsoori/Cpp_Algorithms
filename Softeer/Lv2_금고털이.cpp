#include<iostream>
#include<queue>

using namespace std;

int n, w, ans = 0;
int mi, pi;
priority_queue <pair<int, int>> pq;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> w;

	for (int i = 0; i < w; i++)
	{
		cin >> mi >> pi;
		pq.push({ pi,mi });
	}

	while (n > 0)
	{
		if (pq.top().second > n)
		{
			ans = ans + (n * pq.top().first);
			n = 0;
		}
		else {
			ans = ans + (pq.top().second * pq.top().first);
			n -= pq.top().second;
			pq.pop();
		}

	}

	cout << ans << endl;
	return 0;
}