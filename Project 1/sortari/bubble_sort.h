#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED
void bubble_sort(std::vector <int> &v, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
    {
        if(v[j]>v[j+1])
        {
            std::swap(v[j], v[j+1]);
        }
    }
};


#endif // BUBBLE_SORT_H_INCLUDED
