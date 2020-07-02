#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
ifstream f ("timbre.in");
ofstream g ("timbre.out");

vector < pair <int, int> > v;
int n, m, k, suma=0;
bool funct (pair <int, int> a, pair <int, int> b)
{
    if(a.first>b.first) return 1;
    return 0;
}
int main()
{
    f>>n>>m>>k;
    for(int i=0; i<m; i++)
    {
        int x, y;
        f>>x>>y;
        v.push_back(make_pair(x,y));///citesc magazinele si le pun intr-un vector de perechi
    }
    sort(v.begin(), v.end());///le sortez in functie de timbrul maxim pe care il vinde fiecare magazin
    int i=m-1;
    priority_queue <int, vector<int>, greater<int>> pq;
    while(n>0)///cat timp nu am gasit toate timbrele
    {
        while(v[i].first>=n && i>=0)///daca mai am magazine care vand biletul meu cu index maxim
        {
            pq.push(v[i].second);///le adaug in pq
            i--;
        }
        int val=pq.top();///cumpar de la magazinul cu pret minim
        pq.pop();
        n=n-min(k, n);
        suma+=val;///adaug la suma

    }
    g<<suma;
    return 0;
}
