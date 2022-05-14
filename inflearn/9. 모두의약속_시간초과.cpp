

#include<iostream>
#include<vector>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

//9. 모두의 약수

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector <int> v;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				cnt++;
			}
		}
		v.push_back(cnt);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}