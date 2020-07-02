#include "Comanda.h"
#include "Produs.h"
Comanda::Comanda(Produs Prod, int nrProtii, Data data) :
        Num(Comanda::nrInstante), Prod(Prod), nrProtii(nrProtii), data(data)
{

};
Comanda::Comanda(const Comanda& ob): Num(Comanda::nrInstante), Prod(ob.Prod), nrProtii(ob.nrProtii), data(ob.data)
{

}
void Comanda::operator= (const Comanda& ob)
{
    Prod=ob.Prod;
    nrProtii=ob.nrProtii;
    data=ob.data;
}

std::istream& operator>> (std::istream& in, Comanda& ob)
{
    std::cout<<"Introduceti Prod: ";
    in>>ob.Prod;
    std::cout<<"Introduceti nrProtii: ";
    in>>ob.nrProtii;
    std::cout<<"Introduceti data: ";
    in>>ob.data;
    return in;
}
std::ostream& operator<< (std::ostream& out, Comanda& ob)
{
    out<<"(Num= "<<ob.Num<<", ";
    out<<"Prod= "<<ob.Prod<<", ";
    out<<"nrProtii= "<<ob.nrProtii<<", ";
    out<<"data= "<<ob.data<<") ";
    return out;
}
Comanda::~Comanda() {};

Comanda& Comanda::operator+ (int x)
{
    Comanda c(*this);
    c.nrProtii+=x;
    return c;
}
Comanda& Comanda::operator++ ()
{
    Comanda c(*this);
    c.nrProtii++;
    return c;
}
void Comanda::del()
{

}
Data Comanda::get_data()
{
    return data;
}
Produs& Comanda::get_prod()
{
    return Prod;
}
float Comanda::get_pret()
{
    return nrProtii*(Prod.get_pret());
}
