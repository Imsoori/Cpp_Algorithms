// CountDiv
// test result
// 2022.06.13
// https://app.codility.com/demo/results/trainingJWY36U-WZH/
// O(1)


int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int idx = 0;
    int ans = 0;
    bool flag = false;
    for (int i = A; i <= B; i++)
    {
        if (i % K == 0)
        {
            idx = i;
            flag = true;
            break;
        }
    }

    if (flag) ans = (B - idx) / K;
    else ans = -1;

    return ans + 1;
}