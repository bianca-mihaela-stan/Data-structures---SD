#ifndef COMB_SORT_H_INCLUDED
#define COMB_SORT_H_INCLUDED
#include "bubble_sort.h"
///imbunatateste bubble sort prin faptul ca reduce numarul de valori mici care se afla la sfarsitul vectorului si care vor trebui date inapoi foarte mult, incetinind algoritmul
///comb sort nu mai face comparari intre elemente consecutive, ci compara elemente intre care exista un anumit gap, care se tot micsoreaza
int shrink_factor=13;
int next_gap(int gap)
{
    gap=(gap*10)/shrink_factor;
    if(gap<1)
        return 1;
    return gap;
}
void comb_sort(std::vector <int> &v, int n)
{
    int gap=n;
    int swapping=1;
    while(gap!=1 || swapping==1)
    {
        gap=next_gap(gap);
        swapping=0;
        for(int i=0; i<n-gap; i++)
        {
            if(v[i]>v[i+gap])
            {
                std::swap(v[i], v[i+gap]);
                swapping=1;
            }
        }
    }
}

#endif // COMB_SORT_H_INCLUDED
