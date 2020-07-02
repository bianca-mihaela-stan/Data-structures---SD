#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("cautbin.in");
ofstream g ("cautbin.out");
int v[100005], n, q;
void cautare_binara_0(int x, int st, int dr, int& poz)
{///cea mai mare pozitie pe care se afla un element cu valoarea x
///sau -1 daca aceasta valoare nu se gaseste in sir
    if(st<=dr)
    {
        int mij=st+(dr-st)/2;
        if(v[mij]==x)///daca am gasit elementul caut in dreapta lui alta aparitie
        {
            if(poz<mij) poz=mij;
            cautare_binara_0(x, mij+1, dr, poz);
        }
        else if(v[mij]<x) cautare_binara_0(x, mij+1, dr, poz);
        else cautare_binara_0(x, st, mij-1, poz);
    }
}
void cautare_binara_1(int x, int st, int dr, int& poz)
{///cea mai mare pozitie pe care se afla un element cu valoarea mai mica sau egala cu x in sir
    ///se garanteaza ca cel mai mic numar al sirului este mai mic sau egal decat x
    if(st<=dr)
    {
        int mij=st+(dr-st)/2;
        if(v[mij]==x)///daca am gasi elementul rezultatul va fi acelasi ca la 1
        {
            poz=mij;
            cautare_binara_1(x, mij+1, dr, poz);
        }
        else if (v[mij]<x)///daca am gasit un element mai mic schimb poz daca pozitia sa e mai mare
        {
            if(poz<mij) poz=mij;
            cautare_binara_1(x, mij+1, dr, poz);
        }
        else
        {
            cautare_binara_1(x, st, mij-1, poz);
        }

    }
}
void cautare_binara_2(int x, int st, int dr, int &poz)
{///ea mai mica pozitie pe care se afla un element cu valoarea mai mare
///sau egala cu x in sir. Se garanteaza ca cel mai mare numar din sir este mai mare sau egal decat x
    if(st<=dr)
    {
        int mij=st+(dr-st)/2;
        if(v[mij]==x)///daca am gasit elementul caut in stanga lui
        {
            if(poz>mij) poz=mij;
            cautare_binara_2(x, st, mij-1, poz);
        }
        else if(v[mij]<x) cautare_binara_2(x, mij+1, dr, poz);
        else///daca am gasit un element mai mare caut tot in stanga lui
        {
            if(poz>mij) poz=mij;
            cautare_binara_2(x, st, mij-1, poz);
        }
    }

}
int main()
{
    f>>n;
    for(int i=0; i<n; i++)
        f>>v[i];
    f>>q;
    for(int i=0; i<q; i++)
    {
        int x, y;
        f>>x>>y;
        if(x==0)
        {
            int poz=-2;
            cautare_binara_0(y, 0, n-1, poz);
            g<<poz+1<<"\n";
        }
        else if (x==1)
        {
            int poz=-2;
            cautare_binara_1(y, 0, n-1, poz);
            g<<poz+1<<"\n";
        }
        else if (x==2)
        {
            int poz=n;
            cautare_binara_2(y, 0, n-1, poz);
            g<<poz+1<<"\n";
        }
    }
    return 0;
}
