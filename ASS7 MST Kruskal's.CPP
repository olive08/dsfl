//MST using Kruskal's Algorithm
#include<iostream.h>
#include<string.h>
#include<conio.h>

class Graph
{
	char Vnames[10][10];
	int cost[10][10],no;
public:
	Graph();
	void creat_graph();
	void display();
	int Position(char[]);
	void kru();
};
Graph::Graph()
{
no=0;
for(int i=0;i<10;i++)
for(int j=0;j<10;j++)
 {
 cost[i][j]=999;
 }
}
void Graph::creat_graph()
{
char ans,Start[10],End[10];
int wt,i,j;
cout<<"Enter number of nodes";
cin>>no;
cout<<"\n Enter vertex name:";
for(i=0;i<no;i++)
          cin>>Vnames[i];
do
{
cout<<"\nEnter Start and end point of edge";
cin>>Start>>End;
cout<<"Enter weight";
cin>>wt;
i=Position(Start);
j=Position(End);
cost[i][j]=cost[j][i]=wt;
cout<<"\nMore Edges ";
cin>>ans;
}while(ans=='y' || ans=='Y');
}
void Graph::display()
{
int i,j;
for(i=0;i<no;i++)
{
 cout<<"\n";
 for(j=0;j<no;j++)
	 cout<<"\t"<<cost[i][j];
}
}
int Graph::Position(char key[10])
{
int i;
for(i=0;i<10;i++)
	if(strcmp(Vnames[i],key)==0)
		return i;
return -1;
}

void Graph::kru()
{
int i,j,v[10]={0},x,y,Total_cost=0,min,gr=1,flag=0,temp,d;

while(flag==0)
{
min=999;
 for(i=0;i<no;i++)
	{  for(j=0;j<no;j++)
	   { if(cost[i][j]<min)
	      {
		min=cost[i][j];
		x=i;
		y=j;
	      }
	   }
	 }
if(v[x]==0 && v[y]==0)
{
v[x]=v[y]=gr;
gr++;
}
else if(v[x]!=0 && v[y]==0)
	v[y]=v[x];
else if(v[x]==0 && v[y]!=0)
	v[x]=v[y];
else
{
	if(v[x]!=v[y])
	{
		d=v[x];
		for(i=0;i<no;i++)
		{
			if(v[i]==d)
			v[i]=v[y];
		}//end for
	}
}
cost[x][y]=cost[y][x]=999;
Total_cost=Total_cost+min;
cout<<"\n"<<Vnames[x]<<"\t"<<Vnames[y]<<"\t"<<min;

   temp=v[0]; flag=1;
   for(i=0;i<no;i++)
   {
	   if(temp!=v[i])
	   {
		 flag=0;
		 break;
	   }
   }
}
cout<<"\nTotal cost of tree="<<Total_cost;
}

void main()
{
Graph ob;
clrscr();
ob.creat_graph();
ob.display();
ob.kru();
getch();
}












