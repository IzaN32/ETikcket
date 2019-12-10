#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    string smr = "Semarang";
    string tipe;
    int input, tujuan, jumlah, tgl, bln, thn, pil;
    long int no;
    string kelas;
    string lengkap;
    cout << endl;
    cout << "===MENU PEMESANAN TIKET KERETA DAOP 5 PURWOKERTO===" << endl;
    cout << endl;
    cout << "1. Pemesanan Tiket" << endl;
    cout << "2. Cek Tiket" << endl;
    cout << endl;
    cout << "Masukkan Input : ";cin>>input;
    cout << endl;
    if(input==1){
        cout << "======= TUJUAN =======" << endl;
        string matriks[2][2] = {{"1. Semarang", "2. Yogyakarta"},{"3. Solo\t   ", "4. Madiun"}};
        int baris, kolom;
        for(baris = 0; baris < 2; baris++){
            for(kolom = 0; kolom < 2; kolom ++){
                cout << matriks[baris][kolom] << " ";
        }
        cout << endl;
    }
        cout << "Masukkan Tujuan : ";cin>>tujuan;
        cout << endl;
        if(tujuan==1){
            cout << "=====Tujuan "<<smr<< "=====" << endl;
            cout << "Masukkan Tanggal Keberangkatan" << endl;
            cout << "\t- Tanggal : ";cin>>tgl;
            cout << "\t- Bulan   : ";cin>>bln;
            cout << "\t- Tahun   : ";cin>>thn;
            cout << "Masukkan Jumlah Penumpang\t : ";cin>>jumlah;
            cout << "Masukkan Kelas Kereta\t\t : ";cin>>kelas;
            cout << endl;
            cout << "=====Pencarian Jadwal Kereta=====" << endl;
            cout << "\n|-----------------------|--------------------|---------------|";
            cout << "\n| Nama Kereta           | Jam Berangkat      | Harga         |";
            cout << "\n|-----------------------|--------------------|---------------|";
            cout << "\n| 1. Bengawan           |      08.30         | Rp. 70.000    |";
            cout << "\n| 2. Progo              |      10.00         | Rp. 100.000   |";
            cout << "\n| 3. Gaya Baru Malam    |      12.30         | Rp. 150.000   |";
            cout << "\n| 4. Krakatan           |      14.30         | Rp. 180.000   |";
            cout << "\n| 5. Jaka Tingkir       |      16.30         | Rp. 200.000   |";
            cout << "\n|-----------------------|--------------------|---------------|";
            cout <<endl;
            cout << "Input Pilihan : ";cin>>pil;
            cout << endl;
            cout << "==========DETAIL PENUMPANG==========" << endl;
            for(int i = 0; i<jumlah; i++){
                cout << "PENUMPANG KE-"<<(i+1)<<endl;
                cout << "Tipe ID (KTP/SIM) : ";cin>>tipe;
                cout << "No ID\t: ";cin>>no;
                cout << "Nama Lengkap\t: ";cin>>lengkap;
                cout << "========================================"<<endl;
            }

        }
    }
    return 0;
}
