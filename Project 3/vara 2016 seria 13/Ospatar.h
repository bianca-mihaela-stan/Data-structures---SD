#ifndef OSPATAR_H_INCLUDED
#define OSPATAR_H_INCLUDED
#include <bits/stdc++.h>
#include "Comanda.h"
class Ospatar
{
protected:
    std::string Nume;
    std::vector<Comanda*> comenzi;
    int nrComenzi;
    char gen;
    int varsta;
public:
    Ospatar() : Nume(""), nrComenzi(0), gen('N'), varsta(0) {};
    Ospatar(std::string Nume, std::vector<Comanda*> comenzi, int nrComenzi, char gen, int varsta);
    Ospatar(const Ospatar& ob);
    void operator= (const Ospatar& ob);
    friend std::istream& operator>> (std::istream& in, Ospatar& ob);
    friend std::ostream& operator<< (std::ostream& out, Ospatar& ob);
    ~Ospatar();
};


#endif // OSPATAR_H_INCLUDED
