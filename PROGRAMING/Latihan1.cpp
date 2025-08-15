#include <iostream>
#include <cmath>

using namespace std;

double hmax(double kecepatan, double elevasi) 
{
	double sudut = elevasi * 3.14 / 180;
	double sinkos = sin(sudut);
	double hasil = (kecepatan * kecepatan * (sinkos * sinkos)) / (10 * 2);
	return hasil;
}

double xmax(double kecepatan, double elevasi)
{
	double sudut = elevasi * 3.14 / 180;
	double sinkos = sin(2 * sudut);
	double hasil = (kecepatan * kecepatan * (sinkos)) / 10;
	return hasil;
}

int main()
{
	char opsi;

awal:
	system("cls");
	cout << "\nSelamat datang di penghitung jarak & ketinggian max peluru \ningin mencari apa nih? \nHmax (A) \nXmax (B) \nKeluar (C)\n\n";
	cin >> opsi;

	if (opsi == 'A' || opsi == 'a')
	{
		double kecepatan, elevasi;

		cout << "================================================\n";
		cout << "================[Penghitung Hmax]===============\n";
		cout << "================================================\n";

		cout << "Masukkan Kecepatan (m/s):";
		cin >> kecepatan;
		cout << "Masukkan Sudut Elevasi (o):";
		cin >> elevasi;

		cout << "Hasil dari penghitungan :" << hmax(kecepatan, elevasi) << endl;
		system("pause");
		goto awal;

		return 0;
	}
	if (opsi == 'B' || opsi == 'b')
	{
		double kecepatan, elevasi;

		cout << "================================================\n";
		cout << "================[Penghitung Xmax]===============\n";
		cout << "================================================\n";

		cout << "Masukkan Kecepatan (m/s):";
		cin >> kecepatan;
		cout << "Masukkan Sudut Elevasi (o):";
		cin >> elevasi;

		cout << "Hasil dari penghitungan :" << xmax(kecepatan, elevasi) << endl;
		system("pause");
		goto awal;

		return 0;
	}
	if (opsi == 'C' || opsi == 'c')
	{
		return 0;
	}
	else
	{
		goto awal;
	}

	return 0;

}
