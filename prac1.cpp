#include<iostream>
using namespace std;

struct stud{
string name;
float sgpa;
int roll;

};

void display(struct stud s[], int n){

    for(int i=0;i<n;i++){
        cout<<"\nname: "<<s[i].name;
        cout<<"\nsgpa: "<<s[i].sgpa;
        cout<<"\nroll: "<<s[i].roll;
    }

}
void getInfo(struct stud s[],int n){

    for(int i=0;i<n;i++){
        cout<<"Enter the information for student "<<(i+1);
        cout<<"\nName:";
        cin>>s[i].name;
        cout<<"\nRoll no:";
        cin>>s[i].roll;
        cout<<"\nSGPA:";
        cin>>s[i].sgpa;
    }

}

void rollBubble(struct stud s[],int n){

    for(int i=0;i<(n-1);i++){
        for(int j=0;j<n-i-1;j++){
            if(s[j].roll>s[j+1].roll){
                swap(s[j],s[j+1]);
            }
        }
    }

}


void nameInsertion(struct stud s[],int n){

    for(int i=0;i<n;i++){
        struct stud key=s[i];
        int j=i-1;

        while(j>=0 && s[j].name>key.name){
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=key;
    }

}


int partition(struct stud s[],int low,int high){

    float pivot=s[high].sgpa;
    int i=low-1;

    for(int j=low;j<high;j++){
        if(s[j].sgpa>pivot){
            i++;
            swap(s[i],s[j]);
        }
        
    }
    swap(s[i+1],s[high]);
    return i+1;

}

void quickSort(struct stud s[],int low,int high){

    if(low<high){
        int pi=partition(s,low,high);
        quickSort(s,low,pi-1);
        quickSort(s,pi+1,high);
    }

}


void displayTop(struct stud s[],int n){

    int limit=min(n,10);

    for(int i=0;i<limit;i++){
        cout<<"\n\nRank: "<<(i+1);
        cout<<"\nName:"<<s[i].name;
        cout<<"\nRoll no: "<<s[i].roll;
        cout<<"\nSGPA: "<<s[i].sgpa;
    }

}


void searchSGPA(struct stud s[],int n,float key){
    bool found=false;
    for(int i=0;i<n;i++){
        if(s[i].sgpa==key){
            found=true;
            cout<<"\nName:"<<s[i].name;
            cout<<"\nRoll no: "<<s[i].roll;
            cout<<"\nSGPA: "<<s[i].sgpa;

        }
    }

    if(!found){
        cout<<"\ndata not found in the database";
    }

}


void nameSeach(struct stud s[],int n,string val){
    int start=0;
    int end=n-1;
    int mid;
    bool found=false;

    while(start<=end){
        mid=(start+end)/2;
        if(s[mid].name==val){
            found=true;
            cout<<"\nName:"<<s[mid].name;
            cout<<"\nRoll no: "<<s[mid].roll;
            cout<<"\nSGPA: "<<s[mid].sgpa;
            break;
        }else if(s[mid].name<val){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }


    if(!found){
        cout<<"data not found in the database";
    }
}

int main(){


    int ch,n;
    cout<<"enter number of student's:"<<endl;
    cin>>n;
    bool loop=true;
    struct stud s[n];
    string val;
    getInfo(s,n);

    while (loop)
    {
        cout << "Enter:\n";
        cout << "1. Arrange List by Roll Numbers (Bubble Sort)\n";
        cout << "2. Arrange List Alphabetically (Insertion Sort)\n";
        cout << "3. Display Top 10 Toppers (Quick Sort)\n";
        cout << "4. Search by SGPA\n";
        cout << "5. Search by Name (Binary Search)\n";
        cout << "6. Exit\n\n";

        cout<<"Enter you choice:";
        cin>>ch;


        switch(ch){
            case 1:
                rollBubble(s,n);
                display(s,n);
                break;

            case 2:
                nameInsertion(s,n);
                display(s,n);
                break;

            case 3:
                quickSort(s,0,n-1);
                displayTop(s,n);
                break;

            case 4:
                float key;
                cout<<"enter sgpa to search:";
                cin>>key;
                searchSGPA(s,n,key);
                break;

            case 5:
                cout<<"Enter the name to be search: ";
                cin>>val;
                nameInsertion(s,n);
                nameSeach(s,n,val);
                break;
                
            case 6:
                loop=false;
                break;

            default:
                cout<<"\nInvalid choice...!";

        }
    }
    

    return 0;
}