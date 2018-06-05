/* Priority Queue for patients */
#include<iostream>
#include<string.h>
using namespace std;

class queue
{
     struct node
      {
	    int priority;
	    char name[20];
	    struct node *next;
      }*front;
 public:
   queue()
   {
	front=NULL;
   }
int isEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}
void Insert(char[10],int);
void Remove();
void Display();
};

void queue:: Insert(char N[10],int P)
{
node *temp,*prev,*newnode;

newnode=new node;
strcpy(newnode->name,N);
newnode->priority=P;
newnode->next=NULL;

if(front==NULL)
    front=newnode;
else
{
   temp=front;
   while(temp!=NULL && newnode->priority<=temp->priority)
   {
	prev=temp;
	temp=temp->next;
   }
   if(temp==front)                             //add at beg
   {
      newnode->next=front;
      front=newnode;
   }
   else                  			//add at end and in between
   {
      newnode->next=temp;
      prev->next=newnode;
   }
}
}
void queue::Remove()
{
  node *temp = front;
  front=front->next;
  switch(temp->priority)
  {
	case 1: cout<<"\tGeneral Checkup";break;
	case 2: cout<<"\tNon-serious";break;
	case 3: cout<<"\tSerious";break;
	default: cout<<"\tUnknown";
  }
    cout<<"\nPatient= "<<temp->name<<" got the treatment\n ";
  delete temp;
}
void queue::Display()
{
node *temp=front;
cout<<"\nName"<<"\tPriority";
while(temp!=NULL)
{
	cout<<"\n"<<temp->name<<"\t"<<temp->priority;
	temp=temp->next;
}
}
int main()
{
int ch,priority;
char name[20];
queue Q;
do
{
cout<<"\n1)Enqueue\n2)Dequeue\n3:Display\n4)Quit\nEnter Your choice : ";
cin>>ch;
switch(ch)
{
case 1:
	cout<<"\nname of the patient : ";
	cin>>name;
	cout<<"\npriority(1- General checkup,2- non-serious,3- serious ): ";
	cin>>priority;
	Q.Insert(name,priority);
	Q.Display();
	break;
case 2: if(!Q.isEmpty())
		Q.Remove();
	else
		cout<<"\nQueue is empty";
	break;
case 3: Q.Display();
	break;
}
}while(ch<4);
}