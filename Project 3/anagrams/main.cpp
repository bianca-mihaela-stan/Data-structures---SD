#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
///probloema clasica de hasuri
int main() {
    int n;
    cin>>n;
    unordered_map<string, int> umap;
    string s;
    getline(cin, s);
    int maxx=0;
    for(int i=0; i<n; i++)
    {
        getline(cin, s);///citesc fiecare cuvant
        sort(s.begin(), s.end());///ii sortez literele pentru ca orice 2 anagrame soratte vor fi identice
        umap[s]++;///incrementez numarul de anagrame pentru literele astea
        maxx=max(maxx, umap[s]);///fac update la maxim
    }
    cout<<maxx;
    return 0;
}
