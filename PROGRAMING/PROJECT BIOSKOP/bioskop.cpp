#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <conio.h> 
#include <fstream>
#include <ctime>

using namespace std;

struct User {
    string username;
    string password;
};

struct Film {
    string judul;
    string studio;
    string jamTayang;
    double harga; 
};

vector<User> users;
vector<Film> films;

vector<vector<vector<bool>>> kursiStatus; 

void registerUser() {
	system("cls");
    string username, password, password2;
    cout << "\n----------------------------------------------------------\n";
    cout << "                           REGISTER\n";
    cout << "\n----------------------------------------------------------\n";
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    char ch;
    password = "";
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else if (ch >= 32 && ch <= 126) {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;

    cout << "Konfirmasi Password: ";
    password2 = "";
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password2.empty()) {
                cout << "\b \b";
                password2.pop_back();
            }
        } else if (ch >= 32 && ch <= 126) {
            password2 += ch;
            cout << '*';
        }
    }
    cout << endl;

    if (password != password2) {
        cout << "Password tidak sama! Registrasi gagal.\n";
		system("pause");
        return;
    }

    users.push_back({username, password});
    cout << "Akun berhasil dibuat!\n";
}

bool login(string& loggedInUser, bool& isAdmin) {
    system("cls");
    string username, password;
    cout << "\n----------------------------------------------------------\n";
    cout << "                           LOGIN\n";
    cout << "\n----------------------------------------------------------\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";

    char ch;
    password = "";
    while ((ch = _getch()) != '\r') { 
        if (ch == '\b') { 
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else if (ch >= 32 && ch <= 126) { 
            password += ch;
            cout << '*';
        }
    }
    cout << endl;

    if (username == "admin" && password == "123") {
        isAdmin = true;
        loggedInUser = username;
        return true;
    }

    auto it = find_if(users.begin(), users.end(), [&](const User& u) {
        return u.username == username && u.password == password;
    });

    if (it != users.end()) {
        isAdmin = false;
        loggedInUser = username;
        return true;
    }

    cout << "Login gagal. Username atau password salah.\n";
    system("pause");
    return false;
}
  
void tambahFilm() {
    string judul, studio, jamTayang;
    double harga;
    cout << "Judul film: ";
    cin.ignore();
    getline(cin, judul);
    cout << "Studio: ";
    getline(cin, studio);
    cout << "Jam tayang (misal 19:00): ";
    getline(cin, jamTayang);
    cout << "Harga tiket: ";
    cin >> harga;
    films.push_back({judul, studio, jamTayang, harga});
    kursiStatus.push_back(vector<vector<bool>>(12, vector<bool>(7, false)));
    cout << "Film berhasil ditambahkan!\n";
}

void tampilkanFilm() {
    system("cls");
    cout << "\n------------------------------------------------------------\n";
    cout << "                      Daftar Film Tayang\n";
    cout << "\n------------------------------------------------------------\n";
    if (films.empty()) {
        cout << "Belum ada film.\n";
        return;
    }
    cout << left << setw(5) << "No" << setw(30) << "Judul Film" << setw(15) << "Studio" << setw(10) << "Jam" << setw(10) << "Harga" << endl;
    cout << string(70, '-') << endl;
    for (size_t i = 0; i < films.size(); ++i) {
        cout << left << setw(5) << i + 1
            << setw(30) << films[i].judul
            << setw(15) << films[i].studio
            << setw(10) << films[i].jamTayang
            << setw(10) << fixed << setprecision(0) << films[i].harga << endl;
    }
    cout << string(70, '-') << endl;
}

void tampilkanKursi(const vector<vector<bool>>& kursi) {
    cout << "\n====================\n";
    cout << "-------SCREEN-------\n";
    cout << "====================\n";
    for (int i = 0; i < 12; ++i) {
        char baris = 'A' + i;
        for (int j = 0; j < 7; ++j) {
            string kode = string(1, baris) + to_string(j + 1);
            if (kursi[i][j]) {
                cout << "\033[31m" << kode << "\033[0m "; 
            } else {
                cout << kode << " ";
            }
        }
        cout << endl;
    }
}

void editFilm() {
    tampilkanFilm();
    if (films.empty()) return;
    int idx;
    cout << "Masukkan nomor film yang ingin diedit: ";
    cin >> idx;
    if (idx < 1 || idx > (int)films.size()) {
        cout << "Nomor film tidak valid.\n";
        return;
    }
    cin.ignore();
    cout << "Judul film baru: ";
    getline(cin, films[idx - 1].judul);
    cout << "Studio baru: ";
    getline(cin, films[idx - 1].studio);
    cout << "Jam tayang baru: ";
    getline(cin, films[idx - 1].jamTayang);
    cout << "Harga tiket baru: ";
    cin >> films[idx - 1].harga;
    cout << "Film berhasil diedit!\n";
}

void hapusFilm() {
    tampilkanFilm();
    if (films.empty()) return;
    int idx;
    cout << "Masukkan nomor film yang ingin dihapus: ";
    cin >> idx;
    if (idx < 1 || idx > (int)films.size()) {
        cout << "Nomor film tidak valid.\n";
        return;
    }
    films.erase(films.begin() + (idx - 1));
    cout << "Film berhasil dihapus!\n";
}

void tampilkanNota(const Film& film, const vector<string>& kursiDipilih, int jumlahTiket) {
    system("cls");
    cout << "\n==================== NOTA PEMBELIAN ====================\n";
    cout << "Judul Film   : " << film.judul << endl;
    cout << "Studio       : " << film.studio << endl;
    cout << "Jam Tayang   : " << film.jamTayang << endl;
    cout << "Harga Tiket  : " << fixed << setprecision(0) << film.harga << endl;
    cout << "Jumlah Tiket : " << jumlahTiket << endl;
    cout << "Kursi        : ";
    for (const auto& k : kursiDipilih) cout << k << " ";
    cout << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Total Bayar  : " << fixed << setprecision(0) << film.harga * jumlahTiket << endl;
    cout << "========================================================\n";
    cout << "1. Bayar\n2. Cancel\nPilih opsi: ";
}

void printNotaTxt(const Film& film, const vector<string>& kursiDipilih, int jumlahTiket) {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    char filename[64];
    strftime(filename, sizeof(filename), "nota_%Y%m%d_%H%M%S.txt", &ltm);
    ofstream nota(filename);
    nota << "==================== NOTA PEMBELIAN ====================\n";
    char waktuStr[32];
    strftime(waktuStr, sizeof(waktuStr), "%Y-%m-%d %H:%M:%S", &ltm);
    nota << "Waktu        : " << waktuStr << endl;
    nota << "Judul Film   : " << film.judul << endl;
    nota << "Studio       : " << film.studio << endl;
    nota << "Jam Tayang   : " << film.jamTayang << endl;
    nota << "Harga Tiket  : " << fixed << setprecision(0) << film.harga << endl;
    nota << "Jumlah Tiket : " << jumlahTiket << endl;
    nota << "Kursi        : ";
    for (const auto& k : kursiDipilih) nota << k << " ";
    nota << endl;
    nota << "--------------------------------------------------------\n";
    nota << "Total Bayar  : " << fixed << setprecision(0) << film.harga * jumlahTiket << endl;
    nota << "========================================================\n";
    nota.close();
    cout << "Nota berhasil dicetak ke file: " << filename << endl;
}

void pilihFilm() {
    tampilkanFilm();
    if (films.empty()) return;
    int pilihan;
    cout << "Pilih nomor film yang ingin ditonton: ";
    cin >> pilihan;
    if (pilihan < 1 ||  pilihan > (int)films.size()) {
        cout << "Pilihan tidak valid.\n";
        return;
    }
    int idxFilm = pilihan - 1;
    cout << "Anda memilih film: " << films[idxFilm].judul << endl;
    cout << "Studio: " << films[idxFilm].studio << endl;
    cout << "Jam Tayang: " << films[idxFilm].jamTayang << endl;
    cout << "Harga Tiket: " << films[idxFilm].harga << endl;

    int jumlahTiket;
    cout << "Berapa tiket yang ingin dibeli? " << endl; 
    cin >> jumlahTiket;
    if (jumlahTiket < 1 || jumlahTiket > 84) { 
        cout << "Jumlah tiket tidak valid.\n";
        return;
    }

    vector<string> kursiDipilih;
    for (int t = 0; t < jumlahTiket; ++t) {
        tampilkanKursi(kursiStatus[idxFilm]);
        cout << "Pilih kursi ke-" << t + 1 << " (misal A1): ";
        string kode;
        cin >> kode;
        if (kode.length() < 2 || kode.length() > 3) {
            cout << "Format kursi salah.\n";
            --t;
            continue;
        }
        char baris = toupper(kode[0]);
        int kolom = stoi(kode.substr(1)) - 1;
        int idxBaris = baris - 'A';
        if (idxBaris < 0 || idxBaris >= 12 || kolom < 0 || kolom >= 7) {
            cout << "Kursi tidak valid.\n";
            --t;
            continue;
        }
        if (kursiStatus[idxFilm][idxBaris][kolom]) {
            cout << "Kursi sudah dipilih, silakan pilih kursi lain.\n";
            --t;
            continue;
        }
        kursiStatus[idxFilm][idxBaris][kolom] = true;
        kursiDipilih.push_back(kode);
    }

    cout << "Tiket berhasil dipesan!\n";
    int opsi;
    do {
        tampilkanNota(films[idxFilm], kursiDipilih, jumlahTiket);
        cin >> opsi;
        if (opsi == 1) {
            printNotaTxt(films[idxFilm], kursiDipilih, jumlahTiket);
            system("pause");
        } else if (opsi == 2) {
            cout << "Transaksi dibatalkan.\n";
            system("pause");
        } else {
            cout << "Opsi tidak valid.\n";
        }
    } while (opsi != 1 && opsi != 2);
}

int main() {
    string loggedInUser;
    bool isAdmin = false;
    int menu;

    while (true) {
        system("cls");
        cout << "\n=== Sistem Tiket Bioskop ===\n";
        cout << "1. Registrasi Akun\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            registerUser();
        } 
        else if (menu == 2) 
        {
            if (login(loggedInUser, isAdmin)) 
            {
                if (isAdmin) 
                {
                    int adminMenu;
                    do {
                        cout << "\n=== Menu Admin ===\n";
                        tampilkanFilm();
                        cout << "1. Tambah Film & Studio\n";
                        cout << "2. Edit Film\n";
                        cout << "3. Hapus Film\n";
                        cout << "4. Logout\n";
                        cout << "Pilih menu: ";
                        cin >> adminMenu;
                        if (adminMenu == 1) tambahFilm();
                        else if (adminMenu == 2) editFilm();
                        else if (adminMenu == 3) hapusFilm();
                    } while (adminMenu != 4);
                } else{
                    int userMenu;
                    do {
                        cout << "\n=== Menu User ===\n";
                        tampilkanFilm();
                        cout << "1. Pilih Film\n";
                        cout << "2. Logout\n";
                        cout << "Pilih menu: ";
                        cin >> userMenu;
                        if (userMenu == 1) pilihFilm();
                    } while (userMenu != 2);
                }
            }
        } else if (menu == 3) 
        {
            cout << "Terima kasih!\n";
            break;
        } else 
        {
            cout << "Menu tidak valid.\n";
        }
    }
}
