#include <bits/stdc++.h>
using namespace std;
int v[100005];
vector<pair<int, int>> p;
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>l>>r>>q;
        for(int j=0; j<20; j++)
        {
            int bit=(q >> j) & 1;
            if(bit==1)
            {
                for(int y=l-1; y<r; y++)
                    v[y]+=(1<<j);
            }
        }
    }
    return 0;
}
