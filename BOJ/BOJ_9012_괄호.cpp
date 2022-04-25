
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// 9012. 괄호 
int T;
vector <string> output;
string inp_str;


string checkVPS(string str)
{
	vector <int> v;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			v.push_back(1); // ( = 1 && ) = 0
		}
		else {
			if (!v.empty())
			{
				v.pop_back();
			}
			else {
				return "NO";
			}

		}
	}

	if (v.empty())
	{
		return "YES";
	}
	else {
		return "NO";
	}


}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> inp_str;
		output.push_back(checkVPS(inp_str));
	}

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << endl;
	}

	return 0;
}