#include <bits/stdc++.h>

using namespace std;

struct Kosan {
    string nama;
    int harga;
    Kosan* next;
};

Kosan* buatKosan(string nama, int harga) {
    Kosan* baru = new Kosan;
    baru->nama = nama;
    baru->harga = harga;
    baru->next = nullptr;
    return baru;
}

void sisipdepan(Kosan*& kepala, string nama, int harga) {
    Kosan* baru = buatKosan(nama, harga);
    baru->next = kepala;
    kepala = baru;
}

void sisipBelakang(Kosan*& kepala, string nama, int harga) {
    Kosan* baru = buatKosan(nama, harga);
    if (kepala == nullptr) {
        kepala = baru;
    } else {
        Kosan* temp = kepala;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void sisipTengah(Kosan*& kepala, string nama, int harga, int posisi) {
    Kosan* baru = buatKosan(nama, harga);
    if (posisi == 1 || kepala == nullptr) {
        sisipdepan(kepala, nama, harga);
    } else {
        Kosan* temp = kepala;
        for (int i = 1; i < posisi - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            sisipBelakang(kepala, nama, harga);
        } else {
            baru->next = temp->next;
            temp->next = baru;
        }
    }
}

void lihatData(Kosan* kepala) {
    if (kepala == nullptr) {
        cout << "Data kos kosong" << endl;
        return;
    }
    Kosan* temp = kepala;
    while (temp != nullptr) {
        cout << "Nama Kosan\t: " << temp->nama << endl; 
        cout << "Harga\t\t: " << temp->harga << endl;
        temp = temp->next;
    }
}

void hapusKos(Kosan*& kepala, string nama) {
    if (kepala == nullptr) {
        cout << "Data kos kosong" << endl;
        return;
    }
    if (kepala->nama == nama) {
        Kosan* temp = kepala;
        kepala = kepala->next;
        delete temp;
        cout << "Kosan " << nama << " dihapus" <<  endl;
        return;
    }
    Kosan* temp = kepala;
    Kosan* prev = nullptr;
    while (temp != nullptr && temp->nama != nama) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Kosan tidak ditemukan" << endl;
    } else {
        prev->next = temp->next;
        delete temp;
        cout << "Kosan " << nama << " dihapus" <<  endl;
    }
}

int main() {
    Kosan* kepala = nullptr;
    int pilih, harga, posisi;
    string nama;

    do {
        std::cout << setw (31) << setfill ('=') << "=" << endl;
        std::cout << "|" <<  setw (15) << setfill (' ') << "Menu" << right << setw (15) << setfill (' ') << "|" << endl;
        std::cout << setw (31) << setfill ('=') << "=" << endl;
        std::cout << "|" <<  setw (20) << setfill (' ') << "1. Input Data Kos" << right << setw (10) << setfill (' ') << "|" << endl;
        std::cout << "|" <<  setw (20) << setfill (' ') << "2. Lihat Data Kos" << right << setw (10) << setfill (' ') << "|" << endl;
        std::cout << "|" <<  setw (20) << setfill (' ') << "3. Hapus Data Kos" << right << setw (10) << setfill (' ') << "|" << endl;
        std::cout << "|" <<  setw (12) << setfill (' ') << "4. Exit  " << right << setw (18) << setfill (' ') << "|" << endl;
        std::cout << setw (31) << setfill ('=') << "=" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;
        system ("cls");
        switch (pilih) {
            case 1:
            std::cout << setw (31) << setfill ('=') << "=" << endl;
            std::cout << "|" <<  setw (17) << setfill (' ') << "1. Depan" << right << setw (13) << setfill (' ') << "|" << endl;
            std::cout << "|" <<  setw (18) << setfill (' ') << "2. Tengah" << right << setw (12) << setfill (' ') << "|" << endl;
            std::cout << "|" <<  setw (20) << setfill (' ') << "3. Belakang" << right << setw (10) << setfill (' ') << "|" << endl;
            std::cout << setw (31) << setfill ('=') << "=" << endl;
                cout << "Pilih sisip : ";
                cin >> posisi;
                cout << "Masukkan nama Kos: ";
                cin >> nama;
                cout << "Masukkan harga Kos: ";
                cin >> harga;
                if (posisi == 1) {
                    sisipdepan(kepala, nama, harga);
                } else if (posisi == 2) {
                    cout << "Masukkan nomor posisi penyisipan : ";
                    cin >> posisi;
                    sisipTengah(kepala, nama, harga, posisi);
                } else if (posisi == 3) {
                    sisipBelakang(kepala, nama, harga);
                } else {
                    cout << "pilihan tidak valid" << endl;
                }
                system ("pause");
                system ("cls");
                break;
                

            case 2:
                lihatData(kepala);
                  system ("pause");
                    system ("cls");
                break;

            case 3:
                cout << "Masukkan nama Kos yang ingin dihapus: ";
                cin >> nama;
                hapusKos(kepala, nama);
                  system ("pause");
                system ("cls");
                break;

            case 4:
                cout << "Keluar dari program" << endl;
                break;

            default:
                cout << "Pilihan tidak valid. " << endl;
        }
    } while (pilih != 4);

    return 0;
}