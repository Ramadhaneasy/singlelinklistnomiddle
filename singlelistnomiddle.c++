#include <iostream>
#include <string>

using namespace std;

struct Antrian {
    int nomorAntrian;
    string namaPemilik;
    string waktuKedatangan;
    Antrian* next;
};

Antrian* kepala = nullptr;
Antrian* ekor = nullptr;

// Fungsi untuk menambahkan antrian ke akhir linked list
void tambahAntrian(int nomorAntrian, string namaPemilik, string waktuKedatangan) {
    Antrian* newNode = new Antrian;
    newNode->nomorAntrian = nomorAntrian;
    newNode->namaPemilik = namaPemilik;
    newNode->waktuKedatangan = waktuKedatangan;
    newNode->next = nullptr;

    if (kepala == nullptr) {
        kepala = ekor = newNode;
    } else {
        ekor->next = newNode;
        ekor = newNode;
    }
}

// Fungsi untuk mencetak semua antrian
void cetakAntrian() {
    Antrian* current = kepala;
    while (current != nullptr) {
        cout << "Nomor Antrian: " << current->nomorAntrian << endl;
        cout << "Nama Pemilik: " << current->namaPemilik << endl;
        cout << "Waktu Kedatangan: " << current->waktuKedatangan << endl << endl;
        current = current->next;
    }
}

// Fungsi utama
int main() {
    tambahAntrian(1, "John Doe", "08:00");
    tambahAntrian(2, "Jane Doe", "08:15");
    tambahAntrian(3, "Alice", "08:30");

    // Menampilkan daftar antrian
    cout << "Daftar Antrian:" << endl;
    cetakAntrian();

    return 0;
}
