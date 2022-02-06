#include <iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    
    int step =1;
    while(x>step)
    {
        x -= step;
        step++;
    }
    
    if(step % 2==0) 
    {
        cout<<x<<"/"<<step+1-x<<endl;
    }
    else
    {
        cout<<step+1-x<<"/"<<x<<endl;
    }
    
}
