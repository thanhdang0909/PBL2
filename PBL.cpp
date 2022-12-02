#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>

#include "Item.h"
#include "Node.h"
#include "Linkedlist.h"
#include "Order.h"
//#include "Bill.h"





using namespace std;
void drawLine();
void drawStars();
void adminMenu();
void staffMenu();
void security();
void homePage();

void createFileMenu();
void addNewItemtoFileMenu();


main()
{
//    Linkedlist a;
//    a.readFileMenu();
//    a.ShowList();

    Order A;
    A.getOrder();
//    homePage();

//    createFileMenu();
//    addNewItemtoFileMenu();

}
//dguwxq
















































void drawLine()
{
    for (int i =1; i <=50 ;i++)
    {
        cout<<"=";
    }
    cout<<endl;

}

void drawStars()
{
    for (int i = 1; i <=50; i ++)
    {
        cout<<"*";
        
    }
    cout<<endl;

}
void adminMenu()
{
    system("pause");
    system("cls");
    drawLine();
    cout<<"\t   ADMIN MENU \n";
    drawLine();
    cout<<"0. Logout \n";
    cout<<"1. Tao Menu \n";
    cout<<"2. Xem toan bo Menu\n";
    cout<<"3. Them mon moi vao Menu\n";
    cout<<"4. Sua mon trong Menu\n";
    cout<<"5. Xoa mon trong Menu\n";
    cout<<"6. Xem tong ket ban hang\n";
    cout<<"Vui long nhap lua chon cua ban: ";
}
void staffMenu()
{
    system("pause");
    system("cls");
    drawLine();
    cout<<"\t   STAFF MENU \n"; 
    drawLine();
    cout<<"0. Back to MainMenu\n";
    cout<<"1. Xem Menu\n";
    cout<<"2. Order\n";
    cout<<"Vui long nhap lua chon cua ban: ";

}
void security()
{
    char pwd[] = "password", un[] = "admin";
    char cpwd[20], uname[20];
    char ch;
    int i = 0 , chance = 1;

    retry:
        system("cls");
        drawLine();
        cout<<"\n\nNhap username: ";
        cin>>uname;

        if (strcmpi(un,uname) == 0)
        {
            cout<<"\n\nNhap Password: ";
            do
            {
                ch = _getch();
                if (ch != 13)
                {
                    cpwd[i] = ch;
                    i++;
                    cout<<"*";

                }
                else
                {
                    cpwd[i] = '\0';

                }
            }while (ch != 13);

            if (strcmp(pwd,cpwd) == 0)
            {
                cout<<"\n\nWelcome " << uname <<endl;
                system("pause");
                system("cls");

                adminMenu();
            }

            else 
            {
                cout<<"\n\n";
                cout<<"Ban da nhap sai mat khau\n\n";
                if(chance != 3)
                    cout<<"Ban con "<<3 - chance <<" lan de thu lai\n\n";
                chance++;
                system("pause");
                system("cls");


                if (chance > 3)
                {
                    cout<<"\n\n";
                    cout<<"Ban da nhap sai mat khau qua ba lan\n\n";
                    cout<<"Vui long thu lai sau\n";
                    system("pause");
                    
                }
                else
                {
                    goto retry;

                }
                system("pause");
            }
        }
        else
        {
            cout<<"\n\nUsername chua duoc dang ky\n\n";
            system("pause");
            
        }

}
void homePage()
{
    int ch;
    do
    {
        system("cls");
        drawStars();
        cout<<"\t\t H O M E P A G E \n";
        drawLine();
        cout<<"\n\n0. Exit\n\n";
        cout<<"1. Admin login\n\n";
        cout<<"2. Staff login\n\n";
        cout<<"Vui long nhap lua chon cua ban: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            security();
            break;
        case 2:
            cout<<"so 2 ne";    
            //staffMenu();
            break;

        }

    }while(ch !=0);
    
}

void createFileMenu()
{
    system("cls");
    ofstream  ofs;
    ofs.open("Menu.txt", ios::trunc);//Du lieu cu xoa het, tao moi du lieu
    if(!ofs.is_open())
    {
        cerr <<"Erorr!! Cannot open file."<<endl;
        exit(0);
    }
    else
    {
        string Maloaimon;
        string Loaimon;
        string Mamon;
        string Tenmon;
        long Gia;
        drawLine();
        cout<<"Tao moi file Menu"<<endl;
        drawLine();
        cout<<endl;
        
        int ch;
        do
        {

            cout<<"\nNhap ma loai mon: ";
            cin>>Maloaimon;
            ofs<<Maloaimon<<" ";

            cout<<"\nNhap loai mon: ";
            cin>>Loaimon;
            ofs<<Loaimon<<" ";

            cout<<"\nNha ma mon: ";
            cin>>Mamon;
            ofs<<Mamon<<" ";

            cout<<"\nNhap ten mon: ";
            cin>>Tenmon;
            ofs<<Tenmon<<" ";

            cout<<"Nhap Gia mon: ";
            cin>>Gia;
            ofs<<Gia<<"\n";

/*
            cout<<"\n\nBan vua nhap:"
            <<"\nMa loai mon: "<<Maloaimon
            <<"\nLoai mon: "<<Loaimon
            <<"\nMa mon : "<<Mamon
            <<"\nTen mon : "<<Tenmon
            <<"\nGia: "<<Gia;
*/
            
            cout<<"\n\nBan co muon tiep tuc nhap them mon khong? \n"
                <<"1.Co \n"
                <<"2.Khong \n";
            cout<<"Vui long nhap lua chon cua ban: ";
            cin>>ch;

        }while(ch == 1);

    ofs.close();
    }
}    
void addNewItemtoFileMenu()
{
    system("cls");
    ofstream  ofs;
    ofs.open("Menu.txt", ios::app);//Them du lieu vao cuoi file
    if(!ofs.is_open())
    {
        cerr <<"Erorr!! Cannot open file."<<endl;
        exit(0);
    }
    else
    {
        string Maloaimon;
        string Loaimon;
        string Mamon;
        string Tenmon;
        long Gia;
        drawLine();
        cout<<"Them mon moi vao file Menu"<<endl;
        drawLine();
        cout<<endl;
        
        int ch;
        do
        {

            cout<<"\nNhap ma loai mon: ";
            cin>>Maloaimon;
            ofs<<Maloaimon<<" ";

            cout<<"\nNhap loai mon: ";
            cin>>Loaimon;
            ofs<<Loaimon<<" ";

            cout<<"\nNha ma mon: ";
            cin>>Mamon;
            ofs<<Mamon<<" ";

            cout<<"\nNhap ten mon: ";
            cin>>Tenmon;
            ofs<<Tenmon<<" ";

            cout<<"Nhap Gia mon: ";
            cin>>Gia;
            ofs<<Gia<<"\n";


            
            cout<<"\n\nBan co muon tiep tuc nhap them mon khong? \n"
                <<"1.Co \n"
                <<"2.Khong \n";
            cout<<"Vui long nhap lua chon cua ban: ";
            cin>>ch;

        }while(ch == 1);

    ofs.close();
    }

}