#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime> 
#include "Item.h"
#include "Node.h"
#include "Linkedlist.h"

using namespace std;

#ifndef BILL_h
#define BILL_h

class Bill  //: public Item, public Linkedlist
{
    private:
        Linkedlist<Item> listMamon;
        Linkedlist<int> listSoluong;
        
    public:
        Bill()
        {
            listMamon.Mamon = NULL;

        }
        void getBill(string Mamon, int Soluong)
        {
            listMamon->Mamon = Mamon;
            
            listSoluong = Soluong;

            listMamon = listMamon->next;
            listSoluong = listSoluong->next;
            
        }
/*
        Bill(string listMamon, int listSoluong)
        {
            this->listMamon = listMamon;
            this->listSoluong = listSoluong;
        }
        string getlistMamon(string listMamon)
        {
            return this->listMamon;
        }
        int  getlistSoluong(int listSoluong)
        {
            return this->listSoluong;
        }
        void setlistMamon(string listMamon)
        {
            this->listMamon = listMamon;

        }
        void setlistSoluong(int listSoluong)
        {
            this->listSoluong = listSoluong;

        }

*/   
        
};

#endif