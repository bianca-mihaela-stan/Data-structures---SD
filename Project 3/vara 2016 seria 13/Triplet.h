#ifndef TRIPLET_H_INCLUDED
#define TRIPLET_H_INCLUDED
#include <bits/stdc++.h>
template<class A,class B,class C>
class Triplet
{
private:
    A first;
    B second;
    C third;
public:
    Triplet()
    {

    }
    Triplet(A f,B s,C t): first(f),
        second(s),
        third(t)
    {
    }

};

template<>
class Triplet <int, int, int>
{
    private:
    int first;
    int second;
    int third;
public:
    Triplet(int f=0,int s=0,int t=0): first(f), second(s), third(t) {};
    Triplet& operator- (const Triplet& ob )
    {
        int a=third-ob.third;
        int b=second-ob.second;
        int c=first-ob.first;
        if(b<0) {a--; b=b+12;}
        if(c<0) {b--; c=c+30;}
        Triplet<int, int, int> t(a, b, c);
        return t;
    }
    bool operator> (const Triplet& ob)
    {
        if(first<ob.first) return 0;
        else if(first>ob.first) return 1;
        else
        {
            if(second<ob.second) return 0;
            else if(second>ob.second) return 1;
            else
            {
                if(third<ob.third) return 0;
                else if(third>ob.third) return 1;
                else return 0;
            }
        }
    }
    bool operator>= (const Triplet& ob)
    {
        if(first<ob.first) return 0;
        else if(first>ob.first) return 1;
        else
        {
            if(second<ob.second) return 0;
            else if(second>ob.second) return 1;
            else
            {
                if(third<ob.third) return 0;
                else if(third>ob.third) return 1;
                else return 1;
            }
        }
    }
    bool operator< (const Triplet& ob)
    {
        return 1-((*this)>=ob);
    }
    bool operator<= (const Triplet& ob)
    {
        return 1-((*this)>ob);
    }
    bool operator== (const Triplet& ob)
    {
        return first==ob.first && second==ob.second && third==ob.third;
    }
    bool operator!= (const Triplet& ob)
    {
        return 1-((*this)==ob);
    }


    friend std::istream& operator>> (std::istream& in, Triplet<int, int, int>& ob)
    {
        std::cout<<"Introduceti ziua: ";
        in>>ob.first;
        std::cout<<"Introduceti luna: ";
        in>>ob.second;
        std::cout<<"Introduceti anul: ";
        in>>ob.third;
        return in;
    }
    friend std::ostream& operator<< (std::ostream& out,const Triplet<int, int, int>& ob)
    {
        out<<ob.third<<"."<<ob.second<<"."<<ob.first;
        return out;
    }

};

template<class T>
void check_if_positive(T value) {
    if (value < 0) {
        throw std::runtime_error("Nu poate fi negativ !");
    }
}


template<class T>
void check_if_strict_positive(T value) {
if (value <= 0) {
    throw std::runtime_error("Nu poate fi mai mic sau egal cu 0 !");
}


template<class T, int n>
void check_if_size_n(T value) {
if (value.size() != n) {
    throw std::runtime_error("Nu poate avea lungime diferita de n!");
}

#endif // TRIPLET_H_INCLUDED
