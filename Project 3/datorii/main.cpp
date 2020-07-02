#include <bits/stdc++.h>
#define bit(x) ( x & (-x) )///ultimul bit activat
using namespace std;

const int NMAX = 15005;
int aib[NMAX], n, q;

ifstream f("datorii.in");
ofstream g("datorii.out");

void update(int pos,int val) {
    ///ex: daca vreau sa fac update la valoarea 9=1001 cu 3 adaug la 9 3
    ///apoi adaug 3 la 1001 + (1001 & (0111))=1010 = 10
    ///apoi adaug 3 la 1100=12 si tot asa pana ajungem la un numar mai mare ca n
    for(int i = pos; i <= n; i += bit(i)) {
        aib[i] += val;///incep de la pos si sterg ultimul bit activat pana ajung la 0 (merg din fiu in tata)
    }
}

int query(int pos) {///vreau sa aflu suma elemetelor de la 0 la pos
    int sum = 0;
    for(int i = pos; i > 0; i -= bit(i)) {
        sum += aib[i];
    }
    return sum;
}

int main()
{
    f >> n >> q;///citesc lungimea sirului si numarul de query-uri
    for(int i = 1; i <= n; i++)
    {
        int x;
        f >> x;///citesc valoarea pentru fiecare zi si fac update la aib
        update(i, x);
    }
    while(q--)
    {
        int op;
        f >> op;///citesc optiunea
        if(op == 0) ///cada cineva vrea sa achite o comanda
        {
            int pos, val;
            f >> pos >> val;
            update(pos, -val);/// fac update
        }
        else///daca vreau sa stiu suma
        {
            int st, dr;
            f >> st >> dr;
            g << query(dr) - query(st - 1) << '\n';///fac query pe intervalul respectiv
        }
    }
    return 0;
}
