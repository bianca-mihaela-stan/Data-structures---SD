#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include <ctime>
#include <algorithm>
int mediana (int a, int b, int c, std::vector <int> &v)
{
    if(v[a]<v[b])
    {
        if (v[b]<v[c])
            return b;
        if (v[a]<v[c])
            return c;
        return a;
    }
    if(v[a]<v[c])
        return a;
    if (v[b]<v[c])
        return c;
    return b;

}
int pivot_rand(std::vector <int> &v, int st, int dr)
{
    if(st<dr)
    {
        if(dr-1==st)
        {
            if(v[st]>v[dr])
                std::swap(v[st], v[dr]);
            return st;
        }
        srand((int)time(0));
        int r=(rand()%(st-dr+1)+st);
        int p=v[r];
        std::swap(v[r], v[dr]);
        int i=st-1;
        ///i=ultimul element intalnit (pana acum) mai mic ca p
        ///j=viariabila cu care iterez prin v
        for(int j=st; j<=dr-1; j++)
        {
            if(v[j]<p)
            {
                i++;
                std::swap(v[i], v[j]);
            }
        }
        std::swap(v[i+1], v[dr]);
        return i+1;
    }
}
int pivot_m3(std::vector <int> &v, int st, int dr)
{
    if(st<dr)
    {
        if(dr-1==st)
        {
            if(v[st]>v[dr])
                std::swap(v[st], v[dr]);
            return st;
        }
        srand((int)time(0));
        int r1=(rand()%(st-dr+1)+st);
        int r2=(rand()%(st-dr+1)+st);
        int r3=(rand()%(st-dr+1)+st);
        int r=mediana(r1, r2, r3, v);
        int p=v[r];
        std::swap(v[r], v[dr]);
        int i=st-1;
        for(int j=st; j<=dr-1; j++)
        {
            if(v[j]<p)
            {
                i++;
                std::swap(v[i], v[j]);
            }
        }
        std::swap(v[i+1], v[dr]);
        return i+1;
    }
}
int bfrt(std::vector <int> v, int st, int dr)
{
    if(dr-st+1<=5)
    {
        std::sort(v.begin(), v.end());
        int p=v[(st+dr)/2];
        return p;
    }
    else
    {
        std::vector<int> bucket, temp;
        for(int i=st; i<=dr; i++)
        {
            if((i-st)%5==0 && (i-st)!=0)///daca am pus 5 elemente in bucket
            {
                sort(bucket.begin(), bucket.end());
                temp.push_back(bucket[2]);
                bucket.clear();
            }
            bucket.push_back(v[i]);
        }
        return bfrt(temp, 0, temp.size());
    }
}

int pivot_bfrt(std::vector <int> &v, int st, int dr)
{
    if(st<dr)
    {
        if(dr-1==st)
        {
            if(v[st]>v[dr])
                std::swap(v[st], v[dr]);
            return st;
        }
        int p=bfrt(v, st, dr), r;
        for(int i=st; i<=dr; i++)
        {
            if(v[i]==p)
            {
                r=i;
                break;
            }
        }
        int aux=v[r];
        v[r]=v[dr];
        v[dr]=aux;
        int i=st-1;
        for(int j=st; j<=dr-1; j++)
        {
            if(v[j]<p)
            {
                i++;
                std::swap(v[i], v[j]);
            }
        }
        std::swap(v[i+1], v[dr]);
        return i+1;
    }
}

void quicksort_rand(std::vector <int> &v, int st, int dr)
{
    if(st<dr)
    {
        int p=pivot_rand(v, st, dr);
        if(st!=p-1)quicksort_rand(v, st, p-1);
        if(p+1!=dr)quicksort_rand(v, p+1, dr);
    }
}
void quicksort_m3(std::vector <int> &v, int st, int dr)
{
    if(st<dr)
    {
        int p=pivot_m3(v, st, dr);
        if(st!=p-1)quicksort_m3(v, st, p-1);
        if(p+1!=dr)quicksort_m3(v, p+1, dr);
    }
}

void quicksort_bfrt(std::vector <int> &v, int st, int dr)
{
    if(st<dr)
    {
        int p=pivot_bfrt(v, st, dr);
        if(st!=p-1)quicksort_bfrt(v, st, p-1);
        if(p+1!=dr)quicksort_bfrt(v, p+1, dr);
    }
}

#endif // QUICKSORT_H_INCLUDED
