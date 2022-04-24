#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 1번 주차 문제...
int n=3;
int k=2;
int parking[10];

int Solution(int pos)
{
	int ans = 0;
	int adjNum = 0;
	int MinNum = -2147000000;

	if (parking[pos] > 0)
	{
		//cout << "pos: " << pos << " pakring[pos]: " << parking[pos] << endl;
		parking[pos] -= 1;
		ans = pos;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			if (parking[i] > 0)
			{
				if (adjNum == abs(pos - i))
				{
					MinNum = min(MinNum, i);
				}
				else {
					adjNum = abs(pos - i);
					MinNum = i;
				}

			}

		}
		ans = MinNum;
		parking[ans] -= 1;
	}

	return ans + 1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//vector <int> floor = { 2,2,1,3,1,2,2,1 };
	vector <int> floor = { 2,2,2,2,2 }; //n=3, k=2
	vector <int> answer;
	fill_n(parking, 10, k);
	int tmp;


	for (int i = 0; i < floor.size(); i++)
	{
		answer.push_back(Solution(floor[i] - 1));
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;

	return 0;
}