//AIM: Implement a doubly linked list and traverse it in both directions

// MADE BY: DIPANKER SINGH(397/COE/14)

#include<iostream>

using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;

}*head,*rear;

node* createnode();
void insert();
void del();
void display();
void displayfwd();
void displaybwd();


int main()
{
	head=rear=NULL;
	int val, result;
	cout<< "Menu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
	while(1)
	{
		cout<< "\nEnter your choice: ";
		cin>> val;

		if(val==1)
			insert();
		else if(val==2)
			del();
		else if(val==3)
			display();
		else
			break;
	}

	return 0;
}

node* createnode()
{
	node *temp;
	temp=new node;
	cout<< "Enter the value: ";
	cin>>temp->data;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
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
		temp->prev=rear;
		rear=temp;
	}
	cout<< "\nInserted successfully...\n";
}

void del()
{
	if (head==NULL)
		cout<<"Underflow...";
	else
	{
		if (head==rear)
		{
			head=NULL;
			rear=NULL;
		}
		else
		{
			head->next->prev=NULL;
			head=head->next;
		}
	}
	cout<< "\nDeleted successfully...\n";
}

void display()
{
	cout<<"\nDisplay Menu:\n1. Forward\n2. Backward\n3. Exit\n\nEnter your choice for display: ";
	char ch;
	cin>>ch;
	switch(ch)
	{
		case '1': displayfwd(); break;
		case '2': displaybwd(); break;
		case '3': break;
	}
	cout<< "\n";
}

void displayfwd()
{
	if (head==NULL)
		cout<<"Underflow...";
	else
	{
		for (node *i=head; i!=NULL; i=i->next)
			cout<<i->data<<" ";
	}
}

void displaybwd()
{
	if (head==NULL)
		cout<<"Underflow...";
	else
	{
		for (node *i=rear; i!=NULL; i=i->prev)
			cout<<i->data<<" ";
	}
}



