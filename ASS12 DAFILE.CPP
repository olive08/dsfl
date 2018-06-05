#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#define MAX 10

class Employee
{
       char Name[10];
       int Id,Salary;
public:
       Employee()
       {
		Name[0]='\0';
		Id=Salary=-1;
       }
       void Accept()
	{ cout<<"\nName: ";cin>>Name;
	  cout<<"\nId";cin>>Id;
	  cout<<"\nSalary";cin>>Salary; 
	}
       void Display()
	{ cout<<"\n\t"<<Name<<"\t"<<Id<<"\t"<<Salary;}
       int return_Id()	{ return Id; }
};

class Hashing
{
  struct Chaining
     {
       int Key;
       long int Offset;
       int Link;
       Chaining()
       {
		Key=Offset=Link=-1;
       }
     };
 Chaining Hash_Table[MAX];
 public:
 int Hash(long int);
 int Empty(int);
 void Print();
 void Chaing_WO_Replacement(int,int);
 int Search(int);
};

int Hashing::Hash(long int Key)
{
 return Key%MAX;
}

int Hashing::Empty(int Location)
{
 int I=Location;
 do
 { I++; I=I%MAX;
 }while(Hash_Table[I].Key!=-1 && I!=Location);
 return I;
}
void Hashing::Print()
{
cout<<"\nHvalue\tKey\tOffset\tLink";
  for(int I=0;I<MAX;I++)
    {
      cout<<"\n"<<I<<"\t"<<Hash_Table[I].Key<<"\t";
      cout<<Hash_Table[I].Offset<<"\t"<<Hash_Table[I].Link;
    }
}
//with chaining - without replacement
void Hashing::Chaing_WO_Replacement(int Id,int Addr)
{
  int I=0,Location,Pos=-1,Flag=0;
  char Answer;
  Print();
  Location=Hash(Id);
  if(Hash_Table[Location].Key==-1)//Location is Empty
    { 	Hash_Table[Location].Key=Id;
	Hash_Table[Location].Offset=Addr;
    }
  else
  {
     Pos=Empty(Location);
     if(Pos==Location)
	cout<<"Hash Table Full\n";
     else //hash table not full
     { //Present Key Hash==New Key Hash
      if(Hash(Hash_Table[Location].Key)==Hash(Id))
      {
       I=Location;
       while(Hash_Table[I].Link!=-1)
		I=Hash_Table[I].Link;
       Hash_Table[Pos].Key=Id;
       Hash_Table[Pos].Offset=Addr;
       Hash_Table[I].Link=Pos;
      }//if
     else//Present Key Hash != New Key Hash
      {
       I=Location+1;
       while((I%MAX)!=Location)
       { //search existing key hash same with the new key hash
	if(I==MAX)  I=0;
	if(Hash(Hash_Table[I].Key)== Hash(Id))
	 { Flag=1;  break;}
	I++;
       }//while
       if(Flag==0)
       {
		Hash_Table[Pos].Key=Id;
		Hash_Table[Pos].Offset=Addr;
       }
       else
	 {
	   while(Hash_Table[I].Link!=-1)  
		I=Hash_Table[I].Link;
	   Hash_Table[Pos].Key=Id;
	   Hash_Table[Pos].Offset=Addr;
	   Hash_Table[I].Link=Pos;
	  }

      }//else
    }//else hash table not full
 }
Print();
}
int Hashing::Search(int Key)
    {
	int Location,I,Flag;
	Location=Hash(Key);
	if(Hash_Table[Location].Key==Key)
	  return Hash_Table[Location].Offset;
	else if(Hash(Hash_Table[Location].Key)==Hash(Key))
		{
		   I=Location;
		     while(Hash_Table[I].Link!=-1)
		     {
			I=Hash_Table[I].Link;
			if(Hash_Table[I].Key==Key)
			   return Hash_Table[I].Offset;
		      }
		}
	      else
		{
		  I=Location+1;
		  while((I%MAX)!=Location)
		   { //search existing key hash same with the new key hash
			I=I%MAX;
			if(Hash(Hash_Table[I].Key)== Hash(Key))
			   {
			     while(Hash_Table[I].Link!=-1)
			      {
				 I=Hash_Table[I].Link;
				 if(Hash_Table[I].Key==Key)
				    return Hash_Table[I].Offset;
			      }
			   }
			I++;

		   }//while
		}
    return -1;
    }
class DAF
{
   char File_Name[10];
   Hashing H;
public:
   void Create();
   void Display();
   void Add();
   void Modify(int);
   int Search(int);
};

void DAF::Create()
{
ofstream  File;
char op;
Employee E; int Id,Offset;
cout<<"\nEnter File Name";
cin>>File_Name;
File.open(File_Name);
do
{
	E.Accept();
	Id=E.return_Id();
	File.seekp(0,ios::end);
	Offset=File.tellp();
	H.Chaing_WO_Replacement(Id,Offset);
	File.write((char*)(&E),sizeof(E));
cout<<"\nDo u want to continue";
cin>>op;
}while(op=='y');
File.close();
}

void DAF::Display()
{
ifstream  File;
Employee E;
File.open(File_Name);
 cout<<"\n Employee Database\nName\tId \tSalary";
  File.read((char*)(&E),sizeof(E));
  while(!File.eof())
  {
	      E.Display();
	      File.read((char*)(&E),sizeof(E));
  }
File.close();
}

void DAF::Add()
{
ofstream  File;
Employee E;
int Id,Offset;
File.open(File_Name,ios::app);
E.Accept();
  Id=E.return_Id();
  File.seekp(0,ios::end);
  Offset=File.tellp();
  H.Chaing_WO_Replacement(Id,Offset);
  File.write((char*)(&E),sizeof(E));
  File.close();
}

void DAF::Modify(int Key)
{
long int Addr=H.Search(Key);
if(Addr>-1)
{ 
fstream File; Employee E;
  File.open(File_Name,ios::in | ios::out);
   //cout<<"\nDon't Change Employee ID";
   E.Accept();
   File.seekp(Addr,ios::beg);
   File.write((char*)&E,sizeof(E));
   File.close();
}
  else 
	cout<<"\nEmployee does not present";
}

int main()
{
DAF d;
int key;

d.Create();
d.Display();

d.Add();
d.Display();

cout<<"\nEnter ID to Search";
cin>>key;
addr=d.Search(key);

d.Display();

cout<<"\nEnter ID to modify";
cin>>key;
d.Modify(key);
d.Display();
}
