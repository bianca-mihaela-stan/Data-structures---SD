#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <iterator>
using namespace std;
ifstream f ("freakadebunic.in");
ofstream g ("freakadebunic.out");
int trupe[100005];
int n, k;
vector<int> sir, t;
int viz[100005];
int poz_trupe[100005];
void DFS(int x, vector <vector <int> > m)
{
    if(viz[x]==0)
    {
        viz[x]=1;
        sir.push_back(x);
        if(trupe[x]==1 && poz_trupe[x]==-1)
            poz_trupe[x]=sir.size()-1;
        for(int i=0; i<m[x].size(); i++)
        {
            //cout<<m[x][i]<<" ";
            if(viz[m[x][i]]==0)
            {
                DFS(m[x][i], m);
                sir.push_back(x);
            }
        }
    }
}

void RMQ(vector <int> sir, vector <int> t, int poz_trupe[100005], int dim)
{
    int rmq[100005][dim+5];
    for(int i=0; i<dim; i++)
    {
        rmq[0][i]=i;
    }
    for(int j=1; j<=int(log2(dim)); j++)
    {
        for(int i=0; i<dim-j; i++)
        {
            if(sir[rmq[j-1][i]]<=sir[rmq[j-1][i+1]])
                rmq[j][i]=rmq[j-1][i];
            else
                rmq[j][i]=rmq[j-1][i+1];
        }
    }
    set <int> s;
    for(int i=0; i<t.size(); i++)
    {
        for(int j=i+1; j<t.size(); j++)
        {
            int nod1=t[i];
            int nod2=t[j];///cele 2 noduri
            //cout<<nod1<<" "<<nod2<<"\n";
            int poz_nod1=poz_trupe[nod1];
            int poz_nod2=poz_trupe[nod2];///prima aparitie a fricaruia in sir
            //cout<<poz_nod1<<" "<<poz_nod2<<"\n";
            int log=log2(abs(poz_nod1-poz_nod2)+1);///log de distanta dintre ele
            int min_prefix=rmq[log][min(poz_nod1, poz_nod2)];
            //cout<<log<<" "<<pow(2, log)<<"\n";
            int min_suffix=rmq[log][max(poz_nod1, poz_nod2)-int(pow(2, log))+1];
            //cout<<log<<" "<<min(poz_nod1, poz_nod2)<<" "<<max(poz_nod1, poz_nod2)-int(pow(2, log))+1<<"\n";
            //cout<<rmq[log][min(poz_nod1, poz_nod2)]<<" "<<rmq[log][max(poz_nod1, poz_nod2)-int(pow(2, log))+1]<<"\n\n";
            s.insert(min(sir[min_prefix], sir[min_suffix]));
        }
    }
    g<<s.size()<<"\n";
    set <int, greater <int> > :: iterator itr;
    for (itr = s.begin(); itr != s.end(); ++itr)
    {
        g<< *itr<<" ";
    }
}

int main()
{
    f>>n>>k;
    vector <vector <int> > m(n+1);
    memset(poz_trupe, -1, sizeof(poz_trupe));
    for(int i=0; i<k; i++)
    {
        int x;
        f>>x;
        trupe[x]++;
        t.push_back(x);
    }
    for(int i=0; i<n-1; i++)
    {
        int x, y;
        f>>x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    DFS(1, m);
    RMQ(sir, t, poz_trupe, sir.size());
//    for(int i=0; i<t.size(); i++)
//    {
//        cout<<t[i]<<" "<<poz_trupe[t[i]]<<"\n";
//    }
    return 0;
}
