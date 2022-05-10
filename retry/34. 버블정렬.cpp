#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int N, M;
vector <int> arr;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int i = 0;
	while (i < N - 2)
	{
		if (arr[i] > arr[i + 1])
		{
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;

			i = 0;
		}
		else {
			i++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}