class individ
{
public:
    int i,j;
    char tip;
    int varsta;
    double energie;
    char viu;
    void hraneste();
    void inmulteste();
    void ataca();
    void imbatraneste();
    void moare();

    individ();
    individ(int i_nou,int j_nou,const char tip_nou);
    ~individ();
    void actualizare();
    int esteviu();
    char gettip();
};
