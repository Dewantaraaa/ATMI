#include "kompetensi.h"

bool kompetensi::login(string& loggedInUser, bool& isAdmin)
{
    system("cls");
    string username, password;
    cout << "=====================================================\n";
    cout << "                       LOGIN\n";
    cout << "=====================================================\n";
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
        }
        else if (ch >= 32 && ch <= 126) {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;

    if (username == "ADMIN" && password == "123456") {
        isAdmin = true;
        loggedInUser = username;
        return true;
    }
    else if (username == "USER" && password == "678910") {
        isAdmin = false;
        loggedInUser = username;
        return true;
    }
    else {
        cout << "Login gagal. Username atau password salah.\n";
        system("pause");
        return false;
    }
}

void kompetensi::displayProducts(const vector<Product>& products)
{
    system("cls");
    cout << "======================================================================\n";
    cout << "|                          DAFTAR PRODUK                             |\n";
    cout << "======================================================================" << endl;
    cout << left << setw(20) << "Nama"
        << setw(10) << "Ukuran"
        << setw(10) << "Harga"
        << setw(10) << "Jumlah"
        << "Keterangan" << endl;
    cout << string(70, '-') << endl;
    for (const auto& product : products) {
        cout << left
            << setw(20) << product.nama
            << setw(10) << product.ukuran
            << setw(10) << product.harga
            << setw(10) << product.jumlah;
        if (product.jumlah < 10) {
            cout << "Stok hampir habis";
        }
        cout << endl;
        cout << string(70, '-') << endl;
    }
}

void kompetensi::displayProductsUser(const vector<Product>& products)
{
    system("cls");
    cout << "======================================================================\n";
    cout << "|                          DAFTAR PRODUK                             |\n";
    cout << "======================================================================" << endl;
    cout << left << setw(20) << "Nama"
        << setw(10) << "Ukuran"
        << setw(10) << "Harga"
        << setw(10) << "Jumlah" << endl;
    cout << string(50, '-') << endl;
    for (const auto& product : products) {
        cout << left
            << setw(20) << product.nama
            << setw(10) << product.ukuran
            << setw(10) << product.harga
            << setw(10) << product.jumlah;
        cout << endl;
        cout << string(50, '-') << endl;
    }
}

void kompetensi::tambahProduk()
{
    string nama, ukuran;
    int harga, jumlah;
    cout << "Masukkan nama produk: ";
    cin >> nama;
    cout << "Masukkan ukuran produk: ";
    cin >> ukuran;
    cout << "Masukkan harga produk: ";
    cin >> harga;
    cout << "Masukkan jumlah produk: ";
    cin >> jumlah;
    product.emplace_back(nama, ukuran, harga, jumlah);
}

void kompetensi::editProduk()
{
    if (product.empty()) {
        cout << "Tidak ada produk untuk diedit.\n";
        system("pause");
        return;
    }

    string namaCari;
    cout << "Masukkan nama produk yang ingin diedit: ";
    cin >> namaCari;

    auto it = find_if(product.begin(), product.end(), [&](const Product& p) {
        return p.nama == namaCari;
        });

    if (it == product.end()) {
        cout << "Produk tidak ditemukan.\n";
        system("pause");
        return;
    }

    int pilihan;
    cout << "Pilih data yang ingin diedit:\n";
    cout << "1. Nama\n";
    cout << "2. Ukuran\n";
    cout << "3. Harga\n";
    cout << "4. Jumlah\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
    case 1: {
        string namaBaru;
        cout << "Masukkan nama baru: ";
        cin >> namaBaru;
        it->nama = namaBaru;
        break;
    }
    case 2: {
        string ukuranBaru;
        cout << "Masukkan ukuran baru: ";
        cin >> ukuranBaru;
        it->ukuran = ukuranBaru;
        break;
    }
    case 3: {
        int hargaBaru;
        cout << "Masukkan harga baru: ";
        cin >> hargaBaru;
        it->harga = hargaBaru;
        break;
    }
    case 4: {
        int jumlahBaru;
        cout << "Masukkan jumlah baru: ";
        cin >> jumlahBaru;
        it->jumlah = jumlahBaru;
        break;
    }
    default:
        cout << "Pilihan tidak valid.\n";
        break;
    }
}

