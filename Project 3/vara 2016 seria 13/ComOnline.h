#ifndef COMONLINE_H_INCLUDED
#define COMONLINE_H_INCLUDED
#include <bits/stdc++.h>
#include "Comanda.h"

class ComOnline : virtual public Comanda
{
protected:
    std::string adrLiv;
    int comLiv;
public:
    ComOnline() : Comanda(), adrLiv(""), comLiv(0) {};
    ComOnline(std::string adrLiv, int comLiv, int Num, Produs Prod, int nrProtii, Data data);
    ComOnline(const ComOnline& ob);
    void operator= (const ComOnline& ob);
    friend std::istream& operator>> (std::istream& in, ComOnline& ob);
    friend std::ostream& operator<< (std::ostream& out, ComOnline& ob);
    ~ComOnline();
};

#endif // COMONLINE_H_INCLUDED
