#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> 

using namespace std;

struct Product {
    string name;
    string quantity;
    string code;

    Product(const string& n, string q, string c) : name(n), quantity(q), code(c) {}
};

void displaySortedProducts(vector<Product>& products)
{
    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.quantity < b.quantity;
        });

    cout << "------------------------------------------------\n";
    cout << "| Kode         | Nama Produk      | Jumlah     |\n";
    cout << "------------------------------------------------\n";
    for (const auto& product : products) {
        cout << "| " << setw(13) << left << product.code
            << "| " << setw(17) << left << product.name
            << "| " << setw(11) << left << product.quantity << "|\n";
    }
    cout << "------------------------------------------------\n";
}

void addProduct(vector<Product>& products) 
{
    string productName;
    string productQty;
    string productCode;

    cout << "Masukkan kode produk: ";
    cin >> productCode;
    cin.ignore();
    cout << "Masukkan nama produk: ";
    getline(cin, productName);
    cout << "Masukkan jumlah produk: ";
    cin >> productQty;
    cin.ignore();
    products.emplace_back(productName, productQty, productCode);
}

void searchProduct(const vector<Product>& products) 
{
    string searchName;
    cout << "Masukkan nama produk yang ingin dicari: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    for (const auto& product : products) {
        if (product.name == searchName) {
            cout << "Produk ditemukan: " << product.name << ", Jumlah: " << product.quantity << ", Kode: " << product.code << endl;
            cout << "tekan enter untuk kembali ke menu utama" << endl;
            cin.ignore();
            return;
        }
    }
    if (!found) {
        cout << "Produk tidak ditemukan." << endl;
    }
}

int main()
{
    vector<Product> products;
    string productName;
    string productQty;
	char choice;

awal:
    system("cls");
	cout << "------------------------------------------------\n";
	cout << "---------------[Manajemen Produk]---------------\n";
    cout << "------------------------------------------------\n";
    cout << endl;

	displaySortedProducts(products);

	cout << "Menambahkan Produk (A)   |   ";
	cout << "Cari Produk (B)" << endl;
    cout << "Keluar (C)" << endl << endl;

	cin >> choice;
    if (choice == 'A' || choice == 'a') 
    {
        addProduct(products);
        displaySortedProducts(products);
        goto awal;
    }
    if (choice == 'B' || choice == 'b')
    {
		searchProduct(products);
        goto awal;
    }
    if (choice == 'C' || choice == 'c') 
    {
        cout << "Keluar dari program." << endl;
        return 0;
    }
    else 
    {
        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        goto awal;
	}
}