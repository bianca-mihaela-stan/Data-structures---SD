#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> st(1005);
        int stack_top=0;
        int stack_bottom=0;
        vector<int> lista;
        while(head!=NULL)//transform lista in vector ca sa pot sa accesez elementele indexat
        {
            lista.push_back(head->val);
            head=head->next;
        }
        int n=lista.size();
        vector<int> rezultat(n);
        for(int i=0; i<n; i++)//parcurg lista
        {
            if(stack_top==stack_bottom)//daca lista e vida
            {
                st[stack_top]=i;//pun indicele din lista
                stack_top++;
            }
            else if(st[stack_top-1]>=lista[i])//daca ultimul elemente
            {
                st[stack_top]=i;//pun indicele din lista
                stack_top++;
            }
            else
            {
                while(st[stack_top-1]<lista[i] && stack_top>stack_bottom)
                {
                    for(int i=0; i<stack_top; i++)
                    {
                        cout<<st[i]<<" ";
                    }
                    cout<<"\n";
                    int indice=st[stack_top-1];
                    rezultat[indice]=lista[i];
                    //scot elementul respectiv din stack
                    stack_top--;
                }
                st[stack_top]=i;//pun indicele din lista
                stack_top++;
            }
        }
        return rezultat;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);

        vector<int> ret = Solution().nextLargerNodes(head);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
