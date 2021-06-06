struct tree{
    std::string atribut;
    int aktif;
    int DO;
    tree* leaf;
};

struct mahasiswa{
    std::string namamhs;
    int npm;
    std::string asalsklh;
    int ipk;
    int pendapatanortu;
    std::string statusdo; //status drop out atau aktif 
    mahasiswa* next;
};

typedef mahasiswa* listmhs;
