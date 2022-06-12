// Dominator
// test result
// 2022.06.12
// https://app.codility.com/demo/results/trainingVXSF6K-H9N/
// 


#include <map>


int solution(vector<int>& A) {
  
    std::map<int, int> m_map;
    std::map<int, int> m_freq;
    int ans = -1;
    int idx = 0;

    for (int i = 0; i < A.size(); i++)
    {
        m_map[A[i]]++;
        m_freq[A[i]] = i;
    }

    for (auto elm : m_map)
    {
        if (elm.second > A.size() / 2)
        {
            idx = elm.first;
        }
    }


    if (m_freq[idx])
    {
        ans = m_freq[idx];
    }
    else {

        if (A.size() == 1)
        {
            ans = 0;
        }
        else {
            ans = -1;
        }
    }

    return ans;
}