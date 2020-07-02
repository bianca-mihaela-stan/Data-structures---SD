#include <bits/stdc++.h>
using namespace std;
ifstream f ("hashuri.in");
ofstream g ("hashuri.out");
vector<int> h[666013];
int n, last;
int main()
{
    f>>n;
    for(int i=0; i<n; i++)
    {
        int x, y;
        f>>x>>y;
        int val=y%666013;
        if(x==1)///daca vreau sa adaug elementul x in multime
        {
           int exista=0;
            vector<int>::iterator it;
            for(it=h[val].begin(); it!=h[val].end(); it++)///caut prin collisions numarul
                if(*it==x)
                {
                    exista=1;
                    break;
                }
           if(exista==0) h[val].push_back(y);
        }
        else if (x==2)///daca vreau sa sterg elementul x din multime
        {
            vector<int>::iterator it;
            for(it=h[val].begin(); it!=h[val].end(); it++)///caut prin collisions numarul si il sterg daca il gasesc
                if(*it==y)
                {
                    h[val].erase(it);
                    break;
                }
        }
        else if(x==3)///daca vreau sa verific daca un element e sau nu in multime
        {
            int exista=0;
            vector<int>::iterator it;
            for(it=h[val].begin(); it!=h[val].end(); it++)///caut prin collisions numarul si returnez 1 daca il gasesc
                if(*it==y)
                {
                    exista=1;
                    g<<1<<"\n";
                    break;
                }
            if(exista==0) g<<0<<"\n";
        }
    }
    return 0;
}
