#include "flight.h"
int main()
{
    cout << "======================================================"<< endl;
    cout << "              TUGAS BESAR STRUKTUR DATA               "<< endl;
    cout << "                     SEMESTER 3                       "<< endl;
    cout << "                 TELKOM UNIVERISTY                    "<< endl;
    listClient LC;
    listPengacara LP;
    createListClient(LC);
    createListPengacara(LP);
    infoClient isiClient;
    infoPengacara isiPengacara;
    adrPengacara pengacara;
    adrClient client;
    int n = 0, pilih = menu();
    string namaPengacara,namaClient;
    while(pilih != 0){
        switch(pilih){
        case 1:
            cout << "======================================================" << endl;
            cout << " Ingin memasukkan berapa data Pengacara: ";
            cin >> n;
            while(n>0){
                cout << " Nama Firma: ";
                cin >> isiPengacara.namaFirma;
                cout << " Nama Pengacara: ";
                cin >> isiPengacara.namaPengacara;
                cout << " NIK Pengacara: ";
                cin >> isiPengacara.nikPengacara;
                cout << " Usia: ";
                cin >> isiPengacara.usia;
                pengacara = createElementPengacara(isiPengacara);
                insertPengacara(LP,pengacara);
                n--;
            }
            cout << "======================================================"<< endl;
            break;
        case 2:
            showPengacara(LP);
            break;
        case 3:
            cout << "======================================================" << endl;
            cout << " Nama Pengacara yang Ingin di Hapus: ";
            cin >> namaPengacara;
            hapusPengacara(LP,LC,pengacara,namaPengacara);
            cout << "======================================================" << endl;
            break;
        case 4:
            cout << "======================================================" << endl;
            cout << " Nama Pengacara yang Ingin di Cari: ";
            cin >> namaPengacara;
            pengacara = searchPengacara(LP,namaPengacara);
            cout << " Alamatnya ialah: " << pengacara << endl;
            cout << "======================================================" << endl;
            break;
        case 5:
            cout << "======================================================" << endl;
            cout << " Ingin memasukkan berapa data Client: ";
            cin >> n;
            while(n>0){
                cout << " Nama Client: ";
                cin >> isiClient.namaClient;
                cout << " NIK Client: ";
                cin >> isiClient.nikClient;
                cout << " Masalah: ";
                cin >> isiClient.masalah;
                cout << " Usia: ";
                cin >> isiClient.usia;
                client = createElementClient(isiClient);
                insertClient(LC,client);
                n--;
            }
            cout << "======================================================"<< endl;
            break;
        case 6:
            cout << "======================================================" << endl;
            cout << " Nama Pengacara: ";
            cin >> namaPengacara;
            cout << " Nama Client: ";
            cin >> namaClient;
            kuasaHukumClient(LC,LP,namaPengacara,namaClient);
            cout << "======================================================" << endl;
            break;
        case 7:
            showAllKuasaHukumClient(LC,LP);
            break;
        case 8:
            cout << "======================================================" << endl;
            cout << " Nama Pengacara: ";
            cin >> namaPengacara;
            cout << " Nama Client: ";
            cin >> namaClient;
            client = searchClient(LP,LC,namaPengacara,namaClient);
            cout << " Alamatnya ialah: " << client << endl;
            cout << "======================================================" << endl;
            break;
        case 9:
            cout << "======================================================" << endl;
            cout << " Nama Pengacara: ";
            cin >> namaPengacara;
            cout << " Nama Client yang Ingin di Hapus: ";
            cin >> namaClient;
            hapusKuasaHukumClient(LC,LP,namaPengacara,namaClient);
            cout << "======================================================" << endl;
            break;
        case 10:
            cout << "======================================================" << endl;
            searchClientTerbanyak(LP,LC);
            cout << "======================================================" << endl;
            break;
    }
        pilih = menu();
    }
    return 0;
}
