#include <iostream>
using namespace std;


void ChangeBinary(int num)
{
   if(num==1){ printf("%d",num); return;}
   else{
      ChangeBinary(num/2);
      printf("%d",num%2);
   }
}


int main()
{
   int n;
   scanf("%d", &n);

   ChangeBinary(n);

   return 0;
}
