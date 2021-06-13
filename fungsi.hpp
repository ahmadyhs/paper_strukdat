#include "struct.hpp"

void createtree(tree& t){
  t->atribut = " ";
  t->DO = 0;
  t->aktif = 0;
  t->leaf = nullptr;
}

void createListMhs(listmhs& First){
  First = nullptr;
}

void createElementMhs(listmhs& mhsBaru){
  mhsBaru = new mahasiswa;
  std::cout << "\nMasukkan NPM Mahasiswa = "; std::cin >> mhsBaru->npm;
  std::cout << "\nMasukkan nama Mahasiswa = "; std::cin >> mhsBaru->namamhs;
  std::cout << "\nMasukkan asal sekolah Mahasiswa = "; std::cin >> mhsBaru->asalsklh;
  std::cout << "\nMasukkan IPK Mahasiswa = "; std::cin >> mhsBaru->ipk;
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

void showmhs(listmhs First){
  std::cout << "\nList mahasiswa  : \n";
  while(First != nullptr){
    std::cout << "\nNPM" << First->npm;
    std::cout << "\nNama" << First->namamhs << "\n";
    First = First->next;
  }
}

//funsi-fungsi untuk membuat tree dari beberapa atribut
//hanya untuk mendata mahasiswa yg DO atau aktif berdasar IPK / pendapatan ortu / asal sekolah

void treeIpk(listmhs First, tree& decision){ //tree untuk ipk dengan tiap tingkat akan dihitung jumlah mhs aktif dan DO
  tree b, c;
  createtree(b);
  createtree(c);

  decision->leaf = b;
  b->leaf = c;

  while (First != nullptr){
    if(First->ipk > 3 && First->ipk <= 4){ //gol ipk A
      decision->atribut = "ipk A";
      First->poin += 3;
      if(First->statusdo == "Dropout"){
        decision->DO += 1;
      } else {
        decision->aktif += 1;
      }

    } else if(First->ipk > 2.5 && First->ipk <= 3){ //gol ipk B
      b->atribut = "ipk B";
      First->poin += 2;
      if(First->statusdo == "Dropout"){
        b->DO += 1;
      } else {
        b->aktif += 1;
      }

    } else if(First->ipk > 0 && First->ipk <= 2.5){ //gol ipk C
      c->atribut = "ipk C";
      First->poin += 1;
      if(First->statusdo == "Dropout"){
        c->DO += 1;
      } else {
        c->aktif += 1;
      }
    }
    First = First->next;
  }

}

void treePendapatan(listmhs First, tree& decision){ //tree untuk pendapatan dengan tiap tingkat akan dihitung jumlah mhs aktif dan DO
  tree b, c;
  createtree(b);
  createtree(c);

  decision->leaf = b;
  b->leaf = c;

  while (First != nullptr){
    if(First->pendapatanortu > 3500000){ //gol pendapatan ortu A
      decision->atribut = "pendapatan A";
      First->poin += 3;
      if(First->statusdo == "Dropout"){
        decision->DO += 1;
      } else {
        decision->aktif += 1;
      }

    } else if(First->pendapatanortu > 2100000 && First->pendapatanortu <= 3500000){ //gol pendapatan ortu B
      b->atribut = "pendapatan B";
      First->poin += 2;
      if(First->statusdo == "Dropout"){
        b->DO += 1;
      } else {
        b->aktif += 1;
      }

    } else if(First->pendapatanortu <= 2100000){ //gol pendapatan ortu C
      c->atribut = "pendapatan C";
      First->poin += 1;
      if(First->statusdo == "Dropout"){
        c->DO += 1;
      } else {
        c->aktif += 1;
      }
    }
    First = First->next;
  }

}

void treeAsalSklh(listmhs First, tree& decision){ //tree untuk asal sekolah dengan tiap tingkat akan dihitung jumlah mhs aktif dan DO
  tree b, c;
  createtree(b);
  createtree(c);

  decision->leaf = b;
  b->leaf = c;

  while (First != nullptr){
    if(First->asalsklh == "SMA" || First->asalsklh == "sma"){ //gol asal sekolah SMA
      decision->atribut = "asal sekolah SMA";
      
      if(First->statusdo == "Dropout"){
        decision->DO += 1;
      } else {
        decision->aktif += 1;
      }

    } else if(First->asalsklh == "MA" || First->asalsklh == "ma" ){ //gol asal sekolah MA
      b->atribut = "asal sekolah MA";

      if(First->statusdo == "Dropout"){
        b->DO += 1;
      } else {
        b->aktif += 1;
      }

    } else{ //gol asal sekolah selain SMA dan MA
      c->atribut = "asal sekolah selain SMA & MA";
      if(First->statusdo == "Dropout"){
        c->DO += 1;
      } else {
        c->aktif += 1;
      }
    }
    First = First->next;
  }

}

//fungsi dibawah untuk decision tree
//...
void prediksiDO(listmhs First){
  while(First!=nullptr){
    if(First->poin >= 4 && First->poin <= 6){
      First->prediksido = false;
    }
    else if(First->poin < 4){
      First->prediksido = true;
    }
    First = First->next;
  }
}

void periksaPrediksi(listmhs First){
  while(First!=nullptr){
    if(First->prediksido == true){
      std::cout<<"Mahasiswa diprediksi dropout"<<std::endl;
    }
    else if(First->prediksido == false){
      std::cout<<"Mahasiswa diprediksi tidak dropout"<<std::endl;
    }
    First = First->next;
  }
}