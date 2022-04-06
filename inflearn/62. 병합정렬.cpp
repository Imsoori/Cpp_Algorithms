#include <iostream>
using namespace std;


int n;
int m_data[101], m_tmp[101];

void divide(int lt, int rt)
{
    int mid, p1, p2, p3;
    if(lt<rt)
    {
        mid = (lt+rt)/2;
        divide(lt, mid);
        divide(mid+1, rt);

        p1 = lt;
        p2 = mid+1;
        p3 = lt;

        while(p1<=mid && p2<=rt)
        {
            if(m_data[p1]>m_data[p2]){
                m_tmp[p3++] = m_data[p2++];
            }
            else{
                m_tmp[p3++] = m_data[p1++];
            }
        }
        while(p1<=mid) m_tmp[p3++] = m_data[p1++];
        while(p2<=rt) m_tmp[p3++] = m_data[p2++];
        for(int i= lt; i<=rt; i++)
        {
            m_data[i]=m_tmp[i];
        }
    }
}


int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&m_data[i]);

    divide(1,n);    
    
    for(int i=1; i<=n; i++)
        printf("%d ",m_data[i]);
    return 0;
}