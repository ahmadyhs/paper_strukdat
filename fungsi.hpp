#include "struct.hpp"

tree createElementTree(tree& t, std::string isi){ //input data tree
  t = new pohon;
  t->atribut = isi;
  t->DO = 0;
  t->aktif = 0;
  t->leaf = nullptr;
  return t;
}

void createElementMhs(listmhs& mhsBaru){ //input data mahasiswa
  mhsBaru = new mahasiswa;
  std::cout << "\nMasukkan NPM Mahasiswa = "; std::cin >> mhsBaru->npm;
  std::cout << "Masukkan nama Mahasiswa = "; std::cin >> mhsBaru->namamhs;
  std::cout << "Masukkan asal sekolah Mahasiswa (SMA/MA/sederajat) = "; std::cin >> mhsBaru->asalsklh;
  std::cout << "Masukkan IPK Mahasiswa = "; std::cin >> mhsBaru->ipk;
  std::cout << "Masukkan pendapatan orang tua Mahasiswa = "; std::cin >> mhsBaru->pendapatanortu;
  std::cout << "Masukkan status Mahasiswa (DO/aktif) = "; std::cin >> mhsBaru->statusdo;
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

void insertTree(tree& t, tree baru){ //insert cabang baru pada root
  
  if (t == nullptr) // jika tree null
  {
    t = baru;
  }
  
  else  // jika tree sudah ada isi
  {
    baru->leaf = t;
    t = baru;
  }
}

void showmhs(listmhs First){ // menampilkan data mahasiswa nama dan npm
  std::cout << "\nList mahasiswa  : \n";
  while(First != nullptr){
    std::cout << "\nNPM : " << First->npm;
    std::cout << "\tNama : " << First->namamhs;
    First = First->next;
  }
}

void showtree(tree T){ // menampilkan data status mahasiswa terhadap atribut faktor
  std::cout << "\nData status mahasiswa terhadap atribut";
  while(T != nullptr){
    std::cout << "\n" << T->atribut << "\n>> DO = " << T->DO;
    std::cout << " aktif = " << T->aktif << "\n";
    T = T->leaf;
  }
  std::cout << "\n";
}

// dibawah adalah funsi-fungsi untuk membuat tree dari beberapa atribut
// hanya untuk mendata mahasiswa yg DO atau aktif berdasar IPK / pendapatan ortu / asal sekolah

void treeIpk(listmhs First, tree& T){ //tree untuk ipk dengan tiap tingkat akan dihitung jumlah mhs aktif dan DO
  tree a, b, c;
 
  a = createElementTree(a,"ipk A (3 - 4)");
  b = createElementTree(b,"ipk B (2,5 - 3)");
  c = createElementTree(c, "ipk C (0 - 2,5)");

  insertTree(T,c);
  insertTree(T,b);
  insertTree(T,a);

  while (First != nullptr){
    if(First->ipk > 3 && First->ipk <= 4){ //gol ipk A
      
      if(First->statusdo == "DO" || First->statusdo == "do"){
        a->DO += 1;
      } else {
        a->aktif += 1;
      }

    } else if(First->ipk > 2.5 && First->ipk <= 3){ //gol ipk B

      if(First->statusdo == "DO" || First->statusdo == "do"){
        b->DO += 1;
      } else {
        b->aktif += 1;
      }

    } else if(First->ipk > 0 && First->ipk <= 2.5){ //gol ipk C
      
      if(First->statusdo == "DO" || First->statusdo == "do"){
        c->DO += 1;
      } else {
        c->aktif += 1;
      }
    }
    First = First->next;
  }
  
}


void treePendapatan(listmhs First, tree& T){ //tree untuk pendapatan dengan tiap tingkat akan dihitung jumlah mhs aktif dan DO
  tree a, b, c;
 
  a = createElementTree(a,"pendapatan A (>3.500.000)");
  b = createElementTree(b,"pendapatan B (2.100.000 - 3.500.000)");
  c = createElementTree(c, "pendapatan C (0 - 2.100.000)");

  insertTree(T,c);
  insertTree(T,b);
  insertTree(T,a);

  while (First != nullptr){
    if(First->pendapatanortu > 3500000){ //gol pendapatan ortu A
      
      if(First->statusdo == "DO" || First->statusdo == "do"){
        a->DO += 1;
      } else {
        a->aktif += 1;
      }

    } else if(First->pendapatanortu > 2100000 && First->pendapatanortu <= 3500000){ //gol pendapatan ortu B

      if(First->statusdo == "DO" || First->statusdo == "do"){
        b->DO += 1;
      } else {
        b->aktif += 1;
      }

    } else if(First->pendapatanortu <= 2100000){ //gol pendapatan ortu C
  
      if(First->statusdo == "DO" || First->statusdo == "do"){
        c->DO += 1;
      } else {
        c->aktif += 1;
      }
    }
    First = First->next;
  }

}

void treeAsalSklh(listmhs First, tree& T){ //tree untuk asal sekolah dengan tiap tingkat akan dihitung jumlah mhs aktif dan DO
  tree a, b, c;
 
  a = createElementTree(a,"asal sekolah SMA");
  b = createElementTree(b,"asal sekolah MA");
  c = createElementTree(c, "asal sekolah selain SMA & MA");

  insertTree(T,c);
  insertTree(T,b);
  insertTree(T,a);

  while (First != nullptr){
    if(First->asalsklh == "SMA" || First->asalsklh == "sma"){ //gol asal sekolah SMA
      
      if(First->statusdo == "DO" || First->statusdo == "do"){
        a->DO += 1;
      } else {
        a->aktif += 1;
      }

    } else if(First->asalsklh == "MA" || First->asalsklh == "ma" ){ //gol asal sekolah MA

      if(First->statusdo == "DO" || First->statusdo == "do"){
        b->DO += 1;
      } else {
        b->aktif += 1;
      }

    } else{ //gol asal sekolah selain SMA dan MA

      if(First->statusdo == "DO" || First->statusdo == "do"){
        c->DO += 1;
      } else {
        c->aktif += 1;
      }
    }
    First = First->next;
  }

}

void decision(tree a, tree b, tree c){ // fungsi yang menentukan decision dari faktor paling berpengaruh tehadap drop out
  int DOipk, DOpendapatan, DOasal;
  DOipk = DOpendapatan = DOasal= 0;

  while(a != nullptr){
    if(DOipk < a->DO){
      DOipk = a->DO;
    }
    a = a->leaf;
  }
  while(b != nullptr){
    if(DOpendapatan < b->DO){
      DOpendapatan = b->DO;
    }
    b = b->leaf;
  }
  while(c != nullptr){
    if(DOasal < c->DO){
      DOasal = c->DO;
    }
    c = c->leaf;
  }

  if (DOipk >= DOasal && DOipk > DOpendapatan){
    std::cout << "\nFaktor paling berpengaruh terhadap mahasiswa yang Drop Out adalah IPK\n";
  } else if (DOasal >= DOipk && DOasal >= DOpendapatan){
    std::cout << "\nFaktor paling berpengaruh terhadap mahasiswa yang Drop Out adalah asal sekolah\n";
  } else if (DOpendapatan >= DOasal && DOpendapatan >= DOipk){
    std::cout << "\nFaktor paling berpengaruh terhadap mahasiswa yang Drop Out adalah pendapatan Orang tua\n";
  }
}