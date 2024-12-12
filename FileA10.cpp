#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void add_record(){
    fstream file;
    file.open("Student_Records.txt", ios::app);
    string name, address;
    string roll;
    char division;
    cout << "Enter name: (Use underscore instead of space) ";
    cin >> name;
    for(int i = 0; i < name.length(); i++){
        if(name[i] == '_'){
            name[i] = ' ';
        }
    }
    cout << "Enter address: (Use underscore instead of space) ";
    cin >> address;
    for(int i = 0; i < address.length(); i++){
        if(address[i] == '_'){
            address[i] = ' ';
        }
    }
   
    cout << "Enter roll no:(4 digit) ";
    cin >> roll;
    cout << "Enter division: "; 
    cin >> division;
    file << roll << " " << name << " " << division <<" "<<address << endl;
    file.close();
}

string search(){
    fstream file;
    file.open("Student_Records.txt");
    string roll;
    cout<<"Enter roll number of student to be found: ";
    cin>>roll;
    string line;
    while(getline(file,line)){
        string temp = line.substr(0,4);
        if(temp == roll){
            return line;
            break;
        }
    }
    return "Record not found";


}
void display(){
    fstream file;
    file.open("Student_Records.txt");
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
}

void deleteLine(){
    bool found = false;
    fstream file,tempf,f2;
    file.open("Student_Records.txt");
    string roll;
    cout<<"Enter roll number of student to be deleted: ";
    cin>>roll;
    string line;
    tempf.open("temp.txt",std::ios::out);
    while(getline(file,line)){
        string temp = line.substr(0,4);
        if(temp == roll){
            found = true;
            continue;
           
        }else{
            tempf << line << endl;
        }
    }
    file.close();
    remove("Student_Records.txt");
    tempf.close();
    rename("temp.txt","Student_Records.txt");
    if(found){
        cout<<"Record deleted successfully\n";
    }else{  
        cout<<"Record not found\n";
    }

    
}

int main(){
    int choice;
    do{
        cout << "1. Add record\n2. Search record\n3. Display all records\n4. Delete\n5.Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                add_record();
                break;
            case 2:
                cout << search() << endl;
                break;
            case 3:
                display();
                break;
            case 4:
                deleteLine();
                break;
            case 5:
                cout << "Exiting\n";
                break;
            
            default:
                cout << "Invalid choice\n";
        }   
    }while(choice != 5);
    return 0;

}