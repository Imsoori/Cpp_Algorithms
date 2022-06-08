// PermMissingElem
// test result
// 2022.06.08
// https://app.codility.com/demo/results/trainingFHK2W3-4UJ/
// 

#include <algorithm>

int solution(vector<int>& A) {
    int N = A.size();
    int ans = 0;
    int comp = 1;

    sort(A.begin(), A.end());

    if (N == 0)
    {
        ans = 1;
    }
    else {
        for (int i = 0; i < N; i++)
        {
            if (A[i] == comp)
            {
                comp++;
            }
            else {
                ans = comp;
                break;
            }
        }
    }

    if (ans == 0) return comp;
    else return ans;

}