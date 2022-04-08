#include <iostream>
using namespace std;

//34. 버블 정렬
int n,tmp;
int data[101];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&data[i]);
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(data[j]>data[j+1])
            {
                tmp = data[j];
                data[j]=data[j+1];
                data[j+1] = tmp;
            }
        }
    }

    for(int i=0 ; i<n; i++)
    {
        printf("%d ",data[i]);
    }

    return 0;
}