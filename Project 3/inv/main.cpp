///problema discutata la seminar, in rezolvarea ei m-am folosit de codul meu de la permutariab de la fminostress
#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("inv.in");
ofstream g ("inv.out");
int a[100005];
void merging(int p[100005], int st, int mij, int dr, long long& nr_swaps)
{
    int l[mij-st+2];///fac 2 array-uri separate pentru cele doua bucati la care fac merge
    int r[dr-mij+1];
    for(int i=1; i<=mij-st+1; i++)
    {
        l[i]=p[st+i-1];
    }
    for(int i=1; i<=dr-mij; i++)
    {
        r[i]=p[mij+i];
    }
    int i=1, j=1;
    int t=st;
    int pate=0;///pate e numarul de valori din r care au fost mai mici care s-au dus in spatele lui i

    ///exemplu: 3 6 10  si  1 2 4
    ///1<3, deci se fac 3 swap-uri si 1 va fi in fata lui 3, j++
    ///2<3, daca ar fi sa nu am pate ar insemna ca fac 4 swap-uri (ca trec si peste 1) doar ca 1 nu e acolo, e in
    ///fata lui 3
    ///=>la asta ma ajuta pate, sa tin const cu cate valori din l nu mai fac swap

    ///fac interclasare intre l si r
    while(i<=mij-st+1 && j<=dr-mij)///cat timp niciuna dintre array-uri nu s-a terminat
    {
        if(r[j]<l[i])///daca trebuie sa mut un element catre inceput adauga la numarul de inversiuni
        {
            int len1=mij-st-(i-1)-pate;
            int len2=j-1;
            nr_swaps+=len1+len2+1;
            p[t]=r[j];///pun elementul in pozitia corecta
            pate++;
            j++;
            t++;
        }
        else
        {
            p[t]=l[i];
            i++;
            t++;
        }
    }
    ///cat timp mai am elemente in unul din array-uri le pun in pozitia corecta
    while(i<=mij-st+1)
    {
        p[t]=l[i];
        t++;
        i++;
    }
    while(j<=dr-mij)
    {
        p[t]=r[j];
        j++;
        t++;
    }
}
void merge_sort(int p[100005], int st, int dr, long long& nr_swaps)
{
    if(st<dr)
    {
        if(st+1==dr)///daca am 2 elemente doar fac un swap daca e cazul
        {
            if(p[dr]<p[st])
            {
                nr_swaps++;
                swap(p[st], p[dr]);
            }
        }
        else///altfel fac mergesort pe ambele jumatati si le merge-uiesc dupa
        {
            int mij=(st+dr)/2;
            merge_sort(p, st, mij, nr_swaps);
            merge_sort(p, mij+1, dr, nr_swaps);
            merging(p, st, mij, dr, nr_swaps);
        }
    }
    return;
}

int n;
int main()
{
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>a[i];///citesc numerele
    }
    long long rez=0;
    merge_sort(a, 1, n, rez);///si in timpul la merge sort numar inversiunile
    g<<rez%9917;///initial nu pusesem 9917 si de-aia nu mergea
    return 0;
}
