#include "project.h"

// Fungsi untuk registrasi user baru
void project::registerUser()
{
    system("cls"); // Membersihkan layar
    string username, password, password2;
    cout << "\n----------------------------------------------------------\n";
    cout << "                           REGISTER\n";
    cout << "\n----------------------------------------------------------\n";
    cout << "Username: ";
    cin >> username;

    // Input password dengan karakter tersembunyi (ditampilkan sebagai '*')
    cout << "Password: ";
    char ch;
    password = "";
    while ((ch = _getch()) != '\r') { // Loop sampai Enter ditekan
        if (ch == '\b') { // Jika backspace ditekan
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else if (ch >= 32 && ch <= 126) { // Karakter valid
            password += ch;
            cout << '*';
        }
    }
    cout << endl;

    // Konfirmasi password
    cout << "Konfirmasi Password: ";
    password2 = "";
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password2.empty()) {
                cout << "\b \b";
                password2.pop_back();
            }
        }
        else if (ch >= 32 && ch <= 126) {
            password2 += ch;
            cout << '*';
        }
    }
    cout << endl;

    // Validasi password
    if (password != password2) {
        cout << "Password tidak sama! Registrasi gagal.\n";
        system("pause");
        return;
    }

    // Menyimpan user baru ke dalam daftar users
    users.push_back({ username, password });
    cout << "Akun berhasil dibuat!\n";
}

// Fungsi untuk login user/admin
bool project::login(string& loggedInUser, bool& isAdmin)
{
    system("cls");
    string username, password;
    cout << "\n----------------------------------------------------------\n";
    cout << "                           LOGIN\n";
    cout << "\n----------------------------------------------------------\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";

    // Input password dengan karakter tersembunyi
    char ch;
    password = "";
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else if (ch >= 32 && ch <= 126) {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;

    // Login sebagai admin jika username dan password sesuai
    if (username == "admin" && password == "123") {
        isAdmin = true;
        loggedInUser = username;
        return true;
    }

    // Login sebagai user biasa
    auto it = find_if(users.begin(), users.end(), [&](const User& u) {
        return u.username == username && u.password == password;
    });

    if (it != users.end()) {
        isAdmin = false;
        loggedInUser = username;
        return true;
    }

    // Jika login gagal
    cout << "Login gagal. Username atau password salah.\n";
    system("pause");
    return false;
}

// Fungsi untuk menambah film baru ke daftar
void project::tambahFilm()
{
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
    // Menyimpan data film dan status kursi
    films.push_back({ judul, studio, jamTayang, harga });
    kursiStatus.push_back(vector<vector<bool>>(12, vector<bool>(7, false))); // 12 baris, 7 kolom kursi
    cout << "Film berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan daftar film yang tersedia
void project::tampilkanFilm()
{
    system("cls");
    cout << "\n======================================================================\n";
    cout << "                            Daftar Film Tayang\n";
    cout << "\n======================================================================\n";
    if (films.empty()) {
        cout << "Belum ada film.\n";
        return;
    }
    // Menampilkan tabel film
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

// Fungsi untuk menampilkan status kursi pada studio
void project::tampilkanKursi(const vector<vector<bool>>& kursi)
{
    system("cls");
    cout << "\n====================\n";
    cout << "-------SCREEN-------\n";
    cout << "====================\n";
    // Menampilkan kursi, kursi yang sudah dipilih berwarna merah
    for (int i = 0; i < 12; ++i) {
        char baris = 'A' + i;
        for (int j = 0; j < 7; ++j) {
            string kode = string(1, baris) + to_string(j + 1);
            if (kursi[i][j]) {
                cout << "\033[31m" << kode << "\033[0m ";
            }
            else {
                cout << kode << " ";
            }
        }
        cout << endl;
    }
}

// Fungsi untuk mengedit data film
void project::editFilm()
{
    tampilkanFilm();
    if (films.empty()) return;
    int idx;
    cout << "Masukkan nomor film yang ingin diedit: ";
    cin >> idx;
    if (idx < 1 || idx >(int)films.size()) {
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

// Fungsi untuk menghapus film dari daftar
void project::hapusFilm()
{
    tampilkanFilm();
    if (films.empty()) return;
    int idx;
    cout << "Masukkan nomor film yang ingin dihapus: ";
    cin >> idx;
    if (idx < 1 || idx >(int)films.size()) {
        cout << "Nomor film tidak valid.\n";
        return;
    }
    films.erase(films.begin() + (idx - 1));
    cout << "Film berhasil dihapus!\n";
}

// Fungsi untuk menampilkan nota pembelian tiket
void project::tampilkanNota(const Film& film, const vector<string>& kursiDipilih, int jumlahTiket)
{
    system("cls");
    cout << "\n==================== NOTA PEMBELIAN ====================\n";
    cout << "                        ATMI XXI" << endl;
    cout << "==================== NOTA PEMBELIAN ====================\n";
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

// Fungsi untuk mencetak nota pembelian ke file txt
void project::printNotaTxt(const Film& film, const vector<string>& kursiDipilih, int jumlahTiket)
{
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

// Fungsi untuk proses pemilihan film dan pembelian tiket
void project::pilihFilm()
{
    tampilkanFilm();
    if (films.empty()) return;
    int pilihan;
    cout << "Pilih nomor film yang ingin ditonton: ";
    cin >> pilihan;
    if (pilihan < 1 || pilihan >(int)films.size()) {
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
    if (jumlahTiket < 1 || jumlahTiket > 84) { // Maksimal 84 kursi (12x7)
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
            system("pause"); 
        }
        char baris = toupper(kode[0]);
        int kolom = stoi(kode.substr(1)) - 1;
        int idxBaris = baris - 'A';
        if (idxBaris < 0 || idxBaris >= 12 || kolom < 0 || kolom >= 7) {
            cout << "Kursi tidak valid.\n";
            --t;
            system("pause");
        }
        if (kursiStatus[idxFilm][idxBaris][kolom]) {
            cout << "Kursi sudah dipilih, silakan pilih kursi lain.\n";
            --t;
            system ("pause");
        }
        kursiStatus[idxFilm][idxBaris][kolom] = true;
        kursiDipilih.push_back(kode);
    }

    cout << "Tiket berhasil dipesan!\n";
    int opsi;
    do {
        ulang:
        system("cls");
        tampilkanNota(films[idxFilm], kursiDipilih, jumlahTiket);
        cin >> opsi;
        if (opsi == 1) {
            double bayar;
			cout << "Masukkan Nominal pembayaran: ";
			cin >> bayar;
            if (bayar < films[idxFilm].harga * jumlahTiket || bayar > films[idxFilm].harga *jumlahTiket ) {
                cout << "Pembayaran tidak valid.\n";
                system ("pause");
                goto ulang;
			}
            else {
                cout << "Pembayaran berhasil.\n";
                printNotaTxt(films[idxFilm], kursiDipilih, jumlahTiket);
                system("pause");
            }
        }
        else if (opsi == 2) {
            cout << "Transaksi dibatalkan.\n";
            system("pause");
        }
        else {
            cout << "Opsi tidak valid.\n";
        }
    } while (opsi != 1 && opsi != 2);
}
