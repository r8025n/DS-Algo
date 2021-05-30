#include<stdio.h>
#include<stdlib.h>


int front=-1;
int rear=-1;
int k;

struct node{
    int vertex;
    struct node* next;
};

struct node* newnode;

struct graph{
    int nv;
    struct node** adjlist;
};

struct graph* newgraph;

struct node* createNode(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->vertex=x;
    newnode->next=NULL;

    return newnode;
}

struct graph* createGraph(int v){
    newgraph=(struct graph*)malloc(sizeof(struct graph));
    newgraph->nv=v;
    newgraph->adjlist = (struct node*)malloc(v * sizeof(struct node*));

    int i;
    for(i=0;i<v;i++){
        newgraph->adjlist[i]=NULL;
    }

    return newgraph;
}

void createEdge(struct graph* ngraph, int src,int des){
    //src to des
    newnode=createNode(des);
    newnode->next=ngraph->adjlist[src];
    ngraph->adjlist[src]=newnode;

    //des to src
    newnode=createNode(src);
    newnode->next=ngraph->adjlist[des];
    ngraph->adjlist[des]=newnode;
}


void push(int* q, int value){
    if(rear == k-1)
        printf("\nQueue is Full!!");
    else {
        if(front == -1)
            front = 0;
        rear++;
        q[rear] = value;
    }
}

int pop(int* q){
    int item;
    if(rear==-1){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q[front];
        front++;
        if(front >rear){
            front = rear = -1;
        }
    }
    return item;
}

void bfs(int* q,int* visited,struct graph* graph, int startVertex) {

    visited[startVertex] = 1;
    push(q, startVertex);

    while(rear!=-1){
        int currentVertex = pop(q);
        printf("Visited %d\n", currentVertex);

       struct node* temp = graph->adjlist[currentVertex];

       while(temp!=NULL) {
            int adjVertex = temp->vertex;

            if(visited[adjVertex] == 0){
                visited[adjVertex] = 1;
                push(q, adjVertex);
            }
            temp = temp->next;
       }
    }
}

int main(){
    int i,x, sn;
    printf("Enter number of vertices:\n");
    scanf("%d",&x);
    k=x;
    printf("Insert the Start Node:\n");
    scanf("%d",&sn);

    int visit[x+5];
    int q[x+10];
    memset(visit,0,x*sizeof(visit[0]));

    struct graph* Graph=createGraph(x);

    createEdge(Graph,0,8);
    createEdge(Graph,1,9);
    createEdge(Graph,1,2);
    createEdge(Graph,1,7);
    createEdge(Graph,1,3);
    createEdge(Graph,2,8);
    createEdge(Graph,2,4);
    createEdge(Graph,3,5);
    createEdge(Graph,3,4);
    createEdge(Graph,5,6);
    createEdge(Graph,7,6);
    createEdge(Graph,8,9);

    bfs(q,visit,Graph,sn);
}
