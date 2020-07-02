///complexitate: O(n log n) pt preprocesare
///O(1) pt query


#include <bits/stdc++.h>
using namespace std;
ifstream f ("rmq.in");
ofstream g ("rmq.out");
int m[100005][20];
int v[100005];
int n,q;
int main()
{
    f>>n>>q;
    for(int i=0; i<n; i++)
    {
        f>>v[i];
        m[i][0]=v[i];///pentru putere=1 am fix vectorul initial
    }
    int putere=2;
    for(int j=1; putere<=n; j++)///ieterez pana cand 2^j > n
    {
        for(int i=0; i+putere-1<n; i++)///i este punctul de inceput al secventei curente de lungime putere
        {
            ///m[i][j-1] retine valoarea minima din secventa care incepe cu i si are lungime 2^(j-1)=putere/2
            ///m[i+putere/2][j-1] retine valoarea minima din secventa imediat urmatoare secventei precedente, de lungime 2^(j-1)
            if(m[i][j-1]<m[i+putere/2][j-1])
                m[i][j]=m[i][j-1];
            else
                m[i][j]=m[i+putere/2][j-1];
        }
        putere*=2;
    }

    for(int i=0; i<q; i++)///compplexitate pe query: O(1)
    {
        int x, y;
        f>>x>>y;
        x--;///secventele incep de pe pozitia 0 la mine
        y--;
        int log=(int)log2(y-x+1);
        ///impart secventa pe care am query in 2 secvente: x....x+2^(log2(y-x+1)) si y-2^(log2(y-x+1))+1....y
        ///iar minimul pe toata secventa va fi minumul dintre valorile minime pe cele 2 secvente


        if(m[x][log]<m[y-(1<<log)+1][log])
            g<<m[x][log]<<"\n";
        else
            g<<m[y-(1<<log)+1][log]<<"\n";
    }
    return 0;
}
