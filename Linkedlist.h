#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include "Item.h"
#include "Node.h"
using namespace std;
// Linked list class to implement a linked list.
#ifndef Linkedlist_h
#define Linkedlist_h

template<class T>
class Linkedlist 
{
    private:
        int size;
        Node<T>* head;
        Node<T>* tail;

    public:

        Linkedlist<T>() 
        { 
            this->head = NULL; 
            this->tail = NULL;
            
        } 
        ~Linkedlist()
        {
            while (this->head != NULL) 
            { 
		        Node<T>* temp = this->head;
		        this->head = this->head->next;
		        temp->next = NULL;
		        delete temp;
	        }
            
        }
        int getSize()
        {
            int d= 0;
            Node<T>* node = this->head;
            while (node != NULL)
            {
                d++;
                node = node->next;
            }
            return d;
            

        }
        void AddHead(Node<T>*  node)
        {

            if(this->head == NULL)
            {
                this->head = node;
                this->tail = node;
            }
            else
            {

                node->next = this->head;
                this->head = node;
                
            }
        }
        void AddTail(Node<T>*  node)
        {
            if (this->head == NULL)
            {
                this->head =node ;
                this->tail =node;
            }
            else
            {
                this->tail->next =node;
                this->tail =node;
            }

        }
        void pushBack(const T &data)
        {
	        Node<T>* newNode = new Node<T>(data); 
            if(this->head == NULL) 
            {
                newNode->next=NULL;
                this->head = newNode;
            } 
            else 
            {
                T* temp = this->head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }   
                temp->next = newNode;    

            }    
        }
        
        void readFileMenu()
        {
            ifstream ifs;
            ifs.open("Menu.txt", ios::in);
            if(!ifs)
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
                while ( !ifs.eof())
                {
                   
                    ifs >> Maloaimon;
                    cout<<Maloaimon<<"\t";

                    ifs >> Loaimon;
                    cout<<Loaimon<<"\t";

                    ifs >> Mamon;
                    cout<<Mamon<<"\t";

                    ifs >> Tenmon;
                    cout<<Tenmon<<"\t";

                    ifs >> Gia;
                    cout<<Gia<<"\n";

                    Item* newIt = new Item(Maloaimon,Loaimon,Mamon,Tenmon,Gia);
                    this->pushBack(*newIt);
                    
                }

            }

            ifs.close();
            
        }
        void ShowList()
        {
            
            Node<T> *temp = this->head;
            if (head == NULL)
            {
                cout<<"List Empty! "<<endl;
            }
            else
            {
                cout<< setw(20) << left<< "Ma loai mon "<<" | "
                    << setw(40) << left<< "Loai mon "<<" | "
                    << setw(20) << left<< "Ma mon "<<" | " 
                    << setw(40) << left<< "Ten mon"<<" | " 
                    << setw(10) << left<< "Gia "
                    << endl;
                while (temp != NULL)
                {
                    
                    temp->ShowMenu();
                    temp = temp->next;
                
                }

            }
            
            
        }
        void insertNode(Node<T>* node, int index)
        {
            if (this->head  == NULL || index < 1 )
            {
                node->next = this->head;
                this->head = node;
                if (this->tail == NULL) 
                {
                    this->tail = node;

                }
                this->size++;
                return;

            }
            if (index >= this->size) 
            {		
                this->tail->next = node;
		        this->tail = node;
		        this->size++;
		        return;
	        }
            Node<T>* preNode = NULL;
            Node<T>* temp = this->head;
	        int pos = 0;
	        while (pos < index) 
            {
		        pos++; 
		        preNode = temp;
		        temp = temp->next;
	        }
	        node->next = temp;
	        preNode->next = node;
	        this->size++;
        }
//        void deleteNode();
        

        Node<T>* searchNode(const T &data)
        {
            Node<T>* node = head ;
            while (node != NULL && *node->data != data )
            
            {
                node = node->next;
            }
            if(node != NULL) return node;
            
            return NULL;
            
        }
        


        


         

};

#endif


