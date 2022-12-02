
#include "Item.h"
using namespace std;

#ifndef Node_h
#define Node_h

template<typename T> 
class Node 
{
    public:
        T data;
        Node<T>* next;
    
    public:
        Node<T>(const T &data)
        {
            this->data = data;
            this->next = NULL;
        }
        ~Node()
        {
            if (this->next = NULL )
            {
                delete this->next;
            }
        }

        void CreateNode(const T &data)
        {
            this->data = data ;
            this->next = NULL;
        }

        void ShowMenu()
        {
            
            Item It = this->It;
            cout<< setw(20) << left << It.Maloaimon<<" | "  
                << setw(40) << left << It.Loaimon   <<" | "
                << setw(20) << left << It.Mamon    <<" | "
                << setw(40) << left << It.Tenmon   <<" | "
                << setw(10) << left << It.Gia  
                <<endl;
        }
        
};
#endif  

