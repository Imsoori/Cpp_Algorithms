// OddOccurrencesInArray
// test result
// 2022.06.08
// https://app.codility.com/demo/results/trainingP465WK-VW7/
// 

#include <unordered_map>

int solution(vector<int>& A) {

    unordered_map <int, int> umap;

    for (int i = 0; i < A.size(); i++)
    {
        umap[A[i]]++;
    }

    for (auto elm : umap)
    {
        if (elm.second % 2)
        {
            return elm.first;
        }
    }
}