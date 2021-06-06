#include "tree.hpp"

void createtree(tree& t){
  
}

void createListMhs(listmhs& First){
  First = nullptr;
}

void createElementMhs(listmhs& mhsBaru){
  mhsBaru = new mahasiswa;
  std::cout << "\nMasukkan NPM Mahasiswa = "; std::cin >> mhsBaru->npm;
  std::cout << "\nMasukkan nama Mahasiswa = "; std::cin >> mhsBaru->namamhs;
  std::cout << "\nMasukkan asal sekolah Mahasiswa = "; std::cin >> mhsBaru->asalsklh;
  std::cout << "\nMasukkan IPK Mahasiswa = "; std::cin >> mhsBaru->IPK;
  std::cout << "\nMasukkan pendapatan orang tua Mahasiswa = "; std::cin >> mhsBaru->pendapatanortu;
  mhsBaru->next = nullptr;
}

void insertFirstMhs(listmhs& First, listmhs mhsBaru){
  
  //kalau list kosong
  if (First == nullptr)
  {
    First = mhsBaru;
  }
  //kalau list sudah ada isi
  else
  {
    mhsBaru->next = First;
    First = mhsBaru;
  }
  std::cout << "Mahasiswa sudah dimasukkan ke List.\n"; //jika input berhasil
}

void decisiontreeipk(listmhs First, tree& decision){
  decision->atribut = ipk;
  if(First->ipk > 3 && First->ipk <= 4){ //gol ipk A
    if(First->statusdo == "Dropout"){
      decision->->DO ==
    }
  }

}
