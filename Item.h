#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>
using  namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item
{
    public:
        string Maloaimon;
        string Loaimon;
        string Mamon;
        string Tenmon;
        long Gia;
    public:
        Item()
        {

        }
        Item(string Maloaimon,string Loaimon, string Mamon, string Tenmon, long Gia)
        {
            this->Maloaimon = Maloaimon;
            this->Loaimon = Loaimon;
            this->Mamon = Mamon;
            this->Tenmon = Tenmon;
            this->Gia = Gia;
        }
        

        void NhapMenu()
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
        
        void NhapMenuvaoFile()
        {
            ofstream ofs;
            ofs.open("Menu.txt",ios::out | ios::app);
            if(!ofs)
            {
                cerr <<"Erorr!! Cannot open file."<<endl;
                exit(0);
            }
            else
            {
                ofs <<this->Maloaimon<<" "
                    <<this->Loaimon<<" "
                    <<this->Mamon<<" "
                    <<this->Tenmon<<" "
                    <<this->Gia<<endl;
            }
            ofs.close();

        }
        long getGiatuMamon(string Mamon)
        {
            return this->Gia;
        }
        string getMaloaimon()
        {
            return this->Maloaimon;
        }
        string getLoaimon()
        {
            return this->Loaimon;
        }
        string getMamon()
        {
            return this->Mamon;
        }
        string getTenmon()
        {
            return this->Tenmon;
        }
        long getGia()
        {
            return this->Gia;
        }
        void setMaloaimon()
        {
            this->Maloaimon = Maloaimon;
        }
        void setLoaimon()
        {
            this->Loaimon = Loaimon;
        }
        void setMamon()
        {
            this->Maloaimon = Maloaimon;
        }
        void setTenmon()
        {
            this->Tenmon = Tenmon;
        }
        void setGia()
        {
            this->Gia = Gia;
        }

};
#endif