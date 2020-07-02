#include <bits/stdc++.h>
using namespace std;
long long v[100005];
long long m[100005][20];
int main()
{
    f>>n>>k;
    for(int i=0; i<n; i++)
    {
        f>>v[i];
        m[i][0]=v[i];
    }
    int putere=2;
    for(int j=1; putere<=n; j++)
    {
        for(int i=0; i+putere-1<n; i++)
        {
            m[i][j]=m[i+putere/2][j-1]+m[i][j-1];
        }
        putere*=2;
    }
    for(int i=0; i<n; i++)
    {
        if(i<=k-1)
            sum+=v[i];
        else
        {
            sum+=v[i];
            sum-=v[i-k];
        }
    }
    return 0;
}
