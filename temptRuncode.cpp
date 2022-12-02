


















/*
void ShowMenu();
void Order();
void EnterSpending();
void Admin(); 
void Menu()
{
    int stop;
    do
    {
    
        HomePage();
        cin>>stop;
        switch (stop)
        {
        case 1:
            MenuAdmin();
            break;
        case 2:
            MenuStaff();
            int stopStaff;
            switch (stopStaff)
            {
            case 1:
                ShowMenu();
                break;
            case 2:
                Order();
                break;
            case 3:
                EnterSpending();
            default:
                cout<<"Press any key to continue. . .";
                break;
            }
            break;
        default:
            exit;
            break;
        }

    } while (!stop);
    

}


void HomePage()
{
    cout<<"*************************************************\n";
    cout<<"                   H O M E P A G E               \n";
    cout<<"=================================================\n\n";
    cout<<"0. Exit\n";
    cout<<"1. Admin login\n";
    cout<<"2. Staff login\n";
    cout<<"Enter your choice: ";
}
void MenuAdmin()
{
    cout<<"*************************************************\n";
    cout<<"                     ADMIN PAGE                  \n";
    cout<<"=================================================\n\n";
    cout<<"0. Log out \n";
    cout<<"1. Create New File Menu\n";
    cout<<"2. Add new Product \n";
    cout<<"3. Show all Menu\n";
    cout<<"4. Edit Product\n";
    cout<<"5. Remove Product from Menu\n";
    cout<<"6. Search Product\n";
    cout<<"7. Create New File OderType\n";
    cout<<"8. View Spending\n";
    cout<<"9. View total business\n";

}
void MenuStaff()
{
    cout<<"*************************************************\n";
    cout<<"                     STAFF PAGE                  \n";
    cout<<"=================================================\n\n";
    cout<<"0. Back to Home page \n";
    cout<<"1. Show Menu \n";
    cout<<"2. Order\n";
    cout<<"3. Enter Spending\n";
    cout<<"Enter your choice: ";
}
void ShowMenu()
{

}
void Order()
{

}
void EnterSpending()
{

}
void Admin()
{
    char username, password;
    cout<<"Enter Usename: ";
    cin>>username;

    cout<<"Enter Password";
    cin>>password;
    if (username == 'admin' && password == '123456')
    {
        cout<<"Welcom Admin!!";
        cout<<"Press any key to continue...";
        cin.ignore(1000000000, '\n');
        

    }
}
*


#include <bits/stdc++.h> 
#include <ctime> 
using namespace std; 
int main( ) 
{   
     time_t now = time(0);
   
   // convert sang string
   char* dt = ctime(&now);

   cout << "The current local date and time is: " << dt << endl;
/*
    // chuyen doi hientai thanh dang tm struct cho UTC 
    tm *gmtm = gmtime(&hientai); 
    dt = asctime(gmtm); 
    cout << "UTC date va time la: "<< dt << endl; 

*/    

#include <iostream> 
#include <ctime> 
using namespace std; 
int main( ) 
{ 
    // tra ve date/time hien tai dua tren system hien tai 
    time_t baygio = time(0); 
    cout << "So giay ke tu 1/1/1970 la: " << baygio << endl; 
    tm *ltm = localtime(&baygio); 
    // in cac thanh phan cua cau truc tm struct. 
    cout << "Nam: "<< 1900 + ltm->tm_year << endl; 
    cout << "Thang: "<< 1 + ltm->tm_mon<< endl; 
    cout << "Ngay: "<< ltm->tm_mday << endl; 
    cout << "Thoi gian: "<< 1 + ltm->tm_hour << ":"; 
    cout << 1 + ltm->tm_min << ":"; 
    cout << 1 + ltm->tm_sec << endl;
}