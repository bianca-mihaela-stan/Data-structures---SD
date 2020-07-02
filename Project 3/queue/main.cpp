///initial am vrut sa simulez queue-ul cu 2 array-uri astfel incat primul sa fie pentru inserare, al doilea pentru stergere, dar de fiecare daca sa fac mutarea completa intre ele
///ulterior mi-am dat seama ca nu este nevoie, pot sa adaug 3 elemente in 1, sa le mut inversate in 2, sa terg un element, apoi sa mai inserez 2 tot in 1
///cand voi ramane fara elemente de sters in 2 fac iar mutarea nversata, dar nu are rost sa afc o mutare la fiecare cerere
#include <bits/stdc++.h>
using namespace std;
ifstream f ("queue.in");
ofstream g ("queue.out");
string s;
int sk1[30005], sk2[30005], len1=0, len2=0, n;
int main()
{
    f>>n;
    getline(f, s);
    for(int i=0; i<n; i++)
    {
        getline(f, s);
        g<<i+1<<":";
        if(s[3]=='h')
        {
            ///am push_back
            g<<" read(";
            size_t poz=s.find('(');
            int nr=0;
            if(poz!=string::npos)
            {
                poz=(int) poz+1;
                while(s[poz]!=')')
                {
                    nr=nr*10+s[poz]-48;
                    poz++;
                }
            }
            g<<nr<<")";
            g<<" push("<<1<<","<<nr<<")";///push-ul il fac mereu in 1
            len1++;//indexare de la 1
            sk1[len1]=nr;
        }
        else
        {
            ///am pop_front
            if(len2==0)///daca nu mai am elemente in 2 le iau pe cele din 1
            {
                for(int j=len1; j>=2; j--)
                {
                    g<<" pop("<<1<<") push("<<2<<","<<sk1[j]<<")";
                    len2++;
                    sk2[len2]=sk1[j];
                }
                g<<" pop("<<1<<") write("<<sk1[1]<<")";
                len1=0;
            }
            else///daca am fac pop din ce am
            {
                g<<" pop("<<2<<") write("<<sk2[len2]<<")";
                len2--;
            }

        }
        g<<"\n";
    }
}
