#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> 
#include <fstream>

using namespace std;

struct Mahasiswa {
	string nama;
	string nim;
	string prodi;
	double tabungan;
	string bulan[6] = { "Januari", "Februari", "Maret", "April", "Mei", "Juni" };
	Mahasiswa(const string& n, const string& i, const string& p) : nama(n), nim(i), prodi(p), tabungan(0.0) {
	}
};

class project
{
public:
	void sortMahasiswa(vector<Mahasiswa>& mahasiswa);
	void addMahasiswa(vector<Mahasiswa>& mahasiswa);
	void tambahTabunganMahasiswa(Mahasiswa& mhs);
	void ubahDataMahasiswa(vector<Mahasiswa>& mahasiswa);
	void exportDataMahasiswa(const vector<Mahasiswa>& mahasiswa);
	void removeMahasiswa(vector<Mahasiswa>& mahasiswa, const string& nim);
	void landspace(vector<Mahasiswa> mahasiswa);
};

