// CountFactors
// test result
// 2022.06.16
// https://app.codility.com/demo/results/training5NX6HK-AJ2/

#include <algorithm>
#include <cmath>


int solution(int N) {
    int ans = 0;
    int check = int(sqrt(N));
    for (int i = 1; i < sqrt(N); i++)
    {
        if (N % i == 0)
        {
            ans++;
        }
    }
    if (check * check == N)
    {
        return 2 * ans + 1;
    }
    else {
        return 2 * ans;
    }

}