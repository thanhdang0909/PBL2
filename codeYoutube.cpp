
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>


//#include "Node.h"
//#include "Linkedlist.h"
using namespace std;


class Items;
class Bill;
class billDetails;

//Global function
void addNewItem();
void showMenu();
float getPriceFromFile(int);
char *getNameFromeFile(int);
int generateBillNo();
void headingOrderDetails();
void getOrderDetails();
void placeOrder();


//Menu Function
void adminMenu();
void guestMenu();
void security();
void project();

//Decor Function
void drawLine();
void drawStars();


class Items
{
    protected:
        int ID;
//        char ID[5];
        char Loaimon[10];
        char id[5];
        char name[20];
        float price;
    public:
        int getID()
        {
            return ID;
        }
        float getPrime()
        {
            return price;
        }
        char *getName()
        {
            return name;
        }
        void addItem();
        void showItem();
        void listItem();
}obj_i;


class Bill
{
    protected:
        int billNo;
    public:
        Bill()
        {
            billNo = 0;
        }
        int getBillNo()
        {
            return billNo;
        }
        void setBillNo(int b)
        {
            billNo = b;
        }
}obj_b;



class billDetails: public Bill, public Items
{
    protected:
        int qty;
        float amt;
    public:
        void setOrder(int, int , char[], float, int );
        void listBillDetails();
        float getAmount()
        {
            return amt;
        }
};
 
void Items::addItem()
{
    cout<<"Add Item Details\n";
    cout<<"Item ID:"; cin>>ID;
    cout<<"Item Name: "; cin>>name;
    cout<<"Item Price: ";cin>>price;

}

void Items::showItem()
{
    cout<<"Item Details\n";
    cout<<"Item ID: "<< ID <<endl;
    cout<<"Item Name: "<<name<<endl;
    cout<<"Item Price: "<<price<<endl;
    cout<<endl;
}

void Items::listItem()
{
    cout.setf(ios::left);
    cout<<setw(8)<<ID
        <<setw(25)<<name
        <<setw(12)<<price
        <<endl;

}

void billDetails::setOrder(int b, int i, char nm[], float p, int q)
{
    billNo=b;
    ID = i;
    strcpy(name, nm);
    price = p;
    qty = q;
    amt = price *qty;
}



void billDetails::listBillDetails()
{
    cout.setf(ios::left);
    cout<<setw(5)<<ID
        <<setw(20)<<name
        <<setw(10)<<price
        <<setw(8)<<qty
        <<setw(12)<<amt
        <<endl;

}



void addNewItem()
{
    ofstream fout;
    fout.open("Items.dat",ios::app);
    obj_i.addItem();
    fout.write( (char*)&obj_i , sizeof(obj_i));
    fout.close();

}
void showMenu()
{
    int count = 0;
    ifstream fin;
    fin.open("items.dat",ios::in);

    while ( fin.read( (char*)&obj_i, sizeof(obj_i) ) )
    {
        if(count < 1 )
        {
            cout.setf(ios::left);
            cout<<setw(8)<<"Items ID"
                <<setw(25)<<"Product Name"
                <<setw(12)<<"Rate";

        }
        obj_i.listItem();
        count++;

    }
    fin.close();
}

float getPriceFromFile(int n)
{
    int ID = n;
    float r = 0;
    ifstream fin;
    fin.open("items.dat",ios::in) ;
    while( fin.read( (char*)&obj_i, sizeof(obj_i) ) )
    {
        if ( ID== obj_i.getID() )
        {
            r = obj_i.getPrime();
        }
    }
    fin.close();
    return r;
}
char *getNameFromeFile(int n)
{
    int ID = n;
    char nm[20] = "none";
    ifstream fin("items.dat",ios::in) ;
    while( fin.read( (char*)&obj_i, sizeof(obj_i) ) )
    {
        if ( n == obj_i.getID())
        {
            strcpy(nm,obj_i.getName() );

        }
    }
    fin.close();
    return nm;
}


