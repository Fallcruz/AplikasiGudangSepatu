#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <cmath>
#include <stdio.h>
using namespace std;

struct Data {
    string tipe;
    string warna;
    int ukuran;
    int stock;
};
typedef struct Data infotype;
typedef struct elmList *adr;
struct elmList {
    infotype info;
    adr next;
    adr prev;
    adr help;
};
struct list {
    adr first = NULL;
    adr last = NULL;
};

void menu();
void buatList(list &L);
void buatData(adr &P);
void insertData(list &L, adr P);
void hapusData(list &L, adr &P, string tipe, int ukuran);
void cetakData(list L);
void sortingTipe(list L);
void sortingStock(list L);
void searchData(list L, string tipe);
void editData(list L, string tipe, string warna);
#endif // HEADER_H_INCLUDED
