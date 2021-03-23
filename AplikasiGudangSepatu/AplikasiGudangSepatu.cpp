#include "header.h"

void menu(){
    adr P;
    list L;
    int pilih;
    int i = 0;
    int n, del;
    string hapus, tipe, warna;
    do {
        system("cls");
        cout<<"------------------------------------------------------"<<endl;
        cout<<"|====================================================|"<<endl;
        cout<<"|                   GUDANG SEPATU                    |"<<endl;
        cout<<"|====================================================|"<<endl;
        cout<<"|              1. Insert Data Sepatu                 |"<<endl;
        cout<<"|              2. Lihat Data Sepatu                  |"<<endl;
        cout<<"|              3. Hapus Data Sepatu                  |"<<endl;
        cout<<"|              4. Sorting Data Sepatu                |"<<endl;
        cout<<"|              5. Search Tipe Sepatu                 |"<<endl;
        cout<<"|              6. Edit Data Sepatu                   |"<<endl;
        cout<<"|              7. Keluar                             |"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"| Pilih Menu ( 1 - 7 ) : ";
        cin>>pilih;
        cout<<endl;
        switch(pilih){
        case 1:
            cout<<"| Berapa Sepatu Yang Ingin Di Masukan : ";
            cin >> n;
            cout<<"|----------------------------------"<<endl;
            buatList(L);
            while (i < n){
                buatData(P);
                insertData(L, P);
                i++;
            }
            cout<<endl;
            cout<< "| Loading, please wait..."<<endl;
            Sleep(2000);
            cout<<endl;
            cout<<"| PRESS ENTER TO CONTINUE...";
            getch();
            break;
        case 2:
            cout<< "| Loading, please wait..."<<endl;
            Sleep(1500);
            cetakData(L);
            cout<<"| PRESS ENTER TO CONTINUE...";
            getch();
            break;
        case 3:
            cetakData(L);
            cout<<"|----------------------------------"<<endl;
            cout<<"| Tipe Sepatu Yang Ingin Dihapus : ";
            cin>>hapus;
            cout<<"| Ukuran Berapa : ";
            cin>>del;
            cout<<"|-----------------------------------"<<endl;
            hapusData(L, P, hapus, del);
            break;
        case 4:
            cout<<"|=================================="<<endl;
            cout<<"| Sorting Berdasarkan :"<<endl;
            cout<<"|  1. Tipe Sepatu"<<endl;
            cout<<"|  2. Stock Sepatu"<<endl;
            cout<<"|=================================="<<endl;
            cout<<"| Masukan Pilihan : ";
            cin>>n;
            cout<<endl;
            if (n == 1){
                sortingTipe(L);
                cout<< "| Loading, please wait..."<<endl<<endl;
                Sleep(2000);
                cetakData(L);
                cout<<"| PRESS ENTER TO CONTINUE...";
                getch();
            } else {
                sortingStock(L);
                cout<< "| Loading, please wait..."<<endl<<endl;
                Sleep(2000);
                cetakData(L);
                cout<<"| PRESS ENTER TO CONTINUE...";
                getch();
            }
            break;
        case 5:
            cout<<"| Masukan Tipe Sepatu Yang Ingin Dicari : ";
            cin>>tipe;
            searchData(L,tipe);
            cout<<"| PRESS ENTER TO CONTINUE...";
            getch();
            break;
        case 6:
            editData(L, tipe, warna);
            cout<<endl;
            cout<< "| Loading, please wait..."<<endl;
            Sleep(2000);
            cout<<endl;
            cout<<"| PRESS ENTER TO CONTINUE...";
            getch();
            break;
        case 7:
            cout<<"|--------------------- KELUAR -----------------------|"<<endl;
            break;
        default:
            cout<<"| Pilihan Anda Tidak Ada !!!"<<endl<<endl;
            cout<<"| KEMBALI KE PILIHAN MENU...";
            Sleep(2000);
        }

    }while (pilih != 7);

}
void buatList(list &L){
    L.first = NULL;
    L.last = NULL;
}
void buatData(adr &P){
    P = new elmList;

    cout<<"| Masukkan Tipe Sepatu : ";
    cin>>P->info.tipe;
    cout<<"| Masukkan Warna       : ";
    cin>>P->info.warna;
    cout<<"| Masukkan Ukuran      : ";
    cin>>P->info.ukuran;
    cout<<"| Masukkan Stock       : ";
    cin>>P->info.stock;
    cout<<"|----------------------------------"<<endl;
    P->next = NULL;
    P->prev = NULL;
}
void insertData(list &L, adr P){
    if (L.first == NULL){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void hapusData(list &L, adr &P, string tipe, int ukuran){
    P = L.first;
    if (L.first == NULL){
        cout<<"| Gudang Kosong"<<endl;
        getch();
    } else if (L.first->info.tipe == tipe && L.first->info.ukuran == ukuran){
        if (P->next == NULL){
            L.first = NULL;
        } else {
            P->next->prev = NULL;
            L.first = P->next;
            P->next = NULL;
        }
        cout<<endl;
    } else {
        P = L.first;
        if (P->next == NULL){
            cout<<endl;
            cout<<"| Data Tidak Ada"<<endl;
        } else {
            P = L.first;
            while (P != NULL){
                if (P->info.tipe == tipe && P->info.ukuran == ukuran){
                    break;
                }
                P = P->next;
            }
            if (P == NULL){
                cout<<endl;
                cout<<"| Data Tidak Ada"<<endl;
            } else {
                if (L.first->next == NULL){
                    L.first = NULL;
                } else if (P->next == NULL){
                    P->prev->next = NULL;
                    P->prev = NULL;
                } else {
                    P->next->prev = P->prev;
                    P->prev->next = P->next;
                    P->next = NULL;
                    P->prev = NULL;
                }
                cout<<endl;
            }
        }
    }
}
void cetakData(list L){
    int i=1;
    if (L.first == NULL){
        cout<<"| Data Tidak Ditemukan!!!"<<endl<<endl;
    } else {
        adr P = L.first;
        cout<<"|============================================================|"<<endl;
        cout<<"|                        GUDANG SEPATU                       |"<<endl;
        cout<<"|=====|============|==============|=============|============|"<<endl;
        cout<<"| No. |    TIPE    |     WARNA    |    UKURAN   |    STOCK   |"<<endl;
        cout<<"|-----|------------|--------------|-------------|------------|"<<endl;
        while (P != NULL){
            cout<<setw(4)<<i;
            cout<<setw(11)<<P->info.tipe;
            cout<<setw(14)<<P->info.warna;
            cout<<setw(13)<<P->info.ukuran;
            cout<<setw(14)<<P->info.stock;
            cout<<endl;
            P = P->next;
            i++;
        }
        cout<<"|=====|============|==============|=============|============|"<<endl;
        cout<<endl;
    }
}

void sortingTipe(list L){
    adr bantuan1;
    adr bantuan2;
    string temptipe;
    string tempwarna;
    int tempukuran;
    int tempstock;
    if (L.first == NULL){
        return;
    } else {
        bantuan2 = L.first->next;
        while (bantuan2 != NULL){
            bantuan1 = bantuan2;
            while (bantuan1 != L.first && bantuan1->info.tipe < bantuan1->prev->info.tipe){
                temptipe = bantuan1->info.tipe;
                tempwarna = bantuan1->info.warna;
                tempukuran = bantuan1->info.ukuran;
                tempstock = bantuan1->info.stock;
                bantuan1->info.tipe = bantuan1->prev->info.tipe;
                bantuan1->info.warna = bantuan1->prev->info.warna;
                bantuan1->info.ukuran = bantuan1->prev->info.ukuran;
                bantuan1->info.stock = bantuan1->prev->info.stock;
                bantuan1->prev->info.tipe = temptipe;
                bantuan1->prev->info.warna = tempwarna;
                bantuan1->prev->info.ukuran = tempukuran;
                bantuan1->prev->info.stock = tempstock;
                bantuan1 = bantuan1->prev;
            }
            bantuan2 = bantuan2->next;
        }
    }
}
void sortingStock(list L){
    adr bantuan1;
    adr bantuan2;
    string temptipe;
    string tempwarna;
    int tempukuran;
    int tempstock;
    if (L.first == NULL){
        return;
    } else {
        bantuan2 = L.first->next;
        while (bantuan2 != NULL){
            bantuan1 = bantuan2;
            while (bantuan1 != L.first && bantuan1->info.stock >= bantuan1->prev->info.stock){
                temptipe = bantuan1->info.tipe;
                tempwarna = bantuan1->info.warna;
                tempukuran = bantuan1->info.ukuran;
                tempstock = bantuan1->info.stock;
                bantuan1->info.tipe = bantuan1->prev->info.tipe;
                bantuan1->info.warna = bantuan1->prev->info.warna;
                bantuan1->info.ukuran = bantuan1->prev->info.ukuran;
                bantuan1->info.stock = bantuan1->prev->info.stock;
                bantuan1->prev->info.tipe = temptipe;
                bantuan1->prev->info.warna = tempwarna;
                bantuan1->prev->info.ukuran = tempukuran;
                bantuan1->prev->info.stock = tempstock;
                bantuan1 = bantuan1->prev;
            }
            bantuan2 = bantuan2->next;
        }
    }
}
void searchData(list L, string tipe){
    adr P = L.first;
    while (P != NULL && P->info.tipe != tipe){
       P = P->next;
    }
    if (P->info.tipe == tipe){
            cout<<"|=================================="<<endl;
            cout<<"| Tipe Sepatu : "<<P->info.tipe<<endl;
            cout<<"| Warna       : "<<P->info.warna<<endl;
            cout<<"| Ukuran      : "<<P->info.ukuran<<endl;
            cout<<"| Stock       : "<<P->info.stock<<endl;
            cout<<"|=================================="<<endl;
    }
}

void editData(list L, string tipe, string warna){
    adr P = L.first;
    cout<<"|=============================================="<<endl;
    cout<<"| Masukan Tipe Sepatu Yang Ingin Di Edit : ";
    cin>>tipe;
    cout<<"|----------------------------------------------"<<endl;
    cout<<"| Masukan Warna Sepatu Yang Ingin Di Edit : ";
    cin>>warna;
    cout<<"|=============================================="<<endl;

    while (P != NULL && P->info.tipe != tipe && P->info.warna != warna){
        P = P->next;
    }
    if (P->info.tipe == tipe && P->info.warna == warna){
        cout<<"|----------------------------------"<<endl;
        cout<<"| Masukkan Tipe Sepatu : ";
        cin>>P->info.tipe;
        cout<<"| Masukkan Warna       : ";
        cin>>P->info.warna;
        cout<<"| Masukkan Ukuran      : ";
        cin>>P->info.ukuran;
        cout<<"| Masukkan Stock       : ";
        cin>>P->info.stock;
        cout<<"|----------------------------------"<<endl;
    }
}
