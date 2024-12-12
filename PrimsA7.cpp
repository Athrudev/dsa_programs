#include<iostream>
using namespace std;
# define V 5
const int INT_MAX=10;

void printMST(int parent[],int graph[][V]){
	cout<<"parent\t\t vertex\t\tweight "<<endl;
	for(int v=0;v<V;v++){
		cout<<parent[v]<<"\t\t"<<v<<"\t\t"<<graph[parent[v]][v]<<endl;
	}
}
int minKey(int key[],bool visited[]){
	int min=INT_MAX,min_index;
	
	for(int v=0;v<V;v++){
		
		if(visited[v]==false && key[v]<min){
			min=key[v];
			min_index=v;
		}
	}
	return min_index;
}
void primsAlgorithm(int graph[][V]){
	//making data structures
	bool visited[V];
	int key[V];
	int parent[V];
	
	int current;
	
	//initializing
	for(int i=0;i<V;i++){
		key[i]=INT_MAX;
		visited[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	
	for(int count=0;count<V-1;count++){
		
		//finding current node
		current=minKey(key,visited);
		
		//mark current as visited
		visited[current]=true;
		
		for(int v=0;v<V;v++){
			
			if(visited[v]!=true && graph[current][v]  && graph[current][v]<key[v]){
				
				parent[v]=current;
				key[v]=graph[current][v];
			}
		}
		
	}
	printMST(parent,graph);
}
int main(){
	int graph[V][V]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
	primsAlgorithm(graph);
	return 0;
}