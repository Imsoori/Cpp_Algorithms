#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int reverse(int x)
{
    string tmp = to_string(x);
    int reverseNumber =0;
    reverse(tmp.begin(),tmp.end());
    reverseNumber = stoi(tmp);
    return reverseNumber;
}

bool isPrime(int x)
{
    for(int i=2; i<x; i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n,tmp;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &tmp);
        
        if(isPrime(reverse(tmp)))
        {
            printf("%d ", reverse(tmp));
        }
    }


    return 0;
}