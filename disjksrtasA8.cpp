#include<iostream>
#include<limits.h>
using namespace std;
#define V 3




void printGraph(int dist[]){
    cout<<"\nminimum distance is:\n";
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t\t"<<dist[i]<<endl;
    }
}

int minDistance(int dist[],bool visited[]){
    int min=INT_MAX;
    int min_index;

    for(int i=0;i<V;i++){
        if(!visited[i] && dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }

    return min_index;
}



void dijkstras(int graph[V][V]){

    int dist[V];
    bool visited[V];
    int u;//current
    for(int i=0;i<V;i++){

        dist[i]=INT_MAX;
        visited[i]=false;

    }

    dist[0]=0;

    for(int i=0;i<V-1;i++){
        u=minDistance(dist,visited);

        visited[u]=true;

        for(int v=0;v<V;v++){
            if(!visited[v]&&graph[u][v] &&
            dist[u]!=INT_MAX &&
            dist[u]+graph[u][v]<dist[v] ){
                dist[v]=dist[u]+graph[u][v];
            }
        }

        
    }

    printGraph(dist);

}

int main(){

    int graph[V][V] = {
    {0, 4, 0},  // Weights for edges from vertex 0
    {4, 0, 3},  // Weights for edges from vertex 1
    {0, 3, 0}   // Weights for edges from vertex 2
};

    dijkstras(graph);
    return 0;
}