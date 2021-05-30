#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define inf 0x3f3f3f3f //infinity

using namespace std;

vector<vector<pair<int,int>>> adj; //Adjacency list, adjacent nodes are stored with edgSe weight in a pair type data structure
vector<int> key,parent;
vector<bool> selected;//true=in tree...false=not in tree

void join(int src, int des, int w){
	adj[src].push_back(make_pair(des,w));
	adj[des].push_back(make_pair(src,w));
}

int main(){
	int n,e,src,des,w,sn,minWeight=0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //Used stl priority_queue with a constructor that return mean heap instead of max heap

	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the number of edges:\n");
	scanf("%d",&e);

	adj.assign(n+3,vector<pair<int,int>>());
	selected.assign(n+3,false);
	parent.assign(n+3,-1);
	key.assign(n+3,inf);

	for(int j=0;j<e;j++){
		scanf("%d %d %d",&src,&des,&w);
		join(src,des,w);
		if(j==0){
			sn=src;
		}
	}

	selected[sn]=true;
	key[sn]=0;

	pq.push(make_pair(key[sn],sn));

	while(pq.empty()==false){
		int node=pq.top().second;
		pq.pop();

		selected[node]=true;

		for(auto i=adj[node].begin();i!=adj[node].end();i++){
			int v=i->first;
			int weight=i->second;

			if(selected[v]==false && key[v]>weight){
				key[v]=weight;
				pq.push(make_pair(key[v],v));
				parent[v]=node;
			}
		}

	}

	printf("MST edges:\n");

	for(int k=0;k<=n;k++){
		if(parent[k]==-1)
			continue;

		printf("%d %d\n",parent[k],k);
	}

    for(int k=0;k<=n;k++){
        if(key[k]==inf)
            continue;
        minWeight+=key[k];
    }

	printf("\nTotal Weight= %d\n",minWeight);

	return 0;
}
/*
Test Case 1:
9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
/////////
Test Case 2:
8
16
1 6 54
1 5 80
1 3 47
3 5 23
3 6 75
3 2 55
5 7 93
5 2 32
7 3 66
3 4 88
6 4 74
4 8 29
4 2 31
2 8 79
8 7 68
2 7 74
*/
