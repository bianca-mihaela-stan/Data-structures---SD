#ifndef RADIXSORT_H_INCLUDED
#define RADIXSORT_H_INCLUDED
#include <cstring>
#include <cmath>
void radix_sort(std::vector <int> &v, std::vector <int> original, int n, int base)
{
    int ok=1, shift=0, x;
    int fv[base+1];
    while(ok)
    {
        ok=0;
        memset(fv, 0, sizeof(fv));
        for(int i=0; i<n; i++)
        {
            v[i]=original[i];
            ///ex: iau bucati de cate 4 biti pt baza 16
            x=(v[i]>>shift) & (base-1);
            fv[x+1]++;
            if(x!=0) ok=1;
        }
        ///fac preprocesarea asta a vectorului de frecvente ca sa obtin direct pozitia pe care ar trebui sa pun in vector
        for(int i=1; i<=base; i++)
        {
            fv[i]+=fv[i-1];
        }
        for(int i=0; i<n; i++)
        {
            x=(original[i]>>shift)&(base-1);
            v[fv[x]]=original[i];
            fv[x]++;
        }
        ///modific vectorul original si continui cu urmatorii 4 biti
        for(int i=0; i<n; i++)
            original[i]=v[i];
        shift+=int(log2(base));

    }
}
#endif // RADIXSORT_H_INCLUDED
