#include <iostream>
#include <conio.h>
using namespace std;

char nav;   //Navigator menu

string namaLengkap[4],tipeID[4],noID[4],tujuan;

void orderTicket()
{
    //Pemilihan tujuan
    cout<<"Pilih tujuan keberangkatan:\n";
    cout<<"1) Semarang\n";
    cout<<"2) Yogyakarta\n";
    cout<<"3) Solo\n";
    cout<<"4) Madiun\n";
    cout<<"\n> ";
    selectDestination:
    nav=getch();

    switch(nav)
    {
        case '1':
            cout<<"Semarang\n\n";
            tujuan="Semarang";
            break;
        case '2':
            cout<<"Yogyakarta\n\n";
            tujuan="Yogyakarta";
            break;
        case '3':
            cout<<"Solo\n\n";
            tujuan="Solo";
            break;
        case '4':
            cout<<"Madiun\n\n";
            tujuan="Madiun";
            break;
        default:
            goto selectDestination;
    }


    //Placeholder
    //Diisi tanggal keberangkatan dan kelas kereta


    //Input data penumpang=====================================================================
    int jmlpenumpang;
    passengernumber:
    cout<<"Jumlah penumpang (max 4): ";
    cin>>jmlpenumpang;


    if(jmlpenumpang<1||jmlpenumpang>4)  //Mengecek apakah user
    {
        cout<<"Mohon masukan angka 1 sampai 4 saja!\n\n";
        goto passengernumber;           //menginput angka yang valid
    }



    //Input detail identitas penumpang
    cin.ignore();
    cout<<endl<<endl;
    for(int i=0;i<jmlpenumpang;i++)
    {
        cout<<"===[Penumpang ke-"<<i+1<<"]====\n";
        cout<<"Nama lengkap     : ";
        getline(cin,namaLengkap[i]);
        cout<<"Tipe ID (KTP/SIM): ";
        getline(cin,tipeID[i]);
        cout<<"No ID            : ";
        getline(cin,noID[i]);
        cout<<"=======================\n\n";
    }

}

void checkTicket()
{
    //Placeholder
    //
}

int main()      //Menu utama yang ditampilkan di awal
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
        case '1':
            cout<<nav<<endl<<endl;
            orderTicket();
            break;

        case '2':
            cout<<nav<<endl<<endl;
            checkTicket();
            break;

        case '3':
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
