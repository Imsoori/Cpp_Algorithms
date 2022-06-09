// FrogRiverOne
// test result
// 2022.06.09
// https://app.codility.com/demo/results/trainingCMWRBP-VP9/
// 

#include <unordered_map>

int solution(int X, vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    std::unordered_map<int, int> leafPos;
    int ans = -1;

    for (int i = 0; i < A.size(); i++)
    {
        leafPos[A[i]] = 1;

        if (leafPos.size() == X)
        {
            ans = i;
            break;
        }
    }

    return ans;
}