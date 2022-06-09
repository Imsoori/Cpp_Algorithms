// PermCheck
// test result
// 2022.06.09
// https://app.codility.com/demo/results/training5H8XB4-2CT/
// 

#include <algorithm>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != i + 1)
        {
            return 0;
        }
    }
    return 1;
}