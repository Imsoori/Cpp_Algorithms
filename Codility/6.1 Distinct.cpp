// Distinct
// test result
// 2022.06.10
// https://app.codility.com/demo/results/trainingNS8V2Q-TKV/
// 


#include <unordered_map>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    std::unordered_map<int, int> checkNum;
    int ans = 0;

    for (int i = 0; i < A.size(); i++)
    {
        checkNum[A[i]]++;
    }

    ans = checkNum.size();
    return ans;
}