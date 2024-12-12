#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const string FILENAME="student.txt";
string roll,name,division,address;
void insert(){
    fstream file;
    file.open(FILENAME,ios::app);
    if(!file.is_open()){
        cout<<"error in the file opening";
        return;
    }
    cout<<"\nEnter the roll numer:(4 digit)";
    cin>>roll;
    cout<<"\nEnter the name:(use underscore instead of space)";
    cin>>name;
    for(int i=0;i<name.length();i++){
        if(name[i]=='_'){
            name[i]=' ';
        }
    }
    cout<<"\nEnter the Address:(use underscore instead of space)";
    cin>>address;
    for(int i=0;i<address.length();i++){
        if(address[i]=='_'){
            address[i]=' ';
        }
    }
    cout<<"\nEnter the division: ";
    cin>>division;

    string record=roll+" "+name+" "+address+" "+division;
    file<<record<<"\n";
    file.close();

}


void search(){
    fstream file;
    string key;
    cout<<"Enter the roll number to search: ";
    cin>>key;
    file.open(FILENAME);
    bool found=false;
    string line;
    while(getline(file,line)){
        if(key==line.substr(0,4)){
            cout<<line;
            found=true;
        }
    }
    if(!found){
        cout<<"Data not found";
    }
}


void deleteRecord(){
    fstream file,temp;
    file.open(FILENAME);
    temp.open("temp.txt",ios::app);
    string key;
    bool found=false;
    cout<<"enter the roll no to be search: ";
    cin>>key;
    string line;

    while(getline(file,line)){

        if(key==line.substr(0,4)){
            found=true;
        }else{
            temp<<line<<"\n";
        }

    }
    file.close();
    remove("student.txt");
    temp.close();
    rename("temp.txt","student.txt");
    if(found){
        cout<<"Data deleted successfully";
    }else{
        cout<<"data not found";
    }


}



void display(){
    fstream file;
    file.open(FILENAME);
    string line;
    while(getline(file,line)){
        cout<<line<<"\n";
    }
    file.close();
}

int main()
{

    int ch;
    bool loop=true;
    while(loop){
        cout<<"\n1.add record\n2.search\n3.display\n4.delete\n5.exit\nEnter you choice:";
        cin>>ch;

        switch(ch){
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                display();
                break;

            case 4:
                deleteRecord();
                break;

            case 5:
                loop=false;
                cout<<"\nExited Successfully....!";
                break;
            
            default:
                cout<<"\nInvalid choice";

        }
    }
    return 0;

}