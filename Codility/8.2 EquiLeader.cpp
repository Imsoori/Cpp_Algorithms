// EquiLeader
// test result
// 2022.06.14
// 88%
// https://app.codility.com/demo/results/trainingFF5UHW-KR8/

#include <map>
#include <vector>

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    map <int, int> m_map, m_cmp;
    vector<int> ans;
    int tmpLeader = 0;
    int cmpIdx1, cmpIdx2 = 0;
    for (int i = 0; i < A.size(); i++)
    {
        m_map[A[i]] += 1;
    }

    for (int i = 0; i < A.size() - 1; i++)
    {

        if (m_map[A[i]] > 0)
        {
            m_map[A[i]] -= 1;
            // cout << i << " " << m_map[A[i]] << endl;
        }

        m_cmp[A[i]] += 1;
        cmpIdx1 = i + 1;
        for (auto it = m_cmp.begin(); it != m_cmp.end(); ++it)
        {
            if (it->second > cmpIdx1 / 2)
            {
                tmpLeader = it->first;
                // cout << i << " " << tmpLeader << endl;
                break;

            }
        }
        cmpIdx2 = A.size() - i - 1;

        if (m_map[tmpLeader] > cmpIdx2 / 2 && m_cmp[tmpLeader] > cmpIdx1 / 2)
        {
            //cout << m_map[tmpLeader] << " " << i << endl;
            ans.push_back(i);

        }


    }

    return ans.size();
}