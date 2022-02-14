#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, maxDiffAge, tmp;
    priority_queue <int> ageArr;
    cin>>n;
    
    for(int i=0; i<n; i++){ 
        cin>>tmp;
        ageArr.push(tmp);
    }
  
    maxDiffAge = ageArr.top();
    while(ageArr.size()!=1)
    {
        ageArr.pop();
    }
    maxDiffAge -= ageArr.top();
    cout<<maxDiffAge<<endl;

    return 0;
}