#include <bits/stdc++.h>
using namespace std;
int maxx;
int minn=1000000000;
vector<int> arrayIntersection(vector<int>& first, vector<int>& second) {
    vector<int> fv(maxx-minn+5);
    vector<int> rez;
    int sh=-minn+1;
    for(int i=0; i<first.size(); i++)
    {
        fv[first[i]+sh]++;
    }
    for(int j=0; j<second.size(); j++)
    {
        if(fv[second[j]+sh]>0)
        {
            fv[second[j]+sh]--;
            rez.push_back(second[j]);
        }
    }
    return rez;
}

int main() {
    int N1, N2;
    cin >> N1 >> N2;
    vector<int> first, second;
    for (int i = 0; i < N1; ++i) {
        int val;
        cin >> val;
        maxx=max(maxx, val);
        minn=min(minn, val);
        first.push_back(val);
    }
    for (int i = 0; i < N2; ++i) {
        int val;
        cin >> val;
        second.push_back(val);
    }

    vector<int> intersection = arrayIntersection(first, second);
    cout << intersection.size() << "\n";
    for (auto& val : intersection) {
        cout << val << " ";
    }
    return 0;
}
