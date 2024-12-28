#include <iostream>
using namespace std;

const int MAX_FREEZER = 10;
int idFreezer[MAX_FREEZER];
float suhuFreezer[MAX_FREEZER];
string waktuPengukuran[MAX_FREEZER];
int jumlahFreezer = 0;

void inputSuhu() {
    if (jumlahFreezer >= MAX_FREEZER) {
        cout << "Data freezer sudah penuh! Tidak dapat menambahkan lebih banyak data." << endl;
        return;
    }

    cout << "Masukkan ID Freezer: ";
    cin >> idFreezer[jumlahFreezer];
    cout << "Masukkan Suhu Terkini Freezer: ";
    cin >> suhuFreezer[jumlahFreezer];
    cout << "Masukkan Waktu Pengukuran (hh:mm dd/mm/yyyy): ";
    cin.ignore();
    getline(cin, waktuPengukuran[jumlahFreezer]);

    jumlahFreezer++;
    cout << "Data suhu freezer berhasil disimpan!" << endl;
}

void lihatRiwayatSuhu() {
    if (jumlahFreezer == 0) {
        cout << "Belum ada data suhu freezer yang tercatat." << endl;
        return;
    }

    cout << "\n=== Riwayat Suhu Freezer ===" << endl;
    for (int i = 0; i < jumlahFreezer; i++) {
        cout << "ID Freezer: " << idFreezer[i] << endl;
        cout << "  Suhu Terkini: " << suhuFreezer[i] << "°C" << endl;
        cout << "  Waktu Pengukuran: " << waktuPengukuran[i] << endl;
        cout << "---------------------------------" << endl;
    }
}

const int MAX_PRODUK = 50;
string kodeProduk[MAX_PRODUK];
string tanggalExpired[MAX_PRODUK];
int jumlahStok[MAX_PRODUK];
int jumlahProduk = 0;

const int MAX_CABANG = 10; 
const int MAX_PRODUK_CABANG = 50; 

string namaCabang[MAX_CABANG];
string kodeProdukCabang[MAX_CABANG][MAX_PRODUK_CABANG];
int stokCabang[MAX_CABANG][MAX_PRODUK_CABANG];
int jumlahCabang = 0; 
int jumlahProdukPerCabang[MAX_CABANG] = {0};

void inputDataProduk() {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    cout << "\n=== Daftar Cabang ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    int pilihanCabang;
    cout << "Pilih cabang untuk menambahkan produk (nomor): ";
    cin >> pilihanCabang;

    if (pilihanCabang < 1 || pilihanCabang > jumlahCabang) {
        cout << "Input tidak valid. Silakan coba lagi." << endl;
        return;
    }
    pilihanCabang--;

    if (jumlahProdukPerCabang[pilihanCabang] >= MAX_PRODUK) {
        cout << "Cabang ini sudah mencapai batas maksimum produk." << endl;
        return;
    }

    cout << "Masukkan kode produk: ";
    cin >> kodeProdukCabang[pilihanCabang][jumlahProdukPerCabang[pilihanCabang]];

    cout << "Masukkan jumlah stok: ";
    cin >> stokCabang[pilihanCabang][jumlahProdukPerCabang[pilihanCabang]];

    jumlahProdukPerCabang[pilihanCabang]++;
    cout << "Produk berhasil ditambahkan ke cabang " << namaCabang[pilihanCabang] << "!" << endl;
}


void lihatProdukMendekatiExpired() {
    if (jumlahProduk == 0) {
        cout << "Belum ada data produk yang tercatat." << endl;
        return;
    }

    cout << "\n=== Daftar Produk Mendekati Expired ===" << endl;
    bool adaProdukMendekatiExpired = false;

    for (int i = 0; i < jumlahProduk; i++) {
        if (tanggalExpired[i].find("12/2024") != string::npos) {
            cout << "Kode Produk: " << kodeProduk[i] << endl;
            cout << "  Tanggal Expired: " << tanggalExpired[i] << endl;
            cout << "  Jumlah Stok: " << jumlahStok[i] << endl;
            cout << "---------------------------------" << endl;
            adaProdukMendekatiExpired = true;
        }
    }

    if (!adaProdukMendekatiExpired) {
        cout << "Tidak ada produk yang mendekati expired." << endl;
    }
}

