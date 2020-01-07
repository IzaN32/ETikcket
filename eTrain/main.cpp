//=================================================================================
// Program e-Ticket
//--------------------------------------------------------------------------------
// By:
//    Muhammad Rifqi Zein       (19104006)
//    Rifqi Alfinur Charisma    (19104031)
//    Satria Adi Nugraha        (19104027)
//      Kelompok 8
//=================================================================================

#include <iostream>
#include <conio.h>
#include <fstream>

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
                        },

    //-----------------------------------------------------------------------------
    // Info Kereta
    //-----------------------------------------------------------------------------
    // Sesuai judul >:(
    //-----------------------------------------------------------------------------

    namaKereta[]={"Bengawan","Progo",  "Gaya Baru Malam","Krakatan","Jaka Tingkir"},
    jam[]={       "08:30",   "10:00",  "12:30",          "14:30",   "16:30"},
    harga[]={     "70.000",  "100.000","150.000",        "180.000", "200.000"};

    //Note: Jika ingin melakukan pengeditan terhadap info kereta harap sesuaikan
    //urutan penulisan

//=================================================================================
//== WARNING: Do NOT touch unless you know what you're doing! =====================
//================================================ You have been warned! ==========
//=================================================================================

    char nav;                 //Untuk navigasi menu program

    int
        selector=0,           //Variable pembantu memproses input user
        selectedTrain,        //Kereta terpilih
        jmlpenumpang;         //Jumlah penumpang

    string
        namaLengkap[1000],    //Nama lengkap calon penumpang
        tujuan,               //Tujuan kereta
        tipeID[1000],         //Tipe ID (isi dengan KTP atau SIM)
        noID[1000],           //Nomor ID KTP atau SIM
        gerbong[1000],        //Nomor gerbong
        kursi[1000];          //Nomor kursi


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
    if(k!="SIM"&&k!="KTP"){
        k="INVALID";
        cout<<"Input invalid!\n";
    }
    return k;
}

//=================================================================================
// + Ticket Order
//---------------------------------------------------------------------------------
// Menu pemesanan tiket
//=================================================================================

void inputDestination();
void inputTrain();
void inputID();

void orderTicket()
{
    inputDestination();
    inputTrain();
    inputID();
    cout<<"Input berhasil! Tekan sembarang tombol untuk melanjutkan!\n\n";
    getche();
}

//=================================================================================
// + Choose Your Destination
//---------------------------------------------------------------------------------
// User diminta menginput tujuan keberangkatan dengan menginputkan angka yang
// tertera di layar
//=================================================================================

void inputDestination()
{
    citySort();                     //Mengurutkan daftar kota tujuan berdasarkan abjad
    pilihTujuan:
    cout<<"Pilih tujuan keberangkatan (input dengan angka!):\n";

    for(int j=0;j<(sizeof(kotaTujuan)/sizeof(*kotaTujuan));j++) //Cetak seluruh kota
        cout<<j+1<<") "<<kotaTujuan[j]<<endl;                   //tujuan yang tersedia

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

    //-----------------------------------------------------------------------------
    // Program akan otomatis memproses input user tanpa perlu menggunakan
    // switch-case atau if-else, all thanks to this 1-line of code below:
    //-----------------------------------------------------------------------------

    tujuan=kotaTujuan[selector-1];

    //-----------------------------------------------------------------------------
    // Konfirmasi jika kota yang dipilih sudah benar
    //-----------------------------------------------------------------------------
    cout<<"\nTujuan anda: "<<tujuan<<"\nSudah benar? (Y/N)\n\n";
    cityConfirm:
    nav=getch();
    if(nav=='y'||nav=='Y')
        cout<<"Kota tujuan berhasil disimpan!\n"<<endl;
    else if(nav=='n'||nav=='N')
        goto pilihTujuan;
    else
        goto cityConfirm;
}

//=================================================================================
// + Pick Your Train
//---------------------------------------------------------------------------------
// User (calon penumpang) diminta menginput jenis kereta serta jam keberangkatan
//=================================================================================

void inputTrain()
{
    cout<<"Pilih kereta:"<<endl;
    for(int m=0;m<(sizeof(namaKereta)/sizeof(*namaKereta));m++)
        cout<<m+1<<") "<<namaKereta[m]<<" ("<<jam[m]<<") -- Rp. "<<harga[m]<<endl;
    pk:
    cout<<"\n> ";
    cin>>selector;
    if(selector<1||selector>(sizeof(namaKereta)/sizeof(*namaKereta))){
        cout<<"Mohon input yang benar!\n";
        goto pk;
    }
    selectedTrain=selector-1;
    cout<<endl;
}

