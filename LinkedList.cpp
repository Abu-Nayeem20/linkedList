#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node * nxt;
};

class LinkedList
{
public:
    node * head;

    LinkedList()
    {
        head = NULL;
    }

    // Create new node with data and next
    node* CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;

        return newnode;
    }

    // Insert new value at head
    void InsertAtHead(int value)
    {
        node *a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        a->nxt = head;
        head = a;
    }

    // Insert new value at head

    void InsertAtLast(int value)
    {
        if(head == NULL)
        {
            InsertAtHead(value);
        }
        else
        {
            node *a = CreateNewNode(value);
            node *temp = head;
            while(temp->nxt != NULL)
            {
                temp = temp->nxt;
            }
            temp->nxt = a;
        }

    }

    // Print the linked list
    void Traverse()
    {
        node* a = head;

        while(a != NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    // Delete At Head
    void DeleteAtHead()
    {
        if(head == NULL)
        {
            return;
        }
        node *a = head;
        head = a->nxt;
        delete a;
    }

    // Delete Last Element

    void DeleteLastValue()
    {
        if(head == NULL)
        {
            return;
        }
        node *a = head;
        if(a->nxt == NULL)
        {
            delete a;
            return;
        }

        node *snd_last = head;
        while(snd_last->nxt->nxt != NULL)
        {
            snd_last = snd_last->nxt;
        }
        delete (snd_last->nxt);

        snd_last->nxt = NULL;
    }

    // Get Value by Index

    int getValueByIndex(int index)
    {
        node *a = head;
        int countt = 0;
        while(a != NULL)
        {
            if(countt == index)
            {
                return (a->data);
            }
            countt++;
            a = a->nxt;
        }

    }

    // Check Value Available or Not

    bool checkExistence(int value)
    {
        node *a = head;
        while(a != NULL)
        {
            if(a->data == value)
            {
                return 1;
            }
            a = a->nxt;
        }
        return 0;
    }



};

int main()
{
    LinkedList l;

    l.InsertAtHead(5);
    l.InsertAtHead(4);
    l.InsertAtHead(3);
    l.InsertAtHead(2);
    l.InsertAtHead(1);

    //l.DeleteAtHead();

    l.Traverse();


    l.InsertAtHead(0);

    l.Traverse();

    cout<<"nth index value is: "<<l.getValueByIndex(4)<<"\n";

    //l.DeleteAtHead();
    //l.DeleteLastValue();
    l.InsertAtLast(60);
    l.Traverse();

    if(l.checkExistence(10))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }


    return 0;
}
