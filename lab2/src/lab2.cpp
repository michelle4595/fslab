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
#include<string>
using namespace std;
class student
{
private:string name;
        string usn;
        string branch;
        string sem;
public:void pack(char *fname);
       void unpack();
       void modify();
       void search();
       void del();
       void read();
};
int main() {
	int ch;
	char *fname;
	student s;

	while(1)
	{
		cout<<"1.insert 2.search 3.delete 4.modify"<<endl;
			cout<<"Enter your choice";
			cin>>ch;
		switch(ch)
		{
		case 1:cout<<"Enter file name";
		       cin>>fname;
			   s.read();
		       s.pack(fname);
		       break;
		//case 2:search();
		       //break;
		//case 3:del();
		       //break;
		//case 4:modify();
		       //break;


		}
	}

}
void student::read()
{
	cout<<"Enter Name"<<endl;
	cin>>name;
	cout<<"Enter usn"<<endl;
	cin>>usn;
	cout<<"Enter branch"<<endl;
	cin>>branch;
	cout<<"Enter sem"<<endl;
	cin>>sem;
}
void student::pack(char *fname)
{
	fstream fp;
	string buffer;
	buffer=usn+'|'+name+'|'+branch+'|'+sem;
	buffer.resize(100,'&');
	fp.open(fname,ios::out);
			fp<<buffer;
	fp.close();
}

