#include "ComOnline.h"
ComOnline::ComOnline(std::string adrLiv, int comLiv, int Num, Produs Prod, int nrProtii, Data data) :
        Comanda(Prod, nrProtii, data), adrLiv(adrLiv), comLiv(comLiv)
{

};
ComOnline::ComOnline(const ComOnline& ob): Comanda(ob), adrLiv(ob.adrLiv), comLiv(ob.comLiv)
{

}
void ComOnline::operator= (const ComOnline& ob)
{
    adrLiv=ob.adrLiv;
    comLiv=ob.comLiv;
    Prod=ob.Prod;
    nrProtii=ob.nrProtii;
    data=ob.data;
}

std::istream& operator>> (std::istream& in, ComOnline& ob)
{
    std::cout<<"Introduceti adrLiv: ";
    in>>ob.adrLiv;
    std::cout<<"Introduceti comLiv: ";
    in>>ob.comLiv;
    std::cout<<"Introduceti Prod: ";
    in>>ob.Prod;
    std::cout<<"Introduceti nrProtii: ";
    in>>ob.nrProtii;
    std::cout<<"Introduceti data: ";
    in>>ob.data;
    return in;
}
std::ostream& operator<< (std::ostream& out, ComOnline& ob)
{
    out<<"(adrLiv= "<<ob.adrLiv<<", ";
    out<<"comLiv= "<<ob.comLiv<<", ";
    out<<"Num= "<<ob.Num<<", ";
    out<<"Prod= "<<ob.Prod<<", ";
    out<<"nrProtii= "<<ob.nrProtii<<", ";
    out<<"data= "<<ob.data<<") ";
    return out;
}
ComOnline::~ComOnline() {};
