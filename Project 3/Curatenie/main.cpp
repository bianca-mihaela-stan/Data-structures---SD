#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("curatenie.in");
ofstream g ("curatenie.out");
int srd[500005], rsd[500005], v[500005], m[500005][2], fv[500005], n, q=0, a1, a2;
int cautare (int x)
{
    for(int i=1; i<=n; i++)
    {
        if(srd[i]==x) return i;
    }
    return 0;
}
int main()
{
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>srd[i];
        fv[srd[i]]=i;///construiesc vectorul fv unde retin pozitia in srd a unui nod
    }
    for(int i=1; i<=n; i++)
        f>>rsd[i];
    int x=rsd[1];///x e radacina
    int a=fv[x];
    int p=1;
    v[a]=p;///in vectorul v o sa pun "gradele", unde p este variabila care tine gradul curent
    ///srd 4 2 5 1 3 7 6
    ///rsd 1 2 4 5 3 6 7
    ///fv  4 2 5 1 3 7 6
    ///v     2   1

    ///i=2 si rsd[i]=2 vreau sa vad al cui fiu e 2 si din ce parte: il gasesc doar pe 1 in dreapta la pozitia 4 si pe pozitia 4 in srd e 1 deci e fiul stang al lui 1
    ///i=3 si rsd[i]=4  il gasesc doar pe 2 in dreapta pe pozita 2, adica este fiul stang al lui 2
    ///v   3 2   1
    ///i=4 si rsd[i]=5 si mai mare este 2 care este pe pozitia 2 deci 5 este fiul drept al lui 2
    ///v   3 2 4 1
    ///i=5 si rsd[i]=3 si il gasesc pe 1 in dreapta deci 3 este fiul drept al lui 1
    ///v   3 2 4 1 5
    for(int i=2; i<=n; i++)
    {
        x=rsd[i];
        a=fv[x];
        p++;
        v[a]=p;
        a1=a-1;
        a2=a+1;
        while(v[a1]==0 && a1>=1)///caut in stanga
            a1--;
        while(v[a2]==0 && a2<=n)///caut in dreapta
            a2++;
        if(v[a1]>v[a2])
        {
           m[srd[a1]][1]=x;
        }
        else
        {
            m[srd[a2]][0]=x;
        }
    }
    for(int i=1; i<=n; i++)
    {
        g<<m[i][0]<<" "<<m[i][1]<<"\n";
    }
    return 0;
}
