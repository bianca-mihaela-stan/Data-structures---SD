#include <bits/stdc++.h>

using namespace std;
ifstream f ("patrate3.in");
ofstream g ("patrate3.out");
vector<int> h[200000005];
int main()
{
    f>>n;
    for(int i=0; i<n; i++)
    {
        double x, y;
        f>>x>>y;
        x+=10000;
        y+=10000;
        y*=10000;
        x*=10000;
        h[x].push_back(y);
    }
}
