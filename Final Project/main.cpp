#include <iostream>

using namespace std;

// Data Suhu Freezer
struct FreezerTemperature {
    string freezerID;
    float temperature;
    string timestamp;
};

// Data Produk
struct Product {
    string productCode;
    string expiryDate;
    int stock;
};

// Array untuk menyimpan data
FreezerTemperature temperatureRecords[100];
int temperatureCount = 0;

Product productRecords[100];
int productCount = 0;

// Fungsi untuk menambahkan suhu freezer
void addFreezerTemperature() {
    if (temperatureCount >= 100) {
        cout << "Penyimpanan suhu penuh.\n";
        return;
    }
    cout << "Masukkan ID Freezer: ";
    cin >> temperatureRecords[temperatureCount].freezerID;
    cout << "Masukkan Suhu Terkini: ";
    cin >> temperatureRecords[temperatureCount].temperature;
    cout << "Masukkan Waktu Pengukuran (contoh: 2024-12-19 14:30): ";
    cin.ignore();
    getline(cin, temperatureRecords[temperatureCount].timestamp);
    temperatureCount++;
    cout << "Data suhu berhasil ditambahkan.\n";
}

// Fungsi untuk melihat riwayat suhu per freezer
void viewTemperatureHistory() {
    string freezerID;
    cout << "Masukkan ID Freezer yang ingin dilihat riwayatnya: ";
    cin >> freezerID;

    bool found = false;
    cout << "Riwayat Suhu untuk Freezer " << freezerID << ":\n";
    for (int i = 0; i < temperatureCount; i++) {
        if (temperatureRecords[i].freezerID == freezerID) {
            cout << "- Suhu: " << temperatureRecords[i].temperature
                 << " | Waktu: " << temperatureRecords[i].timestamp << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada data untuk freezer dengan ID tersebut.\n";
    }
}

// Fungsi untuk menambahkan data produk
void addProduct() {
    if (productCount >= 100) {
        cout << "Penyimpanan produk penuh.\n";
        return;
    }
    cout << "Masukkan Kode Produk: ";
    cin >> productRecords[productCount].productCode;
    cout << "Masukkan Tanggal Expired (format: YYYY-MM-DD): ";
    cin >> productRecords[productCount].expiryDate;
    cout << "Masukkan Jumlah Stok: ";
    cin >> productRecords[productCount].stock;
    productCount++;
    cout << "Data produk berhasil ditambahkan.\n";
}

// Fungsi untuk melihat produk yang hampir expired
void viewAlmostExpiredProducts() {
    string currentDate;
    cout << "Masukkan Tanggal Saat Ini (format: YYYY-MM-DD): ";
    cin >> currentDate;

    bool found = false;
    cout << "Produk yang hampir expired:\n";
    for (int i = 0; i < productCount; i++) {
        if (productRecords[i].expiryDate <= currentDate) {
            cout << "- Kode Produk: " << productRecords[i].productCode
                 << " | Tanggal Expired: " << productRecords[i].expiryDate
                 << " | Stok: " << productRecords[i].stock << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada produk yang hampir expired.\n";
    }
}

// Fungsi utama
int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Input Suhu Freezer\n";
        cout << "2. Lihat Riwayat Suhu Freezer\n";
        cout << "3. Input Data Produk\n";
        cout << "4. Lihat Produk Hampir Expired\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFreezerTemperature();
                break;
            case 2:
                viewTemperatureHistory();
                break;
            case 3:
                addProduct();
                break;
            case 4:
                viewAlmostExpiredProducts();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
