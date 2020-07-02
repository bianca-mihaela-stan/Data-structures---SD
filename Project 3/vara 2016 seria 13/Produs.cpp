#include "Produs.h"
Produs::Produs(std::string denProd, float pretProd) :
        denProd(denProd), pretProd(pretProd)
{

};
Produs::Produs(const Produs& ob): denProd(ob.denProd), pretProd(ob.pretProd)
{
}
void Produs::operator= (const Produs& ob)
{
    denProd=ob.denProd;
    pretProd=ob.pretProd;
}

std::istream& operator>> (std::istream& in, Produs& ob)
{
    std::cout<<"Introduceti denProd: ";
    in>>ob.denProd;
    std::cout<<"Introduceti pretProd: ";
    in>>ob.pretProd;
    return in;
}
std::ostream& operator<< (std::ostream& out, Produs& ob)
{
    out<<"(denProd= "<<ob.denProd<<", ";
    out<<"pretProd= "<<ob.pretProd<<") ";
    return out;
}
Produs~::Produs() {};

std::string get_den()
{
    return denProd;
}
float get_pret();
{
    return pretProd;
}
static vector<std::shared_ptr<Produs>> get_produse()
{
    return produse;
}
