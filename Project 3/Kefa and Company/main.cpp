///sortez prietenii crescator dupa venitul lor si vad acre este secventa de prieteni care puteau fi invitati simultan
///cu suma gradelor de prietenie maxima
///complexitate: O(n log n)



#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int main()
{
    int n, d;
    cin>>n>>d;///citesc numarul de prieteni si care este diferenta maxima de venit dintre ei
    for(int i=0; i<n; i++)
    {
        int x, y;
        cin>>x>>y;///citesc venitul si gradul de prietenie pentru fiecare prieten
        v.push_back(make_pair(x, y));///ii retin in v
    }
    sort(v.begin(), v.end(), [] (const pair<int, int>& a, const pair<int, int>& b)
         {
             return a.first<b.first;
         });///sortez prietenii crescator dupa venitul lor
    int i=0, j=i;///iau 2 pointeri cu care iterez prin vector
    long long sum_max=0;///suma maxima a gardelor de prietenie
    long long curr_sum=0;///cuma curenta a gradelor de prietenie
    while(i<=j && j<v.size())
    {
        if(j==i)///daca trebuie sa evaluez o singura persoana
        {
            curr_sum+=v[j].second; ///ii adun radul de prietenie la suma curenta si mai uit mai departe
            j++;
        }
        else if(v[j].first-v[i].first<d)///daca intre primul prieten din secventa si ultimul nu e o diferenta mai mare de d
        {
            curr_sum+=v[j].second;
            j++;
        }
        else///daca secventa curenta nu e valida fac ca secventa sa inceapa de la i+1
        {
            i++;
            if(sum_max<curr_sum)///fac update la suma maxima daca e cazul
                sum_max=curr_sum;
            if(i>=1) curr_sum-=v[i-1].second;///sterg fostul prim element din suma curenta, daca e cazul
        }
    }
    if(sum_max<curr_sum)
        sum_max=curr_sum;
    cout<<sum_max;
    return 0;
}
