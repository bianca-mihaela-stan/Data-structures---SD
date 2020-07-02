#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("deque.in");
ofstream g ("deque.out");
int v[5000005], dq[5000005];
int fr=1, bk=0;
int main()
{
    int n, k;
    f>>n>>k;
    int64_t sum=0;
    for(int i=1; i<=n; i++)
    {
        f>>v[i];///pun toate numerele intr-un vector
        while(v[i-k]==dq[fr] && bk>=fr)///daca primul element din dq a expirat il sterg
        {
            fr++;
        }
        while(bk>=fr && v[i]<dq[bk])///un element mai mic, cand e inserat, ii sterge pe toti mai mari ca el pe care ii gaseste
        {
            bk--;
        }
        bk++;///adaug elementul
        dq[bk]=v[i];
        ///creez suma pentru intervalul curent pe acre o adaug la suma totala
        if(i>=k)
        {
            sum+=dq[fr];
        }
    }
    g<<sum;
    return 0;
}
