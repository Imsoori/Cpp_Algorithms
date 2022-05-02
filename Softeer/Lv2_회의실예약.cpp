#include<iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int RoomArr[51][24];
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
					RoomArr[k][j] = 1; // room, time(9)
				}
			}
		}
	}

	for (int i = 0; i < RoomName.size(); i++)
	{
		cout << "Room " << RoomName[i] << ":\n";
		vector <pair<int, int>> timeTable;
		int startEmpty = 17, endEmpty = 9;
		bool available = false;
		for (int j = 9; j < 18; j++)
		{
			if (RoomArr[i][j] == 0)
			{
				startEmpty = min(startEmpty, j);
				available = true;
			}
			else {
				endEmpty = j;
			}

			if (available && endEmpty != 9 && startEmpty != 17)
			{
				if (startEmpty > endEmpty) endEmpty = 18;
				timeTable.push_back({ startEmpty,endEmpty });
				startEmpty = 17, endEmpty = 9;
			}

		}

		if (startEmpty == endEmpty)
		{
			if (startEmpty == 9 && available)
			{
				cout << "1 available:\n";
				cout << "09-18\n";
			}
			else if (startEmpty == 17 && !available)
			{
				cout << "Not available\n";
			}
		}

		if (timeTable.size())
		{
			cout << timeTable.size() << " available:\n";

			for (int k = 0; k < timeTable.size(); k++)
			{
				printf("%02d-%02d\n", timeTable[k].first, timeTable[k].second);
			}
		}

		if (i != RoomName.size() - 1)
		{
			cout << "-----\n";
		}

	}
	return 0;
}