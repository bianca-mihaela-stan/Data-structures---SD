#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED
#include "binary_insertion_sort.h"
const int RUN=32;
int left[10000000], right[10000000];
void merge(std::vector <int> &v, std::vector<int> &aux, int l, int m, int r)
{
    int poz1=l, poz2=m+1;///marcheaza inceputurile celor 2 siruri
    for(int i=0; i< r-l+1; i++)
    {
        ///daca poz2 e inca in aria lui si v[poz2] e mai mic il pun pe v[poz2]
        ///daca poz1 a iesit din aria lui inseamna ca nu mai am elemente din primul sir si il pun pe v[poz2]
        if((v[poz1]>v[poz2] && poz2<=r) || poz1>m)
        {
            aux[i]=v[poz2];
            poz2++;
        }
        ///daca poz2 si-a iesit din arie pun v[poz1]
        ///si daca v[poz1] e mai mic il pun pe v[poz1]
        else
        {
            aux[i]=v[poz1];
            poz1++;
        }
    }
    ///pun toate elemente din aux in v, pe pozitiile de la l la r
    for(int i=0; i<r-l+1; i++)
    {
        v[i+l]=aux[i];
    }
}
void merge_sort(std::vector<int> &v, std::vector<int> &aux, int l,int r)
{
    if(r>l)
    {
        int m=(l+r)/2;
        merge_sort(v, aux, l, m);
        merge_sort(v, aux, m+1, r);
        merge(v,aux,  l, m, r);
    }
}

#endif // MERGE_SORT_H_INCLUDED
