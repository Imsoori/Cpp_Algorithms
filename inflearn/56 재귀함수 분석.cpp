#include <iostream>
#include <vector>
using namespace std;


void ShowNumber(int n)
{
   if(n==0){
      return;
   }
   else
   {
      ShowNumber(n-1);
      printf("%d ",n);
   
   }
}



int main()
{
   int n;
   scanf("%d",&n);

   ShowNumber(n);

   return 0;
}
