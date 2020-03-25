#include "individ.h"
#include <iostream>
int i,j;
class tabel
{
public:
    individ *matrice[21][71];
    int ocupat[21][71];
    int nr_indivizi;
    tabel();
    void citire_individ(int it,int jt,const char tipt);
    void sterge_individ(int it, int jt);
    ~tabel();
    int exista_indivizi();
    void afisare();
};
tabel::tabel()
{
    for (i=1;i<=20;i++)
        for(j=1;j<=70;j++)
            ocupat[i][j]=0;
    nr_indivizi=0;
}
void tabel::citire_individ(int it,int jt,char tipt)
{
    matrice[it][jt]=individ(int it,int jt,char tipt);
    ocupat[it][jt]=1;
    nr_indivizi++;
}
void tabel::sterge_individ(int it, int jt)
{
    ocupat[it][jt]=0;
    nr_indivizi-=1;
}
tabel::~tabel()
{
    std::cout<<"tabela a fost stearsa";
}
int tabel::exista_indivizi()
{
    if (this->nr_indivizi>0)
        return 1;
    else return 0;
}
void tabel::afisare()
{
    for (i=1;i<21;i++)
        for (j=1;j<71;j++)
            if (this->ocupat[i][j]==1)
                std::cout<<this->matrice[i][j]->gettip();
            else std::cout<<" ";
}
