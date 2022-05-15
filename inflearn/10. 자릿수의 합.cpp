

#include<iostream>
#include<vector>
#include <queue>
#include <string>
#include <cctype>

using namespace std;
// 10. 자릿수의 합

int N;
int cnt[101], ans = 0;
priority_queue <int> pq;

int digit_sum(int x)
{
	int result = 0;
	while (x > 0)
	{
		result += x % 10;
		x = x / 10;
	}
	return result;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cnt[i];
		ans = max(ans, digit_sum(cnt[i]));
	}

	for (int i = 0; i < N; i++) {
		if (digit_sum(cnt[i]) == ans)
		{
			pq.push(cnt[i]);
		}
	}

	cout << pq.top() << endl;

	return 0;
}