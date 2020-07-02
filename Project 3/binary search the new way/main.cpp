#include <bits/stdc++.h>
using namespace std;
class Solution {
int binary_search(vector<int>& v, int& h)
{
    int n= (int)v.size();
    int lg=log2(n)+1;
    int sol=0;

    for(int step=1<<lg; step; step>>=1)
    {
        cout<<sol<<" "<<step<<" "<<v[sol+step]<<" "<<n-sol-step<<"\n";
        if(sol+step<n)
        {
            if(v[sol+step]>=n-sol-step)
            {
                if(v[sol+step]>0)
                    h=max(h, n-sol-step);
            }
            else sol+=step;
        }
    }
    return h;
}
public:
    int hIndex(vector<int>& citations) {
        int h=0;
        if(citations.size()==0) return 0;
        if(citations.size()==1) if(citations[0]>0) return 1; else return 0;
        binary_search(citations, h);
        return h;
    }
};
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> citations = stringToIntegerVector(line);

        int ret = Solution().hIndex(citations);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
