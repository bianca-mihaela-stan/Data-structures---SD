#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
ifstream f("sdo.in");
ofstream g ("sdo.out");
int n, k, low[3000005], ech[3000005], high[3000005];

int quicksort_modificat(int dr, int k, int v[])
{
    int pivot=rand()%dr;///iau un pivot random
    int x=v[pivot];

    int len_l=0,len_e=0, len_h=0;
    for(int i=0; i<dr; i++)///parcurg array-ul de la 0 la dreapta ca sa categorizez toate elmente in funtie de valoarea pivotului
    {
        if(v[i]<x)///daca e mai mic ca pivotul il pun intr-o lista
        {
            low[len_l]=v[i];
            len_l++;
        }
        else if(v[i]==x)///daca e egal cu pivotul in pun in alta lista
        {
            ech[len_e]=v[i];
            len_e++;
        }
        else///daca e mai mare ca pivotul alta lista
        {
            high[len_h]=v[i];
            len_h++;
        }
    }
    if (k<=len_l)///daca pozitia pe care o caut e in low
        quicksort_modificat(len_l, k, low);///fac quicksort pe low
    else if (k<=len_l+len_e)///daca e in ech returnez direct valoarea de la acea pozitie
        return ech[0];
    else///daca e in high fac quicksort pe high
    {
        k=k-(len_l+len_e);
        quicksort_modificat(len_h, k, high);
    }
}
int main()
{
    f>>n;
    f>>k;
    for(int i=0; i<n; i++)
        f>>high[i];
    int val=quicksort_modificat(n, k, high);
    g<<val;
    return 0;
}
