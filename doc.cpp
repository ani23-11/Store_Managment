#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <vector>
#define width 120
using namespace std;

void updown_border();
void loadingscreen(int x);
void storename();
void write_csv();
int read_csv(int l);
void searcher();
void editor_remover(int k);
void error_put();

int main()
{   
    int a;
    loadingscreen(40);
while(1)
{
    system("CLS");
    storename();
    cout<< "\n\t\t\t\t (1) Add Items" << endl
        << "\t\t\t\t (2) Display Items" << endl
        << "\t\t\t\t (3) Modify Items" << endl
        << "\t\t\t\t (4) Delete Items" << endl
        << "\t\t\t\t (5) Search Items" << endl
        << "\t\t\t\t (6) Exit " << endl;
    cout<<"\n\nChoice : ";
    cin>>a;
    switch(a)
        {
            case    1   :   write_csv();
                            break;
            case    2   :   read_csv(0);
                            break;
            case    3   :   editor_remover(0);
                            break;
            case    4   :   editor_remover(1);
                            break;
            case    5   :   searcher();
                            break;
            case    6   :   system("CLS");
                            cout<<"Thank You!\n\n";
                            return 0;
                            break;

                default :   system("CLS");
                            error_put();
        }
}
}

void updown_border()
{
    for(int i=0;i<width;i++)
        cout << "-";
    cout<<"\a"<<endl;
}
void loadingscreen(int x)
{
    system("CLS"); 
    cout<<endl;
    cout<< "Loading..."<<endl;
    Sleep(100);
    for(int i=0;i<width;i++)
    {
        printf("%c",177);
        Sleep(x);
    }
    storename();
}
void storename()
{
    system("CLS");
    cout<<endl;
    updown_border();
    cout<<"\t\t\t\t\t\t"<<"Eleven 7 GENERAL STORE"<<endl;
    updown_border();
}
void error_put()
{
    system("CLS");
    cout<<"Error. Please enter a Valid choice. Press any key to Continue.\n\n";
    getch();
    main();
}

void write_csv()
{
system("CLS"); 
int B=1,X,q=1;
string p,r,s;
ofstream myFile("Book.csv", ios::app);
loadingscreen(20);
if(myFile.is_open())
{
    while(B)
    {   
        storename();
        cout<<"\n\t\t\t\tAdding items to the file :"<<endl<<"\n\t\t\t\t(1) Add Item"<<endl
        <<"\t\t\t\t(2) Exit\n\n";
        cin>>X;
        if(X==1)     
        {   
            cout<<"\n!!!!Enter each detail without spaces!!!!\n\n"; 
            cout<<"Enter Item's Name : ";cin>>p;
            cout<<"Enter Item's Type : ";cin>>r;
            cout<<"Enter Item's ID : ";cin>>s;
            cout<<"Enter Item's Quantity(Must be an Integer Value) : ";cin>>q;

            myFile<<p<<","<<r<<","<<s<<","<<q<<"\n";
            
            cout<<"\nFile Updated. Press any key to Continue.";
            
            getch();
        }
        else if(X==2)
            break; 
        else
            error_put();  
    }
    myFile.close();
}
else
{
    cout<<"Could not open the file";
    getch();
}
}

int read_csv(int l)
{   
system("CLS");
fstream myFile("Book.csv", ios::in);
int m=1;
string line, word;
loadingscreen(20);
if(myFile.is_open())
{
    storename();
    cout<<"S.No.\tItem\t\t\t\tCategory\t\t\tID\t\t\t\tQuantity\n";
    updown_border(); cout<<endl;
    while(getline(myFile,line))
    {
        stringstream str(line);
        while(getline(str,word,','))
        {   
            cout<<setw(5)<<left<<m;
            cout<<"\t"<<setw(15)<<left<<word;
            for(int i=0;i<3;i++)
            {
                getline(str,word,',');
                cout<<"\t\t\t"<<setw(15)<<left<<word;
            }
            cout<<endl; m++;
        }
    }

    if(l==0)
    {
        cout<<"\n\nPress any key to Continue.";
        getch();
    }
    else if(l==1)
        cout<<"\n";
    else if(l==2)
        cout<<"\n\nEnter the S.No. of the Item you want to delete.";
    else
            error_put();
    return m;
    
}

else
{
    cout<<"Could not open the file";
    getch();
}  
}

void searcher()
{
    system("CLS");
    int X,b=1;
    fstream myFile("Book.csv", ios::in);
    string line,check,name,type,id,num;
    loadingscreen(20);

if(myFile.is_open())
{   
            system("CLS"); storename();
            cout<<"\nEnter data to be checked \n(Can be Item's Name or ID)\n: ";
            cin>>check;
            if(myFile.is_open())
            {
            while(getline(myFile,line))
            {
                stringstream str(line);
                getline(str,name,',');
                getline(str,type,',');
                getline(str,id,',');
                getline(str,num,',');
                    if(check==name||check==id)
                        {   
                            cout<<"\nFound it!\n";
                            updown_border();
                            cout<<"\tItem\t\t\t\tCategory\t\t\tID\t\t\t\tQuantity\n";
                            updown_border();
                            cout<<"\t"<<name<<"\t\t\t\t"<<type<<"\t\t\t"<<id<<"\t\t\t\t"<<num<<endl;
                            goto end;
                        }
            }
            cout<<"\nItem not available.";
            }   
}
else
    cout<<"Could not open the file";

end:
cout<<"\n\nPress any key to Continue.";
    getch();
}

void editor_remover(int k)
{
    system("CLS");
    int x,c1=0,z=0;
    string line,line2,column,n1,t1,i1,q1;
    ifstream in("Book.csv");
    ofstream myFile("temp.csv");

if(myFile.is_open()&&in.is_open())
{
    system("CLS");  
    storename();
    int ctr=read_csv(1);
    if(k==0)
        cout<<"\nEnter the S.No. of the Item you want to update/edit : ";
    else if(k==1)
        cout<<"\nEnter the S.No. of the Item you want to delete : ";
    cin>>x;
    if((ctr-1)>=x)
    {
    while(!in.eof())
    {   
        getline(in,line);
        stringstream str(line);
        c1++;
        if(c1==x)
        {
            if(k==0)
            {   
                cout<<"\n!!!!Enter each detail without spaces!!!!\n\n"; 
                cout<<"Enter Item's Name : ";cin>>n1;
                cout<<"Enter Item's Type : ";cin>>t1;
                cout<<"Enter Item's ID : ";cin>>i1;
                cout<<"Enter Item's Quantity : ";cin>>q1;
                myFile<<n1<<","<<t1<<","<<i1<<","<<q1<<"\n";
            }
            else if(k==1)
                continue;
        }  
        else  
            myFile<<line<<endl;
    }
    cout<<"\n\nUpdated data is stored in 'Book.txt'. ";
    cout<<"\n\nDo you want to display the updated data?\n(1) Yes\n(2) No : ";
    cin>>z;
    in.close();
    myFile.close();

    ofstream bb("Book.csv");
    ifstream tt("temp.csv");
    while(!tt.eof())
    {   
        getline(tt,line2);
        stringstream str(line2);
        bb<<line2<<endl;
    }
    tt.close();
    bb.close();
    } 
    else
        error_put();
}

else
    cout<<"Could not open the file";

if(z==1)
    read_csv(0);
else
    cout<<"\n\nPress any key to Continue.";
    getch();
}

