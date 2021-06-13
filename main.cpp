#include <iostream>
#include "fungsi.hpp"

main(){
    tree tripk, trpendapatan, trasalsklh;
    listmhs First;
    listmhs ptrBaru, tes;
    int j = 0, banyakmhs;
    
    First = nullptr;
    tripk = trasalsklh = trpendapatan = nullptr;

    std::cout<<"\n----Program decision tree analisis mahasiswa dropout----\n";
    std::cout<<"\nBerapa banyak mahasiswa yang ingin diinput?\nJumlah mahasiswa = ";
    std::cin>>banyakmhs;

    if(banyakmhs<1){
        std::cout<< "\nInput salah";
        return 0;
    }

    while(j < banyakmhs){    // untuk looping input data mahasiswa
        std::cout<<"\nMahasiswa #" << j+1 << "\n";
        createElementMhs(ptrBaru);
        insertFirstMhs(First, ptrBaru);
        j++;
    }

    showmhs(First);         // menampilkan data npm dan nama mahasiswa
    std::cout << "\n";
    
    treeIpk(First, tripk);  // membuat tree untuk mendata status mahasiswa berdasar ipk
    showtree(tripk);        // menampilkan data status mahasiswa berdasar ipk
    
    treePendapatan(First, trpendapatan);    // membuat tree untuk mendata status mahasiswa berdasar pendapatan ortu
    showtree(trpendapatan);                 // menampilkan data status mahasiswa berdasar pendapatan ortu

    treeAsalSklh(First, trasalsklh);      // membuat tree untuk mendata status mahasiswa berdasar asal sekolah
    showtree(trasalsklh);                 // menampilkan data status mahasiswa berdasar asal sekolah

    decision(tripk, trpendapatan, trasalsklh); // decision dari faktor yang paling berpengaruh dari mahasiswa drop out

    return 0;
}
