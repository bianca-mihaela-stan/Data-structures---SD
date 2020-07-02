#include "ComOnlineSpec.h"
ComOnlineSpec::ComOnlineSpec(Produs Prod, std::string ObsC, float pretSupl, int Num, int nrProtii, Data data, std::string adrLiv, int comLiv) :
        ComSpec( ObsC, pretSupl, Num, Prod, nrProtii, data), ComOnline( adrLiv, comLiv, Num, Prod, nrProtii, data)
{

}
ComOnlineSpec::ComOnlineSpec(const ComOnlineSpec& ob): ComSpec(ob), ComOnline(ob) {};
void ComOnlineSpec::operator= (const ComOnlineSpec& ob)
{
    ObsC=ob.ObsC;
    pretSupl=ob.pretSupl;
    Prod=ob.Prod;
    nrProtii=ob.nrProtii;
    data=ob.data;
    adrLiv=ob.adrLiv;
    comLiv=ob.comLiv;
}

std::istream& operator>> (std::istream& in, ComOnlineSpec& ob)
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
    std::cout<<"Introduceti adrLiv: ";
    in>>ob.adrLiv;
    std::cout<<"Introduceti comLiv: ";
    in>>ob.comLiv;
    return in;
}
std::ostream& operator<< (std::ostream& out, ComOnlineSpec& ob)
{
    out<<"(ObsC= "<<ob.ObsC<<", ";
    out<<"pretSupl= "<<ob.pretSupl<<", ";
    out<<"Num= "<<ob.Num<<", ";
    out<<"Prod= "<<ob.Prod<<", ";
    out<<"nrProtii= "<<ob.nrProtii<<", ";
    out<<"data= "<<ob.data<<", ";
    out<<"adrLiv= "<<ob.adrLiv<<", ";
    out<<"comLiv= "<<ob.comLiv<<") ";
    return out;
}
ComOnlineSpec::~ComOnlineSpec() {};
