#include <bits/stdc++.h>
#define bit(x) ( x & (-x) )
using namespace std;

const int NMAX = 1e5 + 5;
int aib[NMAX], n;

ifstream f("baruri.in");
ofstream g("baruri.out");

void update(int pos,int val) {
    for(int i = pos; i <= n; i += bit(i)) {
        aib[i] += val;
    }
}

int query(int pos) {
    int sum = 0;
    for(int i = pos; i > 0; i -= bit(i)) {
        sum += aib[i];
        //cout << aib[i] << ' ';
    }
    return sum;
}

int main()
{
    int t;
    f >> t;
    while(t--) {
        f >> n;
        for(int i = 1; i <= n; i++) {
            aib[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            int x;
            f >> x;
            update(i, x);
        }
        int q;
        f >> q;
        while(q--) {
            int op;
            f >> op;
            if(op == 0) {
                int b, d;
                f >> b >> d;
                g << query(min(b + d, n)) - query(max(b - d - 1, 0)) - (query(b) - query(b - 1)) << '\n';
            }
            if(op == 1) {
                int x, b;
                f >> x >> b;
                update(b, x);
            }
            if(op == 2) {
                int x, b;
                f >> x >> b;
                update(b, -x);
            }
            if(op == 3) {
                int x, b1, b2;
                f >> x >> b1 >> b2;
                update(b1, -x);
                update(b2, x);
            }
        }
    }
    return 0;
}