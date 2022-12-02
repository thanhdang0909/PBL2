#include<bits/stdc++.h>
#include<windows.h>
#include"Item.h"
using namespace std;

Item::Item()
{

}
Item::Item(string Maloaimon,string Loaimon, string Mamon, string Tenmon, long gia)
{
    this->Maloaimon = Maloaimon;
    this->Loaimon = Loaimon;
    this->Mamon = Mamon;
    this->Tenmon = Tenmon;
    this->Gia = Gia;
}

void Item::NhapMenu()
{

    cin.ignore();
    cout<<"\nNhap ma loai mon: ";
    getline(cin, this->Maloaimon);
    cout<<"\nNhap loai mon: ";
    getline(cin, this->Loaimon);
    cout<<"\nNhap ma mon: ";
    getline(cin, this->Mamon);
    cout<<"\nNhap ten mon: ";
    getline(cin, this->Tenmon);
    cout<<"\nNhap gia: ";
    cin>>this->Gia;

}
void Item::ShowMenu()
{
    cout<< setw(10) << left<< "Ma loai mon "<<" | "
        << setw(20) << left<< "Loai mon "<<" | "
        << setw(10) << left<< "Ma mon "<<" | " 
        << setw(30) << left<< "Ten mon"<<" |" 
        << setw(10) << left<< "Gia "
        << endl;

    cout<< setw(10) << left << Maloaimon<<" | "  
        << setw(20) << left << Loaimon   <<" | "
        << setw(10) << left << Mamon    <<" | "
        << setw(30) << left << Tenmon   <<" | "
        << setw(10) << left << Gia  
        <<endl;
}
void Item::NhapMenuvaoFile()
{
    this->NhapMenu();

}
void Item::CapnhatMenuvaoFile()
{
    ifstream filein;
    filein.open("Menu.txt", ios_base::in);
          


}
string Item::getMaloaimon()
{
    return this->Maloaimon;

}
string Item::getLoaimon()
{
    return this->Loaimon;

}
string Item::getMamon()
{
    return this->Mamon;

}
string Item::getTenmon()
{
    return this->Tenmon;

}
long Item::getGia()
{
    return this->Gia;
}
string Item::setMaloaimon()
{
    this->Maloaimon = Maloaimon;
}
string Item::setLoaimon()
{
    this->Loaimon = Loaimon;
}
string Item::setMamon()
{
    this->Mamon = Mamon;
}
string Item::setTenmon()
{
    this->Tenmon = Tenmon;

}
long Item::setGia()
{
    this->Gia = Gia;
}
