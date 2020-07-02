#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream f ("nrtri.in");
ofstream g ("nrtri.out");
int v[805], n, rez=0;

int main()
{
    ///citire
    f>>n;
    for(int i=0; i<n; i++)
        f>>v[i];
    sort(v, v+n);
    for(int i=0; i<=n-3; i++)
    {
        for(int j=i+2; j<=n-1; j++)
        {
            /// perechi de 2 numere si vad daca il gasesc pe al 3-lea astfel
            ///incat a+b>=c
            int x=v[i];
            int y=v[j];
            for(int p=i+1; p<j; p++)
            {
                int z=v[p];
                if(x+z>=y)
                {
                    rez+=j-p;///cum numerele sunt sortate, toate numerele de
                            ///la dreapta unui nr ce satisface proprietatea
                            ///vor satisface proprietatea
                    break;
                }
            }
            ///imbunatatire: cautare binara pentru un nr >= y-x
        }
    }
    g<<rez;
    return 0;
}
