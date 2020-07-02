#include <bits/stdc++.h>
using namespace std;
ifstream f ("covrigi.in");
ofstream g ("covrigi.out");
int n, m, k, v[50005], c[50005], nr_dest, nr_rp, i;
int main()
{
    f>>n>>m>>k;///citesc numarul de concurenti, numarul de sali si cat costa un rp
    for(int i=1; i<=n; i++)
        f>>v[i];///citesc vectorul de castiguri
    for(int i=1; i<=m; i++)
    {
        f>>c[i];///citesc concurentii
        nr_dest+=c[i];///incrementez numarul de destepti
    }
    sort(c+1, c+m+1, greater<int>());///sortez salile descrescator pentru ca vreau sa omor eficient
    int cov=v[nr_dest+1];///momentan sunt in clasament pe pozitia nr_dest+1
    nr_rp=0;///nu s-a numparat niciun rp
    i=1;
    int poz=nr_dest+1;
    int maxx=v[poz];///castigul de acum
    while(poz>1)
    {
        poz-=c[i];///avansez in clasament cu atatea locuri cu cati concurez anulez in prima sala
        i++;
        nr_rp++;///am cumparat un rp
        if(v[poz]-nr_rp*k>maxx)///daca castigul asta e mai mare fac update
        {
            maxx=v[poz]-nr_rp*k;
        }
    }
    ///cum am calculat toate cazurile, acum stiu care e varianta optima
    g<<maxx;
    return 0;
}
