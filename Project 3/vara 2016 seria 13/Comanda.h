#ifndef COMANDA_H_INCLUDED
#define COMANDA_H_INCLUDED
#include <bits/stdc++.h>
#include "Triplet.h"
#include "Produs.h"
using Data = Triplet <int,int,int>;


class Comanda
{
protected:
    int Num;
    static int nrInstante;
    Produs Prod;
    int nrProtii;
    Data data;
    static std::vector<std::shared_ptr<Comanda>> comenzi1;
public:
    Comanda(): Num(Comanda::nrInstante),nrProtii(0), data(Data(0,0,0)) {};
    Comanda(Produs Prod, int nrProtii, Data data);
    Comanda(const Comanda& ob);
    void operator= (const Comanda& ob);
    friend std::istream& operator>> (std::istream& in, Comanda& ob);
    friend std::ostream& operator<< (std::ostream& out, Comanda& ob);
    ~Comanda();

    Comanda& operator+ (int x);
    Comanda& operator++ ();
    void del();
    Data get_data();
    Produs& get_prod();
    float get_pret();
};
 std::vector<std::shared_ptr<Comanda>> Comanda::comenzi1 = {{}};
 int Comanda::nrInstante=1;
#endif // COMANDA_H_INCLUDED
