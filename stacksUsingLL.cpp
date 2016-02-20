//AIM: Implement a stack using linked list
//MADE BY: DIPANKER SINGH(397/COE/14)

#include<iostream>
using namespace std;
struct node
{
	int value;
	node *next;
};

class link_stack
{
	node *top;
	public:
	link_stack()
	{
		top=NULL;
	}
	node* create();
	void push();
	void pop();
	void display();
	int r_top()
	{return top->value;};
};

node* link_stack::create()
{
	node *temp;
	temp=new node;
	cout<< "Enter the value: ";
	cin>> temp->value;
	temp->next=NULL;
	return temp;
}

void link_stack::push()
{
	node *temp;
	temp= create();

	if(top==NULL)
		top= temp;
	else
	{
		temp->next=top;
		top= temp;
	}
	cout<< "Pushed successfully.....\n";
}

void link_stack::pop()
{
	node *temp;

	if(top==NULL)
		cout<< "Undeflow.....\n";
	else
	{
		temp= top;
		top= top->next;
		delete(temp);
		cout<< "Poped successfully.....\n";
	}
}

void link_stack::display()
{
	node *temp;
	temp= top;
	if(top==NULL)
		cout<< "Stack is empty.....";
	else
	{
		cout<< "Stack is:\n";
		while(temp!=NULL)
		{
			cout<< temp->value<< "\n";
			temp= temp->next;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	link_stack element;
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