void kompetensi::hapusProduk()
{
    if (product.empty()) {
        cout << "Tidak ada produk untuk dihapus.\n";
        system("pause");
        return;
    }
    string namaHapus;
    cout << "Masukkan nama produk yang ingin dihapus: ";
    cin >> namaHapus;
    auto it = find_if(product.begin(), product.end(), [&](const Product& p) {
        return p.nama == namaHapus;
        });
    if (it != product.end()) {
        product.erase(it);
        cout << "Produk berhasil dihapus.\n";
    }
    else {
        cout << "Produk tidak ditemukan.\n";
    }
    system("pause");
}

void kompetensi::cetakStokKeFile(const vector<Product>& products, const string& filename)
{
    ofstream file(filename);
    if (file.is_open()) {
        file << left << setw(20) << "Nama"
            << setw(10) << "Ukuran"
            << setw(10) << "Harga"
            << setw(10) << "Jumlah"
            << "Keterangan" << endl;
        file << string(70, '-') << endl;
        for (const auto& product : products) {
            file << left
                << setw(20) << product.nama
                << setw(10) << product.ukuran
                << setw(10) << product.harga
                << setw(10) << product.jumlah;
            if (product.jumlah < 10) {
                file << "Stok kurang dari 10!";
            }
            file << endl;
            file << string(70, '-') << endl;
        }
        file.close();
    }
    else {
        cout << "Gagal membuka file untuk menyimpan data." << endl;
        system("pause");
    }
}

void kompetensi::beliProduk()
{
    char beliLagi;
    do {
        system("cls");
        displayProductsUser(product);

        string namaBeli;
        cout << "Masukkan nama produk yang ingin dibeli: ";
        cin >> namaBeli;

        auto it = find_if(product.begin(), product.end(), [&](const Product& p) {
            return p.nama == namaBeli;
            });

        if (it == product.end()) {
            cout << "Produk tidak ditemukan.\n";
            system("pause");
            continue;
        }

        int jumlahBeli;
        cout << "Masukkan jumlah yang ingin dibeli: ";
        cin >> jumlahBeli;

        if (jumlahBeli > it->jumlah) {
            cout << "Stok tidak mencukupi.\n";
            system("pause");
            continue;
        }

        PembelianItem item;
        item.nama = it->nama;
        item.ukuran = it->ukuran;
        item.harga = it->harga;
        item.jumlah = jumlahBeli;
        item.subtotal = it->harga * jumlahBeli;
        keranjang.push_back(item);

        it->jumlah -= jumlahBeli;

        system("cls");
        displayProductsUser(product);

        cout << "Apakah ingin membeli barang lagi? (y/n): ";
        cin >> beliLagi;
    } while (beliLagi == 'y' || beliLagi == 'Y');

    system("cls");
    cout << "================== STRUK PEMBELIAN ==================\n";
    cout << left << setw(20) << "Nama"
        << setw(10) << "Ukuran"
        << setw(10) << "Harga"
        << setw(10) << "Jumlah"
        << setw(10) << "Subtotal" << endl;
    cout << string(60, '-') << endl;

    int totalHarga = 0;
    for (const auto& item : keranjang) {
        cout << left << setw(20) << item.nama
            << setw(10) << item.ukuran
            << setw(10) << item.harga
            << setw(10) << item.jumlah
            << setw(10) << item.subtotal << endl;
        totalHarga += item.subtotal;
    }
    cout << string(60, '-') << endl;

    double diskon = 0;
    if (totalHarga > 80000) {
        diskon = totalHarga * 0.05;
        cout << "Diskon 5%: " << diskon << endl;
    }
    double totalBayar = totalHarga - diskon;
    cout << "Total Harga: " << totalHarga << endl;
    cout << "Total Bayar: " << totalBayar << endl;

    int uangBayar;
    do {
        cout << "Masukkan uang yang dibayarkan: ";
        cin >> uangBayar;
        if (uangBayar < totalBayar) {
            cout << "Uang tidak mencukupi. Pembelian gagal.\n";
            system("pause");
            return;
        }
    } while (uangBayar < totalBayar);

    double kembalian = uangBayar - totalBayar;
    system("cls");
    cout << "================== STRUK PEMBAYARAN ==================\n";
    cout << left << setw(20) << "Nama"
        << setw(10) << "Ukuran"
        << setw(10) << "Harga"
        << setw(10) << "Jumlah"
        << setw(10) << "Subtotal" << endl;
    cout << string(60, '-') << endl;
    for (const auto& item : keranjang) {
        cout << left << setw(20) << item.nama
            << setw(10) << item.ukuran
            << setw(10) << item.harga
            << setw(10) << item.jumlah
            << setw(10) << item.subtotal << endl;
    }
    cout << string(60, '-') << endl;
    if (diskon > 0) {
        cout << "Diskon 5%: " << diskon << endl;
    }
    cout << "Total Bayar: " << totalBayar << endl;
    cout << "Uang Dibayarkan: " << uangBayar << endl;
    cout << "Kembalian: " << kembalian << endl;
    cout << "======================================================\n";
    system("pause");
    ofstream strukFile("struk_pembelian.txt");
    if (strukFile.is_open()) {
        strukFile << "================== STRUK PEMBELIAN ==================\n";
        strukFile << left << setw(20) << "Nama"
            << setw(10) << "Ukuran"
            << setw(10) << "Harga"
            << setw(10) << "Jumlah"
            << setw(10) << "Subtotal" << endl;
        strukFile << string(60, '-') << endl;
        for (const auto& item : keranjang) {
            strukFile << left << setw(20) << item.nama
                << setw(10) << item.ukuran
                << setw(10) << item.harga
                << setw(10) << item.jumlah
                << setw(10) << item.subtotal << endl;
        }
        strukFile << string(60, '-') << endl;
        if (diskon > 0) {
            strukFile << "Diskon 5%: " << diskon << endl;
        }
        strukFile << "Total Harga: " << totalHarga << endl;
        strukFile << "Total Bayar: " << totalBayar << endl;
        strukFile.close();
    }
    else {
        cout << "Gagal menyimpan struk ke file.\n";
        system("pause");
    }
}

