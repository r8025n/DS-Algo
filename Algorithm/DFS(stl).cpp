#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> visit; //(visit[i]=0)-> not visited.....(visit[i]=1) -> visited

void createEdge(int src,int des){
  adj[src].push_back(des);
  adj[des].push_back(src);
}

void DFS(int sn){
  if(visit[sn]==1)
    return;

  visit[sn]=1;

  printf("Visited %d\n",sn);

  for(int i=0;i<adj[sn].size();i++){
    DFS(adj[sn][i]);
  }
}

int main(){
  int n,e,sn,a,b,i;
  printf("Enter the number of nodes:\n");
  scanf("%d",&n);
  //commented part is used for taking inputs from users
  
  /*printf("Enter the number of edges:\n");
  scanf("%d",&e);*/
  printf("Enter the starting node:\n");
  scanf("%d",&sn);

  visit.assign(n,0);
  adj.assign(n,vector<int>());

  /*for(i=0;i<e;i++){
    scanf("%d %d",&a,&b);
    createEdge(a,b);
  }*/

  createEdge(0,8);
  createEdge(1,9);
  createEdge(1,2);
  createEdge(1,7);
  createEdge(1,3);
  createEdge(2,8);
  createEdge(2,4);
  createEdge(3,5);
  createEdge(3,4);
  createEdge(5,6);
  createEdge(7,6);
  createEdge(8,9);

  for(i=0;i<n;i++){
    if(visit[i]!=1)
        DFS(i);
  }

  return 0;
}