void daftarCabang() {
    if (jumlahCabang >= MAX_CABANG) {
        cout << "Maksimum jumlah cabang telah tercapai. Tidak bisa menambah cabang lagi." << endl;
        return;
    }

    cout << "Masukkan nama cabang baru: ";
    cin.ignore();
    getline(cin, namaCabang[jumlahCabang]);
    jumlahCabang++;

    cout << "Cabang berhasil didaftarkan!" << endl;
}


void lihatStokPerCabang() {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang didaftarkan. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    cout << "\n=== Stok Per Cabang ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << "Cabang: " << namaCabang[i] << endl;
        if (jumlahProdukPerCabang[i] == 0) {
            cout << "  Tidak ada produk yang tersedia di cabang ini." << endl;
        } else {
            for (int j = 0; j < jumlahProdukPerCabang[i]; j++) {
                cout << "  Kode Produk: " << kodeProdukCabang[i][j]
                     << ", Stok: " << stokCabang[i][j] << endl;
            }
        }
        cout << "----------------------------" << endl;
    }
}

void transferStokAntarCabang() {
    if (jumlahCabang < 2) {
        cout << "Transfer tidak dapat dilakukan. Minimal harus ada dua cabang yang terdaftar." << endl;
        return;
    }

    cout << "\n=== Daftar Cabang ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    int cabangAsal, cabangTujuan;
    cout << "Pilih cabang asal (nomor): ";
    cin >> cabangAsal;
    cout << "Pilih cabang tujuan (nomor): ";
    cin >> cabangTujuan;

    if (cabangAsal < 1 || cabangAsal > jumlahCabang || cabangTujuan < 1 || cabangTujuan > jumlahCabang || cabangAsal == cabangTujuan) {
        cout << "Input tidak valid. Silakan coba lagi." << endl;
        return;
    }

    cabangAsal--;
    cabangTujuan--;

    cout << "\n=== Produk di Cabang Asal (" << namaCabang[cabangAsal] << ") ===" << endl;
    if (jumlahProdukPerCabang[cabangAsal] == 0) {
        cout << "Cabang ini tidak memiliki produk." << endl;
        return;
    }

    for (int i = 0; i < jumlahProdukPerCabang[cabangAsal]; i++) {
        cout << i + 1 << ". Kode Produk: " << kodeProdukCabang[cabangAsal][i] << " (Stok: " << stokCabang[cabangAsal][i] << ")" << endl;
    }

    int produkDipilih, jumlahTransfer;
    cout << "Pilih produk yang akan ditransfer (nomor): ";
    cin >> produkDipilih;

    if (produkDipilih < 1 || produkDipilih > jumlahProdukPerCabang[cabangAsal]) {
        cout << "Produk tidak valid. Silakan coba lagi." << endl;
        return;
    }

    produkDipilih--;

    cout << "Masukkan jumlah yang akan ditransfer: ";
    cin >> jumlahTransfer;

    if (jumlahTransfer <= 0 || jumlahTransfer > stokCabang[cabangAsal][produkDipilih]) {
        cout << "Jumlah transfer tidak valid. Silakan coba lagi." << endl;
        return;
    }

    stokCabang[cabangAsal][produkDipilih] -= jumlahTransfer;

    bool produkDitemukan = false;
    for (int i = 0; i < jumlahProdukPerCabang[cabangTujuan]; i++) {
        if (kodeProdukCabang[cabangTujuan][i] == kodeProdukCabang[cabangAsal][produkDipilih]) {
            stokCabang[cabangTujuan][i] += jumlahTransfer;
            produkDitemukan = true;
            break;
        }
    }

    if (!produkDitemukan) {
        int indexBaru = jumlahProdukPerCabang[cabangTujuan];
        kodeProdukCabang[cabangTujuan][indexBaru] = kodeProdukCabang[cabangAsal][produkDipilih];
        stokCabang[cabangTujuan][indexBaru] = jumlahTransfer;
        jumlahProdukPerCabang[cabangTujuan]++;
    }

    cout << "Transfer stok berhasil dilakukan!" << endl;
}

