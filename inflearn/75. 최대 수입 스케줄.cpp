#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Data{
    int cost;
    int day;

    Data(int x, int y)
    {
        cost = x;
        day = y;
    }
    bool operator<(const Data &tmp)const{
        return cost>tmp.day;
    }
};

int main()
{
    int n, x,y,res=0;
    int maxDay=-2147000000;
    vector <Data> v;
    priority_queue <int> pq;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &x,&y);
        v.push_back(Data(x,y));
        if(y>maxDay) maxDay =y ;
    }

    sort(v.begin(),v.end());

    for(int i=maxDay; i>0; i--)
    {
        for(int j=0; j<n; j++)
        {
            if(v[j].day<i) break;
            pq.push(v[j].cost);
        }
        if(!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
    }

    printf("%d\n",res);

    return 0;
}

