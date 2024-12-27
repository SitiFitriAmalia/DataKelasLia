#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// Struktur Mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

Mahasiswa dataMhs[30];
int jumlahMhs = 0;

// Fungsi Menampilkan Menu
void tampilkanMenu() {
    system("cls");
    cout << "Aplikasi Data Mahasiswa\n";
    cout << "1. Tambah Data Mahasiswa\n";
    cout << "2. Lihat Semua Data\n";
    cout << "3. Update Data Mahasiswa\n";
    cout << "4. Hapus Data Mahasiswa\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

// Fungsi Validasi Input Float untuk IPK
float validasiIPK() {
    float ipk;
    while (true) {
        cin >> ipk;
        if (cin.fail() || ipk < 0 || ipk > 4) {
            cout << "IPK tidak valid. Harap masukkan angka antara 0 hingga 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return ipk;
        }
    }
}

// Fungsi Menambah Data Mahasiswa
void masukanData() {
    system("cls");
    if (jumlahMhs >= 30) {
        cout << "Data sudah penuh.\n";
        return;
    }

    cout << "Masukkan NIM: ";
    getline(cin, dataMhs[jumlahMhs].nim);
    cout << "Masukkan Nama: ";
    getline(cin, dataMhs[jumlahMhs].nama);
    cout << "Masukkan Alamat: ";
    getline(cin, dataMhs[jumlahMhs].alamat);
    cout << "Masukkan IPK: ";
    dataMhs[jumlahMhs].ipk = validasiIPK();

    jumlahMhs++;
    cout << "\nData berhasil disimpan.\n";
}

// Fungsi Menampilkan Semua Data Mahasiswa
void tampilkanSemuaData() {
    system("cls");
    if (jumlahMhs == 0) {
        cout << "Tidak ada data mahasiswa.\n";
        return;
    }

    cout << "No\tNIM\t\tNama\t\tAlamat\t\t\tIPK\n";
    for (int i = 0; i < jumlahMhs; i++) {
        cout << i + 1 << "\t" 
             << dataMhs[i].nim << "\t" 
             << dataMhs[i].nama << "\t" 
             << dataMhs[i].alamat << "\t" 
             << fixed << setprecision(2) << dataMhs[i].ipk << "\n";
    }
}

// Fungsi Update Data Mahasiswa
void updateData() {
    system("cls");
    if (jumlahMhs == 0) {
        cout << "Tidak ada data untuk diperbarui.\n";
        return;
    }

    string cariNIM;
    cout << "Masukkan NIM mahasiswa yang ingin diperbarui: ";
    getline(cin, cariNIM);

    bool ditemukan = false;
    for (int i = 0; i < jumlahMhs; i++) {
        if (dataMhs[i].nim == cariNIM) {
            ditemukan = true;
            cout << "\nData ditemukan!\n";
            cout << "NIM: " << dataMhs[i].nim << "\n";
            cout << "Nama: " << dataMhs[i].nama << "\n";
            cout << "Alamat: " << dataMhs[i].alamat << "\n";
            cout << "IPK: " << fixed << setprecision(2) << dataMhs[i].ipk << "\n";

            cout << "\nMasukkan data baru:\n";
            cout << "Masukkan Nama: ";
            getline(cin, dataMhs[i].nama);
            cout << "Masukkan Alamat: ";
            getline(cin, dataMhs[i].alamat);
            cout << "Masukkan IPK: ";
            dataMhs[i].ipk = validasiIPK();

            cout << "\nData berhasil diperbarui.\n";
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data dengan NIM " << cariNIM << " tidak ditemukan.\n";
    }
}

// Fungsi Hapus Data Mahasiswa
void hapusData() {
    system("cls");
    if (jumlahMhs == 0) {
        cout << "Tidak ada data untuk dihapus.\n";
        return;
    }

    string cariNIM;
    cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
    getline(cin, cariNIM);

    bool ditemukan = false;
    for (int i = 0; i < jumlahMhs; i++) {
        if (dataMhs[i].nim == cariNIM) {
            ditemukan = true;
            char konfirmasi;
            cout << "Apakah Anda yakin ingin menghapus data ini? (y/n): ";
            cin >> konfirmasi;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                for (int j = i; j < jumlahMhs - 1; j++) {
                    dataMhs[j] = dataMhs[j + 1];
                }
                jumlahMhs--;
                cout << "Data berhasil dihapus.\n";
            } else {
                cout << "Penghapusan dibatalkan.\n";
            }
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data dengan NIM " << cariNIM << " tidak ditemukan.\n";
    }
}

// Fungsi Utama
int main() {
    char pilihan;
    do {
        tampilkanMenu();
        pilihan = getchar();
        getchar();  // Menghindari input enter yang tidak diinginkan

        switch (pilihan) {
            case '1':
                masukanData();
                break;
            case '2':
                tampilkanSemuaData();
                break;
            case '3':
                updateData();
                break;
            case '4':
                hapusData();
                break;
            case '5':
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }

        if (pilihan != '5') {
            cout << "Tekan enter untuk kembali ke menu...";
            getchar();  // Mengambil input enter untuk kembali ke menu
        }

    } while (pilihan != '5');

    return 0;
}