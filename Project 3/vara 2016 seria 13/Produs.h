#ifndef PRODUS_H_INCLUDED
#define PRODUS_H_INCLUDED
#include <bits/stdc++.h>

class Produs
{
protected:
    std::string denProd;
    float pretProd;
    static std::vector<std::shared_ptr<Produs>> produse;
public:
    Produs(std::string denProd="", float pretProd=0);
    Produs(const Produs& ob);
    void operator= (const Produs& ob);
    friend std::istream& operator>> (std::istream& in, Produs& ob);
    friend std::ostream& operator<< (std::ostream& out, Produs& ob);
    ~Produs();

    std::string get_den();
    float get_pret();
    static std::vector<std::shared_ptr<Produs>> get_produse();
};

std::vector<std::shared_ptr<Produs>>  Produs::produse= {{}};
#endif // PRODUS_H_INCLUDED
