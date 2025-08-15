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

class kompetensi
{
public:
    struct User {
        string username;
        string password;
    };

    vector<User> users;

    struct Product {
        string nama;
        string ukuran;
        int harga;
        int jumlah;

        Product(const string& n, string u, double h, int j) : nama(n), ukuran(u), harga(h), jumlah(j) {}
    };

    vector<Product> product;

    struct PembelianItem {
        string nama;
        string ukuran;
        int harga;
        int jumlah;
        int subtotal;
    };

    vector<PembelianItem> keranjang;

    bool login(string& loggedInUser, bool& isAdmin);
    void displayProducts(const vector<Product>& products);
    void displayProductsUser(const vector<Product>& products);
    void tambahProduk();
    void editProduk();
    void hapusProduk();
    void cetakStokKeFile(const vector<Product>& products, const string& filename);
    void beliProduk();
    void landSpace();
};

