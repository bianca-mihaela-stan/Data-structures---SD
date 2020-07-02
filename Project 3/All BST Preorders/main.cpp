///in f vreau sa generez toti arborii cu noduri de la 1 la n (un fel de "genrare binara")
///=> generez toti arborii cu noduri de la 1 la i-1 si toti arborii cu noduri de la i+1 la n, iar i va fi redacina (unde i merge de la 1 la n)
#include <bits/stdc++.h>
using namespace std;
int nr=0;
struct node
{
    int val;
    node* left;
    node* right;
};

vector<node*> f(int st, int dr)///returnez un vector cu toate posibilitatile
{
    vector<node*> v;
    if(st>dr)///daca am apelat prost functia f
    {
        v.push_back(NULL);
    }
    else if(st==dr)///daca n=1
    {
        node* root=new node;
        root->left=NULL;
        root->right=NULL;
        root->val=st;
        v.push_back(root);
    }
    else for(int i=st; i<=dr; i++)/// altfel fac generarea
    {
        vector<node*> a=f(st, i-1);///toate posibilitatile pentru subarborele stang
        vector<node*> b=f(i+1, dr);///toate posibilitatile pentru subarborele drept
        for(int p=0; p<a.size(); p++)///merg prin toate posibilitatile pentru subarborele stang
        {
            for(int j=0; j<b.size(); j++)///apoi merg prin toate posibilitatile pentru subarborele drept
            {
                node* root=new node;
                root->val=i;
                root->left=a[p];///combin toate posibilitatile intre ele, conectandu-le la radacina curenta si le adaug in vectorul de posibilitati
                root->right=b[j];
                v.push_back(root);
            }
        }
    }
    return v;
}


void preorder(node* root)
{
    if(root!=NULL)
    {
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void preorder_for_v(vector<node*> v)///afisez in preordine toate posibilitatile
{
    for(int i=0; i<v.size(); i++)
    {
        preorder(v[i]);
        cout<<"\n";
    }
}

int main() {
    int n;
    cin >> n;
    preorder_for_v(f(1, n));
    return 0;
}
