#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
int data;
node *left,*right;
};

class tree
{
	node *root;
public:
	void create();
	void insert();
	void PreTrav(node*);
	int Search(int);
	int Rsearch(node*,int);
	void DFS();
	void RDFS(node*);
	void BFS();
	void RBFS(node*);
	node *R_mir(node*);
	void mirror();
	void Delete(int);
	node *return_root()
	{
		return root;
	}
};

void tree::create()
{
char op;
node *newnode,*temp;
do
{
   newnode=new node;
   cout<<"Enter data: ";
   cin>>newnode->data;
   newnode->left=newnode->right=NULL;

   if(root==NULL)
      root=newnode;
   else
     {
      temp=root;
while(1)
{
    if(newnode->data<temp->data)
    {
       if(temp->left==NULL)
       {
	  temp->left=newnode;
	  break;
       }
       else
	  temp=temp->left;
    }
    else
    {
       if(temp->right==NULL)
       {
	  temp->right=newnode;
	  break;
       }
       else
	  temp=temp->right;
    }
}//while
}
cout<<"\nAdd More...(Y/N)\n";
cin>>op;
}while(op=='y');
}

void tree::insert()
{
node *newnode,*temp;
   newnode=new node;
   cout<<"Enter data: ";
   cin>>newnode->data;
   newnode->left=newnode->right=NULL;

   if(root==NULL)
      root=newnode;
   else
     {
      temp=root;
while(1)
{
    if(newnode->data<temp->data)
    {
       if(temp->left==NULL)
       {
	  temp->left=newnode;
	  break;
       }
       else
	  temp=temp->left;
    }
    else
    {
       if(temp->right==NULL)
       {
	  temp->right=newnode;
	  break;
       }
       else
	  temp=temp->right;
    }
}//while
}
}

void tree::PreTrav(node *temp)
{
if(temp!=NULL)
{
	cout<<"\t"<<temp->data;
	PreTrav(temp->left);
	PreTrav(temp->right);
}
}


//Non Recursive Search
int tree::Search(int key)
{
int Flag=0;
node *temp=root;
  while(temp!=NULL)
      {
	if(key<temp->data)
	 temp=temp->left;
	else if(key>temp->data)
	      temp=temp->right;
	     else
	     {
		Flag=1;
		break;
	     }
       }
return Flag;
}


//Recursive Search
int tree::Rsearch(node *temp, int key)
{
static int Flag=0;
if(temp!=NULL)
{
if(key==temp->data)
 {
	Flag=1;
	return Flag;
 }
else if(key<temp->data)
	Rsearch(temp->left,key);
else if(key>temp->data)
	Rsearch(temp->right,key);
else
	return -1;
}
}
//Depth First Search Non Recursive
void tree::DFS()
{
node *Stack[20],*temp=root;
int Top=0;
while(Top>=0)
{
	while(temp!=NULL)
	{
		cout<<"\t"<<temp->data;
		Stack[Top++]=temp;
		temp=temp->left;
	}
	temp=Stack[--Top];
	temp=temp->right;
}
}


//Depth First Search Recursive
void tree::RDFS(node *temp)
{
if(temp!=NULL)
 {
   cout<<"\t"<<temp->data;
   RDFS(temp->left);
   RDFS(temp->right);
 }
}


//Breath First Search Non Recursive(Levelwise Display)
//Count Number of Node,No of Leaf Node & Height of the tree
void tree::BFS()
{
node *Queue[20],*temp=root;
int Front=0,Rear=1,Level=-1,Count=0,Leaf=0;

if(temp==NULL)
	cout<<"\nEmpty tree";

else
{
	Queue[0]=temp;
	Queue[1]=NULL;

cout<<"\nLevel "<<++Level;

do
 {
  temp=Queue[Front++];
  if(temp==NULL)
   {
	  Queue[++Rear]=NULL;
	  cout<<"\nLevel "<<++Level;
   }
  else
   {
     Count++;//Total Number of Nodes in a tree
     cout<<" "<<temp->data<<" ";

     if(temp->left!=NULL)
	  Queue[++Rear]=temp->left;

     if(temp->right!=NULL)
	 Queue[++Rear]=temp->right;

     else if(temp->right==NULL && temp->left==NULL)
	    Leaf++;//Number of Leaf Nodes
    }
 }while(Front<Rear);
}
cout<<"\n Height of tree: "<<Level-1<<"\n Total No of Nodes: "<<Count<<"\n Number of leaf Nodes: "<<Leaf;

}

//Breath First Search  Recursive
void tree::RBFS(node *temp)
{
static int Front=0,Rear=0;
static node *Queue[10];
if(Front<=Rear)
 {
   cout<<" "<<temp->data<<" ";
   if(temp->left!=NULL)
	Queue[Rear++]=temp->left;
   if(temp->right!=NULL)
	Queue[Rear++]=temp->right;
   temp=Queue[Front++];
   RBFS(temp);
 }
}

