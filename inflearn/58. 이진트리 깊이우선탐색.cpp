#include <iostream>
using namespace std;

void D(int v)
{
   if(v>7) return;
   else{
      printf("%d ",v); //전위순회
      D(2*v);
      // printf("%d ",v); // 중위순회
      D(2*v+1);
      //printf("%d ",v); //후위순회
   }
}

int main()
{
   D(1);
   return 0;
}