void kompetensi::landSpace()
{
    string loggedInUser;
    bool isAdmin = false;
    int menu;

    while (true) {
        system("cls");
        cout << "\n=====================================================\n";
        cout << "|  #belanja hemat    PROJECT     #belanja lebih 80k |" << endl;
        cout << "|                  SUPERMARKET    #diskon 5% lohh!  |" << endl;
        cout << "=====================================================" << endl;
        cout << "| 1. Login                                          |\n";
        cout << "| 2. Keluar                                         |\n";
        cout << "=====================================================" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1)
        {
            if (login(loggedInUser, isAdmin))
            {
                if (isAdmin)
                {
                    int adminMenu;
                    do {
                        cout << "\n=== Menu Admin ===\n";
                        displayProducts(product);
                        cout << "1. Tambah Produk\n";
                        cout << "2. Edit Produk\n";
                        cout << "3. Hapus Produk\n";
                        cout << "4. Cetak Stok\n";
                        cout << "5. Logout\n";
                        cout << "Pilih menu: ";
                        cin >> adminMenu;
                        if (adminMenu == 1) tambahProduk();
                        else if (adminMenu == 2) editProduk();
                        else if (adminMenu == 3) hapusProduk();
                        else if (adminMenu == 4) cetakStokKeFile(product, "stok.txt");
                    } while (adminMenu != 5);
                }
                else {
                    int userMenu;
                    do {
                        cout << "\n=== Menu User ===\n";
                        displayProductsUser(product);
                        cout << "1. Beli\n";
                        cout << "2. Logout\n";
                        cout << "Pilih menu: ";
                        cin >> userMenu;
                        if (userMenu == 1)
                        {
                            beliProduk();
                        }
                    } while (userMenu != 2);
                }
            }
        }
        else if (menu == 2)
        {
            cout << "Terima kasih!\n";
            break;
        }
        else
        {
            cout << "Menu tidak valid.\n";
        }
    }
}
