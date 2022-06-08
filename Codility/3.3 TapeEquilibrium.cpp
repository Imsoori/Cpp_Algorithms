// TapeEquilibrium
// test result
// 2022.06.08
// https://app.codility.com/demo/results/trainingSEK269-AAS/
// 

// you can use includes, for example:
#include <algorithm>
#include <numeric> //accumulate
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
    int n = A.size();
    int minValue = 2147000000;
    int left = A[0];
    int right = std::accumulate(A.begin(), A.end(), -left);
    

    for (int p = 1; p < n; p++)
    {
        minValue = min(minValue, abs(left - right));
        left += A[p];
        right -= A[p];
    }

    //minValue = min(minValue, abs(left - right));
    return minValue;
}