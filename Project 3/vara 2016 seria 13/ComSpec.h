#ifndef COMSPEC_H_INCLUDED
#define COMSPEC_H_INCLUDED
#include <bits/stdc++.h>
#include "Comanda.h"

class ComSpec: virtual public Comanda
{
protected:
    std::string ObsC;
    float pretSupl;
public:
    ComSpec() : Comanda(), ObsC(""), pretSupl(0) {};
    ComSpec(std::string ObsC, float pretSupl, int Num, Produs Prod, int nrProtii, Data data);
    ComSpec(const ComSpec& ob);
    void operator= (const ComSpec& ob);
    friend std::istream& operator>> (std::istream& in, ComSpec& ob);
    friend std::ostream& operator<< (std::ostream& out, ComSpec& ob);
    ~ComSpec();
};


#endif // COMSPEC_H_INCLUDED
