// BinaryGap
// test result
// 2022.06.07
// https://app.codility.com/demo/results/trainingH33AY2-FRT/
// 
#include <algorithm>
#include <vector>

int solution(int N) {
    
    int r, q;
    int maxCnt = 0, ans = 0;
    vector <int> binaryCal, onePos;

    while (N > 0)
    {
        q = N / 2;
        r = N % 2;

        binaryCal.push_back(r);

        if (q == 1)
        {
            binaryCal.push_back(q);
            break;
        }

        N = q;
    }

    for (int i = 0; i < binaryCal.size(); i++)
    {
        if (binaryCal[i] == 1)
        {
            onePos.push_back(i);
        }
    }

    if (onePos.size() == 1)
    {
        return 0;
    }
    else {
        for (int i = 0; i < onePos.size() - 1; i++)
        {
            ans = onePos[i + 1] - onePos[i];
            maxCnt = max(ans, maxCnt);
        }
    }

    return maxCnt - 1;

}