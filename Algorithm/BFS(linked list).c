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

int q[1000];
int top=-1,bottom=0;

void pushNode(int node){
    top++;
    q[top]=node;
}

int popNode(){
    int node=q[bottom];
    bottom++;
    if(bottom==top+1){
        top=-1;
        bottom=0;
    }
    return node;
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}


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

void bfs(struct node** adjList,int startingNode,int *visited){
    struct node* temp;
    pushNode(startingNode);
    visited[startingNode]=1;

    while(isEmpty()==0){
        int currentNode=popNode();
        printf("%d Visited\n",currentNode);
        temp=adjList[currentNode];
        while(temp!=NULL){
            int adjNode=temp->vertex;
            if(visited[adjNode]==0){
                visited[adjNode]=1;
                pushNode(adjNode);
            }
        temp=temp->next;
        }
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

    struct graph* bfsGraph=createGraph(nodes);


    printf("Enter node pairs creating edges:\n");
    while(edges--){
        scanf("%d %d",&src,&des);
        createEdge(bfsGraph->adjList,src,des);
    }

    bfs(bfsGraph->adjList,0,visited);

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

