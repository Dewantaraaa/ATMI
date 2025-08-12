#include "project.h"

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

// Fungsi utama program
int main() {
    string loggedInUser; // Menyimpan username yang sedang login
    bool isAdmin = false; // Menyimpan status apakah user adalah admin
    int menu; // Variabel untuk pilihan menu utama
    project ob; // Membuat objek dari class project

    // Loop utama program, berjalan terus sampai user memilih keluar
    while (true) {
        system("cls"); // Membersihkan layar
        // Menampilkan menu utama
        cout << "\n=====================================================\n";
        cout << "|                   ATMI XXI                        |" << endl;
        cout << "|               PASTI MURAH !!!!                    |" << endl;
        cout << "=====================================================" << endl;
        cout << "| 1. Registrasi Akun                                |\n";
        cout << "| 2. Login                                          |\n";
        cout << "| 3. Keluar                                         |\n";
        cout << "=====================================================" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        // Pilihan menu utama
        if (menu == 1) {
            // Registrasi akun baru
            ob.registerUser();
        }
        else if (menu == 2)
        {
            // Proses login
            if (ob.login(loggedInUser, isAdmin))
            {
                // Jika login sebagai admin
                if (isAdmin)
                {
                    int adminMenu;
                    do {
                        cout << "\n=== Menu Admin ===\n";
                        ob.tampilkanFilm(); // Menampilkan daftar film
                        cout << "1. Tambah Film & Studio\n";
                        cout << "2. Edit Film\n";
                        cout << "3. Hapus Film\n";
                        cout << "4. Logout\n";
                        cout << "Pilih menu: ";
                        cin >> adminMenu;
                        // Pilihan menu admin
                        if (adminMenu == 1) ob.tambahFilm();
                        else if (adminMenu == 2) ob.editFilm();
                        else if (adminMenu == 3) ob.hapusFilm();
                    } while (adminMenu != 4); // Keluar jika pilih logout
                }
                else {
                    // Jika login sebagai user biasa
                    int userMenu;
                    do {
                        cout << "\n=== Menu User ===\n";
                        ob.tampilkanFilm(); // Menampilkan daftar film
                        cout << "1. Pilih Film\n";
                        cout << "2. Logout\n";
                        cout << "Pilih menu: ";
                        cin >> userMenu;
                        // Pilihan menu user
                        if (userMenu == 1) ob.pilihFilm();
                    } while (userMenu != 2); // Keluar jika pilih logout
                }
            }
        }
        else if (menu == 3)
        {
            // Keluar dari program
            cout << "Terima kasih!\n";
            break;
        }
        else
        {
            // Jika input menu tidak valid
            cout << "Menu tidak valid.\n";
        }
    }
}