void lihatPenjualanPerCabang(int penjualanCabang[], int jumlahCabang, string namaCabang[]) {
    cout << "\n=== Penjualan Per Cabang ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << namaCabang[i] << ": " << penjualanCabang[i] << " unit terjual" << endl;
    }
}

void lihatProdukTerlaris(int jumlahCabang, int jumlahProdukPerCabang[], string namaCabang[], string kodeProdukCabang[][MAX_PRODUK], int penjualanProdukCabang[][MAX_PRODUK]) {
    cout << "\n=== Produk Terlaris Per Cabang ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << "\nCabang: " << namaCabang[i] << endl;

        if (jumlahProdukPerCabang[i] == 0) {
            cout << "Tidak ada produk di cabang ini.\n";
            continue;
        }

        int maxPenjualan = -1, indeksTerlaris = -1;
        for (int j = 0; j < jumlahProdukPerCabang[i]; j++) {
            if (penjualanProdukCabang[i][j] > maxPenjualan) {
                maxPenjualan = penjualanProdukCabang[i][j];
                indeksTerlaris = j;
            }
        }

        if (indeksTerlaris != -1) {
            cout << "Produk Terlaris: " << kodeProdukCabang[i][indeksTerlaris]
                 << " (Terjual: " << penjualanProdukCabang[i][indeksTerlaris] << " unit)" << endl;
        }
    }
}

int penjualanCabang[MAX_CABANG] = {0};
int penjualanProdukCabang[MAX_CABANG][MAX_PRODUK] = {0};

void menuPerformaCabang(int penjualanCabang[], int jumlahCabang, string namaCabang[], int jumlahProdukPerCabang[], string kodeProdukCabang[][MAX_PRODUK], int penjualanProdukCabang[][MAX_PRODUK]) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    int pilihan;
    do {
        cout << "\n=== Menu Performa Cabang ===" << endl;
        cout << "1. Lihat Penjualan Per Cabang\n";
        cout << "2. Lihat Produk Terlaris Per Cabang\n";
        cout << "3. Kembali ke Menu Utama\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                lihatPenjualanPerCabang(penjualanCabang, jumlahCabang, namaCabang);
                break;
            case 2:
                lihatProdukTerlaris(jumlahCabang, jumlahProdukPerCabang, namaCabang, kodeProdukCabang, penjualanProdukCabang);
                break;
            case 3:
                cout << "Kembali ke Menu Utama..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);
}

string lokasiRak[MAX_CABANG][MAX_PRODUK];
const int MAX_RAK = 50; 

void inputLokasiProduk(string kodeProdukCabang[MAX_CABANG][MAX_PRODUK_CABANG], int jumlahProdukPerCabang[MAX_CABANG], string lokasiRak[MAX_CABANG][MAX_PRODUK_CABANG], int jumlahCabang) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    int cabangIndex, produkIndex;
    int rakIndex;
    
    cout << "\n=== Pilih Cabang ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    cout << "Pilih Cabang (1 - " << jumlahCabang << "): ";
    cin >> cabangIndex;
    cabangIndex--;

    if (cabangIndex < 0 || cabangIndex >= jumlahCabang) {
        cout << "Cabang tidak valid." << endl;
        return;
    }

    cout << "\n=== Produk di Cabang " << namaCabang[cabangIndex] << " ===" << endl;
    if (jumlahProdukPerCabang[cabangIndex] == 0) {
        cout << "Tidak ada produk yang tersedia di cabang ini." << endl;
        return;
    }

    for (int i = 0; i < jumlahProdukPerCabang[cabangIndex]; i++) {
        cout << i + 1 << ". " << kodeProdukCabang[cabangIndex][i] << endl;
    }

    cout << "Pilih Produk (1 - " << jumlahProdukPerCabang[cabangIndex] << "): ";
    cin >> produkIndex;
    produkIndex--;

    if (produkIndex < 0 || produkIndex >= jumlahProdukPerCabang[cabangIndex]) {
        cout << "Produk tidak valid." << endl;
        return;
    }

    cout << "=== Pilihan Rak ===" << endl;

    cout << "Pilih Rak (1 - " << MAX_RAK << "): ";
    cin >> rakIndex;

    if (rakIndex < 1 || rakIndex > MAX_RAK) {
        cout << "Rak tidak valid." << endl;
        return;
    }

    lokasiRak[cabangIndex][produkIndex] = "Rak " + to_string(rakIndex);
    cout << "Lokasi rak untuk produk " << kodeProdukCabang[cabangIndex][produkIndex] << " di cabang " << namaCabang[cabangIndex] << " berhasil disimpan di Rak " << rakIndex << "." << endl;
}

