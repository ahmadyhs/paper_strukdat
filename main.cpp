#include <iostream>
#include "fungsi.hpp"

main(){
    tree decision;
    listmhs First;
    listmhs ptrBaru, tes;
    int jumlah, i , j = 0, banyakmhs;
    createListMhs(First);

    std::cout<<"\nProgram ....\n";
    std::cout<<"\nBerapa banyak mahasiswa yang ingin diinput?\nJumlah mahasiswa = ";
    std::cin>>banyakmhs;

    if(banyakmhs<1){
        std::cout<< "\nInput salah";
    }

    while(banyakmhs >= 1 && j < banyakmhs){
        std::cout<<"\nMahasiswa #" << j+1;
        createElementMhs(ptrBaru);
        insertFirstMhs(First, ptrBaru);
        j++;
    }

    return 0;
}
