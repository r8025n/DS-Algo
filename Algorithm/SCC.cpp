/////
//used the two dfs method to find the Strongly connected components

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> adj; //adjacency list
vector<vector<int>> adjT; //transpose adjacency list
vector<int> visited; //0=not visited...1=visited
stack<int> s;
int flip,scc=0;

void join(int src, int des){
	adj[src].push_back(des);
	adjT[des].push_back(src);
}

//when flip=0, dfs will traverse adjacency and during return push the nodes to a stack
//when flip=1, dfs will traverse the transpose adjacency matrix popping unvisited nodes from stack and print the SCC's
void dfs(int sn, vector<vector<int>> a){
	visited[sn]=1;

	///flip=1
	if(flip==1){
        printf("%d ",sn);
	}

	for(auto i=a[sn].begin();i!=a[sn].end();i++){
		if(visited[*i]!=1){
			dfs(*i,a);
		}
	}
	///flip=0
	if(flip==0){
        s.push(sn);
	}
}


int main(){
	int n,e,i,src,des;
	flip=0;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the number of edges:\n");
	scanf("%d",&e);

	adj.assign(n+2,vector<int>());
	adjT.assign(n+2,vector<int>());
	visited.assign(n+2,0);

	for(i=0;i<e;i++){
		scanf("%d %d",&src,&des);
		join(src,des);
	}

	//flip=0 and dfs on the adjacency list
	for(i=0;i<n;i++){
		if(visited[i]!=1){
			dfs(i,adj);
		}
	}

	flip=1;
	visited.assign(n+2,0);

	//flip=1 and dfs on the transpose list taking nodes from top of the stack
	while(s.empty()==false){
		int node=s.top();
		s.pop();
		if(visited[node]!=1){
            scc++;
            printf("SCC %d-> ",scc);
			dfs(node,adjT);
			printf("\n");
		}
	}

	return 0;
}

/*
Testcases 1:

8
13
0 1
4 0
1 4
1 5
4 5
1 2
2 3
3 2
5 6
6 5
7 6
7 3
3 7

TestCase 2:

8
9
0 1
1 2
2 3
2 4
3 0
4 5
5 6
6 4
6 7

*/
