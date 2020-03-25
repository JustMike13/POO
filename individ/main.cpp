#include <iostream>
#include "individ.cpp"
using namespace std;
int main()
{
    tabel.citire_individ(1,1,"+");
    tabel.citire_individ(10,7,"+");
    tabel.citire_individ(1,5,"-");
    tabel.citire_individ(16,11,"-");
    tabel.citire_individ(15,11,"-");
    tabel.citire_individ(19,20,"-");
    tabel.citire_individ(1,6,"+");
    tabel.citire_individ(1,2,"+");
    while(tabel.exista_indivizi==1)
        for(i=1;i<21;i++)
            for(j=1;j<71;j++)
            {
                if (tabel.ocupat[i][j]==1)
                    if(tabel.matrice[i][j]->esteviu==1)
                        tabel.matrice[i][j]->actualizare();
                    else tabel.sterge_individ(i,j);
            }
    return 0;
}

