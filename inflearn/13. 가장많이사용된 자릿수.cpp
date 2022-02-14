#include <iostream>
#include <string>
using namespace std;


int main()
{
    char n[100];
    scanf("%s", n);

    int arr[10]={0};
    int max=0,answer=0;

    for(int i=0; i<100;i++)
    {
        if(n[i])
        {
            arr[n[i]-'0']++;
        }
    }
    
    for(int j=9; j>=0; j--)
    {
        if(arr[j]>max)
        {
            max = arr[j];
            answer = j;
        }
    }

    printf("%d", answer);
    
    return 0;
}