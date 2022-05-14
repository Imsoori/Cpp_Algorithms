

#include<iostream>
#include<vector>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

//9. 모두의 약수
int N;
int cnt[50001];


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j = j + i)
		{
			cnt[j] += 1;
		}

	}

	for (int i = 1; i <= N; i++)
	{
		cout << cnt[i] << " ";
	}

	return 0;
}