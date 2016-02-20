// AIM: Implement a queue using linked list
// MADE BY: DIPANKER SINGH(397/COE/14)

#include<bits/stdc++.h>

using namespace std;

struct node
{
	int value;
	node *next;
};

class link_queue
{
	node *front, *rear;
	public:
	link_queue()
	{
		front=NULL;
		rear=NULL;
	}
	node* create();
	void insert();
	void del();
	void display();
	int r_front()
	{return front->value;};
	int r_rear()
	{return rear->value;};
};

node* link_queue::create()
{
	node *temp;
	temp=new node;
	cout<< "Enter the value: ";
	cin>> temp->value;
	temp->next=NULL;
	return temp;
}

void link_queue::insert()
{
	node *temp;
	temp= create();

	if(rear==NULL)
	{
		rear= temp;
		front= temp;
	}
	else
	{
		rear->next=temp;
		rear= temp;
	}
	cout<< "Inserted successfully.....\n";
}

void link_queue::del()
{
	node *temp;

	if(rear==NULL)
		cout<< "Undeflow.....\n";
	else if(front==rear)
	{
		temp= front;
		front= NULL;
		rear= NULL;
		delete(temp);
		cout<< "Deleted successfully.....\n";
	}
	else
	{
		temp= front;
		front= front->next;
		delete(temp);
		cout<< "Deleted successfully.....\n";
	}
}

void link_queue::display()
{
	node *temp;
	temp= front;
	if(rear==NULL)
		cout<< "Queue is empty.....";
	else
	{
		cout<< "Queue is:\n";
		while(temp!=NULL)
		{
			cout<< temp->value<< " ";
			temp= temp->next;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	link_queue element;
	int val, result;
	cout<< "Menu:\n1. Insert\n2. Delete\n3. Display\n4. Give front\n5. Give rear\n6. Exit\n";
	while(1)
	{
		cout<< "\nEnter your choice: ";
		cin>> val;
		
		if(val==1)
			element.insert();
		else if(val==2)
			element.del();
		else if(val==3)
			element.display();
		else if(val==4)
		{
			result= element.r_front();
			cout<< result<< "\n";
		}
		else if(val==5)
		{
			result= element.r_rear();
			cout<< result<< "\n";
		}
		else
			break;
	}
	return 0;
}

