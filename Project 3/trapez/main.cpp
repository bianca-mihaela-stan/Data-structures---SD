#include <bits/stdc++.h>
using namespace std;
ifstream f ("trapez.in");
ofstream g ("trapez.out");
int n;
pair <int, int> a[1005];
unordered_map <int64_t, int> umap;
int main()
{
    f>>n;
    for(int i=0; i<n; i++)
    {
        f>>a[i].first>>a[i].second;
    }
    int maxx=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int numarator=a[j].second-a[i].second;
            int numitor=a[j].first-a[i].first;
            int d=__gcd(numitor, numarator);
            numitor/=d;
            numarator/=d;
            if(numitor==0) numarator=1;
            if(numarator==0) numitor=1;
            if(numitor<0) {numitor=-numitor; numarator=-numarator;}
            cout<<i<<" "<<j<<": "<<numarator<<" "<<numitor<<"\n";
            int64_t s=(int64_t)numarator*2000000000+numitor;
            umap[s]++;
            if(umap[s]>1)
                maxx++;
        }
    }
    g<<maxx<<"\n";
    return 0;
}
