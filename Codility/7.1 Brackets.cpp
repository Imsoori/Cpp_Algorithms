// Brackets
// test result
// 2022.06.11
// https://app.codility.com/demo/results/trainingB9QXFJ-KCJ/
// 


#include <vector>


int solution(string& S) {
  
    vector <char> vc;
    char cmp;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '{' || S[i] == '[' || S[i] == '(')
        {
            vc.push_back(S[i]);
        }
        else {

            if (vc.empty())
            {
                return 0;
            }
            else {
                cmp = vc.back();

                if (cmp == '{' && S[i] == '}')
                {
                    vc.pop_back();
                }
                else if (cmp == '[' && S[i] == ']')
                {
                    vc.pop_back();
                }
                else if (cmp == '(' && S[i] == ')')
                {
                    vc.pop_back();
                }
                else {
                    return 0;
                }
            }

        }
    }
    if (vc.empty()) return 1;
    else return 0;
}