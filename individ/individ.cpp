int varsta_max=10;
using namespace std;
#include <iostream>

#include "tabel.cpp"
tabel tabel;
//ap_en= aport energetic
int ap_en(int i2,int j2)
{
    int a=1;
    if(tabel.ocupat[i2-1][j2-1]==0)
        a++;
    if(tabel.ocupat[i2-1][j2]==0)
        a++;
    if(tabel.ocupat[i2-1][j2+1]==0)
    a++;

    if(tabel.ocupat[i2][j2-1]==0)
        a++;
    if(tabel.ocupat[i2][j2+1]==0)
        a++;

    if(tabel.ocupat[i2+1][j2-1]==0)
        a++;
    if(tabel.ocupat[i2+1][j2]==0)
        a++;
    if(tabel.ocupat[i2+1][j2+1]==0)
        a++;
    return a;
}
individ::individ()=default;
individ::individ(int i_nou,int j_nou,char tip_nou)
{
    this->i=i_nou;
    this->j=j_nou;
    this->tip=tip_nou;
}
individ::~individ()
{
    cout<<"individul a fost eliminat";
}
void individ::hraneste()
{
    if(tabel.ocupat[i-1][j-1]==0)
        energie=energie+ap_en(i-1,j-1);
    if(tabel.ocupat[i-1][j]==0)
        energie=energie+ap_en(i-1,j);
    if(tabel.ocupat[i-1][j+1]==0)
        energie=energie+ap_en(i-1,j+1);

    if(tabel.ocupat[i][j-1]==0)
        energie=energie+ap_en(i,j-1);
    if(tabel.ocupat[i][j+1]==0)
        energie=energie+ap_en(i,j+1);

    if(tabel.ocupat[i+1][j-1]==0)
        energie=energie+ap_en(i+1,j-1);
    if(tabel.ocupat[i+1][j]==0)
        energie=energie+ap_en(i+1,j);
    if(tabel.ocupat[i+1][j+1]==0)
        energie=energie+ap_en(i+1,j+1);
    if(varsta<varsta_max/2)
        energie+=(varsta_max/2-varsta)*2;
}
void individ::inmulteste()
{
    int fii=3;
    if (fii>0)
        if(tabel.ocupat[i+1][j]==0)
            {individ(i+1,j,tip);fii=fii-1;}
    if (fii>0)
        if(tabel.ocupat[i+1][j+1]==0)
            {individ(i+1,j+1,tip);fii=fii-1;}
    if (fii>0)
        if(tabel.ocupat[i][j+1]==0)
            {individ(i,j+1,tip);fii=fii-1;}
    if (fii>0)
        if(tabel.ocupat[i-1][j+1]==0)
            {individ(i-1,j+1,tip);fii=fii-1;}
    if (fii>0)
        if(tabel.ocupat[i-1][j]==0)
            {individ(i-1,j,tip);fii=fii-1;}
    if (fii>0)
        if(tabel.ocupat[i-1][j-1]==0)
            {individ(i-1,j-1,tip);fii=fii-1;}
    if (fii>0)
        if(tabel.ocupat[i][j-1]==0)
            {individ(i,j-1,tip);fii=fii-1;}
    if (fii>0)
        if(tabel.ocupat[i+1][j-1]==0)
            {individ(i+1,j-1,tip);fii=fii-1;}
}
void individ::ataca()
{
    if(tabel.ocupat[i-1][j-1]==1)
        if(tabel.matrice[i-1][j-1]->gettip!=this->tip)
            if(this->energie>tabel.matrice[i-1][j-1]->energie)
                {this->energie-=tabel.matrice[i-1][j-1]->energie;tabel.matrice[i-1][j-1]->moare();}


    if(tabel.ocupat[i-1][j]==1)
        if(tabel.matrice[i-1][j]->gettip!=this->tip)
            if(this->energie>tabel.matrice[i-1][j]->energie)
                {this->energie-=tabel.matrice[i-1][j]->energie;tabel.matrice[i-1][j]->moare();}


    if(tabel.ocupat[i-1][j+1]==1)
        if(tabel.matrice[i-1][j+1]->gettip!=this->tip)
            if(this->energie>tabel.matrice[i-1][j+1]->energie)
                {this->energie-=tabel.matrice[i-1][j+1]->energie;tabel.matrice[i-1][j+1]->moare();}



    if(tabel.ocupat[i][j-1]==1)
        if(tabel.matrice[i][j-1]->gettip!=this->tip)
            if(this->energie>tabel.matrice[i][j-1]->energie)
                {this->energie-=tabel.matrice[i][j-1]->energie;tabel.matrice[i][j-1]->moare();}


    if(tabel.ocupat[i][j+1]==1)
        if(tabel.matrice[i][j+1]->gettip!=this->tip)
            if(this->energie>tabel.matrice[i][j+1]->energie)
                {this->energie-=tabel.matrice[i][j+1]->energie;tabel.matrice[i][j+1]->moare();}


    if(tabel.ocupat[i+1][j-1]==1)
        if(tabel.matrice[i+1][j-1]->gettip!=this->tip)
            if(this->energie>tabel.matrice[i+1][j-1]->energie)
                {this->energie-=tabel.matrice[i+1][j-1]->energie;tabel.matrice[i+1][j-1]->moare();}


    if(tabel.ocupat[i+1][j]==1)
        if(tabel.matrice[i+1][j]->gettip!=this->tip)
            if(this->energie>tabel.matrice[i+1][j]->energie)
                {this->energie-=tabel.matrice[i+1][j]->energie;tabel.matrice[i+1][j]->moare();}


    if(tabel.ocupat[i+1][j+1]==1)
        if(tabel.matrice[i+1][j+1]->gettip!=this->tip)
            if(this->energie>tabel.matrice[i+1][j+1]->energie)
                {this->energie-=tabel.matrice[i+1][j+1]->energie;tabel.matrice[i+1][j+1]->moare();}
}
void individ::imbatraneste()
{
    varsta++;
    energie-=5;
    if(varsta>varsta_max || energie<=0)
        moare();
}
void individ::moare()
{
    this->viu=0;
}
void individ::actualizare()
{
    this->hraneste();
    this->inmulteste();
    this->ataca();
    this->imbatraneste();
}
int individ::esteviu()
{
    return this->viu;
}
char individ::gettip()
{
    return this->tip;
}
