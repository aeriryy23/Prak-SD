#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Obat {
    int idObat;
    string namaObat;
    Obat* next;

    Obat(int id, string nama, Obat* nxt = nullptr)
        : idObat(id), namaObat(nama), next(nxt) {}
};

Obat* table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = nullptr;
}

int hashFunc(int idObat) {
    return idObat % SIZE;
}

void insertObat(int idObat, string namaObat) {
    int idx = hashFunc(idObat);
    Obat* baru = new Obat(idObat, namaObat, table[idx]);
    table[idx] = baru;
    cout << "Obat dengan ID " << idObat << " (" << namaObat << ") berhasil ditambahkan ke dalam data apotik.\n";
}

Obat* searchObat(int idObat) {
    int idx = hashFunc(idObat);
    Obat* temp = table[idx];
    while (temp) {
        if (temp->idObat == idObat)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void deleteObat(int idObat) {
    int idx = hashFunc(idObat);
    Obat* temp = table[idx];
    Obat* prev = nullptr;

    while (temp && temp->idObat != idObat) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Obat dengan ID " << idObat << " tidak ditemukan.\n";
        return;
    }

    if (!prev)
        table[idx] = temp->next;
    else
        prev->next = temp->next;

    cout << "Obat dengan ID " << idObat << " (" << temp->namaObat << ") telah dihapus dari data apotik.\n";
    delete temp;
}

void displayObat() {
    cout << "\n=== DATA OBAT DALAM APOTIK ===\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        Obat* temp = table[i];
        if (!temp)
            cout << "Kosong";
        while (temp) {
            cout << "[" << temp->idObat << ", " << temp->namaObat << "]";
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    init();
    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n===== MENU APOTIK =====\n";
        cout << "1. Tambah Obat\n";
        cout << "2. Cari Obat\n";
        cout << "3. Hapus Obat\n";
        cout << "4. Tampilkan Semua Obat\n";
        cout << "0. Keluar\n";
        cout << "========================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id;
            string nama;
            cout << "Masukkan ID Obat: ";
            cin >> id;
            cout << "Masukkan Nama Obat: ";
            cin.ignore();
            getline(cin, nama);
            insertObat(id, nama);
        } 
        else if (pilihan == 2) {
            int id;
            cout << "Masukkan ID Obat yang dicari: ";
            cin >> id;
            Obat* o = searchObat(id);
            if (o)
                cout << "Ditemukan: " << o->namaObat << " (ID: " << o->idObat << ")\n";
            else
                cout << "Obat tidak ditemukan.\n";
        } 
        else if (pilihan == 3) {
            int id;
            cout << "Masukkan ID Obat yang akan dihapus: ";
            cin >> id;
            deleteObat(id);
        } 
        else if (pilihan == 4) {
            displayObat();
        } 
        else if (pilihan == 0) {
            cout << "Terima kasih, program apotik selesai.\n";
        } 
        else {
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    }

    return 0;
}
