
#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    if(a+b>b+a)
        return 1;
    return 0;
}
string largestConcat(vector<string>& v) {
    sort(v.begin(), v.end(), cmp);///sortez numerele in functie de care ordine de concatenari e mai mare

    string s;
    for(int i=0; i<v.size(); i++)
    {
        s+=v[i];
    }

    if(s[0]=='0') ///dac prima litera e 0 insemna ca numere sunt toate 0 => 0
    {
        s='0';
        return s;
    }
    return s;
}

int main() {
    int N;
    cin >> N;
    vector<string> v;
    for (int i = 0; i < N; ++i) {
        string number;
        cin >> number;
        v.push_back(number);
    }

    cout << largestConcat(v) << "\n";
    return 0;
}
