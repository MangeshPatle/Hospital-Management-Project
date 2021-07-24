///////////////////////////hodpital management system//////////////////////////////////g

//////////////////////header files/////////////////////////////////
#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<cstring>
///////////////////////function declaration
void menu();
void pascode();
void cpascode();
using namespace std;
//////////////////////////class One///////
class one{
    public:
    virtual void get()=0;
    virtual void show()=0;
};
//////////////////////////////class information//////////////////////////
class info:public one{
    public:
    char name[50],time[50];
    int num,age;
    void get(){
        system("cls");
        cin.sync();
        cout<<"\nenter the patient name =";
        cin.getline(name,50);
        cout<<"\nenter the Appointment time =";
        cin.getline(time,50);
        cout<<"\nenter Age =";
        cin>>age;
        cout<<"\nenter Appointment No =";
        cin>>num;
    }
    void show(){
        cout<<"\nname ="<<name;
        cout<<"\nAge ="<<age;
        cout<<"\nNo ="<<num;
        cout<<"\ntime ="<<time;
    }
};
////////////////////////////////class rana/////////////////////////
class rana:public info{
    public:
    info a1;
    void get(){
        system("cls");
        ofstream out("Rana.txt",ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your Entry has been saved ";
        getch();
        menu();
    }
    void show(){
        ifstream in("rana.txt");
            while (!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu(); 
    }
};

///////////////////////////////////////////class dr.waqar..................................
class waqar:public info{
    public:
    info a1;
    void get(){
        system("cls");
        ofstream out("waqar.txt",ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your Entry has been saved ";
        getch();
        menu();
    }
    void show(){
        ifstream in("waqar.txt");
       
             while (!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu(); 
    }
};
/////////////////////////////////////class Dr ahmad...............
class ahmad:public info{
    public:
    info a1;
    void get(){
        system("cls");
        ofstream out("ahmad.txt",ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your Entry has been saved ";
        getch();
        menu();
    }
    void show(){
        ifstream in("ahmad.txt");
            while (!in.eof())
            {
                in.read((char*)&a1,sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu(); 
    }
};
class staff:public one{
    public:
    char all[199];
    char name[50],age[20],sal[30],pos[50];
    void get(){
        ofstream out("staff.txt",ios::app);
        {
            system("cls");
            cin.sync();
            cout<<"\n\t\t\tHOSTPTAL-STAFF-INFORMATION\n";
            cout<<"\n\tEnter Bio-data abut staff here\n";
            cout<<"\n\t\tEnter name = ";
            cin.getline(name,50);
            cout<<"\n\t\tEnter age = ";
            cin.getline(age,20);
            cout<<"\n\t\tEnter sallary = ";
            cin.getline(sal,30);
            cout<<"\n\t\tEnter working position = ";
            cin.getline(pos,50);

        }
        out<<"\nName= "<<name<<"\nage "<<age<<"\nsallary "<<sal<<"\nworking position\n"<<pos;
        out<<"-------------------------\n";
        out<<"-------------------------\n";
        out.close();
        cout<<"\n\nyour information has been saved:\n\t\t\tpress any key to continue ";
        getch();
        menu();
    }
    void show(){
        ifstream in("staff.txt");
        if(!in)
        {
            cout<<"file open error";
        }
        while(!(in.eof()))
        {
            in.getline(all,999);
            cout<<all<<endl;
        }
        in.close();
        cout<<"\n\n\t\t\tpress any key to continue : ";
        getch();
        menu();
    } 
};

///////////////////////////class information///////////////
class information
{
    public:
    void drinfo(){
        system("cls");
        system("color 3e");
        cout<<"\n\n\t\t         (three doctors available)\n\n\t\t[Information and timing as ginven below]\n";
        cout<<"---------------------------------------------------------------------------------\n";
        cout<<"\t\t\tDr Available:\n";
        cout<<"\t=============================================\n";
        cout<<"\t\tDr Rana(Skin specialist)\n\n";
        cout<<"\t\t\t[[timing]]:\n\n";
        cout<<"\tmonday to friday\t\t9am tpo 5pm\n";
        cout<<"\tsaturday           \t\t9am to 1pm\n";
        cout<<"\tsunday             \t\toff\n";
        cout<<"------------------------------------------------------------------------------------\n";
        cout<<"\t\tDr waqar(child specialist)\n\n";
        cout<<"\t\t\t[[timing]]:\n\n";
        cout<<"\tmonday to friday\t\t2pm tpo 10pm\n";
        cout<<"\tsaturday           \t\t8am to 1pm\n";
        cout<<"\tsunday             \t\t12pm to 9pm\n";
        cout<<"------------------------------------------------------------------------------------\n";
        cout<<"\t\tDr ahmad(DVM)\n\n";
        cout<<"\t\t\t[[timing]]:\n\n";
        cout<<"\tmonday to friday\t\t8am tpo 5pm\n";
        cout<<"\tsaturday           \t\t10am to 1pm\n";
        cout<<"\tsunday             \t\toff\n";
        cout<<"------------------------------------------------------------------------------------\n";
        cout<<"\npress any key for continue: ";
        getch();
        menu();
    }
    void call_dr(){
        system("cls");
        int choice;
        cout<<"\n\n\n\t\t press 1 for dr Rana \n\n\t\t press 2 for dr waqar \n\n\t\t press 3 for dr ahmad\n\n\tpress:-";
        cin>>choice;

        one*ptr;
        rana s3;
        waqar s4;
        ahmad s5;
        if(choice==1)
        {
            ptr=&s3;
            ptr->get();
        }
        if(choice==2)
        {
            ptr=&s4;
            ptr->get();
        }
        if(choice==3)
        {
            ptr=&s5;
            ptr->get();
        }
        else
        {
            cout<<"sorry invalid choice...............................................";
            getch();menu();
        }
    }
};

class patient_details{
    public:
    rana r1;
    waqar r2;
    ahmad r3;
    int x;
    void data(){
        system("cls");
        system("color 3e");
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Paitient details~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\n\t\tPress 1 for dr.Rana's patient list";
        cout<<"\n\t\tPress 2 for dr.Waqar's patient list";
        cout<<"\n\t\tPress 3 for dr.Ahmad's patient list";
        cout<<"\n\tPress:-";
        cin>>x;
        if(x==1)
        {
            r1.show();
        }
        else if(x==2)
        {
            r2.show();
        }
        else if(x==3)
        {
            r3.show();
        }
        else
        { 
            cout<<"invalid input\n";
            getch();
            menu();
        }
    }
    
};

void menu(){
    system("cls");
    system("color 3e");
    cout<<"\n\n";
    cout<<"------------------------------------------------------------------------------------\n";
    cout<<"\t\t please select any option                            \n";
    cout<<"\n\n\t1-\t press 1 for Available doctor indormation\n\n";
    cout<<"\t2-\t press 2 for Doctor appontment\n\n";
    cout<<"\t3-\t press 3 for Saving staff indormation\n\n";
    cout<<"\t4-\t press 4 for chacking patient appointment menu:\n\n";
    cout<<"\t5-\t press 5 for chacking staff indormation menu:\n\n";
    cout<<"\t6-\t press 6 for change password or create password : \n\n";
    cout<<"\t7-\t [ press 7 for logout ]\n\n";
    cout<<"\n=====================================================================\n";
    cout<<"\n\n\t please Enter your choice :-";
    information a1;
    staff a2;
    patient_details a3;
    one*ptr;
    //info s6;
    int a;
    cin>>a;
    switch(a){
        case 1:a1.drinfo();
        break;

        case 2:a1.call_dr();
        break;

        case 3:ptr=&a2;
               ptr->get(); //a2.get();
        break;

        case 4:a3.data();  
        break;

        case 5:a2.show();
        break;

        case 6:cpascode();
        break;

        case 7:pascode();
        break;

        default:cout<<"soory!invalid choice\n";
        break;
        
    }
}   

void pascode()
{
    char n[50];
    system("cls");
    char p1[50],p2[50],p3[50];
    system("color 1e");
    ifstream in("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\t\t\tEnter password : ";
        cin.getline(p1,50);
        in.getline(p2,50);
        if(strcmp(p2,p1)==0)
        {
            menu();
        }
        else
        {
            cout<<"\n\n\t\tincorrect password please try again\n";
            Sleep(999);
            pascode();
        }
    }
    in.close();

}
void cpascode(){
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\t\t\tEnetr the new password :- ";
        cin.getline(n,50);
        out<<n;
    }
    out.close();
    cout<<"\n\nypour password has been saved:";
    getch();
    menu();
}
int main()
{
    pascode();
    system("pause");
}