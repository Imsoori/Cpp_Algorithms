// CyclicRotation
// test result
// 2022.06.07
// https://app.codility.com/demo/results/training5FPUBP-YUB/
// 
#include <queue>
#include <vector>


vector<int> solution(vector<int>& A, int K) {

    queue<int> q;
    vector<int> ans;
    int vectorSize = A.size();
    if (vectorSize == 0) return ans;
    int r = vectorSize - (K % vectorSize);


    for (int i = 0; i < A.size(); i++)
    {
        q.push(A[i]);
    }

    while (r > 0)
    {
        int tmp = q.front();
        q.pop();
        q.push(tmp);
        r--;
    }

    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}