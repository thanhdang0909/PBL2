#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime> 
#include "Item.h"
#include "Node.h"
#include "Linkedlist.h"
#include "Bill.h"
using namespace std;

#ifndef Order_h
#define Order_h

class Order //: public Item , public Linkedlist 
{
    private:
        friend class Bill;
        int Chietkhau;
        int Ban;
        int Tongtien;
    
    public:
        Order()
        {

        }
        
        void getOrder()
        {
            system("cls");
            ofstream  ofs;
            ofs.open("Order.txt", ios::app);//Them du lieu vao cuoi file
            if(!ofs.is_open())
            {
                cerr <<"Erorr!! Cannot open file."<<endl;
                exit(0);
            }
            else
            {
                string Mamon;
                int Soluong;

                time_t now = time(0); 
                char* t = ctime(&now);
                cout<<"\n"<<t;
                ofs<<"\n\n"<<t;

                cout<<"Nhap ma ban: ";
                cin>>this->Ban;
                ofs<<"Ban "<<this->Ban<<"\n";


                cout<<"Nhap ma mon va so luong mon: "<<endl;
                do
                {
                    cin>>Mamon;
                    ofs<<Mamon<<"\t";

                    cin>>Soluong;
                    ofs<<Soluong<<"\n";

                    Bill* newBill = new Bill(Mamon,Soluong);
                    

                }
                while (Mamon != "0" );

            }
            
        }
        
      


};

#endif