#include "ComSpec.h"
ComSpec::ComSpec(std::string ObsC, float pretSupl, int Num, Produs Prod, int nrProtii, Data data) :
        Comanda( Prod, Num, nrProtii, data), ObsC(ObsC), pretSupl(pretSupl)
{

};
ComSpec::ComSpec(const ComSpec& ob): ObsC(ob.ObsC), pretSupl(ob.pretSupl), ComSpec& ComSpec::operator= (const ComSpec& ob)
{
        ObsC=ob.ObsC;
    pretSupl=ob.pretSupl;
    Num=ob.Num;
    Prod=ob.Prod;
    nrProtii=ob.nrProtii;
    data=ob.data;
    return (*this);
}

std::istream& operator>> (std::istream& in, ComSpec& ob)
{
    std::cout<<"Introduceti ObsC: ";
    in>>ob.ObsC;
    std::cout<<"Introduceti pretSupl: ";
    in>>ob.pretSupl;
    std::cout<<"Introduceti Num: ";
    in>>ob.Num;
    std::cout<<"Introduceti Prod: ";
    in>>ob.Prod;
    std::cout<<"Introduceti nrProtii: ";
    in>>ob.nrProtii;
    std::cout<<"Introduceti data: ";
    in>>ob.data;
    return in;
}
std::ostream& operator<< (std::ostream& out, ComSpec& ob)
{
    out<<"(ObsC= "<<ob.ObsC<<", ";
    out<<"pretSupl= "<<ob.pretSupl<<", ";
    out<<"Num= "<<ob.Num<<", ";
    out<<"Prod= "<<ob.Prod<<", ";
    out<<"nrProtii= "<<ob.nrProtii<<", ";
    out<<"data= "<<ob.data<<") ";
    return out;
}
ComSpec~::ComSpec() {};
