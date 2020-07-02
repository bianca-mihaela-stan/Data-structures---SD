#include <iostream>
#include <ctime>
#include <random>
#include <fstream>
using namespace std;
ifstream f ("abce.in");
ofstream g ("abce.out");
int*v= new int[100000];
int p=0;
void generare_sir(int q, int* v)
{
    srand(time(0));
    int seed=rand()*rand();
    mt19937_64 r(seed);
    uniform_int_distribution<int> distr;
    for(int i=0; i<q; i++)
    {
        v[i]=(distr(r)%(100*q));
    }
}
struct treap_node
{
    int key, priority;
    treap_node *left, *right;
};
treap_node* rotate_right(treap_node *y)
{
    treap_node *x=y->left;
    treap_node *T1=x->left;
    treap_node *T2=x->right;
    treap_node *T3=y->right;
    x->left=T1;
    x->right=y;
    y->left=T2;
    y->right=T3;
    return x;
}
treap_node* rotate_left(treap_node *x)
{
    treap_node *y=x->right;
    treap_node *T2=y->left;
    treap_node *T3=y->right;
    treap_node *T1=x->left;
    y->left=x;
    x->right=T2;
    return y;
}


treap_node* new_node(int key)
{
    treap_node* temp=new treap_node;
    temp->key=key;
    temp->priority=v[p];
    p++;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void output_inorder(treap_node* root)
{
    if(root)
    {
        output_inorder(root->left);
        cout<<"key: "<<root->key<<" | priority: "<< root->priority;
        if(root->left)
            cout<<" | left child: "<<root->left->key<<" with priority: "<<root->left->priority;
        if(root->right)
            cout<<" | right child: "<<root->right->key<<" with priority: "<<root->right->priority;
        cout<<"\n";
        output_inorder(root->right);
    }
}


treap_node* insert_node(treap_node* root, int key)
{
    if(root==NULL)///daca treap-ul este gol doar creeez un nou nod
        return new_node(key);
    else if(key<=root->key)
    {
        root->left=insert_node(root->left, key);///inserez in stanga
        if(root->left->priority > root->priority)///daca nu e satisfacuta conditia de heap de maxim
            root=rotate_right(root);
    }
    else///inserez la dreapta
    {
        root->right=insert_node(root->right, key);

        if(root->right->priority > root->priority)
            root=rotate_left(root);
    }
    return root;
}





treap_node* delete_node(treap_node* root, int key, int& nr_aparitii)
{
    if(!root)
        return root;
    if(key<root->key)///il caut in partea stanga
    {
        root->left=delete_node(root->left, key, nr_aparitii);
    }
    else if (key>root->key)///il caut in partea dreapta
    {
        root->right=delete_node(root->right, key, nr_aparitii);
    }
    ///altfel, daca am gasit nodul
    else if (root->left==NULL)///daca are noduri doar in dreapta sau in stanga e usor de sters
    {
        treap_node *temp=root->right;
        delete (root);
        nr_aparitii++;
        root=temp;
    }
    else if (root->right==NULL)
    {
        treap_node *temp=root->left;
        delete (root);
        nr_aparitii++;
        root=temp;
    }
    ///daca are noduri in ambele parti trebuie sa tin cont de prioritati
    else if (root->left->priority<root->right->priority)///vreau sa il pun in locul lui root pe nodul cu prioritate mai mare
    {
        nr_aparitii++;
        root=rotate_left(root);///asa ca rotesc la stanga sa il aduc pe cel cu prioritate mai mare in varf
        root->left=delete_node(root->left, key, nr_aparitii);///si apoi sterg din subarborele stang
    }
    else
    {
        nr_aparitii++;
        root=rotate_right(root);
        root->right=delete_node(root->right, key, nr_aparitii);
    }
    return root;
}





bool find_val(treap_node* root, int key)
{
    if (root==NULL)
        return 0;
    else if(root->key==key)
        return 1;
    else if (key < root->key)
        return find_val(root->left, key);
    else return find_val(root->right, key);
}



int succesor(treap_node* root, int x, int& potential)
{
    if(root==NULL)
    {
        if(potential==100000000)
            return -1;
        else return potential;
    }
    else if(root->key==x)
        return x;
    else if(root->key>x)///am gasit un nr mai mare ca x, poate chiar succesorul lui
    {
        if(root->key<potential) potential=root->key;
        succesor(root->left, x, potential);///caut in stanga elementului gasit, poate exista noduri si mai mici care sunt totusi mai mari ca x
    }
    else
    {
        succesor(root->right, x, potential);///daca am gasit un element mai mic ca x caut in dreapta lui, poate exista si noduri mai mari ca x
    }
}


int predecesor(treap_node* root, int x, int& potential)
{
    if(root==NULL)
    {
        if(potential==-100000001)
            return -1;
        else return potential;
    }
    else if(root->key==x)
        return x;
    else if(root->key<x)
    {
        if(root->key>potential) potential=root->key;
        predecesor(root->right, x, potential);
    }
    else
    {
        predecesor(root->left, x, potential);
    }
}


void afisare_interval(treap_node* root, int x, int y)/// parcurgere SRD
{
    if(root)
    {
        afisare_interval(root->left, x, y);
        if(root->key>=x && root->key<=y) g<<root->key<<" ";
        afisare_interval(root->right, x, y);
    }
    return;
}

int main()
{
    int q, x, y, z;
    f>>q;
    generare_sir(q, v);///generz un sir de nr random pe care sa le am la indemana
    treap_node* root= NULL;
    for(int i=0; i<q; i++)
    {
        f>>x;
        if(x==1)
        {
            f>>y;
            root=insert_node(root, y);
        }
        else if (x==2)
        {
            f>>y;
            int nr_aparitii=0;
            root=delete_node(root, y, nr_aparitii);
            g<<nr_aparitii<<"\n";
        }
        else if (x==3)
        {
            f>>y;
            g<<find_val(root, y)<<"\n";
        }
        else if (x==4)
        {
            f>>y;
            int potential=-1000000000;
            g<<predecesor(root, y, potential)<<"\n";
        }
        else if (x==5)
        {
            f>>y;
            int potential=1000000000;
            g<<succesor(root, y, potential)<<"\n";
        }
        else if (x==6)
        {
            f>>y>>z;
            afisare_interval(root, y, z);
            g<<"\n";
        }

    }
    delete v;
    return 0;
}
