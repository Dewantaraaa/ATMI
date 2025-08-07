#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int nilai;

int address()
{
	int* n = &nilai;
	cout << "address = " << n << endl;
	return *n;	
}

int kuadrat()
{
	int hasilk = nilai * nilai;
	cout << "hasilnya " << nilai << "x" << nilai << " = " << hasilk << endl;
	return hasilk;
}

int akar()
{
	double hasila = sqrt(nilai);
	cout << "Akar " << nilai << " = " << hasila << endl;
	return hasila;
}

int main()
{
	awal:
	cout << "----------------------------------------------------\n";
	cout << "\t\t\tPointer" << endl;
	cout << "----------------------------------------------------\n";
	cout << "";

	cout << "Masukkan nilai = ";
	cin >> nilai;
	address();
	kuadrat();
	akar();
	goto awal;

}
