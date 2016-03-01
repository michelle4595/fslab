//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : prg.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student{
private:string name;
        string usn;
        string branch;
        string sem;
public:void pack(string fname);
       void unpack(string);
       void unpack(ifstream &);
       //void modify();
       void search(string,string);
      // int delet();
       void read();
       //void write();
};

void student::read()
{


	cout<<"in read";
	cout<<"enter name";
	cin>>name;
	cout<<"enter usn";
	cin>>usn;
	cout<<"enter branch";
	cin>>branch;
	cout<<"enter sem";
	cin>>sem;

}
void student::pack(string fname)
{

	 string temp;
	 temp=usn+'|'+name+'|'+branch+'|'+sem;
	 temp.resize(100,'$');
	 ofstream f1(fname.c_str(),ios::app);
	 f1<<temp<<endl;
	 f1.close();

}
void student::search(string key,string fname)
{
	student s[10];
	int i=0,count=0;
	ifstream f1(fname.c_str());
	while(!f1.eof())
	{
		cout<<"in search";
		s[i].unpack(f1);
		if(key==s[i].usn)
		{
			cout<<"record found\n";
			cout<<s[i].usn<<"\t"<<s[i].name;
			break;

		}
		i++;
	}
	f1.close();
}
void student::unpack(ifstream &f1)
{
	string temp;
	getline(f1,usn,'|');
	getline(f1,name,'|');
	getline(f1,branch,'|');
	getline(f1,sem,'$');
	getline(f1,temp);
}
void student::unpack(string fname)
{
	string temp;
	ifstream f1(fname.c_str());
	getline(f1,usn,'|');
	getline(f1,name,'|');
	getline(f1,branch,'|');
	getline(f1,sem,'$');
	f1.close();
}
void modify(string key,string fname)
{
	int pos;
	pos=search(key);
	pos=pos-100;
	if(pos>0)
	{
		cout<<"what should be modifies\n";
		cout<<"1.usn2.name3.branch4.sem";
		cin>>var;
		switch(var)
		{
		case 1:cin>>usn;
		break;
		case 2:cin>>name;
		break;
		case 3:cin>>branch;
		break;
		case 4:cin>>sem;
		break;
		}

		}
	pack(fname);
	f1.open(fname,ios|out)
			f1.seek(pos);
	f1<<buf;
	f1.close();
}
}

int main()
{
	student s;
	string fname,key;
	int choice;
	while(1)
	{
		 cout<<"1.insert 2.search 3.delete 4.modify\n";
		 cout<<"enter ur choice";
		 cin>>choice;
		 switch(choice)
		 {
		 case 1:

	          cout<<"enter the filename";
		       cin>>fname;
		       s.read();
		      s.pack(fname);
		       break;
		case 2:cout<<"enter usn to be searched\n";
		       cin>>key;
		       s.search(key,fname);
		       break;

		case 3:cout<<"enter filename";
		      cin>>fname;
		      cout<<"enter usn to be searched\n";
		      cin>>key;
		      s.modify(key,fname);
	           break;
		//case 4:modify();
		   //    break;
		//default:cout<<"terminates";
		//break;
		}
	}
		       return 0;
}

