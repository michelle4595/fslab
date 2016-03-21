#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
class Student
{
private:
    string usn,name,branch,buffer,sem;
public:int count,rrn_list[100];
void read();
void write();
void pack();
void unpack();
void creat_rrn();
void search_by_rrn(int);
};
void Student::read()
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
void Student::pack()
{

     string sem;
     stringstream out;
     out<<"sem";
     sem=out.str();
     buffer.erase();
     buffer=usn+'|'+name+'|'+branch+'|'+sem+'|'+ '$'+'\n';
}
void Student::write()
{
    int pos;
    fstream file;
    file.open("m.txt",ios::out|ios::app);
    pos=file.tellp();
    file<<buffer;
    file.close();
    rrn_list[++count]=pos;
}
void Student::creat_rrn()
{
    fstream file;
    int pos;
    count=0;
    file.open("m.txt",ios::in);
    while(!file.eof())
    {
        pos=file.tellg();
        buffer.erase();
        getline(file,buffer);
        if(buffer.empty())
            continue;
        rrn_list[++count]=pos;
    }
    file.close();
}
void Student::search_by_rrn(int rrn)
{
    int pos=-1;
    fstream file;
    if(rrn>count)
        cout<<"record not found\n";
    else
    {
        buffer.erase();
        file.open("m.txt");
        pos=rrn_list[rrn];
        file.seekp(pos,ios::beg);
        getline(file,buffer);
        cout<<"\n record is ..."<<buffer<<"\n";
    }
}
int main()
{
    int ch,rrn;
    Student s;
    s.creat_rrn();
    while(1)
    {
         cout<<endl<<"1.add 2.search 3.exit\n";
         cout<<"enter ur choice";
         cin>>ch;
         switch(ch)
         {
         case 1:


             cout<<"enter dta\n";
              s.read();
              s.pack();
              s.write();
               break;
        case 2:cout<<"enter usn to be rrn\n";
        cin>>rrn;
               s.search_by_rrn(rrn);
               break;

         }
    }
    return 0;
}
