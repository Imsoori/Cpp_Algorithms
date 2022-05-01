#include<iostream>
#include<vector>

using namespace std;

int M, N, K, input;
vector <int> secretRecipe;
vector <int> customButton;
string output = "normal";
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	for (int i = 0; i < M; i++)
	{
		cin >> input;
		secretRecipe.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		customButton.push_back(input);
	}

	int j = 0;

	for (int i = 0; i < customButton.size(); i++)
	{
		if (customButton[i] == secretRecipe[j])
		{
			if (j < secretRecipe.size())
			{
				j += 1;
			}

			if (j == secretRecipe.size() - 1) {
				output = "secret";
				break;

			}
		}
		else {
			j = 0;
		}
	}

	cout << output << endl;

	return 0;
}