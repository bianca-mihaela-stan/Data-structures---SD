///Cum am gadit problema?

///1. Nu mi-am dat seama ca poate sa fie vorba si de linii care nu trec prin origine si am rezolvat problema doar
///    pentru liniile care terc prin origine.

///2. Am luat toate perechile de puncte, am pus intr-un unoodered_map fractiile corespunzatoare fiecarei linii
///     si de fiecare data cand gaseam 2 puncte care se aflau pe o linie din umap incrementam valoarea din umap.
///     De mentionat ca la punctul asta am avut impresia ca toate liniile cu 0 la numitor sunt identice si toate
///     liniile cu 0 la numarator sunt identice.

///3.Mi-am dat seama ca "daca eu sunt punctul X, tu esti punctul Y si Z vrea sa fie pe linie cu noi, inseamna ca
///Z e pe linie cu mine si are aceeasi panta ca panta dintre mine si Y". Deci practic X poate "vedea" in fata lui
///linia cu cele mai multe puncte daca el are cele mai mici coordonate de pe acea linie.
///Ce inseamna asta la nivel de implementare? Nu am un umap pentru toate perechile de puncte, fiecare punct cu perechile
///primeste un umap.

///4. Imi iesea din timp.
///O mica optimizare pe care am facut-o incercand sa minimizez timpul este ca daca deja am gasit o panta cu mai mult de jumatate din
///puncte pe ea inseamna ca sigur am gasit panta cu cele ami multe puncte.
///=> am pus conditia: if(maxx>=(n+1)/2)
                    ///break;
/// si mi-a intrat in timp si am luat 100! Ca apoi sa realizez ca nu e corect pentru ca eu vreau sa stiu nr de puncte de pe linie, nu
///linia.
///M-am apucat iar de optimizat si am zis sa nu mai pun ca cheie in umap perechi, sa pun ceva mai simplu. Gen un string. Nici asa nu mi-a
///intrat in timp asa ca m-am resemnat si am folosit cheia ca un int format inmultind cu 20 000 005 care e 5+suma maxima
///care poate fi obtinuta vreodata din difreneta a doua valori >=-10 000 000 si <=10 000 000.
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
ifstream f ("flori2.in");
ofstream g ("flori2.out");
int t, n;
pair <int, int> a[1005];
unordered_map <int64_t, int> umap;
int main()
{
    f>>t;///citesc numarul de teste
    for(int q=0; q<t; q++)
    {
        f>>n;///citesc numarul de flori
        for(int i=0; i<n; i++)
        {
            f>>a[i].first>>a[i].second;
        }
        int maxx=0;
        for(int i=0; i<n-1; i++)///iau punctele 2 cate 2 si pun codul pantei lor in umap
        {
            for(int j=i+1; j<n; j++)
            {
                int numarator=a[j].second-a[i].second;///calculez numitorul si numaratorul
                int numitor=a[j].first-a[i].first;
                int d=__gcd(numitor, numarator);///functie din algorithm
                numitor/=d;///simplific fractia
                numarator/=d;
                if(numitor<0) {numitor=-numitor; numarator=-numarator;}///vreau ca - sa fie mereu la numarator
                int64_t s=(int64_t)numarator*20000005+numitor;///fac un int care "codeaza" perechea mea de numarator si numitor din fractie
                umap[s]++;///pun acest cod in umap
                maxx=max(umap[s], maxx);///fac update la maxim
            }
            umap.clear();///dupa fiecare test golesc umap-ul
        }
        g<<maxx+1<<"\n";///cum am luat punctele 2 cate 2, cand gasesc o panta, eu adaug 1 la umap, desi aveam 2 puncte pe ea
        ///cand gasesc al treilea punct pe panta aia il adaug si pe el.. si tot asa, mereu in umap o sa am cu 1 mai putine puncte
    }
    return 0;
}
