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
		int startEmpty = 18, endEmpty = 9;
		bool available = false;
		for (int j = 9; j < 18; j++)
		{
			if (RoomArr[i][j] == 0)
			{
				startEmpty = min(startEmpty, j);
				if (j == 17)
				{
					endEmpty = 18;
					available = true;
				}

			}
			else {
				endEmpty = j;
				if (startEmpty != 18)
				{
					available = true;
				}

			}

			if (available)
			{
				timeTable.push_back({ startEmpty,endEmpty });
				available = false;
				startEmpty = 18;
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
		else if (startEmpty > endEmpty)
		{
			cout << "Not availabe\n";
		}

		if (i != RoomName.size() - 1)
		{
			cout << "-----\n";
		}

	}
	return 0;
}