//Display Mirror image of tree Non Recursive
void mirror()
{
node *Queue[20],*temp;
int Front=0,Rear=1;
Queue[0]=root;
Queue[1]= NULL;

while(Front<Rear)
 {
  temp=Queue[Front++];
  if(temp==NULL)
   {
    cout<<"\n";
    Queue[++Rear]=NULL;
   }
  else
   {
     cout<<temp->data;
     if(temp->right!=NULL)
	 Queue[++Rear]=temp->right;
     if(temp->left!=NULL)
	 Queue[++Rear]=temp->left;
    }
 }
}

//Mirror Image Recursive
node * R_mir( node *temp)
{
node *temp1;
if(temp!=NULL)
 {
   temp1=temp->left;
   temp->left=temp->right;
   temp->right=temp1;

   if(temp->left!=NULL)
	 R_mir(temp->left);
   if(temp->right!=NULL)
	 R_mir(temp->right);
 }
 return temp;
}

//Delete Node
void tree::Delete(int key)
{
node *Stack[10],*ptree=root,*tree=root,*Rtree,*temp;
char Flag;

while(tree->data!=key &&tree!=NULL)
   {
      if(key>tree->data)
       {
		 ptree=tree;
		 Flag='R';
		 tree=tree->right;
       }
      else
       {
		ptree=tree;
		Flag='L';
		tree=tree->left;
	}
    }//while

if(tree!=NULL)
{
 if(tree->left==NULL && tree->right==NULL)
  {
   if(root==tree)
	root=NULL;
   if(Flag=='R')
	ptree->right=NULL;
   else
	ptree->left=NULL;
  }


 else // delete Node with left and right children
  if(tree->left!=NULL && tree->right!=NULL)
   {
     Rtree=temp=tree->right;
     while(temp->left!=NULL)
      {
	Rtree=temp;
	temp=temp->left;
      }
    Rtree->left=temp->right;
    if(root==tree)
     root=temp;
   else if(Flag=='L')
	ptree->left=temp;
   else if(Flag=='R')
	ptree->right=temp;
   temp->left=tree->left;
   if(Rtree!=temp)
	temp->right=tree->right;
   } //if
  else
	if(tree->right!=NULL)//with right child
	{
	   if(root==tree)
		root=root->right;
	   else if(Flag=='L')
		ptree->left=tree->right;
	   else
		ptree->right=tree->right;
	}
       else if(tree->left!=NULL) //with left child
	     {
	       if(root==tree)
			root=root->left;
	       else if(Flag=='L')
			ptree->left=tree->left;
	       else
			ptree->right=tree->left;
	     }
 delete(tree);
}
else
 cout<<"\n Node is not present";
}


/********** Main  ********/
void main()
{
tree ob;
node *root1;
char op;
int key,f,ch,h,ch1;
clrscr();
do
{
cout<<"\n 1. create \n 2. Insert \n3: Search \n 4. DFS \n 5. BFS \n 6.Mirror \n 7. Delete \n 7.Exit";
cout<<"\n Enter your choice: ";
cin>>ch;
switch(ch)
{
case 1:
	ob.create();
	ob.PreTrav(ob.return_root());
	break;
case 2:
	ob.insert();
	ob.PreTrav(ob.return_root());
	break;
case 3:
	cout<<"\n Enter element to search:";
	cin>>key;
	cout<<"\n Recursive (1) / Non-Recursive(2)";
	cin>>ch1;
	if(ch1==1)
	{
		h=ob.Rsearch(ob.return_root(),key);
		if(h==1)
			cout<<"\n Elemnt found";
		else
			cout<<"\n No such element";
	}
	else
	{
		f=ob.Search(key);
		if(f==1)
			cout<<"\n Elemnt found";
		else
			cout<<"\n No such element";
	}
	break;
case 4:
	cout<<"\n Recursive (1) / Non-Recursive(2)";
	cin>>ch1;
	if (ch1==1)
	{
		ob.RDFS(ob.return_root());
		cout<<"\n ";
	}
	else
		ob.DFS();
	break;
case 5:
	cout<<"\n Recursive (1) / Non-Recursive(2)";
	cin>>ch1;
	if(ch1==1)
	{
		ob.RBFS(ob.return_root());
		cout<<"\n ";
	}
	else
		ob.BFS();
	break;
case 6:
	cout<<"\n Mirror(No orignal tree mirrored) (1) / Original tree is mirrored(2)";
	cin>>ch1;
	if(ch1==1)
	{
		ob.mirror();
		cout<<"\n";
	}
	else
	{
		root1=R_mir(ob.return_root());
		ob.DFS(root1);
	}
	break;
case 7:
	cout<<"\n Enter the node to delete:";
	cin>>key;
	ob.Delete(key);
	ob.DFS(ob.return_root());
	break;
}
cout<<"\n Do you want to cont..";
cin>>op;
}while(op=='y' || op=='Y');
getch();
}