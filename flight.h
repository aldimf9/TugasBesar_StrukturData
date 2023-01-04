#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <iostream>
using namespace std;
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define adrParent(P) (P)->adrParent
#define nil NULL
struct infoClient{
    string namaClient;
    string nikClient;
    string masalah;
    int usia;
};
struct infoPengacara{
    string namaFirma;
    string namaPengacara;
    string nikPengacara;
    int usia;
};
typedef struct elementPengacara *adrPengacara;
typedef struct elementClient *adrClient;
struct elementClient{
    infoClient info;
    adrPengacara adrParent;
    adrClient next;
};

struct listClient{
    adrClient first;
};
struct elementPengacara{
    infoPengacara info;
    adrPengacara next;
};
struct listPengacara{
    adrPengacara first;
};
void createListPengacara(listPengacara &LP);
adrPengacara createElementPengacara(infoPengacara data);
void insertPengacara(listPengacara &LP,adrPengacara pengacara);
void showPengacara(listPengacara LP);
adrPengacara searchPengacara(listPengacara LP,string nama);
void hapusPengacara(listPengacara &LP,listClient &LC,adrPengacara &pengacara,string nama);
void createListClient(listClient &LC);
adrClient createElementClient(infoClient data);
void insertClient(listClient &LC, adrClient client);
void kuasaHukumClient(listClient &LC,listPengacara LP,string pengacara,string client);
void showAllKuasaHukumClient(listClient LC,listPengacara LP);
adrClient searchClient(listPengacara LP,listClient LC,string namaPengacara,string namaClient);
void hapusKuasaHukumClient(listClient &LC,listPengacara LP,string namaPengacara,string namaClient);
void searchClientTerbanyak(listPengacara LP,listClient LC);
int menu();

#endif // FLIGHT_H_INCLUDED
