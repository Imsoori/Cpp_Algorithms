#include<iostream>
#include <algorithm>

using namespace std;

int n, m;
int maxVelocity = 0;
int given[101];
int setting[101];


int main(int argc, char** argv)
{
	cin >> n >> m;
	int dis, h = 0, vel, j = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> dis >> vel;
		h += dis;
		for (; j <= h; j++)
		{
			given[j] = vel;
		}
	}
	h = 0;
	j = 1;

	for (int i = 0; i < m; i++)
	{
		cin >> dis >> vel;
		h += dis;
		for (; j <= h; j++)
		{
			setting[j] = vel;
		}
	}
	int over;
	for (int i = 1; i <= 100; i++)
	{
		if (setting[i] > given[i])
		{
			over = setting[i] - given[i];
			maxVelocity = max(maxVelocity, over);
		}

	}

	cout << maxVelocity << endl;
	return 0;
}