#include <iostream>
#include <vector>

using namespace std;

// 54. 올바른 괄호 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input_str;
	string result = "YES";
	vector <char> v;

	cin >> input_str;

	for (int i = 0; i < input_str.size(); i++)
	{

		if (input_str[i] == '(')
		{

			v.push_back(input_str[i]);

		}
		else {

			if (v.empty())
			{
				result = "NO";
				break;
			}
			else {
				v.pop_back();
			}

		}


	}



	cout << result << endl;

	return 0;

}
