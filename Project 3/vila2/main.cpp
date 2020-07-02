#include <bits/stdc++.h>

using namespace std;
ifstream f ("vila2.in");
ofstream g ("vila2.out");
int n, k;
deque <int> dq1, dq2;
int v[100005];
int maxx=0;
int main()
{
    f>>n>>k;
    for(int i=1; i<=n; i++)
    {
        f>>v[i];

        ///voi avea 2 deque-uri care, pentru o secventa de lungime k retin: prima minimul, a doua maximul
        if(!dq1.empty())//pt minim
        {
            if(dq1.front()==i-k-1)///daca primul elemet a iesit din range-ul de k elemente il scot
                {dq1.pop_front();}
            ///daca modulul diferentei dintre elementul curent si cel mai mic element din range-ul asta e mai mare decat maximul de pana acum fac update
            maxx=max(maxx, abs(v[i]-v[dq1.front()]));
            while(!dq1.empty() && v[i]<v[dq1.back()])///cand punem un element un dq il punem la spate is radem tot ce e mai mare ca el in fata lui
            {
                dq1.pop_back();
            }
        }
        ///am nevoie sa pun i in dq si nu v[i] pentru ca vreau sa stiu cand primul element iese din range
        dq1.push_back(i);///dupa ce am ras toate elementele pot sa il pun pe cel curent

        ///pentru maxim fac acelasi lucru
        if(!dq2.empty())
        {
            if(dq2.front()==i-k-1)
                {dq2.pop_front();}
            maxx=max(maxx, abs(v[i]-v[dq2.front()]));
            while(!dq2.empty() && v[i]>v[dq2.back()])
            {
                dq2.pop_back();
            }
        }
        dq2.push_back(i);
    }
    g<<maxx;///in final afisez maximul
    return 0;
}