int generateBillNo()
{
    Bill b;
    int n = 0;
    ifstream fin("bill.dat", ios::in|ios::binary);
    while( fin.read( (char*)&b, sizeof(b) ) )
    {
        n = b.getBillNo();

    }
    fin.close();


    if ( n == 0 ) n =1;
    else n +=1 ;
    //thay luon  n+=1 tu dau thu;

    b.setBillNo(n);
    ofstream fout("bill.dat", ios::out|ios::app|ios::binary);
    fout.write( (char*)&b, sizeof(b) );
    fout.close();
    return n;
}
void headingOrderDetails()
{
    cout.setf(ios::left);
    cout<<setw(5)<<"No."
        <<setw(5)<<"ID"
        <<setw(20)<<"Product Name"
        <<setw(5)<<"Price"
        <<setw(5)<<"Qty."
        <<setw(5)<<"Amount"
        <<endl;

}
void getOrderDetails(int bn)
{
    billDetails ord;
    float total = 0;
    int no = 1;
    ifstream fin;
    fin.open("orders.dat");
    while ( fin.read( (char*)&ord, sizeof(ord) ) )
    {
        if ( bn == ord.getBillNo() )
        {
            cout.setf(ios::left);
            cout<<setw(5)<<no++;
            ord.listBillDetails();
            total += ord.getAmount();

        }
    }
    cout.setf(ios::left);
    cout<<setw(40)<<" "
        <<setw(8)<<"Total:  "
        <<setw(12)<<total
        <<endl;

}


void placeOrder()
{
    billDetails ord;
    int bn, n , qt;
    char itemName[20];
    float orderTotal = 0;
    bn = generateBillNo();

    ofstream fout("orders.dat" , ios::app);
    do
    {
        
        system("cls");
        cout<<"0.End Order and Exit\n";
        showMenu();
        cout<<"Enter item ID ";
        cin>>n;
        if ( n == 0)
        {
            goto out;
        }
            
        cout<<"Order for ID: "<<n<<" : "<<getNameFromeFile(n)<<" @RS. "<<getPriceFromFile(n)<<endl;
        cout<<"Enter Qty: ";
        cin>>qt;

        ord.setOrder(bn,n,getNameFromeFile(n), getPriceFromFile(n), qt);

        fout.write( (char*)&ord , sizeof(ord) );



    } while ( n != 0);
    out:
    fout.close();
    cout<<"End of Order file...\n";
    

    headingOrderDetails();
    getOrderDetails(bn);
}

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
    int ch;
    do 
    {
        system("cls");
        drawLine();
        cout<<"\t   ADMIN MENU \n";
        drawLine();
        cout<<"0. Logout \n";
        cout<<"1. Add new Product \n";
        cout<<"2. Show all Menu\n";
        cout<<"3. Modify Product\n";
        cout<<"4. Remove Product from Menu\n";
        cout<<"5. Search Product\n";
        cout<<"6. View out of stock products\n";
        cout<<"7. Restar the products service\n";
        cout<<"8. View order details\n";
        cout<<"9. View total business\n";
        cout<<"10. View Product wise details\n";
        cout<<"Enter your choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            addNewItem();
            break;
        case 2:
            showMenu();
            break;
        case 3:
            break;

        case 4:
            break;


        case 5:
            break;

        
        case 6:
            break;

        
        case 7:
            break;
        
        case 8:
            break;


        case 9:
            break;
        
        case 10:
            break;
        }
        system("pause");

//        default:
//x            break;

    }while(ch !=0 );

}



void guestMenu()
{
    int ch;
    do
    {
        system("cls");
        drawLine();
        cout<<"\t   GUESY MENU \n";
        drawLine();
        cout<<"0. Back to MainMenu\n";
        cout<<"1. View Product Menu\n";
        cout<<"2. Place Order\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            showMenu();
            break;
        case 2:
            placeOrder();
            break;
            
//        default:
//            break;
        }
        system("pause");

    }while ( ch !=0);
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
        cout<<"\n\nEnter username: ";
        cin>>uname;

        if (strcmpi(un,uname) == 0)
        {
            cout<<"\n\nEnter Password: ";
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
            }while (ch !=13);

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
                cout<<"Password does not match...\n\n";
                cout<<chance<<" used of 3 chance...\n";
                chance++;
                system("pause");
                system("cls");

                if (chance > 3)
                {
                    cout<<"\n\n";
                    cout<<"Unauthorized access attempt\n\n";
                    cout<<"Not an registterd username...\n\n";
                    system("pause");
                    exit(0);
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
            cout<<"\n\n";
            cout<<"\n\nUnauthorized access attempt\n\n";
            cout<<"Not an registred username...\n\n";
        }
}
void project()
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
        cout<<"2. Guest Checkin\n\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            security();
            break;
        case 2:
            guestMenu();
            break;
//        default:
//            break;
        }
    }while(ch !=0);

}
// Driver Code
int main()
{
    project();
}
