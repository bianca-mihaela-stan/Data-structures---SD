#include <bits/stdc++.h>
using namespace std;

int closestPair(vector<int>& first, vector<int>& second) {
    sort(first.begin(), first.end());///sortez cei 2 vectori
    sort(second.begin(), second.end());

    int minn1=1000000005;
    int minn2=1000000005;

    int a=0, b=0;
    while(a<first.size() && b<second.size())///calculez cea mai mica diferenta second-first
    {
        if(second[b]<first[a]) b++;
        else { minn1=min(minn1, second[b]-first[a]); a++;}
    }

    a=0, b=0;
    while(a<first.size() && b<second.size())///calculez cea mai mica diferenta second-first
    {
        if(second[b]>first[a]) a++;
        else { minn2=min(minn2, first[a]-second[b]); b++;}
    }
    return min(minn1, minn2);
}

int main() {
    int n; cin >> n;
    vector<int> first, second;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        first.push_back(val);
    }
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        second.push_back(val);
    }
    cout << closestPair(first, second) << "\n";
    return 0;
}