//=================================================================================
// + Passenger Identity Input
//---------------------------------------------------------------------------------
// User akan diminta menginputkan data diri mereka seperti nama dan nomor ID yang
// berupa SIM atau KTP
//=================================================================================

void inputID()
{
    //-----------------------------------------------------------------------------
    // User akan ditanya ingin memesan tiket untuk berapa banyak orang
    //-----------------------------------------------------------------------------
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
        do{
            cout<<"Tipe ID (KTP/SIM): ";            //Semacam failsafe apabila user
            getline(cin,tipeID[i]);                 //Menginput selain KTP atau SIM
            tipeID[i]=ktpsimchecker(tipeID[i]);     //pada form input tipeID
        }while(tipeID[i]=="INVALID");

        cout<<"No ID            : ";getline(cin,noID[i]);
        cout<<"Gerbong          : ";getline(cin,gerbong[i]);
        cout<<"No kursi         : ";getline(cin,kursi[i]);
        cout<<"=======================\n\n";
    }

}

//=================================================================================
// + Ticket Check
//---------------------------------------------------------------------------------
// Untuk melihat atau mengecek tiket yang sudah dipesan sebelumnya
//=================================================================================

void checkTicket()
{
    bool telahMemesan=namaLengkap[0]!="";

    if(!telahMemesan)
        cout<<"Maaf, anda sepertinya belum memesan tiket. Harap pesan tiket terlebih dahulu sebelum menekan menu ini\n\n";
    else{
        for(int p=0;p<jmlpenumpang;p++){
            cout<<"------------------------------------\n";
            cout<<" Penumpang "<<p+1<<endl;
            cout<<"------------------------------------\n";
            cout<<" Nama Lengkap: "<<namaLengkap[p]<<endl;
            cout<<" Tujuan       : "<<tujuan<<endl;
            cout<<" No "<<tipeID[p]<<"       : "<<noID[p]<<endl;
            cout<<" Kereta       : "<<namaKereta[selectedTrain]<<endl;
            cout<<" Gerbong      : "<<gerbong[p]<<endl;
            cout<<" Kursi        : "<<kursi[p]<<endl;
            cout<<" Jam Berangkat: "<<jam[selectedTrain]<<endl;
            cout<<" Harga        : Rp "<<harga[selectedTrain]<<endl;
            cout<<"------------------------------------\n\n";
        }
        cout<<"\nCetak tiket? (Y/N)\n\n";
        cetk:
        cout<<"> ";
        nav=getch();

        if(nav=='y'||nav=='Y'){
            cout<<"Y\n";
            ofstream out ("Tiket.txt");
            out<<"======================================\n";
            out<<"===[TIKET KERETA DAOP 5 PURWOKERTO]===\n";
            out<<"======================================\n\n";
            for(int p=0;p<jmlpenumpang;p++){
                out<<"------------------------------------\n";
                out<<" Penumpang "<<p+1<<endl;
                out<<"------------------------------------\n";
                out<<" Nama Lengkap: "<<namaLengkap[p]<<endl;
                out<<" No "<<tipeID[p]<<"       : "<<noID[p]<<endl;
                out<<" Tujuan       : "<<tujuan<<endl;
                out<<" Kereta       : "<<namaKereta[selectedTrain]<<endl;
                out<<" Gerbong      : "<<gerbong[p]<<endl;
                out<<" Kursi        : "<<kursi[p]<<endl;
                out<<" Jam Berangkat: "<<jam[selectedTrain]<<endl;
                out<<" Harga        : Rp "<<harga[selectedTrain]<<endl;
                out<<"------------------------------------\n\n";
            }out.close();
            cout<<"Tercetak!\n\n";
        }else if(nav=='n'||nav=='N')
            cout<<"N\n\n";
        else
            goto cetk;
    }
}


//=================================================================================
// + Main Menu
//---------------------------------------------------------------------------------
// Merupakan menu utama program. Menampilkan apa yang dapat program lakukan untuk
// user. Navigasi dilakukan dengan cara menekan angka yang tertera pada menu. Hasil
// input user kemudian ditangkap oleh getch() dan diproses dengan switch-case
//=================================================================================

int main()
{
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
