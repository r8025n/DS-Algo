////
//topological sorting using BFS and indegree approach
//First pushed all the nodes with indegree=0 to queue
//then run BFS with any one of them

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj; //adjacency list
vector<int> indegree; //to keep track of the indegree values
queue<int> q;

//function to create the adjacency list
void join(int src, int des){
	adj[src].push_back(des);
	indegree[des]=indegree[des]+1;
}

//bfs function for topological sorting
void t_sort(){
	while(q.empty()==false){
		int node=q.front();
        printf("%d->",node); //whenever a node is popped from the q, it is considered the next sorted element and printed
		q.pop();

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			indegree[*i]=indegree[*i]-1;
			//nodes whose indegrees becoming 0 during bfs, pushed to q
			if(indegree[*i]==0){
				q.push(*i);
			}
		}
	}
}

int main(){
	int n,e,i,j,sn,src,des;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the number of edges:\n");
	scanf("%d",&e);
	adj.assign(n,vector<int>());
	indegree.assign(n,0);

	printf("Enter the edges:\n");
	for(i=0;i<e;i++){
		scanf("%d %d",&src,&des);
		join(src,des);
	}

	for(j=0;j<n;j++){
		if(indegree[j]==0){
			q.push(j);
		}
	}

	t_sort();

	return 0;
}

/*
Test Case:
6
6
5 0
5 2
4 0
4 1
2 3
3 1
*/
