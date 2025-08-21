#include <windows.h>
#include <iostream>
#include <cmath>


using namespace std;

int menu, jari, d1, d2;	
const double pi = 3.14;						// Deklarasi PI
double volume, tinggi, luas, kel;			// Deklarasi rad, tinggi dan jarak

void tabung();
void luaslayang();
void kellayang();

int main()
{
	system("color F0");
	char yt;
awal:
	cout << "==============================================";
	cout << "\n                 LATIHAN 2                \n";
	cout << "==============================================";
	cout << "\n1. Luas Layang-Layang\n";
	cout << "2. Keliling Layang-Layang\n";
	cout << "3. Volume Tabung\n";
	cout << "4. Keluar \n";
	cout << "\nPilih Menu : ";
	cin >> menu;
	switch (menu)
	{
	case 1:
	satu:
		system("cls"); // Clear Screen
		luaslayang();
		break;

	case 2:
	duwa:
		system("cls"); // Clear Screen
		kellayang(); // Memanggil fungsi hmax
		break;

	case 3:
	tiga:
		system("cls"); // Clear Screen
		tabung(); // Memanggil fungsi hmax
		break;

	case 4:
		goto akhir;
		break;

	default:
		cout << "\n==================";
		cout << "\nPilihan Tidak Ada";
		cout << "\n==================";

	}
	cout << "\n\nCoba Lagi? Ya atau Tidak " << endl;
	cout << "Masukkan Data Lagi (y/t) ?  ";
	cin >> yt;
	cout << endl;
	if (yt == 'Y' || yt == 'y') {
		if (menu == 1)
		{
			goto satu;
		}
		else if (menu == 2)
		{
			goto duwa;
		}
		else if (menu == 3)
		{
			goto tiga;
		}
		else
		{
			system("cls");
			goto awal;
		}
	}
	if (yt == 'T' || yt == 't') {
		if (menu == 1)
		{
			system("cls");
			goto awal;
		}
		else if (menu == 2)
		{
			system("cls");
			goto awal;
		}
		else if (menu == 3)
		{
			system("cls");
			goto awal;
		}
		else
		{
			goto akhir;
		}
	}
akhir:
	return 0;
}


void tabung()	// Jarak
{
	cout << ">>>>> MENGHITUNG VOLUME TABUNG <<<<<\n";
	cout << "\nMasukkan Jari-Jari Tabung	: ";
	cin >> jari; // Memasukkan angka ke variabel jari
	cout << "Masukkan Tinggi Tabung		: ";
	cin >> tinggi; // Memasukkan angka ke variabel tinggi
	volume = pi * pow(jari, 2) * tinggi;
	cout << "\n> Volume Tabungnya adalah " << volume << "m3";
}

void luaslayang() // Tinggi
{
	cout << ">>>>> MENGHITUNG LUAS LAYANG-LAYANG <<<<<\n";
	cout << "\nMasukkan Diagonal 1	: ";
	cin >> d1; // Memasukkan angka ke variabel jari
	cout << "Masukkan Diagonal 2	: ";
	cin >> d2; // Memasukkan angka ke variabel tinggi
	luas = 0.5 * d1 * d2;
	cout << "\n> Luas Layang-Layang tersebut adalah " << luas << "m2";
}

void kellayang() // Tinggi
{
	cout << ">>>>> MENGHITUNG KELILING LAYANG-LAYANG <<<<<\n";
	cout << "\nMasukkan Sisi 1	: ";
	cin >> d1; // Memasukkan angka ke variabel jari
	cout << "Masukkan Sisi 2	: ";
	cin >> d2; // Memasukkan angka ke variabel tinggi
	kel = 2 * (d1 + d2);
	cout << "\n> Keliling Layang-Layang tersebut adalah " << kel << "m ";
}
