#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("algsort.in");
ofstream g ("algsort.out");
int a[500005];
void interclasare(int l, int m, int d)
{
    int n1, n2, i, j, k;
    n1=m-l+1;
    n2=d-m;
    int v[n1], u[n2];///imi creez 2 array-uri noi
    for(i=1; i<=n1; i++)
    {
        v[i]=a[l-1+i];
    }
    for(j=1; j<=n2; j++)
    {
        u[j]=a[m+j];
    }

    i=1; j=1; k=l;
    while(i<=n1 && j<=n2)///fac interclasare clasica
    {
        if(v[i]<=u[j])
        {
            a[k]=v[i];
            i++;
        }
        else
        {
            a[k]=u[j];
            j++;
        }
        k++;
    }
    while(i<=n1)
    {
        a[k]=v[i];
        i++;
        k++;
    }
    while(j<=n2)
    {
        a[k]=u[j];
        j++;
        k++;
    }
}
void mergesort(int l, int d)
{
    int m;
    if(l<d)
    {m=(l+d)/2;
    mergesort(l,m);///fac mergesort pe ambele bucati
    mergesort(m+1,d);
    interclasare(l,m,d);}///si apelez interclasarea
}

int main()
{
    int n, i;
    f>>n;
    for(i=1; i<=n; i++)
        f>>a[i];
    mergesort(1, n);///fac mergesort de ;la 1 la n
    for(i=1; i<=n; i++)
        g<<a[i]<<" ";
    return 0;
}
