#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//76. 이항 계수
int n, r;
int dp[21][21];

int Combination(int a, int b)
{
	if (a == b || b == 0) return 1;
	if (dp[a][b] != 0) return dp[a][b];

	return dp[a][b] = Combination(a - 1, b - 1) + Combination(a - 1, b);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r;

	cout << Combination(n, r);

	return 0;
}