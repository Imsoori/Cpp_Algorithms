#include <iostream>
#include <string>
using namespace std;


int main()
{
    int n;
    scanf("%d",&n);

    int result=0, cnt=1,sum=0;
    int nine =9;

    while(sum + nine < n )
    {
        sum += nine;
        result += nine * cnt; 
        nine = nine*10;
        cnt++;
    }
   
    result += (n-sum)*cnt;
    
    printf("%d",result);
    
    
    return 0;
}