void lihatIsiRak(string kodeProdukCabang[MAX_CABANG][MAX_PRODUK_CABANG], int jumlahProdukPerCabang[MAX_CABANG], string lokasiRak[MAX_CABANG][MAX_PRODUK_CABANG], int jumlahCabang) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    int cabangIndex;
    cout << "\n=== Pilih Cabang untuk Lihat Isi Rak ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    cout << "Pilih Cabang (1 - " << jumlahCabang << "): ";
    cin >> cabangIndex;
    cabangIndex--;

    if (cabangIndex < 0 || cabangIndex >= jumlahCabang) {
        cout << "Cabang tidak valid." << endl;
        return;
    }

    cout << "\nIsi Rak di Cabang " << namaCabang[cabangIndex] << ":" << endl;
    if (jumlahProdukPerCabang[cabangIndex] == 0) {
        cout << "Tidak ada produk di cabang ini." << endl;
        return;
    }

    bool adaProdukDitempatkan = false;
    for (int i = 0; i < jumlahProdukPerCabang[cabangIndex]; i++) {
        if (!lokasiRak[cabangIndex][i].empty()) { 
            cout << "Produk: " << kodeProdukCabang[cabangIndex][i] << " - Lokasi Rak: " << lokasiRak[cabangIndex][i] << endl;
            adaProdukDitempatkan = true;
        }
    }

    if (!adaProdukDitempatkan) {
        cout << "Tidak ada produk yang ditempatkan di rak." << endl;
    }
}

void inputPengecekanHarian(int jumlahCabang, string namaCabang[], int jumlahProdukPerCabang[], string kodeProdukCabang[][MAX_PRODUK_CABANG], string lokasiRak[][MAX_PRODUK_CABANG]) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    int cabangIndex, produkIndex;
    string suhuFreezer;
    string kondisiProduk;
    
    cout << "\n=== Pilih Cabang untuk Pengecekan Harian ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    cout << "Pilih Cabang (1 - " << jumlahCabang << "): ";
    cin >> cabangIndex;
    cabangIndex--;

    if (cabangIndex < 0 || cabangIndex >= jumlahCabang) {
        cout << "Cabang tidak valid." << endl;
        return;
    }

    cout << "\n=== Pengecekan Harian di Cabang " << namaCabang[cabangIndex] << " ===" << endl;

    cout << "Masukkan suhu freezer (°C): ";
    cin >> suhuFreezer;

    cout << "Masukkan kondisi produk (baik/kerusakan): ";
    cin >> kondisiProduk;

    cout << "\n=== Produk di Cabang " << namaCabang[cabangIndex] << " ===" << endl;
    for (int i = 0; i < jumlahProdukPerCabang[cabangIndex]; i++) {
        cout << i + 1 << ". " << kodeProdukCabang[cabangIndex][i] << " - Lokasi Rak: " << lokasiRak[cabangIndex][i] << endl;
    }

    cout << "Pilih produk untuk pemeriksaan (1 - " << jumlahProdukPerCabang[cabangIndex] << "): ";
    cin >> produkIndex;
    produkIndex--; 

    if (produkIndex < 0 || produkIndex >= jumlahProdukPerCabang[cabangIndex]) {
        cout << "Produk tidak valid." << endl;
        return;
    }

    cout << "\nPengecekan untuk produk " << kodeProdukCabang[cabangIndex][produkIndex] << " di cabang " << namaCabang[cabangIndex] << " berhasil disimpan." << endl;
    cout << "Suhu Freezer: " << suhuFreezer << "°C" << endl;
    cout << "Kondisi Produk: " << kondisiProduk << endl;
    cout << "Produk " << kodeProdukCabang[cabangIndex][produkIndex] << " di rak " << lokasiRak[cabangIndex][produkIndex] << " telah diperiksa." << endl;
}

