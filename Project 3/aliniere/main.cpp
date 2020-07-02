#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f ("aliniere.in");
ofstream g("aliniere.out");
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.second==b.second)
        return a.first < b.first;+
    return (a.second < b.second);
}
int v[100005], c[100005];
vector < pair <int, int> > t;
int n, q, x, y, nr;
int main()
{
    f>>n;
    for(int i=0; i<n; i++)
    {
        f>>v[i];
        if(i==0) c[i]=0;
        else c[i]=c[i-1]+(v[i-1]>v[i]);///daca se intampla vreo descrestere
    }
    f>>q;///cites numarul de query
    x=0;
    for(int p=0; p<q; p++)
    {
        int rez=0;
        f>>nr;
        x=0;
        t.clear();
        for(int r=0; r<nr; r++)///merg prin fiecare interval
        {
            f>>y;
            if(c[y]-c[x]==0)///daca nu se intampla nicio descrestere in intervalul asta in adaug in vector
                t.push_back(make_pair(v[x], v[y]));
            else rez++;///altfel incrementez numarul de intervale ce au trebuit aruncate
            x=y+1;///de-aici incepe noul interval
        }
        y=n-1;
        if(c[y]-c[x]==0)///verific si ultimul interval
            t.push_back(make_pair(v[x], v[y]));
        else rez++;
        if(t.size()>0)
        {
            sort(t.begin(), t.end(), sortbysec);///le sortez dupa a doua valoare
            int ultim=t[0].second;
            for(int i=1; i<t.size(); i++)
            {
                if(t[i].first<ultim) rez++;///daca cumva intervalul asta incepe mai devreme decat se termina cel dinainte, il dau afara
                else {ultim=t[i].second;}
            }
        }
        g<<rez<<"\n";
    }

    return 0;
}
