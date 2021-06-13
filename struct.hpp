struct pohon{
    std::string atribut;
    int aktif;
    int DO;
    pohon* leaf;
};

struct mahasiswa{
    std::string namamhs;
    int npm;
    std::string asalsklh;
    float ipk;
    int pendapatanortu;
    std::string statusdo; //status dropout atau aktif 
    mahasiswa* next;
    int poin = 0;
    bool prediksido;
};

typedef mahasiswa* listmhs;
typedef pohon* tree; 