string jadwalPembersihanCabang[MAX_CABANG];

void lihatJadwalPembersihan(int jumlahCabang, string namaCabang[], string jadwalPembersihanCabang[]) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    int cabangIndex;
    
    cout << "\n=== Pilih Cabang untuk Melihat Jadwal Pembersihan ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    cout << "Pilih Cabang (1 - " << jumlahCabang << "): ";
    cin >> cabangIndex;
    cabangIndex--; 

    if (cabangIndex < 0 || cabangIndex >= jumlahCabang) {
        cout << "Cabang tidak valid." << endl;
        return;
    }

    cout << "\n=== Jadwal Pembersihan di Cabang " << namaCabang[cabangIndex] << " ===" << endl;
    cout << "Jadwal Pembersihan: " << jadwalPembersihanCabang[cabangIndex] << endl;
}

void inputPenjualan(int jumlahCabang, string namaCabang[], string kodeProdukCabang[MAX_CABANG][MAX_PRODUK_CABANG], int stokCabang[MAX_CABANG][MAX_PRODUK_CABANG], int penjualanCabang[MAX_CABANG], int penjualanProdukCabang[MAX_CABANG][MAX_PRODUK], int jumlahProdukPerCabang[MAX_CABANG]) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    int cabangIndex, produkIndex, jumlahTerjual;

    cout << "\n=== Pilih Cabang untuk Proses Penjualan ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    cout << "Pilih Cabang (1 - " << jumlahCabang << "): ";
    cin >> cabangIndex;
    cabangIndex--;

    if (cabangIndex < 0 || cabangIndex >= jumlahCabang) {
        cout << "Cabang tidak valid." << endl;
        return;
    }

    cout << "\n=== Daftar Produk di Cabang " << namaCabang[cabangIndex] << " ===" << endl;
    for (int i = 0; i < jumlahProdukPerCabang[cabangIndex]; i++) {
        cout << i + 1 << ". " << kodeProdukCabang[cabangIndex][i] << " (Stok: " << stokCabang[cabangIndex][i] << ")" << endl;
    }

    cout << "Pilih Produk (1 - " << jumlahProdukPerCabang[cabangIndex] << "): ";
    cin >> produkIndex;
    produkIndex--;

    if (produkIndex < 0 || produkIndex >= jumlahProdukPerCabang[cabangIndex]) {
        cout << "Produk tidak valid." << endl;
        return;
    }

    cout << "Masukkan Jumlah Terjual: ";
    cin >> jumlahTerjual;

    if (stokCabang[cabangIndex][produkIndex] < jumlahTerjual) {
        cout << "Stok tidak cukup untuk transaksi ini." << endl;
        return;
    }

    stokCabang[cabangIndex][produkIndex] -= jumlahTerjual;

    penjualanCabang[cabangIndex] += jumlahTerjual;
    penjualanProdukCabang[cabangIndex][produkIndex] += jumlahTerjual;

    cout << "\nPenjualan Berhasil!" << endl;
    cout << "Produk: " << kodeProdukCabang[cabangIndex][produkIndex] << endl;
    cout << "Jumlah Terjual: " << jumlahTerjual << endl;
    cout << "Sisa Stok: " << stokCabang[cabangIndex][produkIndex] << endl;
}

