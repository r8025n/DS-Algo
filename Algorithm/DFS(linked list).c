#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int vertex;
    struct node* next;
};

struct graph{
    int numberOfNodes;
    struct node** adjList;
};

struct node* createNode(int x){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->vertex=x;
    newNode->next=NULL;

    return newNode;
}

struct graph* createGraph(int n){
    struct graph* newGraph=(struct graph*)malloc(n*sizeof(struct graph));
    newGraph->numberOfNodes=n;
    newGraph->adjList=(struct node**)malloc(n*sizeof(struct node*));

    for(int i=0;i<n;i++){
        newGraph->adjList[i]=NULL;
    }

    return newGraph;
}

void createEdge(struct node** adjList,int src,int des){
    //from source to destination
    struct node* tempNode=createNode(des);
    tempNode->next=adjList[src];
    adjList[src]=tempNode;

    //from destination to source
    tempNode=createNode(src);
    tempNode->next=adjList[des];
    adjList[des]=tempNode;
}

void dfs(struct node** adjList,int startingNode,int *visited){
    struct node* temp=adjList[startingNode];
    visited[startingNode]=1;
    printf("%d visited\n",startingNode);

    while(temp!=NULL){
        int node=temp->vertex;
        if(visited[node]!=1){
            dfs(adjList,node,visited);
        }
        temp=temp->next;
    }
}

int main(){
    int nodes,edges;
    int src,des;
    printf("Enter Number of nodes:\n");
    scanf("%d",&nodes);
    printf("Enter Number of edges:\n");
    scanf("%d",&edges);

    int visited[nodes+3];
    memset(visited,0,sizeof(visited));

    struct graph* dfsGraph=createGraph(nodes);

    
    printf("Enter node pairs creating edges:\n");
    
    while(edges--){
        scanf("%d %d",&src,&des);
        createEdge(dfsGraph->adjList,src,des);
    }

    dfs(dfsGraph->adjList,0,visited);

    return 0;
}

/*
10
12
0 8
1 9
1 2
1 7
1 3
2 8
2 4
3 5
3 4
5 6
7 6
8 9
*/

