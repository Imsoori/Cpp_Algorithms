#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    
    map <string, int> IDidx;
    // (id, idx)
    for(auto i=0; i<id_list.size(); i++)
    {
        IDidx[id_list[i]] = i;
    }
    
    
     map<string, set<string>> reportMatching;
    
    for(auto elm : report)
    {
        stringstream str(elm);
        string from, to;
        str>>from>>to;
        reportMatching[to].insert(from);
    }
    
    for(auto iter: reportMatching)
    {
        if(iter.second.size()>=k)
        {
           for(auto anotheriter : iter.second)
           {
                answer[IDidx[anotheriter]]+=1;
           }
        }
    }
    
   
    
    return answer;
}