void lihatStokTersedia(int jumlahCabang, string namaCabang[], string kodeProdukCabang[MAX_CABANG][MAX_PRODUK_CABANG], int stokCabang[MAX_CABANG][MAX_PRODUK_CABANG], int jumlahProdukPerCabang[MAX_CABANG]) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    int cabangIndex;

    cout << "\n=== Pilih Cabang untuk Melihat Stok Tersedia ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    cout << "Pilih Cabang (1 - " << jumlahCabang << "): ";
    cin >> cabangIndex;
    cabangIndex--;

    if (cabangIndex < 0 || cabangIndex >= jumlahCabang) {
        cout << "Cabang tidak valid." << endl;
        return;
    }

    cout << "\n=== Daftar Stok di Cabang " << namaCabang[cabangIndex] << " ===" << endl;
    if (jumlahProdukPerCabang[cabangIndex] == 0) {
        cout << "Tidak ada produk yang terdaftar di cabang ini." << endl;
        return;
    }

    for (int i = 0; i < jumlahProdukPerCabang[cabangIndex]; i++) {
        cout << i + 1 << ". " << kodeProdukCabang[cabangIndex][i] << " (Stok Tersedia: " << stokCabang[cabangIndex][i] << ")" << endl;
    }
}

void inputPembersihanFreezer(int jumlahCabang, string namaCabang[], string jadwalPembersihanCabang[MAX_CABANG]) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    int cabangIndex;

    cout << "\n=== Pilih Cabang untuk Input Pembersihan Freezer ===" << endl;
    for (int i = 0; i < jumlahCabang; i++) {
        cout << i + 1 << ". " << namaCabang[i] << endl;
    }

    cout << "Pilih Cabang (1 - " << jumlahCabang << "): ";
    cin >> cabangIndex;
    cabangIndex--;

    if (cabangIndex < 0 || cabangIndex >= jumlahCabang) {
        cout << "Cabang tidak valid." << endl;
        return;
    }

    string tanggalPembersihan;
    cout << "Masukkan Tanggal Pembersihan Freezer (dd-mm-yyyy): ";
    cin.ignore();
    getline(cin, tanggalPembersihan);

    jadwalPembersihanCabang[cabangIndex] = tanggalPembersihan;

    cout << "Jadwal pembersihan freezer untuk cabang " << namaCabang[cabangIndex] << " telah berhasil dicatat pada tanggal " << tanggalPembersihan << "." << endl;
}

void lihatRiwayatPembersihan(int jumlahCabang, string namaCabang[], string jadwalPembersihanCabang[MAX_CABANG]) {
    if (jumlahCabang == 0) {
        cout << "Belum ada cabang yang terdaftar. Silakan daftar cabang terlebih dahulu." << endl;
        return;
    }

    cout << "\n=== Riwayat Pembersihan Freezer ===" << endl;
    bool adaJadwal = false;

    for (int i = 0; i < jumlahCabang; i++) {
        if (!jadwalPembersihanCabang[i].empty()) {
            cout << "- Cabang: " << namaCabang[i] << endl;
            cout << "  Jadwal Pembersihan Terakhir: " << jadwalPembersihanCabang[i] << endl;
            adaJadwal = true;
        }
    }

    if (!adaJadwal) {
        cout << "Belum ada riwayat pembersihan freezer yang tercatat." << endl;
    }
}

void menuTemperatureControl() {
    int pilihan;
    do {
        cout << "\n=== Temperature Control ===" << endl;
        cout << "1. Input Suhu Freezer" << endl;
        cout << "2. Lihat Riwayat Suhu Freezer" << endl;
        cout << "3. Input Data Produk" << endl;
        cout << "4. Lihat Produk Mendekati Expired" << endl;
        cout << "5. Kembali" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputSuhu();
                break;
            case 2:
                lihatRiwayatSuhu();
                break;
            case 3:
                inputDataProduk();
                break;
            case 4:
                lihatProdukMendekatiExpired();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 5);
}

