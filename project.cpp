#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>

using namespace std;

class displayPrograms{
    public:
        void display_header()
        {
            system("CLS");
            cout<<"=====================================================================\n"<<endl;
            cout<<setw(45)<<"JUST DIAL !!!\n\n";
            cout<<"=====================================================================\n"<<endl;
        }

        void default_menu()
        {
            cout<<"WHAT OPERATION DO YOU WANT TO DO!!"<<endl;
            cout<<"[1] DISPLAY ALL CONTACTS\n[2] SEARCH A CONTACT\n[3] RETURN TO BROWSER"<<endl;
        }

        void default_menu_search()
        {
            cout<<"WITH WHAT PARAMETER DO YOU WANT TO SEARCH ?"<<endl;
            cout<<"[1] Name\n[2] Number\n[3] Address\n[4] Email ID\n[5] GO BACK"<<endl;
        }

};

class justDial : private displayPrograms
{
    private:
        string  adminMAil;
        string adminPass;
        string newfName;
        string newlname;
        long long newNumber;
        string newAddress;
        string newEmail;
        string fname;
        string search_fname;
        string lname;
        string search_lname;
        long long number;
        long long searchNumber;
        string address;
        string searchAddress;
        string email;
        string search_email;
    public:

//CORE BACKEND

        void addNewContact(){
            cout<<"Enter Name : ";
            cin>>newfName>>newlname;
            cout<<"Enter Number :";
            cin>>newNumber;
            cout<<"Enter address : ";
            cin>>newAddress;
            cout<<"Enter Email Id :";
            cin>>newEmail;
        }

        void contact_display(){
            cout<<"------------------------------------------------------\n";
            cout<<"Name : "<<fname<<" "<<lname<<endl;
            cout<<"Phone Number : "<<number<<endl;
            cout<<"Address : "<<address<<endl;
            cout<<"Email Id : "<<email<<endl;
            cout<<"------------------------------------------------------\n";
        }

        int searchContact_input(){
            
            int choice;
            m:
            default_menu_search();
            cout<<"Enter Choice : ";
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"Enter Name: ";
                    cin>>search_fname>>search_lname;
                    break;
                case 2:
                    cout<<"Enter Number: ";
                    cin>>searchNumber;
                    break;
                case 3:
                    cout<<"Enter Address :";
                    cin>>searchAddress;
                    break;
                case 4:
                    cout<<"Enter Email ID: ";
                    cin>>search_email;
                    break;
                case 5:
                    break;
                default:
                    cout<<"Invalid input"<<endl;
                    goto m;
            } 
            return choice;
        }

