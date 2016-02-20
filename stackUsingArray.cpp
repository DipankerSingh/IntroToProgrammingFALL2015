//AIM: Implement a stack using array
// MADE BY: DIPANKER SINGH(397/COE/14)

#include<iostream>

using namespace std;

#define size 5
int arr[size];

class array_stack
{
	int top;
	public:
	array_stack()
	{
		top=-1;
	}
	void push();
	void pop();
	void display();
	int r_top()
	{return arr[top];};
};

void array_stack::push()
{
	int value;
	cout<< "Enter the value: ";
	cin>> value;
	top++;
	if(top==size)
	{
		top--;
		cout<< "Overflow.....\n";
	}
	else
	{
		arr[top]=value;
		cout<< "Pushed successfully.....\n";
	}
}

void array_stack::pop()
{
	if(top==-1)
		cout<< "Undeflow.....\n";
	else
	{
		arr[top]=-1;
		top--;
		cout<< "Poped successfully.....\n";
	}
}

void array_stack::display()
{
	if(top==-1)
		cout<< "Stack is empty.....\n";
	else
	{
		cout<< "Stack is:\n";
		for(int i=top; i>=0; i--)
			cout<< arr[i]<< "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);

	array_stack element;
	int val, result;
	cout<< "Menu:\n1. Push\n2. Pop\n3. Display\n4. Give top\n5. Exit\n";
	while(1)
	{
		cout<< "\nEnter your choice: ";
		cin>> val;
		
		if(val==1)
			element.push();
		else if(val==2)
			element.pop();
		else if(val==3)
			element.display();
		else if(val==4)
		{
			result= element.r_top();
			cout<< result<< "\n";
		}
		else
			break;
	}
	return 0;
}
