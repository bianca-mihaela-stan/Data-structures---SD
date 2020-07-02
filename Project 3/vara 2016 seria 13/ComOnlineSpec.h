#ifndef COMONLINESPEC_H_INCLUDED
#define COMONLINESPEC_H_INCLUDED
#include <bits/stdc++.h>
#include "ComSpec.h"
#include "ComOnline.h"

class ComOnlineSpec:public ComSpec, public ComOnline
{
protected:
public:
    ComOnlineSpec() : ComSpec(), ComOnline() {};
    ComOnlineSpec( Produs Prod, std::string ObsC="", float pretSupl=0, int Num=0, int nrProtii=0, Data data=Data(0,0,0), std::string adrLiv="", int comLiv=0);
    ComOnlineSpec(const ComOnlineSpec& ob);
    void operator= (const ComOnlineSpec& ob);
    friend std::istream& operator>> (std::istream& in, ComOnlineSpec& ob);
    friend std::ostream& operator<< (std::ostream& out, ComOnlineSpec& ob);
    ~ComOnlineSpec();
};

#endif // COMONLINESPEC_H_INCLUDED
