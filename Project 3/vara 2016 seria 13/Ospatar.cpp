#include "Ospatar.h"
Ospatar::Ospatar(std::string Nume, std::vector<Comanda*> comenzi, int nrComenzi, char gen, int varsta) :
        Nume(Nume), comenzi(comenzi), nrComenzi(nrComenzi), gen(gen), varsta(varsta)
{

};
Ospatar::Ospatar(const Ospatar& ob): Nume(ob.Nume), comenzi(ob.comenzi), nrComenzi(ob.nrComenzi), gen(ob.gen), varsta(ob.varsta) {0};
Ospatar& Ospatar::operator= (const Ospatar& ob)
{
        Nume=ob.Nume;
    comenzi=ob.comenzi;
    nrComenzi=ob.nrComenzi;
    gen=ob.gen;
    varsta=ob.varsta;
    return (*this);
}

std::istream& operator>> (std::istream& in, Ospatar& ob)
{
    std::cout<<"Introduceti Nume: ";
    in>>ob.Nume;
    std::cout<<"Introduceti comenzi: ";
    in>>ob.comenzi;
    std::cout<<"Introduceti nrComenzi: ";
    in>>ob.nrComenzi;
    std::cout<<"Introduceti gen: ";
    in>>ob.gen;
    std::cout<<"Introduceti varsta: ";
    in>>ob.varsta;
    return in;
}
std::ostream& operator<< (std::ostream& out, Ospatar& ob)
{
    out<<"(Nume= "<<ob.Nume<<", ";
    out<<"comenzi= "<<ob.comenzi<<", ";
    out<<"nrComenzi= "<<ob.nrComenzi<<", ";
    out<<"gen= "<<ob.gen<<", ";
    out<<"varsta= "<<ob.varsta<<") ";
    return out;
}
Ospatar~::Ospatar() {};
