#ifndef BINARY_INSERTION_SORT_H_INCLUDED
#define BINARY_INSERTION_SORT_H_INCLUDED

void insertion_sort(std::vector <int> &v, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        ///tin mereu in spatele lui i un vector sortat
        int x=v[i];
        int j=i-1;
        while(v[j]> x && j>=left)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=x;
    }
}
int binary_search(int x, int left, int right, std::vector<int> &v)
{
    if(right<=left)///ajunge in cazul < cand: (a+b)/2-1<a => (a+b)/2<a+1 => ex: (3+4)/2=3, 3-1=2; si avem practic doar un element cu care sa comparam
    {
        if(x>v[left])
            return left+1;
        else return left;
    }
    else if (right>left)
    {
        int mid=(left+right)/2;
        if(x==v[mid]) return mid+1;
        if(x>v[mid]) return binary_search(x, mid+1, right , v);
        else return binary_search(x, left, mid-1, v);
    }
}
void binary_insertion_sort(std::vector <int> &v, int left, int right)
{
    for(int i=left; i<=right; i++)///iau toate numerele din sir
    {
        int x=v[i], poz;
        int j=i-1;
        if(v[j]>x && j>left)///le caut in sirul soratat daca e cazul (daca x e mai mare decat predecesorul lui vectorul e tot sortat)
        {
            poz=binary_search(x, left, j, v);///caut pozitia pe care ar trebui sa fie x
            while (j>=poz)///le mut pe restul ca sa il pune pe x
            {
                v[j+1]=v[j];
                j--;
            }
            v[j+1]=x;
        }
        else if (v[j]>x && j==left)///cand sunt doar 2 elemente in sir doar fac swap daca e cazul
        {
            std::swap(v[j], v[i]);
        }
    }
}

#endif // BINARY_INSERTION_SORT_H_INCLUDED
