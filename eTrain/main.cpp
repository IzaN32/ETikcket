//=================================================================================
// Program e-Ticket
//--------------------------------------------------------------------------------
// By:
//    Muhammad Rifqi Zein       (191040xx)
//    Rifqi Alfinur Charisma    (191040xx)
//    Satria Adi Nugraha        (19104027)
//=================================================================================

#include <iostream>
#include <conio.h>

using namespace std;

//=================================================================================
// + Deklarasi Variable
//---------------------------------------------------------------------------------
// Variable-variable global akan dideklarasikan disini. Adapun nilai-nilai dari
// variable berikut dapat diubah dan program akan menyesuaikan secara otomatis
//=================================================================================

    //-----------------------------------------------------------------------------
    // Maximum Slot
    //-----------------------------------------------------------------------------
    // Jumlah maksimal kursi kereta yang dapat dipesan melaui program
    //-----------------------------------------------------------------------------

    int maxslot=4;

    //-----------------------------------------------------------------------------
    // Kota Tujuan
    //-----------------------------------------------------------------------------
    // Bagian ini bersifat fully costumizable, yang mana berarti Anda dapat
    // menambah, mengubah, atau menghapus kota dari daftar di bawah. Program
    // akan otomatis beradaptasi terhadap perubahan yang Anda buat termasuk
    // mengurutkannya secara alfabet
    //-----------------------------------------------------------------------------

    string kotaTujuan[]={   "Semarang",
                            "Yogyakarta",
                            "Solo",
                            "Madiun"
                        };

//=================================================================================
//== WARNING: Do NOT touch unless you know what you're doing! =====================
//================================================ You have been warned! ==========
//=================================================================================

    char nav;                    //Untuk navigasi menu program

    string namaLengkap[1000],    //Nama lengkap calon penumpang
           tujuan,               //Tujuan kereta
           tipeID[1000],         //Tipe ID (isi dengan KTP atau SIM)
           noID[1000];           //Nomor ID KTP atau SIM

//=================================================================================
// + Destination Name Sorting
//---------------------------------------------------------------------------------
// Mengurutkan daftar kota tujuan secara alfabet menggunakan
// algoritma Selection Sorting
//=================================================================================

void citySort()
{
    string temp;
    int pm;
    int ct=sizeof(kotaTujuan)/sizeof(*kotaTujuan);

    for(int c=0;c<ct-1;c++){
        pm=c;
        for(int j=c+1;j<ct;j++){
            if(kotaTujuan[j]<kotaTujuan[pm]){
                pm=j;
            }
        }
        if(pm!=c){
            temp=kotaTujuan[c];
            kotaTujuan[c]=kotaTujuan[pm];
            kotaTujuan[pm]=temp;
        }
    }
}

//=================================================================================
// + KTP/SIM Checker
//---------------------------------------------------------------------------------
// Sebuah macro (shortcut/fungsi) untuk mengecek apakah user menggunakan KTP atau
// SIM saat pendaftaran
//=================================================================================

string ktpsimchecker(string k)
{
    if(k=="ktp")
        k="KTP";
    if(k=="sim")
        k="SIM";
    if(k!="SIM"||k!="KTP")
        k="Invalid!";
    return k;
}

//=================================================================================
// + Ticket Order
//---------------------------------------------------------------------------------
// Menu pemesanan tiket
//=================================================================================

