void Hotel::update()
{
    cout<<"\n--------Hotel Manager System-------------";
    int t_id;
    if(head == NULL)
    {
        cout<<"\n\n Linked list is Empty";

    }
    else
    {
        cout<<"\n\nRoom ID: ";
        cin>>t_id;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (t_id  == ptr->id)
            {
                cout<<"\n\nRoom ID: ";
                cin>>ptr->id;

                cout<<"\n\nCustomer Name: ";
                cin>>ptr->name;

                cout<<"\n\nAllocated Date : ";
                cin>>ptr->date;

                cout<<"\n\nRoon Type : ";
                cin>>ptr->roomtype;

                cout<<"\n\n\t Update Record Successfully ";
            }
            ptr = ptr->next;
        }
    }
    
}    
void Hotel::del()
{
    cout<<"\n--------Hotel Manager System-------------";
    int t_id;
    if(head == NULL)
    {
        cout<<"\n\n Linked list is Empty";

    }
    else
    {
        cout<<"\n\nRoom ID: ";
        cin>>t_id;
        if (i_id ==8un k head->id)
        {
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout<<"Delete Room Record Successfully. \n";
        }
        else
        {
            Node* pre = head;
            Node* ptr = head;
            while (ptr != NULL)
            {
                if ( t_id == ptr-> id)
                {
                    pte->next = ptr->next;
                    delete ptr;
                    cout<<" Delete Room Record Successfully. \n";
                    break;

                }
            }
            pre = ptr;
            ptr = ptr->next;


        }

    }
}    
void Hotel::show()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout<<"\nRoomID: "<<ptr->id;

        cout<<"\n\nCustomer Name: "<<ptr->name

        cout<<"\n\nAllocated Date : "<<ptr->date;

        cout<<"\n\nRoom Type : "<<ptr->roomtype;
        ptr = ptr->next;
    }
}
void Hotel::sort()
{
    if(head == NULL)
    {
        cout<<"\n\n Linked list is Empty";
        menu();

    }
    int count = 0 , t_date, t_id;
    string t_name, t_roomtype;
    Node *ptr = head;
    while( ptr != NULL)
    {
        count++;
        ptr = ptr->next;

    }
    for(int i =1;i <count;i++)
    {
        Node *ptr = head;
        for (int j =1; j< count; j++)
        {
            if (ptr->id >  ptr->next->id)
            {
                t_id  = ptr->id;
                t_name  = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->roomtype;

                ptr->id = ptr->next->id;
                ptr->name  = ptr->next->id;
                ptr-> = ptr->next->id;
                ptr->id = ptr->next->id;

                
            }
        }
    }

}