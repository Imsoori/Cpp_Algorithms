#include <iostream>
#include <deque>
#include <string>
using namespace std;

//#10866 덱
int n;
string strInput;
deque <int> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(false);
    //cout.tie(false);
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>strInput;

        if(strInput == "push_front")
        {
            int num;
            cin>> num;
            dq.push_front(num);
        }
        else if(strInput == "push_back")
        {
            int num;
            cin>> num;
            dq.push_back(num);
        }
        else if(strInput == "pop_front")
        {
            if(dq.empty())
            {
                cout<<"-1"<<endl;
            }
            else{
                cout<<dq.front()<<endl;
                dq.pop_front();
            }
        }
        else if(strInput == "pop_back")
        {
            if(dq.empty())
            {
                cout<<"-1"<<endl;
            }
            else{
                cout<<dq.back()<<endl;
                dq.pop_back();
            }
        }
        else if(strInput == "size")
        {
            cout<<dq.size()<<endl;
        }
        else if(strInput == "empty")
        {
            if(dq.empty())
            {
                cout<<"1"<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        else if(strInput == "front")
        {
            if(dq.empty())
            {
                cout<<"-1"<<endl;
            }
            else{
                cout<<dq.front()<<endl;
            }
        }
        else if(strInput == "back")
        {
            if(dq.empty())
            {
                cout<<"-1"<<endl;
            }
            else{
                cout<<dq.back()<<endl;
            }
        }
    }
   
    return 0;
}