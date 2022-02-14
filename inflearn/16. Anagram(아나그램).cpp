#include <iostream>
#include <string>
#include <map>
using namespace std;


int main()
{
    string str1,str2;
    cin>>str1>>str2;

    map <char,int> m1;
    map <char,int> m2;

    for(int i=0; i< str1.size();i++)
    {
        m1[str1[i]]++;
    }

    for(int i=0; i< str2.size();i++)
    {
        m2[str2[i]]++;
    }

    for(int i =0; i<str1.size(); i++)
    {
        if(m1[str1[i]]!=m2[str1[i]])
        {
            printf("NO");
        }
    }
    printf("YES");

    return 0;
}