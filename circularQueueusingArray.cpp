//AIM: Implement a circular queue using array

// MADE BY: DIPANKER SINGH(397/COE/14)
	
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define size 4
int arr[size];

class cir_queue
{
	int front;
	int rear;
	public:
	cir_queue()
	{
		front=-1;
		rear=-1;
	}
	void insert();
	void del();
	void display();
	int r_rear()
	{return rear;};
	int r_front()
	{return front;};
};

void cir_queue::insert()
{
	int value;
	cout<< "Enter the value: ";
	cin>> value;
	rear++;
	rear= rear%size;
	if(front==-1)
	{
		front++;
		arr[rear]=value;
		cout<< "Inserted successfully.....\n";
	}
	else if(rear==front)
	{
		rear= (front-1+size)%size;
		cout<< "Overflow.....\n";
	}
	else
	{
		arr[rear]=value;
		cout<< "Inserted successfully.....\n";
	}
}

void cir_queue::del()
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
		front= front%size;
		cout<< "Deleted successfully.....\n";
	}
}

void cir_queue::display()
{
	if(rear==-1)
		cout<< "C.Queue is empty.....\n";
	else
	{
		cout<< "C.Queue is:\n";
		for(int i=front; i!=rear; i=(i+1)%size)
			cout<< arr[i]<< " ";
		cout<< arr[rear]<< "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);

	cir_queue element;
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
