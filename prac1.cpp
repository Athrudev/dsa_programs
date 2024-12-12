#include<iostream>
using namespace std;
struct student{
	string name;
	int roll;
	double gpa;
};
/*
int partition(struct student it[],int low,int high){
	
	struct student pivot=it[low];
	int i=low,j=high;
	
	while(i<j){
		while(i<=high && it[i].gpa<=pivot.gpa){
			i++;
		}
		
		while(j<=low && it[j].gpa>pivot.gpa){
			j--;
		}
		
		if(i<j){
			swap(it[i],it[j]);
		}
	}
	swap(it[low],it[j]);
	return j;
}

void quickSort(struct student it[],int low,int high){
	if(low<high){
		int p=partition(it,low,high);
		quickSort(it,low,p-1);
		quickSort(it,p+1,high);
	}
}
*/
/*
void insertionSort(struct student it[]){
struct student temp;
for (int i = 0; i < n - 1; i++) {
    int j = i + 1;
     temp = it[j]; // Assuming `it` is an array or vector of a struct/class with a `gpa` field.
    while (j > 0 && it[j - 1].gpa > temp.gpa) {
        it[j] = it[j - 1];
        j--;
    }
    it[j] = temp;
}
}
*/
int binarySearch(struct student it[],int n,int target){

	
	int low=0;
	int high=n-1;
	int mid;
	
	while(low<=high){
		
		mid=(low+high)/2;
		
		if(it[mid].roll==target){
			return mid;
		}
		else if(it[mid].roll>target){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;
}
void insertionSort(struct student it[],int n){
	struct student temp;
	for(int i=0;i<n-1;i++){
		int j=i+1;
		temp=it[j];
		
		while(it[j-1].gpa>temp.gpa && j>0){
			it[j]=it[j-1];
			j--;
			
		}
		it[j]=temp;
	}
}
int partition(struct student it[],int low,int high){
	struct student pivot=it[low];
	int i=low,j=high;
	
	while(i<j){
		while(i<=high&& it[i].gpa<=pivot.gpa){
			i++;
		}
		
		while(j>=0 && it[j].gpa>pivot.gpa){
			j--;
		}
		if(i<j){
			swap(it[i],it[j]);
		}
	}
	swap(it[low],it[j]);
	return j;
}
void quickSort(struct student it[],int low,int high){
	if(low<high){
		int p=partition(it,low,high);
		quickSort(it,low,p-1);
		quickSort(it,p+1,high);
	}
}
int main(){

	struct student it[3]={{"harsh",15,8.5},{"yash",12,3.0},{"om",55,5.5}};
	int n=3,j;
	struct student temp;
	int target;
	
	cout<<"enter the roll no. to search :"<<endl;
	cin>>target;
	
	int pos=binarySearch(it,n,target);
	if(pos==-1){
		cout<<"record not found !"<<endl;
	}
	else{
		cout<<"data of stud with roll no. "<<target<<" :"<<endl<<endl;
		cout<<"name :"<<it[pos].name<<endl;
		cout<<"roll :"<<it[pos].roll<<endl;
		cout<<"gpa :"<<it[pos].gpa<<endl<<endl;
	}
	
	
	//quickSort(it,0,n-1);
	
	cout<<"student data :"<<endl;
	for(int i=0;i<n;i++){
		cout<<"data of stud no."<<i<<" :"<<endl<<endl;
		cout<<"name :"<<it[i].name<<endl;
		cout<<"roll :"<<it[i].roll<<endl;
		cout<<"gpa :"<<it[i].gpa<<endl<<endl;
		
	}
	return 0;
}

	/*	
	for(int i=0;i<n;i++){
		cout<<"Enter data of student no."<<i<<" :"<<endl;
		cout<<"Enter name:"<<endl;
		cin>>it[i].name;
		cout<<"Enter roll no.:"<<endl;
		cin>>it[i].roll;
		cout<<"Enter gpa:"<<endl;
		cin>>it[i].gpa;
	}


for(int i=0;i<n-1;i++){
	for(int j=0;j<n-i-1;j++){
		if(it[j+1].gpa<it[j].gpa){
			swap(it[j],it[j-1]);
		}
	}
}

		
*/
