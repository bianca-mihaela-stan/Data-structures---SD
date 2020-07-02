#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f ("operatie.in");
ofstream g ("operatie.out");
int n, d, w[1005][1005], v[1005];
int main()
{
    f>>n>>d;///citesc n si numarul de biti
    memset(v, -1, sizeof(-1));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            f>>w[i][j];
            if(i==j && i%2==1)
            {
                v[i]=w[i][j];
            }
        }
    }
    ///daca (i + j) % 4 == 0 => w[i][j] = v[i] ^ v[j]
    ///daca (i + j) % 4 = 2 => w[i][j] = v[i] & v[j]
    ///daca (i + j) % 2 = 1 => w[i][j] = v[i] -> v[j]

    ///din v[i]^v[i] aflam valoarea lui v[i] (pentru toate pozitiile impare
    ///a->b=c daca b=0 => a=not c, daca a=1 atunci b=c
    ///=> din v[i]->v[j]=w[i][j] si v[j]->v[i]=w[j][i], daca i e impar stiu toti bitii lui v[i]
    ///=> din v[j]->v[i]=w[j][i] pot sa aflu care sunt valorile bitilor din v[j] care corespund valorilor de 0 din v[i]
    ///din v[i]->v[j]=w[i][j] pot sa aflu valorile din v[j] crae corespund valorilor de 1 din v[i]
    ///astfel am aflat toti bitii lui v[j]

    ///cu xor facem verificarea

    for(int i=1; i<n; i+=2)///astea sunt numerele de pe poz impare pe care le stiu deja
    {
        for(int j=0; j<n; j+=2)///astea sunt toate numerele pare
        {
            int rez1=w[i][j];///b->c
            int b=v[i];
            int rez2=w[j][i];///c->b
            int a[d];
            memset(a, 0, sizeof(0));///iau un array gol cu d biti
            int t=d-1;
            while(t>=0)
            {
                if(b%2==0)///cum am zis, daca b=0 a=not c
                {
                    a[t]=1-rez2%2;
                }
                else///daca b=1 a=c (alt c)
                {
                    a[t]=rez1%2;
                }
                t--;
                rez1/=2;///asta ca sa am alti biti mereu
                rez2/=2;
                b/=2;
            }
            int putere=1;
            v[j]=0;
            for(int p=d-1; p>=0; p--)///construiesc v[j] din reprezentarea sa pe biti
            {
                v[j]+=a[p]*putere;
                putere*=2;
            }
        }
    }
    ///verificare xor
    for(int i=0; i<n; i++)
    {
        int start;
        if(i%4==0) start=0;///decid de unde incep xorurile pe linia asta in functie de fomula din enunt
        else start=4-(i%4);
        for(int j=start; j<n; j+=4)
        {
            if((v[i]^v[j])!=w[i][j])
            {
                g<<-1;///daca nu corespund valorile afisez -1
                return 0;
            }
        }
    }
    for(int i=0; i<n; i++)
        g<<v[i]<<" ";
    return 0;
}
