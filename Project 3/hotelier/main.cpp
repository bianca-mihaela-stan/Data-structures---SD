///rezolvata in 2019
#include <iostream>
using namespace std;
char s[100005];
int v[10];
int main()
{
    int p, n, i, j;
    cin>>n;///citesc numarul de evenimente si lista de evenimente
    cin>>s;

    for(i=0; i<n; i++)
    {
        if(s[i]=='L')///daca cineva intra din partea stanga iterez din stanga pana gasesc un loc liber
        {
            p=0;
            while(v[p]==1)
                p++;
            v[p]=1;
        }
        else if(s[i]=='R')///daca cineva intra din partea dreapta iterez din dreapta pana gasesc un loc liber
        {
            p=9;
            while(v[p]==1)
                p--;
            v[p]=1;
        }
        else {int x=s[i]-'0'; v[x]=0;}///daca cineva pleaca eliberez camera
    }
    for(i=0; i<=9; i++)///afisez statutul fiecarei camere
        cout<<v[i];
    return 0;
}
