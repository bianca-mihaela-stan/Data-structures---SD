///initial am vrut sa pun 3 stack-uri (pentru cele 3 tipuri separate pe paranteze) dar asta ar fi acceptat si solutia ([)]
///dupa ce am facut cu o singura stiva am observat ca programul meu nu considera secventele de ()[]{} ca o secventa parantezata corect de 6 elemente
///asa ca am adaugat fv, unde fv[i] este lungimea cel mai lung sir parantezat corect care se termina pe pozitia i
#include <bits/stdc++.h>
using namespace std;
ifstream f ("paranteze.in");
ofstream g ("paranteze.out");
int n, maxx=0;
int fv[1000005];
stack<pair<char, int>> st;
int main()
{
    f>>n;
    string s;
    getline(f, s);///citesc sirul
    getline(f, s);
    for(int i=0; i<n; i++)
    {
        ///pun in stack paranteza curenta si indicele curent
        if(s[i]=='(') st.push(make_pair('(', i+1));
        if(s[i]=='[') st.push(make_pair('[', i+1));
        if(s[i]=='{') st.push(make_pair('{', i+1));

        if(s[i]==')')
        {
            if(!st.empty() && st.top().first=='(')///daca citesc o paranteza inchisa si ultima chestie era o paranteza deschisa
            {
                maxx=max((i+1)-st.top().second+1+fv[st.top().second-1], maxx);///maximul curect va fi lungimea parantezarii inchise adineauri + ce lungime
                                                                              ///avea secventa parantezta corect de  dinaintea primei paranteza considerate acum
                fv[i+1]=(i+1)-st.top().second+1+fv[st.top().second-1];///updatam si fv-ul
                st.pop();
            }
            else
            {
                while(!st.empty())///daca stiva nu goala si citesc o paranteza inchisa care nu inchide nimic pot sa sterg toate elementele din stiva pentru ca oricum maximul e deja retinut
                {
                    st.pop();
                }
            }
        }
        ///repet acelasi mecanism si pentru urmatoarele paranteze
        if(s[i]==']')
        {
            if(!st.empty() && st.top().first=='[')
            {
                maxx=max((i+1)-st.top().second+1+fv[st.top().second-1], maxx);
                fv[i+1]=(i+1)-st.top().second+1+fv[st.top().second-1];
                st.pop();
            }
            else
            {
                while(!st.empty())
                {
                    st.pop();
                }
            }
        }
        if(s[i]=='}')
        {
            if(!st.empty() && st.top().first=='{')
            {
                maxx=max((i+1)-st.top().second+1+fv[st.top().second-1], maxx);
                fv[i+1]=(i+1)-st.top().second+1+fv[st.top().second-1];
                st.pop();
            }
            else
            {
                while(!st.empty())
                {
                    st.pop();
                }
            }
        }
    }
    g<<maxx;
    return 0;
}
