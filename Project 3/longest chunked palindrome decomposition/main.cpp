#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long hash(int st, int dr, string text)
    {
        long long h=0;
        while(dr>=st)
        {
           h=h*100+text[dr]-'a'+1;
           dr--;
        }
        return h;
    }
    int longestDecomposition(string text) {
        int i=0; int j=text.size()-1;
        int nr=0;
        while(i<=j)
        {
            if(hash(0, i,text)==hash(j, text.size()-1, text))
            {
                if(i==j) {nr+=1; text="";}
                else
                {
                    text=text.substr(i+1, j-1-(i+1)+1);
                    i=-1; j=text.size();
                    nr+=2;
                }
            }
            else
            {
                if(i==j || i+1==j) nr+=1;
            }
            i++; j--;
        }
        return nr;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string text = stringToString(line);

        int ret = Solution().longestDecomposition(text);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
