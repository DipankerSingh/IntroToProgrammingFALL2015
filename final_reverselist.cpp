// AIM: Implemet a linked list and reverse it

//MADE BY: DIPANKER SINGH(397/COE/14)

#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct node
{
    int data;
    node *next;
}*head,*rear;

node* createnode();
int menu(int flag);
void insert();
void del();
void display();
int underflow();
void reverse(node **head);

int main()
{
    head=rear=NULL;
    int flag=1;
    while (flag)
        flag=menu(flag);
    return 0;
}

node* createnode()
{
    node *temp;
    temp=new node;
    cin>>temp->data;
    temp->next=NULL;
    return temp;
}

int menu(int flag)
{
    system("cls");
    cout<<"1. Insert\n2. Delete\n3. Display\n4. Reverse\n5. Exit\n\nEnter: ";
    char ch;
    cin>>ch;
    switch(ch)
    {
        case '1': insert(); break;
        case '2': del(); break;
        case '3': display(); break;
        case '4': reverse(&head); break;
        case '5': flag=0; break;
    }
    return flag;
}

void insert()
{
    node *temp;
    temp=createnode();
    if (head==NULL)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

void del()
{
    if (underflow())
        cout<<"List is Empty";
    else
    {
        cout<<"Deleted Entry is: "<<head->data;
        if (head==rear)
        {
            head=NULL;
            rear=NULL;
        }
        else
            head=head->next;
    }
    getch();
}

void display()
{
    if (underflow())
        cout<<"List is empty";
    else
    {
        for (node *i=head; i!=NULL; i=i->next)
            cout<<i->data<<" ";
    }
    getch();
}

int underflow()
{
    if (head==NULL)
        return 1;
    else
        return 0;
}

void reverseutil(node *curr, node *prev, node **head)
{
    if (!curr->next)
    {
        *head=curr;
        curr->next=prev;
        return;
    }
    node *next= curr->next;
    curr->next=prev;
    reverseutil(next,curr,head);
}

void reverse(node **head)
{
    if (!head)
        return;
    reverseutil(*head, NULL, head);
}



