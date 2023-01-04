#include "flight.h"
void createListPengacara(listPengacara &LP){
// F.S membuat List Pengacara
    first(LP) = nil;
}
adrPengacara createElementPengacara(infoPengacara data){
// F.S mengembalikan alamat yang berisi data pengacara
    adrPengacara pengacara = new elementPengacara;
    info(pengacara).namaFirma = data.namaFirma;
    info(pengacara).namaPengacara = data.namaPengacara;
    info(pengacara).nikPengacara = data.nikPengacara;
    info(pengacara).usia = data.usia;
    next(pengacara) = nil;
    return pengacara;
}
void insertPengacara(listPengacara &LP,adrPengacara pengacara){
// F.S menambahkan data dari alamat pengacara ke dalam list Pengacara di akhir list
    if(first(LP) == nil){
        first(LP) = pengacara;
        next(pengacara) = first(LP);
    }else{
        adrPengacara cariAdrAkhir = first(LP);
        while(next(cariAdrAkhir)!= first(LP)){
            cariAdrAkhir = next(cariAdrAkhir);
        }
        next(cariAdrAkhir) = pengacara;
        next(pengacara) = first(LP);
    }
}
void showPengacara(listPengacara LP){
// F.S menampilkan list Pengacara
    adrPengacara pengacara = first(LP);
    int iterasi = 1;
    if(first(LP)!= nil){
        cout << "=================== LIST PENGACARA ===================" << endl;
        while(next(pengacara) != first(LP)){
        cout << "Data ke-" << iterasi << endl;
        cout << "Nama Firma     : " << info(pengacara).namaFirma << endl;
        cout << "Nama Pengacara : " << info(pengacara).namaPengacara << endl;
        cout << "NIK Pengacara  : " << info(pengacara).nikPengacara << endl;
        cout << "Usia Pengacara : " << info(pengacara).usia << endl;
        cout << endl;
        pengacara = next(pengacara);
        iterasi++;
    }
        cout << "Data ke-" << iterasi << endl;
        cout << "Nama Firma     : " << info(pengacara).namaFirma << endl;
        cout << "Nama Pengacara : " << info(pengacara).namaPengacara << endl;
        cout << "NIK Pengacara  : " << info(pengacara).nikPengacara << endl;
        cout << "Usia Pengacara : " << info(pengacara).usia << endl;
        cout << endl;
    }else{
        cout << " List Pengacara Kosong!!!\n"<<endl;
    }

}
void hapusPengacara(listPengacara &LP,listClient &LC,adrPengacara &pengacara,string nama){
    adrClient cariClient;
    adrPengacara cariPengacara;
    if(first(LP)!= nil){
        pengacara = searchPengacara(LP,nama);
        if(pengacara!= nil){
            if(pengacara == first(LP) && next(pengacara) == first(LP)){
                first(LP) = nil;
                next(pengacara) = nil;
                cariClient = first(LC);
                while(cariClient != nil){
                    if(adrParent(cariClient) == pengacara){
                        adrParent(cariClient) = nil;
                    }
                    cariClient = next(cariClient);
                }
            }else{
                cariPengacara = first(LP);
                while(next(cariPengacara) != pengacara){
                    cariPengacara = next(cariPengacara);
                }
                if(pengacara == first(LP)){
                    first(LP) = next(pengacara);
                    next(cariPengacara) = first(LP);
                    next(pengacara) = nil;
                }else{
                    next(cariPengacara) = next(pengacara);
                    next(pengacara) = nil;
                }
                cariClient = first(LC);
                while(cariClient != nil){
                    if(adrParent(cariClient) == pengacara){
                        adrParent(cariClient) = nil;
                    }
                    cariClient = next(cariClient);
                }
            }
        }else{
            cout << "Pengacara tidak ditemukan !!!!"<<endl;
        }
    }else{
        cout << "List Kosong !!!\n" << endl;
    }
}
adrPengacara searchPengacara(listPengacara LP,string nama){
// F.S Mencari data pengacara
    adrPengacara pengacara = first(LP);
    if(first(LP)!= nil){
        while(next(pengacara) != first(LP) && info(pengacara).namaPengacara != nama){
            pengacara = next(pengacara);
        }
        if(info(pengacara).namaPengacara != nama){
            pengacara = nil;
        }
    }
    return pengacara;
}
void createListClient(listClient &LC){
    // F.S membuat List client
    first(LC) = nil;
}
adrClient createElementClient(infoClient data){
    // F.S mengembalikan alamat yang berisi data client
    adrClient Client = new elementClient;
    info(Client).namaClient = data.namaClient;
    info(Client).nikClient = data.nikClient;
    info(Client).masalah = data.masalah;
    info(Client).usia = data.usia;
    adrParent(Client) = nil;
    next(Client) = nil;
    return Client;
}
void insertClient(listClient &LC, adrClient client){
    // F.S menambahkan data dari alamat client ke dalam list Pengacara di akhir list
    if(first(LC) == nil){
        first(LC) = client;
    }else{
        adrClient cariAdrAkhir = first(LC);
        while(next(cariAdrAkhir)!= nil){
            cariAdrAkhir = next(cariAdrAkhir);
        }
        next(cariAdrAkhir) = client;
    }
}
void kuasaHukumClient(listClient &LC,listPengacara LP,string pengacara,string client){
    // F.S menghubungkan data klien ke data pengacara
    adrClient cariClient = first(LC);
    while(cariClient != nil && info(cariClient).namaClient != client){
        cariClient = next(cariClient);
    }
    if(cariClient != nil && adrParent(cariClient) == nil){
        adrPengacara cariPengacara = searchPengacara(LP,pengacara);
        if (info(cariPengacara).namaPengacara == pengacara){
            adrParent(cariClient) = cariPengacara;
        }else{
            cout << " Pengacara Tidak Ditemukan!!!! \n"<<endl;
        }
    }else if(adrParent(cariClient) != nil){
        cout << " Client telah memiliki Kuasa Hukum !!! \n"<<endl;
    }else{
        cout << " Client Tidak Ditemukan!!!! \n"<<endl;
    }
}
void showAllKuasaHukumClient(listClient LC,listPengacara LP){
    // F.S Menampilkan seluruh data pengacara beserta kliennya
    adrClient client = first(LC);
    int iterasi = 1;
    cout << "=============== show data PENGACARA beserta CLIENT ===============" << endl;
    while(client != nil){
        if(adrParent(client)!= nil){
         cout << "Data ke-" << iterasi << endl;
         iterasi++;
         cout << "Nama Firma     : " << info(adrParent(client)).namaFirma << endl;
         cout << "Nama Pengacara : " << info(adrParent(client)).namaPengacara << endl;
         cout << "NIK Pengacara  : " << info(adrParent(client)).nikPengacara << endl;
         cout << "Usia Pengacara : " << info(adrParent(client)).usia << endl;

         cout << "Nama Client     : " << info(client).namaClient << endl;
         cout << "NIK Pengacara  : " << info(client).nikClient << endl;
         cout << "Masalah client : " << info(client).masalah << endl;
         cout << "Usia client : " << info(client).usia << endl;

         cout << endl;
        }
        client = next(client);
    }
}
adrClient searchClient(listPengacara LP,listClient LC,string namaPengacara,string namaClient){
    // F.S Mencari data klien pada pengacara tertentu
    adrPengacara pengacara = searchPengacara(LP,namaPengacara);
    if(pengacara!=nil)
    {
        adrClient client= first(LC);
        while(client!=nil)
        {
            if(adrParent(client)==pengacara && info(adrParent(client)).namaPengacara == namaPengacara)
            {
                return client;
            }
        }client = next(client);
    }else
    {
        return nil;
    }
}
void hapusKuasaHukumClient(listClient &LC,listPengacara LP,string namaPengacara,string namaClient){
    // F.S Menghapus data klien pada pengacara tertentu
    adrClient client = searchClient(LP,LC,namaPengacara,namaClient);
    if(client != nil){
        adrParent(client) = nil;
    }else{
        cout << " Client Tidak Ditemukan!!! \n" << endl;
    }
}
void searchClientTerbanyak(listPengacara LP,listClient LC){
    // F.S Menampilkan pengacara yang melayani klien paling banyak
    adrPengacara terbanyak,pengacara = first(LP);
    int prevjumlah = 0;
    if(first(LP) != nil){
        while(next(pengacara) != first(LP)){
            int jumlah = 0;
            adrClient client = first(LC);
            while(client != nil){
                if(adrParent(client) == pengacara){
                    jumlah++;
                }
                client = next(client);
            }
            if(terbanyak == nil || prevjumlah < jumlah ){
                terbanyak = pengacara;
            }
            pengacara = next(pengacara);
        }
        cout << "Nama Firma     : " << info(pengacara).namaFirma << endl;
        cout << "Nama Pengacara : " << info(pengacara).namaPengacara << endl;
        cout << "NIK Pengacara  : " << info(pengacara).nikPengacara << endl;
        cout << "Usia Pengacara : " << info(pengacara).usia << endl;
        cout << endl;
    }else{
        cout << " List Kosong !!! \n"<< endl;
    }
}
int menu(){
    int pilih = 0;
    cout << "======================== MENU ========================"<< endl;
    cout << "1.  Insert Data Pengacara"<< endl;
    cout << "2.  Menampilkan semua data pengacara"<< endl;
    cout << "3.  Menghapus data pengacara dan kliennya"<< endl;
    cout << "4.  Mencari data pengacara"<< endl;
    cout << "5.  Insert data klien"<< endl;
    cout << "6.  Menghubungkan data klien ke data pengacara"<< endl;
    cout << "7.  Menampilkan seluruh data pengacara beserta klien"<< endl;
    cout << "8.  Mencari data klien pada pengacara tertentu"<< endl;
    cout << "9.  Menghapus data klien pada pengacara tertentu "<< endl;
    cout << "10. Menampilkan pengacara klien terbanyak"<< endl;
    cout << "0   Keluar\n"<<endl;
    cout << "======================================================"<< endl;
    cout << " Pilih Menu: ";
    cin>>pilih;
    return pilih;
}
