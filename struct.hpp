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
    std::string statusdo; //status drop out atau aktif 
    mahasiswa* next;
};

typedef mahasiswa* listmhs;
typedef pohon* tree; 