void orderTicket()
{
    //-----------------------------------------------------------------------------
    // + Choose Your Destination
    //-----------------------------------------------------------------------------
    // User diminta menginput tujuan keberangkatan dengan menginputkan angka yang
    // tertera di layar
    //-----------------------------------------------------------------------------

    int selector=0;
    citySort();
    pilihTujuan:
    cout<<"Pilih tujuan keberangkatan (input dengan angka!):\n";

    for(int j=0;j<(sizeof(kotaTujuan)/sizeof(*kotaTujuan));j++)
        cout<<j+1<<") "<<kotaTujuan[j]<<endl;

    cout<<"\n> ";
    cin>>selector;

    //-----------------------------------------------------------------------------
    // Berjaga-jaga jika user menginput yang aneh-aneh
    //-----------------------------------------------------------------------------
    if(selector<1||selector>(sizeof(kotaTujuan)/sizeof(*kotaTujuan)))
    {
        cout<<"\nMohon input dengan angka yang valid!\n\n";
        goto pilihTujuan;
    }

    tujuan=kotaTujuan[selector-1];

    //-----------------------------------------------------------------------------
    // Konfirmasi jika kota yang dipilih sudah benar
    //-----------------------------------------------------------------------------
    cout<<"Tujuan anda: "<<tujuan<<"\nSudah benar? (Y/N)\n\n";
    cityConfirm:
    nav=getch();
    if(nav=='y'||nav=='Y')
        cout<<"Kota tujuan berhasil disimpan!\n"<<endl;
    else if(nav=='n'||nav=='N')
        goto pilihTujuan;
    else
        goto cityConfirm;

//=================================================================================
// + Date (Time, not dinner! >_<)
//---------------------------------------------------------------------------------
// Diisi tanggal keberangkatan dan kelas kereta
//=================================================================================

    cout << "\n\t\t|-----------------------|--------------------|---------------|";
    cout << "\n\t\t| Nama Kereta           | Jam Berangkat      | Harga         |";
    cout << "\n\t\t|-----------------------|--------------------|---------------|";
    cout << "\n\t\t| 1. Bengawan           |      08.30         | Rp. 70.000    |";
    cout << "\n\t\t| 2. Progo              |      10.00         | Rp. 100.000   |";
    cout << "\n\t\t| 3. Gaya Baru Malam    |      12.30         | Rp. 150.000   |";
    cout << "\n\t\t| 4. Krakatan           |      14.30         | Rp. 180.000   |";
    cout << "\n\t\t| 5. Jaka Tigkir        |      16.30         | Rp. 200.000   |";
    cout << "\n\t\t|-----------------------|--------------------|---------------|";
/**< user menginputkan jenis kereta yang diingikan */
    cout<<endl<<endl;



    //Placeholder

//=================================================================================
// + Passenger Identity Input
//---------------------------------------------------------------------------------
// User (calon penumpang) akan diminta menginputkan data diri mereka seperti nama
// dan nomor ID yang berupa SIM atau KTP
//=================================================================================

    int jmlpenumpang;
    passengernumber:
    cout<<"Jumlah penumpang (max "<<maxslot<<"): ";
    cin>>jmlpenumpang;

    //-----------------------------------------------------------------------------
    // Berjaga-jaga apabila user menginput yang aneh-aneh
    //-----------------------------------------------------------------------------
    if(jmlpenumpang<1||jmlpenumpang>maxslot){
        cout<<"Mohon masukan angka 1 sampai "<<maxslot<<" saja!\n\n";
        goto passengernumber;
    }

    //if(!(cin>>jmlpenumpang)){
    //    cin.clear();
    //    cin.ignore();
    //    cout<<"Mohon masukan angka 1 sampai "<<maxslot<<" saja!\n\n";
    //    goto passengernumber;
    //}

    //-----------------------------------------------------------------------------
    // Input detail identitas penumpang
    //-----------------------------------------------------------------------------
    cin.ignore();
    cout<<endl<<endl;
    for(int i=0;i<jmlpenumpang;i++)
    {
        cout<<"===[Penumpang ke-"<<i+1<<"]====\n";
        cout<<"Nama lengkap     : ";
        getline(cin,namaLengkap[i]);
        cout<<"Tipe ID (KTP/SIM): ";
        getline(cin,tipeID[i]);
        tipeID[i]=ktpsimchecker(tipeID[i]);
        cout<<"No ID            : ";
        getline(cin,noID[i]);
        cout<<"=======================\n\n";
        /**< user menginputkan kuris yang diinginkan */
    }
    //-----------------------------------------------------------------------------

    //Placeholder
    //Blablabla
    //============================================================
    /**< data user ditampilkan lagi mulai dari kereta yang diinginkan, waktu, total harga,, nama lengkap dll. */
    /**< kode briva akan muncul dan deadline pembayaran maksimal 1 jam */

}

void checkTicket()
{
//=================================================================================
// + Ticket Check
//---------------------------------------------------------------------------------
// Untuk melihat atau mengecek tiket yang sudah dipesan sebelumnya
//=================================================================================

    //Placeholder
    /**< data user, kereta yang diinginkan, waktu berangkat, kode briva, deadlne, pembayaran,
     status tiket atif atau tidak aktif */
}

int main()
{
//=================================================================================
// + Main Menu
//---------------------------------------------------------------------------------
// Merupakan menu utama program. Menampilkan apa yang dapat program lakukan untuk
// user. Navigasi dilakukan dengan cara menekan angka yang tertera pada menu. Hasil
// input user kemudian ditangkap oleh getch() dan diproses dengan switch-case
//=================================================================================

    menu:
    cout<<"=====================================================\n";
    cout<<"===[MENU PEMESANAN TIKET KERETA DAOP 5 PURWOKERTO]===\n";
    cout<<"=====================================================\n\n";
    cout<<"1) Pemesanan tiket\n";
    cout<<"2) Cek tiket\n";
    cout<<"3) Keluar\n";
    cout<<"\n> ";
    noKey:
    nav=getch();

    switch(nav)
    {
        case '1':                   //Pemesanan tiket
            cout<<nav<<endl<<endl;
            orderTicket();
            break;

        case '2':                   //Cek tiket
            cout<<nav<<endl<<endl;
            checkTicket();
            break;

        case '3':                   //Keluar
            cout<<nav<<endl<<endl;
            cout<<"Anda yakin ingin keluar? (Y/N)\n\n";
            quitconf:
            nav=getch();

            if(nav=='Y'||nav=='y')
                return 0;
            else if(nav=='N'||nav=='n')
                goto menu;
            else
                goto quitconf;
            break;

        default:
            goto noKey;
    }
    goto menu;
}
