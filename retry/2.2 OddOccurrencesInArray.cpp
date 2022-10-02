#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// codility
// 2.2 OddOccurencesInArray

int solution(vector<int> &A)
{
    int idx;
    unordered_map<int, int> m_map;

    for(int i=0; i<A.size(); i++)
    {
        m_map[A[i]]++;
    }

    for(auto mIdx : m_map)
    {
        if(mIdx.second %2)
        {
            idx = mIdx.first;
        }
    }
    return idx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vinput = {9,3,9,3,9,7,9};
    cout<<solution(vinput)<<endl;

    return 0;
}