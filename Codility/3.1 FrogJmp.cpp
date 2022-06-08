// FrogJmp
// test result
// 2022.06.08
// https://app.codility.com/demo/results/trainingXWR3YN-BYZ/
// 


int solution(int X, int Y, int D) {
    int q, r, ans;
    q = (Y - X) / D;
    r = (Y - X) % D;

    if (r == 0)
    {
        ans = q;
    }
    else {
        ans = q + 1;
    }
    return ans;
}