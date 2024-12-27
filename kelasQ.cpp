#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


struct mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
    };

mahasiswa sikc[30];

int pos=-1;

void tampilkanData(int p){
    cout << sikc[p].nim<<" , "<< sikc[p].nama<<" , "<< sikc[p].alamat<<" , "<<sikc[p].ipk<<endl;
}

void masukanData(){
    pos++;
    system("cls");
    fflush(stdin);
    cout << "masukan nim: ";
    getline (cin, sikc[pos].nim);
    cout << "masukan nama: ";
    getline (cin, sikc[pos].nama);
    cout << "masukan alamat: ";
    getline (cin, sikc[pos].alamat);
    cout << "masukan ipk: ";
    cin >> sikc[pos].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void perbaikanData(int p)
{
system("cls");
fflush(stdin);
cout << "masukan nama: ";
getline (cin, sikc[p].nama);
cout << "masukan alamat: ";
getline (cin, sikc[p].alamat);
cout << "masukan ipk: ";
cin >> sikc[p].ipk;
cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


int main() {
    // ujicoba memasukan data di array index pertama
    masukanData();
    // ujicoba memasukan data di array index kedua
    masukanData();
    //ujicoba tampilkan data terakhir input
    tampilkanData(pos);

    // ujicoba tampilkan data pada array pertama
    tampilkanData(0);
    // ujicoba merubah data pada array pertama
    perbaikanData(0);
    // ujicoba merubah data pada array kedua
    tampilkanData(0);
    return 0;
}