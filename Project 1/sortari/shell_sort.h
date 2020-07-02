#ifndef SHELL_SORT_H_INCLUDED
#define SHELL_SORT_H_INCLUDED

void shell_sort(std::vector<int> &v, int n, int a)
{
    ///la fel ca si comb sort, folosind compaqrarea pe bucati mai largi reuseste sa pozitioneze corect variabilele mici de la sfarsitul vectorului, care erau costisitoare de shiftat inapoi

    for(int gap=(a-1)/2; gap>=1; a=a/3, gap=(a-1)/2)
    {
        for(int i=gap; i<n; i++)
        {
            int temp=v[i];
            int j;
            for(j=i; j>=gap && v[j-gap]>temp; j-=gap)
                v[j]=v[j-gap];
            v[j]=temp;
        }
    }
}

#endif // SHELL_SORT_H_INCLUDED
