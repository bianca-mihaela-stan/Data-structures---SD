#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream f ("blat.in");
ofstream g ("blat.out");
int m, n, k, a[105][105], poz[105], b[105], c[105];
vector <int> pb, st;
///pb[i] o sa tina suma pe care o iau toti studentii pe problema i
///st[i] pucntajele pe toate problemele pentru studentul i
int sum1=0, sum2=0, sum3=0, sum4=10005;
int main()
{
    f>>n>>k>>m;///n probleme, m studenti, se aleg k probleme
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            f>>a[i][j];
            if(i==1)
            {
                pb.push_back(a[i][j]);
            }
            else
            {
                pb[j-1]+=a[i][j];
            }
            if(j==1)
            {
                st.clear();///cand i=1 golim vectorul
            }
            st.push_back(a[i][j]);///punem
            if(j==n)///cand ajung la n
            {
                ///sortez st ca sa iau cel mai mic si cel mai mare punctaj
                sort(st.begin(), st.end());
                int poz=n-1;
                int nr=1;
                int sum_max=0;
                while(nr<=k)
                {
                    sum_max+=st[poz];///cel mai mare punctaj pe care il poate lua studentul i
                    poz--;
                    nr++;
                }
                if(sum_max>sum3)///daca e mai mic ca sum3 fac update
                    sum3=sum_max;
                poz=0;
                int sum_min=0;
                while(poz<k)
                {
                    sum_min+=st[poz];///cel mai mic punctaj pe care il poate lua studentul i
                    poz++;
                }
                if(sum_min<sum4)
                    sum4=sum_min;
            }
        }
    }
    sort(pb.begin(), pb.end());///sortez problemele in functie de puncajele care se iau pe ele
    int i=n-1;
    int nr=1;
    while(nr<=k)///cele mai mari punctaje
    {
        sum1+=pb[i];
        i--;
        nr++;
    }
    i=0;
     while(i<k)///cele mai mici punctaje
    {
        sum2+=pb[i];
        i++;
    }
    g<<sum1<<"\n"<<sum2<<"\n"<<sum3<<"\n"<<sum4;///fisez cele 4 sume
    return 0;
}