//ADMIN SECTION

        void del_doc(){
            string del_fname;
            string del_lname;
            cout<<"Enter contact name to delete: ";
            cin>>del_fname>>del_lname;
            fstream myFile;
            fstream myFile1;
            myFile.open("temp.txt",ios::out|ios::app);
            myFile1.open("doctors_database.txt",ios::in);
            while(!myFile1.eof()){
                myFile1>>fname>>lname>>number>>address>>email;
                if(del_fname!=fname || del_lname!=lname ){
                    myFile<<fname<<" "<<lname<<" "<<number<<" "<<address<<" "<<email<<"\n";
                }
            }
            myFile1.close();
            myFile.close();
            remove("doctors_database.txt");
            rename("temp.txt","doctors_database.txt");
        }

        void del_law(){
            string del_fname;
            string del_lname;
            cout<<"Enter contact name to delete: ";
            cin>>del_fname>>del_lname;
            fstream myFile;
            fstream myFile1;
            myFile.open("temp.txt",ios::out|ios::app);
            myFile1.open("lawyers_database.txt",ios::in);
            while(!myFile1.eof()){
                myFile1>>fname>>lname>>number>>address>>email;
                if(del_fname!=fname || del_lname!=lname ){
                    myFile<<fname<<" "<<lname<<" "<<number<<" "<<address<<" "<<email<<"\n";
                }
            }
            myFile1.close();
            myFile.close();
            remove("lawyers_database.txt");
            rename("temp.txt","lawyers_database.txt");
        }

        void del_admin(){
            m:
            int choice;
            char ch;
            system("CLS");
            display_header();
            cout<<"From where do you want to delete contact? -->"<<endl;
            cout<<"[1] DOCTORS\n[2] LAWYERS\n[3] RETURN TO ADMIN MENU\n";
            cout<<"Enter choice :"; cin>>choice;
            
            switch (choice)
            {
            case 1:
                del_doc();
                cout<<"CONTACT SUCCESSFULLY DELETED"<<endl;
                break;
            case 2:
                del_law();
                cout<<"CONTACT SUCCESSFULLY DELETED"<<endl;
                break;
            
            case 3:
                admin_menu();
                break;
            default:
               cout<<"Invalid choice";
                
            }
            cout<<"Do you want to add another contact? (y/n) : ";
            cin>>ch;
            if(ch=='y')
                goto m;
            else
                admin_menu();
        }

        void add_doc(){
            fstream myFIle;
            myFIle.open("doctors_database.txt",ios::app|ios::out);
            addNewContact();
            myFIle<<newfName<<" "<<newlname<<" "<<newNumber<<" "<<newAddress<<" "<<newEmail<<endl;
            
        }

        void add_lawyer(){
            fstream myFIle;
            myFIle.open("lawyers_database.txt",ios::app|ios::out);
            addNewContact();
            myFIle<<newfName<<" "<<newlname<<" "<<newNumber<<" "<<newAddress<<" "<<newEmail<<endl;
            
        }

        void add_admin(){
            m:
            int choice;
            char ch;
            system("CLS");
            display_header();
            cout<<"Where do you want to add contact? -->"<<endl;
            cout<<"[1] DOCTORS\n[2] LAWYERS\n[3] RETURN TO ADMIN MENU\n";
            cout<<"Enter choice :"; cin>>choice;
            
            switch (choice)
            {
            case 1:
                add_doc();
                cout<<"CONTACT SUCCESSFULLY ADDED"<<endl;
                break;
            case 2:
                add_lawyer();
                cout<<"CONTACT SUCCESSFULLY ADDED"<<endl;
                break;
            
            case 3:
                admin_menu();
                break;
            default:
               cout<<"Invalid choice";
                
            }
            cout<<"Do you want to add another contact? (y/n) : ";
            cin>>ch;
            if(ch=='y')
                goto m;
            else
                admin_menu();
        }

        void access_check(){
            string mailId;
            string pass;
            bool accessible = false;
            char ch;
            m:
            system("CLS");
            display_header();
            cout<<"ENTER VALID EMAIL ID AND PASSWORD TO ACCESS ADMIN MENU"<<endl;
            cout<<"Enter Email id : ";
            cin>>mailId;
            cout<<"Enter Password : ";
            cin>>pass;
            fstream myFile;
            myFile.open("admin_database.txt",ios::in);
            while(!myFile.eof()){
                myFile>>adminMAil>>adminPass;
                if(adminMAil == mailId && adminPass == pass){
                    accessible = true;
                    break;
                }
            }
            if(accessible)
                admin_menu();
            else{
                cout<<"Invalid Email or Password\nDo you want to try again? (y/n) : ";
                cin>>ch;
                if(ch=='y')
                    goto m;
                else
                    display_mainMenu();
            }

            
        }
        
        void admin_menu(){
            int choice;
            system("CLS");
            display_header();
            cout<<setw(50)<<"Welcome to admin section -->"<<endl;
            cout<<"What Operation would you like to perform :"<<endl;
            cout<<"[1] ADD CONTACT\n[2] DELETE CONTACT\n[3] MAIN MENU"<<endl;
            cout<<"Enter choice : "; cin>>choice;
            switch (choice)
            {
            case 1:
                add_admin();
                break;
            case 2:
                del_admin();
                break;
            case 3:
                display_mainMenu();
                break;
            default:
                break;
            }
        }
   

// DOCTOR SECTION BACKEND

        void searchContact_doctor()
        {
            m:
            system("CLS");
            display_header();
            cout<<setw(50)<<"WELCOME TO SEARCH ENGINE -->"<<endl;
            char ch;
            int choice = searchContact_input();
            if(choice == 5)
                doctor_menu();
            else{
                fstream myFile;
                myFile.open("doctors_database.txt",ios::in);
                if(choice==1){
                    myFile>>fname>>lname>>number>>address>>email;
                    while(!myFile.eof()){
                        if((fname==search_fname && search_lname==lname) )
                            contact_display();
                        myFile>>fname>>lname>>number>>address>>email;
                    }
                }
                else if(choice==2){
                    myFile>>fname>>lname>>number>>address>>email;
                    while(!myFile.eof()){
                        if((number==searchNumber) )
                            contact_display();
                        myFile>>fname>>lname>>number>>address>>email;
                    }
                }
                else if(choice==3){
                    myFile>>fname>>lname>>number>>address>>email;
                    while(!myFile.eof()){
                        if((address==searchAddress))
                            contact_display();
                        myFile>>fname>>lname>>number>>address>>email;
                    }
                }
                else if(choice==4){
                    myFile>>fname>>lname>>number>>address>>email;
                    while(!myFile.eof())
                        if((email == search_email) )
                            contact_display(); 
                        myFile>>fname>>lname>>number>>address>>email;
                    }
                }
                cout<<"Do you want to search another contact ? (y/n) "<<endl;
                cout<<"Enter choice : ";
                cin>>ch;
                if(ch=='y')
                    goto m;
                else
                    doctor_menu();
        }


        void doctor_menu(){
            m:
            int choice;
            system("CLS");
            display_header();
            cout<<setw(50)<<"WELCOME TO DOCTORS CONTACTS!!"<<endl;
            default_menu();
            cin>>choice;
            switch(choice){
                case 1:
                    display_doctors();
                    break;
                case 2:
                    searchContact_doctor();
                case 3:
                    display_menu();
                    break;
                default:
                    cout<<"Invalid Choice"<<endl;
            }
            goto m;
        }

        void display_doctors(){

            system("CLS");
            display_header();
            cout<<setw(48)<<"LIST OF ALL DOCTORS!!!"<<endl;
            fstream myFile;
            myFile.open("doctors_database.txt",ios::in);
            myFile>>fname>>lname>>number>>address>>email;
            while(!myFile.eof()){
                contact_display();
                myFile>>fname>>lname>>number>>address>>email;            
            }
            int choice;
            m:
            cout<<"\n\n[1] RETURN TO DOCTORS MENU \n[2] EXIT"<<endl;
            cout<<"ENTER CHOICE :"; cin>>choice;
            switch(choice){
                case 1:
                    system("CLS");
                    doctor_menu();
                    break;
                case 2:
                    cout<<"Exited the menu !"<<endl;
                    exit(0);
                    break;
                default:
                    cout<<"Invalid Choice !";
            }
            goto m;
        }

