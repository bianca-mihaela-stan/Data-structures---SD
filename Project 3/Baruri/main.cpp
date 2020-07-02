#include <bits/stdc++.h>
#define bit(x) ( x & (-x) )///ultimul bit activat
using namespace std;

const int NMAX = 1e5 + 5;
int aib[NMAX], n;

ifstream f("baruri.in");
ofstream g("baruri.out");

void update(int pos,int val) {
    ///ex: daca vreau sa fac update la valoarea 9=1001 cu 3 adaug la 9 3
    ///apoi adaug 3 la 1001 + (1001 & (0111))=1010 = 10
    ///apoi adaug 3 la 1100=12 si tot asa pana ajungem la un numar mai mare ca n
    for(int i = pos; i <= n; i += bit(i))
    {
        aib[i] += val;
    }
}

int query(int pos) {///vreau sa aflu suma elemetelor de la 0 la pos
    int sum = 0;
    for(int i = pos; i > 0; i -= bit(i)) {///incep de la pos si sterg ultimul bit activat pana ajung la 0 (merg din fiu in tata)
        sum += aib[i];
    }
    return sum;
}

int main()
{
    int t;
    f >> t;///citesc numarul de teste
    while(t--) {
        f >> n;///citesc cate baruri sunt in testul curent
        for(int i = 1; i <= n; i++) ///aib indexat de la 1
        {
            aib[i] = 0;///la inceput array-ul care retine aib-ul este complet 0
        }
        for(int i = 1; i <= n; i++)
        {
            int x;
            f >> x;///[entru fiecare informatie despre un bar fac update la aib
            update(i, x);
            for(int j=1; j<=n; j++)
            {
                cout<<aib[j]<<" ";
            }
            cout<<"\n";
        }
        int q;
        f >> q;///citesc numarul de query-uri
        while(q--) {
            int op;
            f >> op;///citesc optiunea
            if(op == 0) {///cati prieteni sunt in barurile aflate la o distanta maxima d fata de barul b (nu se pun cei din barul b)
                int b, d;
                f >> b >> d;
                g << query(min(b + d, n)) - query(max(b - d - 1, 0)) - (query(b) - query(b - 1)) << '\n';
                ///suma de la b in ambele directii d pozitii - numarul din b=
                ///suma de la 0 la b+d- suma de la 0 la b-d-1 - suma din b
                ///unde suma din b = suma de la 0 la b - suma de la 0 la b-1
            }
            if(op == 1) {///x prieteni noi intra in barul b
                int x, b;
                f >> x >> b;
                update(b, x);
            }
            if(op == 2) {///x prieteni din barul b pleaca
                int x, b;
                f >> x >> b;
                update(b, -x);
            }
            if(op == 3) {///x prieteni se muta din barul b1 in barul b2
                int x, b1, b2;
                f >> x >> b1 >> b2;
                update(b1, -x);
                update(b2, x);
            }
        }
    }
    return 0;
}
