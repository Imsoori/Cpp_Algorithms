#include<iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int RoomArr[51][10];
vector <string> RoomName;
priority_queue <string> Room;

int main(int argc, char** argv)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		RoomName.push_back(str);
	}

	sort(RoomName.begin(), RoomName.end());

	for (int i = 0; i < m; i++)
	{
		string str;
		int s, e;
		cin >> str >> s >> e;

		for (int k = 0; k < RoomName.size(); k++)
		{
			if (str == RoomName[k])
			{
				for (int j = s; j < e; j++)
				{
					RoomArr[k][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < RoomName.size(); i++)
	{
		cout << "Room " << RoomName[i] << ":\n";
		vector <pair<int, int>> timeTable;
		int startEmpty = 18, endEmpty = 0;
		bool available = false;
		for (int j = 0; j < 10; j++)
		{
			if (RoomArr[i][j] == 0)
			{
				startEmpty = min(startEmpty, i);
				available = true;
			}
			else {
				endEmpty = i;
			}
			if (available && endEmpty != 0)
			{
				timeTable.push_back({ startEmpty,endEmpty });
			}
		}
		if (!available)
		{
			cout << "Not available\n";
		}

		cout << "-----\n";
	}
	return 0;
}