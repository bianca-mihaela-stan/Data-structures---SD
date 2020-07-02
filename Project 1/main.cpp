#include <iostream>
#include <fstream>
#include <vector>
#include "sortari/bubble_sort.h"
#include "sortari/comb_sort.h"
#include "sortari/quicksort.h"
#include "sortari/radixsort.h"
#include "sortari/merge_sort.h"
#include "sortari/binary_insertion_sort.h"
#include "sortari/shell_sort.h"
#include <ctime>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;
ifstream f ("project.in");
ofstream g ("project.out");
int n, maxx;
vector <int> v;
vector <int> original, aux, sortat;
uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
uint64_t currentTime()
{
    return timeSinceEpochMillisec();;
}
void generare_sir(int n, vector <int> &original,int maxx)
{
    srand(time(0));
    int seed=rand()*rand();
    mt19937_64 r(seed);
    uniform_int_distribution<int> distr;
    for(int i=0; i<n; i++)
    {
        original.push_back(distr(r)%maxx);
    }
}
bool verificare_sortare(vector<int> sortat, vector<int> v)
{
    for (int i=0; i<v.size(); i++)
    {
        if(v[i]!=sortat[i])
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    f>>t;
    for(int i=0; i<t; i++)
    {
        cout<<"A inceput testul "<<i+1<<".\n";
        f>>n;
        f>>maxx;
        g<<"\nTestul "<<i+1<<": maxx="<<maxx<<" n="<<n<<"\n\n";
        cout<<"\nPe vector neordonat: \n\n";
        g<<"Pe vector neordonat: \n\n";
        ///generarea sirului:
        v.clear();
        original.clear();
        sortat.clear();
        generare_sir(n, original, maxx);
        cout<<"S-a generat sirul.\n";
        ///apelare sort din STL:
        g<<"Sort din STL: ";
        v.clear();
        for(int i=0; i<n; i++)
            sortat.push_back(original[i]);
        uint64_t t1=currentTime();
        sort(sortat.begin(), sortat.end());
        uint64_t t2=currentTime();
        g<<t2-t1<<" milisecunde\n";
        cout<<"S-a terminat sortarea din STL.\n";
        ///apelare bubble sort:
        g<<"Bubble sort: ";
        if(maxx>1000000000 || n>10000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            bubble_sort(v, n);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu bubble sort.\n";
        ///apelare comb sort
        g<<"Comb sort: ";
        if(maxx>1000000000 || n>10000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            comb_sort(v, n);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu comb sort.\n";
        ///apelare quicksort cu pivot random
        g<<"Quicksort random: ";
        if(maxx>1000000000 || n>10000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            quicksort_rand(v, 0,  n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu quicksort cu pivot random.\n";
        ///apelare quicksort cu mediana din 3
        g<<"Quicksort mediana din 3: ";
        if(maxx>1000000000 || n>10000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            quicksort_m3(v, 0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu quicksort cu mediana din 3.\n";
        ///apelare quicksort cu mediana medianelor
        g<<"Quicksort cu mediana medianelor: ";
        if(maxx>1000000000 || n>10000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            quicksort_bfrt(v, 0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu quicksort cu bfprt.\n";
        ///apelare radixsort cu baza 16
        g<<"Radixsort cu baza 16: ";
        if(maxx>100000000 || n>10000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            radix_sort(v, original, n, 16);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu radixsort cu baza 16.\n";
        ///apelare radixsort cu baza 256
        g<<"Radixsort cu baza 256: ";
        if(maxx>10000000 || n>100000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            radix_sort(v, original, n, 16);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu radixsort cu baza 256.\n";
        ///apelare mergesort
        g<<"Merge sort: ";
        if(maxx>1000000000 || n>10000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                v.push_back(original[i]);
                aux.push_back(original[i]);
            }
            uint64_t t1=currentTime();
            merge_sort(v, aux,0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu mergesort.\n";
        g<<"Insertion sort: ";
        if(maxx>1000000000 || n>50000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                v.push_back(original[i]);
            }
            uint64_t t1=currentTime();
            insertion_sort(v,0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu insertion sort.\n";
        g<<"Binary insertion sort: ";
        if(maxx>1000000000 || n>50000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                v.push_back(original[i]);
            }
            uint64_t t1=currentTime();
            binary_insertion_sort(v,0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu binary insertion sort.\n";
         g<<"Shell sort: ";
        if(maxx>1000000 || n>10000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                v.push_back(original[i]);
            }
            uint64_t t1=currentTime();
            int x=pow(3, int(log2((n/3)*2+1)/log2(3)));
            shell_sort(v, n, x);///dupa formula (3^k-1)/2, Knuth, 1973[3], based on Pratt, 1971, care garanteaza O(n^(3/2)) in worst case
            uint64_t t2=currentTime();

            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu shell sort.\n";


        sort(original.begin(), original.end(),greater<int>());

        cout<< "\nPe vector cu nr ordonate descrescator:\n\n";
        g<<"\nPe vector cu nr ordoante descrescator:\n\n";
         g<<"Sort din STL: ";
        v.clear();
        sortat.clear();
        for(int i=0; i<n; i++)
            sortat.push_back(original[i]);
        t1=currentTime();
        sort(sortat.begin(), sortat.end());
        t2=currentTime();
        g<<t2-t1<<" milisecunde\n";
        cout<<"S-a terminat sortarea din STL.\n";
        ///apelare bubble sort:
        g<<"Bubble sort: ";
        if(maxx>1000000000 || n>10000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            bubble_sort(v, n);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu bubble sort.\n";
        ///apelare comb sort
        g<<"Comb sort: ";
        if(maxx>1000000000 || n>10000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            comb_sort(v, n);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu comb sort.\n";
        ///apelare quicksort cu pivot random
        g<<"Quicksort random: ";
        if(maxx>1000000000 || n>1000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            quicksort_rand(v, 0,  n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu quicksort cu pivot random.\n";
        ///apelare quicksort cu mediana din 3
        g<<"Quicksort mediana din 3: ";
        if(maxx>1000000000 || n>1000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            quicksort_m3(v, 0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu quicksort cu mediana din 3.\n";
        ///apelare quicksort cu mediana medianelor
        g<<"Quicksort cu mediana medianelor: ";
        if(maxx>1000000000 || n>10000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            quicksort_bfrt(v, 0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu quicksort cu bfprt.\n";
        ///apelare radixsort cu baza 16
        g<<"Radixsort cu baza 16: ";
        if(maxx>100000000 || n>10000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            radix_sort(v, original, n, 16);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu radixsort cu baza 16.\n";
        ///apelare radixsort cu baza 256
        g<<"Radixsort cu baza 256: ";
        if(maxx>10000000 || n>100000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
                v.push_back(original[i]);
            uint64_t t1=currentTime();
            radix_sort(v, original, n, 16);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu radixsort cu baza 256.\n";
        ///apelare mergesort
        g<<"Merge sort: ";
        if(maxx>1000000000 || n>10000000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                v.push_back(original[i]);
                aux.push_back(original[i]);
            }
            uint64_t t1=currentTime();
            merge_sort(v, aux,0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu mergesort.\n";
        g<<"Insertion sort: ";
        if(maxx>1000000000 || n>50000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                v.push_back(original[i]);
            }
            uint64_t t1=currentTime();
            insertion_sort(v,0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu insertion sort.\n";
        g<<"Binary insertion sort: ";
        if(maxx>1000000000 || n>50000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                v.push_back(original[i]);
            }
            uint64_t t1=currentTime();
            binary_insertion_sort(v,0, n-1);
            uint64_t t2=currentTime();
            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu binary insertion sort.\n";
         g<<"Shell sort: ";
        if(maxx>1000000 || n>10000)
        {
            g<<"input prea mare\n";
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                v.push_back(original[i]);
            }
            uint64_t t1=currentTime();
            int x=pow(3, int(log2((n/3)*2+1)/log2(3)));
            shell_sort(v, n, x);///dupa formula (3^k-1)/2, Knuth, 1973[3], based on Pratt, 1971, care garanteaza O(n^(3/2)) in worst case
            uint64_t t2=currentTime();

            g<<t2-t1<<" milisecunde, ok:"<<verificare_sortare(sortat, v)<<"\n";
        }
        cout<<"S-a terminat sortarea cu shell sort.\n";
    }

    return 0;
}