void menuBranchManagement() {
    int pilihan;
    do {
        cout << "\n=== Branch Management ===" << endl;
        cout << "1. Lihat Stok Per Cabang" << endl;
        cout << "2. Transfer Stok Antar Cabang" << endl;
        cout << "3. Lihat Performa Cabang" << endl;
        cout << "4. Kembali" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                lihatStokPerCabang();
                break;
            case 2:
                transferStokAntarCabang();
                break;
            case 3:
                menuPerformaCabang(penjualanCabang, jumlahCabang, namaCabang, jumlahProdukPerCabang, kodeProdukCabang, penjualanProdukCabang);
                break;
            case 4:
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 4);
}

void menuStorageOperation() {
    int pilihan;
    do {
        cout << "\n=== Storage Operation ===" << endl;
        cout << "1. Input Lokasi Produk" << endl;
        cout << "2. Lihat Isi Rak" << endl;
        cout << "3. Input Pengecekan Harian" << endl;
        cout << "4. Lihat Jadwal Pembersihan" << endl;
        cout << "5. Kembali" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputLokasiProduk(kodeProdukCabang, jumlahProdukPerCabang, lokasiRak, jumlahCabang);
                break;
            case 2:
                lihatIsiRak(kodeProdukCabang, jumlahProdukPerCabang, lokasiRak, jumlahCabang);
                break;
            case 3:
                inputPengecekanHarian(jumlahCabang, namaCabang, jumlahProdukPerCabang, kodeProdukCabang, lokasiRak);
                break;
            case 4:
                lihatJadwalPembersihan(jumlahCabang, namaCabang, jadwalPembersihanCabang);
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 5);
}

void menuSalesOperation() {
    int pilihan;
    do {
        cout << "\n=== Sales Operation ===" << endl;
        cout << "1. Input Penjualan" << endl;
        cout << "2. Lihat Stok Tersedia" << endl;
        cout << "3. Input Pembersihan Freezer" << endl;
        cout << "4. Lihat Riwayat Pembersihan" << endl;
        cout << "5. Kembali" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputPenjualan(jumlahCabang, namaCabang, kodeProdukCabang, stokCabang, penjualanCabang, penjualanProdukCabang, jumlahProdukPerCabang);
                break;
            case 2:
                lihatStokTersedia(jumlahCabang, namaCabang, kodeProdukCabang, stokCabang, jumlahProdukPerCabang);
                break;
            case 3:
                inputPembersihanFreezer(jumlahCabang, namaCabang, jadwalPembersihanCabang);
                break;
            case 4:
                lihatRiwayatPembersihan(jumlahCabang, namaCabang, jadwalPembersihanCabang);
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 5);
}

void menuOwner() {
    int pilihan;
    do {
        cout << "\n=== Menu Owner ===" << endl;
        cout << "1. Temperature Control" << endl;
        cout << "2. Branch Management" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuTemperatureControl();
                break;
            case 2:
                menuBranchManagement();
                break;
            case 3:
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 3);
}

void menuStaff() {
    int pilihan;
    do {
        cout << "\n=== Menu Staff ===" << endl;
        cout << "1. Storage Operation" << endl;
        cout << "2. Sales Operation" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuStorageOperation();
                break;
            case 2:
                menuSalesOperation();
                break;
            case 3:
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 3);
}

void menuUtama() {
    int role;
    do {
        cout << "\n=== Pilih Role ===" << endl;
        cout << "1. Owner" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih role: ";
        cin >> role;

        switch (role) {
            case 1:
                menuOwner();
                break;
            case 2:
                menuStaff();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan sistem." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (role != 3);
}

int main() {
    
    // Contoh cabang dan produk untuk simulasi
    namaCabang[0] = "Cabang A";
    jumlahCabang = 1;
    kodeProdukCabang[0][0] = "P001";
    kodeProdukCabang[0][1] = "P002";
    jumlahProdukPerCabang[0] = 2;
    
    menuUtama();
    return 0;
}
