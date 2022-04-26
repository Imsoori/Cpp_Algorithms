#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ans;
	int input[10] = { 0, };
	int state[3] = { 0, };

	for (int i = 0; i < 8; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < 7; i++)
	{
		int diff = input[i + 1] - input[i];
		if (diff == 1)
		{
			state[0]++; // + 
		}
		else if (diff == -1)
		{
			state[1]++; // - 
		}
		else {
			state[2]++;
			break;
		}
	}
	if (state[0] == 7)
	{
		ans = "ascending";

	}
	else if (state[1] == 7) {
		ans = "descending";
	}
	else {
		ans = "mixed";
	}

	cout << ans << endl;

	return 0;
}