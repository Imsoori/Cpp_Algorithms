#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 53. k 진수 출력

int n, k;
int ans;
vector <int> R;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	scanf("%d %d", &n, &k);

	while (true)
	{
		int q = n % k;
		R.push_back(q);
		n = n / k;

		if (n < k)
		{
			R.push_back(n);
			break;
		}
	}

	while (!R.empty())
	{
		if (k == 16)
		{
			printf("%X", R.back());
		}
		else {
			printf("%d", R.back());
		}
		R.pop_back();
	}

	return 0;

}