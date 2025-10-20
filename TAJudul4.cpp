#include <iostream>
using namespace std;

struct Node {
    int nim;
    Node* kiri;
    Node* kanan;

    Node(int n) {
        nim = n;
        kiri = kanan = nullptr;
    }
};

Node* insert(Node* akar, int nim) {
    if (akar == nullptr)
        return new Node(nim);
    if (nim < akar->nim)
        akar->kiri = insert(akar->kiri, nim);
    else if (nim > akar->nim)
        akar->kanan = insert(akar->kanan, nim);
    return akar;
}

bool search(Node* akar, int nim) {
    if (akar == nullptr)
        return false;
    if (akar->nim == nim)
        return true;
    else if (nim < akar->nim)
        return search(akar->kiri, nim);
    else
        return search(akar->kanan, nim);
}

void inorder(Node* akar) {
    if (akar == nullptr)
        return;
    inorder(akar->kiri);
    cout << akar->nim << " ";
    inorder(akar->kanan);
}

int countNodes(Node* akar) {
    if (akar == nullptr)
        return 0;
    return 1 + countNodes(akar->kiri) + countNodes(akar->kanan);
}

int findMin(Node* akar) {
    if (akar == nullptr)
        return -1;
    while (akar->kiri != nullptr)
        akar = akar->kiri;
    return akar->nim;
}

int findMax(Node* akar) {
    if (akar == nullptr)
        return -1;
    while (akar->kanan != nullptr)
        akar = akar->kanan;
    return akar->nim;
}

int main() {
    Node* dataMahasiswa = nullptr;
    int pilihan, nim;

    do {
        cout << "\n=== SISTEM MANAJEMEN DATA MAHASISWA ===\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Cari Mahasiswa\n";
        cout << "3. Tampilkan Semua NIM (Inorder)\n";
        cout << "4. Lihat NIM Terkecil\n";
        cout << "5. Lihat NIM Terbesar\n";
        cout << "6. Hitung Jumlah Mahasiswa\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;
            dataMahasiswa = insert(dataMahasiswa, nim);
            cout << "Data mahasiswa berhasil ditambahkan.\n";
        } 
        else if (pilihan == 2) {
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> nim;
            if (search(dataMahasiswa, nim))
                cout << "Mahasiswa dengan NIM " << nim << " ditemukan.\n";
            else
                cout << "Mahasiswa tidak ditemukan.\n";
        } 
        else if (pilihan == 3) {
            cout << "Daftar NIM Mahasiswa (Inorder): ";
            inorder(dataMahasiswa);
            cout << endl;
        } 
        else if (pilihan == 4) {
            cout << "NIM Terkecil: " << findMin(dataMahasiswa) << endl;
        } 
        else if (pilihan == 5) {
            cout << "NIM Terbesar: " << findMax(dataMahasiswa) << endl;
        } 
        else if (pilihan == 6) {
            cout << "Jumlah Mahasiswa: " << countNodes(dataMahasiswa) << endl;
        } 
        else if (pilihan == 7) {
            cout << "Keluar dari program...\n";
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 7);

    return 0;
}