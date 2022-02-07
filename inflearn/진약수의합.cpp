#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, sum=0;
    queue <int> q;
    cin>>n;

    for(int i=1; i<n; i++)
    {
        if(n%i==0)
        {
            sum += i;
            q.push(i);
        }
    } 

    while(!q.empty())
    {
        if(q.size()==1)
        {
            cout<< q.front() << " = "<<sum<<endl;
        }
        else{
            cout<< q.front()<<" + ";
        }
        q.pop();
    }


    return 0;
}