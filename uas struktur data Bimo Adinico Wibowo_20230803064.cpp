#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Deklarasi kelas Buku
class Buku {
private:
    string judul;
    string pengarang;
    int id;
public:
    // Constructor
    Buku(string judul, string pengarang, int id) : judul(judul), pengarang(pengarang), id(id) {}

    // Getter
    string getJudul() const {
        return judul;
    }

    string getPengarang() const {
        return pengarang;
    }

    int getId() const {
        return id;
    }
};

// Database buku
vector<Buku> perpustakaan;

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku() {
    cout << "Daftar Buku:" << endl;
    cout << "---------------------------------" << endl;
    cout << "ID\t| Judul\t\t| Pengarang" << endl;
    cout << "---------------------------------" << endl;
    for (const Buku& buku : perpustakaan) {
        cout << buku.getId() << "\t| " << buku.getJudul() << "\t| " << buku.getPengarang() << endl;
    }
    cout << "---------------------------------" << endl;
}

// Fungsi untuk menambah buku baru
void tambahBuku() {
    string judul, pengarang;
    int id;

    cout << "Masukkan judul buku: ";
    getline(cin >> ws, judul);  // getline untuk membaca string dengan spasi

    cout << "Masukkan pengarang buku: ";
    getline(cin >> ws, pengarang);

    cout << "Masukkan ID buku: ";
    cin >> id;

    perpustakaan.push_back(Buku(judul, pengarang, id));
    cout << "Buku berhasil ditambahkan!" << endl;
}

// Fungsi untuk menghapus buku berdasarkan ID
void hapusBuku(int id) {
    for (auto it = perpustakaan.begin(); it != perpustakaan.end(); ++it) {
        if (it->getId() == id) {
            perpustakaan.erase(it);
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Buku tidak ditemukan." << endl;
}

// Fungsi untuk memperbarui informasi buku berdasarkan ID
void perbaruiBuku(int id) {
    for (auto& buku : perpustakaan) {
        if (buku.getId() == id) {
            string judulBaru, pengarangBaru;

            cout << "Masukkan judul baru untuk buku " << buku.getJudul() << ": ";
            getline(cin >> ws, judulBaru);

            cout << "Masukkan pengarang baru untuk buku " << buku.getJudul() << ": ";
            getline(cin >> ws, pengarangBaru);

            buku = Buku(judulBaru, pengarangBaru, id);
            cout << "Informasi buku berhasil diperbarui!" << endl;
            return;
        }
    }
    cout << "Buku tidak ditemukan." << endl;
}

int main() {
    // Autentikasi admin atau pengguna
    string username, password;
    bool isAdmin = false;

    cout << "Login:" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    // Check apakah admin atau pengguna
    if (username == "Bimo" && password == "bimo21") {
        isAdmin = true;
        cout << "Login sebagai admin berhasil!" << endl;
    } else if (username == "pengguna" && password == "pengguna123") {
        isAdmin = false;
        cout << "Login sebagai pengguna berhasil!" << endl;
    } else {
        cout << "Username atau password salah. Program berhenti." << endl;
        return 0;
    }

    // Menu operasi CRUD
    int pilihan;
    while (true) {
        cout << endl;
        cout << "Menu Operasi Perpustakaan:" << endl;
        cout << "1. Tampilkan daftar buku" << endl;
        if (isAdmin) {
            cout << "2. Tambah buku baru" << endl;
            cout << "3. Hapus buku" << endl;
            cout << "4. Perbarui informasi buku" << endl;
        }
        cout << "0. Keluar" << endl;
        cout << "Pilih operasi yang diinginkan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanBuku();
                break;
            case 2:
                if (isAdmin) {
                    tambahBuku();
                } else {
                    cout << "Operasi ini hanya dapat dilakukan oleh admin." << endl;
                }
                break;
            case 3:
                if (isAdmin) {
                    int idHapus;
                    cout << "Masukkan ID buku yang ingin dihapus: ";
                    cin >> idHapus;
                    hapusBuku(idHapus);
                } else {
                    cout << "Operasi ini hanya dapat dilakukan oleh admin." << endl;
                }
                break;
            case 4:
                if (isAdmin) {
                    int idPerbarui;
                    cout << "Masukkan ID buku yang ingin diperbarui: ";
                    cin >> idPerbarui;
                    perbaruiBuku(idPerbarui);
                } else {
                    cout << "Operasi ini hanya dapat dilakukan oleh admin." << endl;
                }
                break;
            case 0:
                cout << "Program berakhir. Terima kasih!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
    return 0;
}