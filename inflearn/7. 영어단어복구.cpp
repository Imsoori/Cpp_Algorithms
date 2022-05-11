#include<iostream>
#include<vector>
#include <queue>
#include <string>
#include <cctype>

using namespace std;
//7. 영어 단어 복구 

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input_str, output_str;
	//공백포함 string
	getline(cin, input_str);


	for (int i = 0; i < input_str.size(); i++)
	{
		if (input_str[i] == ' ') continue;
		if (input_str[i] >= 'A' && input_str[i] <= 'Z') // 65, 90
		{
			//output_str += (input_str[i] + 32);
			output_str += tolower(input_str[i]);
		}
		else {
			output_str += input_str[i];
		}
	}

	cout << output_str << endl;
	return 0;
}