#include<iostream>
#include<vector>
#include <queue>
#include <string>
#include <cctype>

using namespace std;
//8. ¿Ã¹Ù¸¥ °ýÈ£ 

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input_str;
	int cnt = 0;
	cin >> input_str;

	for (int i = 0; i < input_str.size(); i++)
	{
		if (input_str[i] == '(') cnt++;
		else if (input_str[i] == ')') cnt--;

		if (cnt < 0)break;

	}
	if (cnt == 0)
	{
		cout << "YES\n";

	}
	else {
		cout << "NO\n";
	}

	return 0;
}


