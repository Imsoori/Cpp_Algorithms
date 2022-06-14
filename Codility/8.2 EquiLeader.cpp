// EquiLeader
// test result
// 2022.06.14
// 
// 

#include <map>
#include <vector>


int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    map <int, int> m_map, m_cmp;
    vector<int> ans;
    bool check = false;
    int tmpLeader = 0;

    for (int i = 0; i < A.size(); i++)
    {
        m_map[A[i]] += 1;
    }

    for (int i = 0; i < A.size() - 1; i++)
    {
        check = false;
        if (m_map[A[i]] > 0)
        {
            m_map[A[i]] -= 1;
        }

        m_cmp[A[i]] += 1;

        if (m_cmp[A[i]] > m_cmp.size() / 2)
        {
            tmpLeader = A[i];
            check = true;
        }

        if (check)
        {
            if (m_map[tmpLeader] > m_map.size() / 2)
            {
                ans.push_back(tmpLeader);
            }
        }

    }

    return ans.size();
}