// MissingInteger
// test result
// 2022.06.10
// https://app.codility.com/demo/results/trainingG3BWP2-72A/
// 

#include <algorithm>

int solution(vector<int>& A) {
    
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int ans = 1;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] <= 0)
        {
            continue;
        }
        else {

            if (A[i] == ans)
            {
                ans += 1;
            }
            else {
                break;
            }
        }

    }

    return ans;
}