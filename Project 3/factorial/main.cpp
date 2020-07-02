#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("fact.in");
ofstream g ("fact.out");
int n, minn=100000005;
int nr_zerouri(int n)
{
    int putere=5;
    int sum=0;
    while(n/putere)
    {
        sum+=n/putere;
        putere=putere*5;
    }
    return sum;///de cate ori incape 5 in n + de cate ori incape 25 in n+ de cate ori incape 125 in n +...
}
void cautare_binara(int k, int st, int dr, int& minn)
{
    if(st<=dr)
    {
        //int putere=5;
        int mij=(st+dr)/2;
        int sum=nr_zerouri(mij);
        //cout<<mij<<" "<<sum<<"\n";
        if(sum==k)///daca am ajuns la fix n zerouri (nu mai multe) inseamna ca suntem la distanta maxim 5 de numarul minim cautat si pot sa il caut iterativ
        {
            if(minn>mij)
                minn=mij;
            while(nr_zerouri(mij-1)==k)
            {
                mij--;
                minn=mij;
            }
        }
        else if (sum>k) cautare_binara(k, st, mij-1, minn);///daca am mai multe zerouri caut in jos
        else cautare_binara(k, mij+1, dr, minn);///daca am mai putine caut in sus
    }
}
int main()
{
    f>>n;
    if(n==0) g<<1;
    else {cautare_binara(n, 0, 10*n, minn);///caut nrnim cu n k-uri de la 0 la 10*n ca mijlocul sa fie fix 5*n, care sigur are cel putin n 5-uri in factorial
    if(minn==100000005) g<<-1;
    else g<<minn;
    ;}
    return 0;
}
