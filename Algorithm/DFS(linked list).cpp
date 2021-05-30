#include<bits/stdc++.h>


struct node{
	int vertex;
	struct node* next;
};

struct node* newNode;

struct graph{
	int nv;
	struct node** adjList;
};

struct graph* newGraph;

struct node* createNode(int x){
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->vertex=x;
	newNode->next=NULL;

	return newNode;
}

struct graph* createGraph(int n){
	newGraph=(struct graph*)malloc(sizeof(struct graph));
	newGraph->nv=n;
	newGraph->adjList=(struct node**)malloc(n*sizeof(struct node));

	int i;
	for(i=0;i<n;i++){
		newGraph->adjList[i]=NULL;
	}

	return newGraph;
}

void createEdge(struct graph* g,int src,int des){
	//from source to destination
	newNode=createNode(des);
	newNode->next=g->adjList[src];
	g->adjList[src]=newNode;

	//from destination to source
	newNode=createNode(src);
	newNode->next=g->adjList[des];
	g->adjList[des]=newNode;
}

void dfs(struct graph* graph, int* visit, int sv){
	struct node* temp=graph->adjList[sv];

	visit[sv]=1;
	printf("Visited %d\n",sv);

	while(temp!=NULL){
		int vx=temp->vertex;
		if(visit[vx]==0){
			dfs(graph, visit, vx);
		}
		temp=temp->next;
	}

}




int main(){
	int n,sn;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the starting node:\n");
	scanf("%d",&sn);

	int visit[n+5];
	memset(visit,0,n*sizeof(visit[0]));

	struct graph* graph = createGraph(n);
	createEdge(graph, 0, 1);
	createEdge(graph, 0, 2);
	createEdge(graph, 1, 2);
	createEdge(graph, 2, 3);

  dfs(graph, visit, sn);
}
