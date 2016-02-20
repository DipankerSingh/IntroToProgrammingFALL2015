// AIM: Implement a queue using array

// MADE BY: DIPANKER SINGH(397/COE/14)
	
#include<bits/stdc++.h>

using namespace std;

#define size 5
int arr[size];

class array_queue
{
	int front;
	int rear;
	public:
	array_queue()
	{
		front=-1;
		rear=-1;
	}
	void insert();
	void del();
	void display();
	int r_rear()
	{
        return arr[rear];
    };
	int r_front()
	{
	    return arr[front];
    };
};

void array_queue::insert()
{
	int value;
	cout<< "Enter the value: ";
	cin>> value;
	if(rear==-1)
	{
		front++;
		rear++;
		arr[rear]=value;
		cout<< "Inserted successfully.....\n";
	}
	else if(rear==size-1)
		cout<< "Overflow.....\n";
	else
	{
		rear++;
		arr[rear]=value;
		cout<< "Inserted successfully.....\n";
	}
}

void array_queue::del()
{
	if(rear==-1)
		cout<< "Undeflow.....\n";
	else if(front==rear)
	{
		arr[front]=-1;
		rear=-1;
		front=-1;
		cout<< "Deleted successfully.....\n";
	}
	else
	{
		arr[front]=-1;
		front++;
		cout<< "Deleted successfully.....\n";
	}
}

void array_queue::display()
{
	if(rear==-1)
		cout<< "Queue is empty.....\n";
	else
	{
		cout<< "Queue is:\n";
		for(int i=front; i<=rear; i++)
			cout<< arr[i]<< " ";
	}
}


int main()
{
	ios::sync_with_stdio(false);

	array_queue element;
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
