#pragma once
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

// Deklarasi class utama untuk aplikasi bioskop
class project
{
public:
	// Struktur data untuk menyimpan informasi user
	struct User {
		string username; // Nama pengguna
		string password; // Password pengguna
	};

	// Struktur data untuk menyimpan informasi film
	struct Film {
		string judul;      // Judul film
		string studio;     // Nama studio
		string jamTayang;  // Jam tayang film
		double harga;      // Harga tiket film
	};

	vector<User> users;   // Daftar semua user yang terdaftar
	vector<Film> films;   // Daftar semua film yang tersedia

	// Status kursi untuk setiap film dan studio
	// Format: kursiStatus[film][baris][kolom], bernilai true jika kursi sudah dipilih
	vector<vector<vector<bool>>> kursiStatus;

	// Fungsi untuk registrasi user baru
	void registerUser(); //denyar
	// Fungsi untuk login user/admin
	bool login(string& loggedInUser, bool& isAdmin); //denyar
	// Fungsi untuk menambah film baru
	void tambahFilm(); //dewa
	// Fungsi untuk menampilkan daftar film
	void tampilkanFilm(); //denyar
	// Fungsi untuk menampilkan status kursi pada studio
	void tampilkanKursi(const vector<vector<bool>>& kursi); //dewa
	// Fungsi untuk mengedit data film
	void editFilm(); //santi
	// Fungsi untuk menghapus film dari daftar
	void hapusFilm(); //santi
	// Fungsi untuk menampilkan nota pembelian tiket
	void tampilkanNota(const Film& film, const vector<string>& kursiDipilih, int jumlahTiket); //gawok
	// Fungsi untuk mencetak nota pembelian ke file txt
	void printNotaTxt(const Film& film, const vector<string>& kursiDipilih, int jumlahTiket); //dewa
	// Fungsi untuk proses pemilihan film dan pembelian tiket
	void pilihFilm(); //gawok
};

