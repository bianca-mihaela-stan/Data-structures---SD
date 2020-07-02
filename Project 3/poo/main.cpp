#include<bits/stdc++.h>
using namespace std;

class Model
{
protected:
    string nume;
    unsigned greutate;
    int an;
    float v_max;
public:

    virtual float calcul_autonomie() = 0;

    Model(string nume = "", unsigned greutate = 0, int an = 0, float v_max = 0): nume(nume),
                                                                                an(an),
                                                                                greutate(greutate),
                                                                                v_max(v_max){}
                };


class MasinaCFosil : virtual public Model
{
protected:
    string combustibil;
    int capacitate;
public:
    MasinaCFosil () : Model(), combustibil(""), capacitate(0) {};
    MasinaCFosil(string nume = "", unsigned greutate = 0, int an = 0, float v_max = 0, string combustibil="", int capacitate=0) : Model(nume, greutate, an, v_max),
                                                                                                                                    combustibil(combustibil),
                                                                                                                                    capacitate(capacitate) {};

    float calcul_autonomie()
    {
        return capacitate/sqrt(greutate);
    }
    friend ostream& operator<< (ostream& out, const MasinaCFosil& ob)
    {
        out<<"Masina cu combustibil fosil "<<ob.nume<<" cu greutate "<<ob.greutate<<" din anul "<<ob.an<<" cu viteza "<<ob.v_max<<" pe ";
        out<<ob.combustibil<<" de capacitate "<<ob.capacitate<<"\n";
        return out;
    }

    friend istream& operator>> (istream& in, MasinaCFosil & ob)
    {
        in>>ob.nume;
        in>>ob.greutate;
        in>>ob.an;
        in>>ob.v_max;
        in>>ob.combustibil>>ob.capacitate;
        return in;

    }
};
