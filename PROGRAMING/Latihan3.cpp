#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n == 0) {
        return 1; 
    }
    else {
        return n * faktorial(n - 1); 
    }
}

int penjumlahan(int n) {
    if (n == 0) {
        return 0; 
    }
    else {
        return n + penjumlahan(n - 1); 
    }
}

int main() 
{

awal:
    int n;
    
	cout << "================================================\n";
	cout << "=======[Penghitung Faktorial & Penjumlahan]=====\n";
	cout << "================================================\n";

    cout << "Masukkan nilai n: ";
    cin >> n;

    cout << n << "! = ";
    for (int i = 1; i <= n; ++i) {
        cout << i;
        if (i < n) {
            cout << " x ";
        }
    }
    cout << " = " << faktorial(n) << endl;

    cout << n << "+ = ";
    for (int i = 1; i <= n; ++i) {
        cout << i;
        if (i < n) {
            cout << " + ";
        }
    }
    cout << " = " << penjumlahan(n) << endl;

	char opsi;
	cout << "\nIngin menghitung lagi? (Y/N): ";
	cin >> opsi;
	if (opsi == 'Y' || opsi == 'y') {
		goto awal;
	}
	cout << "Terima kasih telah menggunakan program ini!" << endl;
	system("pause");

    return 0;
}
