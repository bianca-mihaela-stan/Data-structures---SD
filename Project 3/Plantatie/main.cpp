///problema clasica de rmq in 2d, care intreaba care este elementul maxim dintr-o submatrice patrat cu coltul din stanga sus si latura date

#include <bits/stdc++.h>
using namespace std;
ifstream f ("plantatie.in");
ofstream g ("plantatie.out");
int v[502][502];
int m[502][502][11];///m este o matrice tridimensionala, in care a 3-a dimensiune este practic pentru rmq
int n, q;
int main()
{
    f>>n>>q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            f>>v[i][j];
            m[i][j][0]=v[i][j];///matricea "0" a lui m este identica cu cea initiala (pentru patratele de latura 1)
        }
    }
    for(int k=1; (1<<k)<=n; k++)///merg in toate k-urile pana la log2(n)
    {
        for(int i=0; i<=n-(1<<k); i++)///iau toate patratele care se pot forma, de latura 2^k si coltul din stanga sus de coordonate (i, j)
        {
            for(int j=0; j<=n-(1<<k); j++)
            {
                ///retin care este valoarea maxima din toate patratele obtinute: de latura 2^k, cu
                int a=max(m[i][j][k-1], m[i][j+(1<<(k-1))][k-1]);///patratele din stanga sus si dreapta sus
                int b=max(m[i+(1<<(k-1))][j][k-1], m[i+(1<<(k-1))][j+(1<<(k-1))][k-1]);///patratele din stanga jos si dreapta sus
                m[i][j][k]=max(a, b);
            }
        }
    }

    for(int x=0; x<q; x++)///query-urile
    {
        int i, j, k;
        f>>i>>j>>k;
        i--;///eu am elementele de la 0 la n-1 in matrice
        j--;
        int log=(int)log2(k);
        ///calculez maximul dintre cele 4 patrate de latura 2^log(k) care se pot forma cu coltul din stanga sus de coordonate (i, j)
        int a=max(m[i][j+k-(1<<log)][log], m[i][j][log]);
        int b=max(m[i+k-(1<<log)][j+k-(1<<log)][log], m[i+k-(1<<log)][j][log]);
        g<<max(a, b)<<"\n";
    }
    return 0;
}