// LAWYER SECTION BACKEND

        void searchContact_lawyer()
        {
            m:
            system("CLS");
            display_header();
            cout<<setw(50)<<"WELCOME TO SEARCH ENGINE -->"<<endl;
            char ch;
            int choice = searchContact_input();
            if(choice == 5)
                lawyer_menu();
            else{
                fstream myFile;
                myFile.open("lawyers_database.txt",ios::in);
                if(choice==1){
                    myFile>>fname>>lname>>number>>address>>email;
                    while(!myFile.eof()){
                        if((fname==search_fname && search_lname==lname) )
                            contact_display();
                        myFile>>fname>>lname>>number>>address>>email;
                    }
                }
                else if(choice==2){
                    myFile>>fname>>lname>>number>>address>>email;
                    while(!myFile.eof()){
                        if((number==searchNumber) )
                            contact_display();
                        myFile>>fname>>lname>>number>>address>>email;
                    }
                }
                else if(choice==3){
                    myFile>>fname>>lname>>number>>address>>email;
                    while(!myFile.eof()){
                        if((address==searchAddress))
                            contact_display();
                        myFile>>fname>>lname>>number>>address>>email;
                    }
                }
                else if(choice==4){
                    myFile>>fname>>lname>>number>>address>>email;
                    while(!myFile.eof()){
                        if((email == search_email) )
                            contact_display();
                        myFile>>fname>>lname>>number>>address>>email;
                    }
                }
                cout<<"Do you want to search another contact ? (y/n) "<<endl;
                cout<<"Enter choice : ";
                cin>>ch;
                if(ch=='y')
                    goto m;
                else
                    lawyer_menu();
            }
        }

        void lawyer_menu(){
            m:
            int choice;
            system("CLS");
            display_header();
            cout<<setw(50)<<"WELCOME TO LAWYERS CONTACTS!!"<<endl;
            default_menu();
            cin>>choice;
            switch(choice){
                case 1:
                    display_lawyers();
                    break;
                case 2:
                    searchContact_lawyer();
                case 3:
                    display_menu();
                    break;
                default:
                    cout<<"Invalid Choice"<<endl;
            }
            goto m;
        }

        void display_lawyers(){

            system("CLS");
            display_header();
            cout<<setw(48)<<"LIST OF ALL LAWYERS!!!"<<endl;
            fstream myFile;
            myFile.open("lawyers_database.txt",ios::in);
            myFile>>fname>>lname>>number>>address>>email;
            while(!myFile.eof()){
                contact_display();
                myFile>>fname>>lname>>number>>address>>email;
            }
            int choice;
            cout<<"\n\n[1] RETURN TO LAWYERS MENU \n[2] EXIT"<<endl;
            m:
            cout<<"ENTER CHOICE :"; cin>>choice;
            switch(choice){
                case 1:
                    system("CLS");
                    lawyer_menu();
                    break;
                case 2:
                    cout<<"Exited the menu !"<<endl;
                    exit(0);
                    break;
                default:
                    cout<<"Invalid Choice !";
            }
            goto m;
        }

// MAIN MENUS

        void display_menu(){
            int choice;
            m:
            system("CLS");
            display_header();
            cout<<"[1] DOCTORS\n[2] LAWYERS\n[3] RETURN TO MAIN MENU\n";
            cout<<"Enter choice : ";
            cin>>choice;
            switch (choice)
            {
            case 1:
                doctor_menu();
                break;
            case 2:
                lawyer_menu();
                break;
            case 3:
                display_mainMenu();          
            default:
                cout<<"Invalid choice!!!";
            }
            goto m;
        }

        void display_mainMenu(){
            m:
            int choice;
            system("CLS");
            display_header();
            cout<<setw(48)<<"WELCOME TO JUST DIAL!"<<endl;
            cout<<"[1] BROWSE CONTACTS\n[2] ADD / DELETE CONTACTS (ADMIN ONLY)\n[3] EXIT\n";
            cout<<"Enter choice : ";
            cin>>choice;
            switch (choice)
            {
            case 1:
                display_menu();
                break;
            case 2:
                access_check();
                break;
            case 3:
                cout<<"EXITED THE MENU!!"<<endl;
                exit(0);
                break;
            default:
                cout<<"Invalid choice!!!";
            }
            goto m;
        }

};

int main()
{
    justDial a;
    a.display_mainMenu();
    return 0;
}