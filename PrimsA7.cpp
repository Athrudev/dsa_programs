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
int mindist(int dist[],bool visited[]){
	int min=INT_MAX,min_index;
	
	for(int v=0;v<V;v++){
		
		if(visited[v]==false && dist[v]<min){
			min=dist[v];
			min_index=v;
		}
	}
	return min_index;
}
void primsAlgorithm(int graph[][V]){
	//making data structures
	bool visited[V];
	int dist[V];
	int parent[V];
	
	int u;
	
	//initializing
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		visited[i]=false;
	}
	dist[0]=0;
	parent[0]=-1;
	
	for(int count=0;count<V-1;count++){
		
		//finding current node
		u=mindist(dist,visited);
		
		//mark u as visited
		visited[u]=true;
		
		for(int v=0;v<V;v++){
			
			if(visited[v]!=true && graph[u][v]  && graph[u][v]<dist[v]){
				
				parent[v]=u;
				dist[v]=graph[u][v];
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