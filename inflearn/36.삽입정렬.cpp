#include <iostream>
#include <vector>
#include <string>
#include <queue>

// 36. 삽입정렬
int main()
{
    int arr[100],n;
    int tmp;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    int i, j;
    for( i=1; i<n; i++)
    {
        tmp = arr[i];
        for( j=i-1; j>=0; j--)
        {
            if(arr[j]>tmp) arr[j+1]=arr[j];
            else break;
        }
        arr[j+1] = tmp;
    }

    for( i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

