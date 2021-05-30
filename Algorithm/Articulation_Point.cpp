#include<iostream>
#include<vector>
#include<queue>


using namespace std;

vector<vector<int>> adj;
vector<int> visited,low,dis,parent;
queue<int> articulationPoint;
vector<bool> artP;//false=not an articulation point, true=articulation point
int t=0,root;

void join(int src, int des){
	adj[src].push_back(des);
	adj[des].push_back(src);
}

void dfsMod(int sn){
	t++;
	visited[sn]=1;
	dis[sn]=low[sn]=t;
    int child=0;
	for(auto i=adj[sn].begin();i!=adj[sn].end();i++){
		if(*i==parent[sn]){
			continue;
		}
		if(visited[*i]==1){
			low[sn]=min(low[sn],dis[*i]);
		}
		else if(visited[*i]!=1){
			parent[sn]=*i;
			dfsMod(*i);
			low[sn]=min(low[sn],low[*i]);
			if(dis[sn]<=low[*i] && sn!=root){
                printf("%d\n",sn);
				artP[sn]=true;
			}
			child++;
		}
		if(child>1 && sn==root){
            artP[root]=true;
		}
	}
}




int main(){
	int i,n,e,sn,src,des,node,c=0;
	printf("Enter the number of vertices:\n");
	scanf("%d",&n);

	adj.assign(n+3,vector<int>());
	visited.assign(n+3,0);
	artP.assign(n+3,false);
	low.assign(n+3,0);
	parent.assign(n+3,0);
	dis.assign(n+3,0);

	printf("Enter the number of edges:\n");
	scanf("%d",&e);
	printf("Enter thge edges:\n");
	for(i=0;i<e;i++){
		scanf("%d %d",&src,&des);
		join(src,des);
	}
	printf("Enter the root node:\n");
	scanf("%d",&root);
	sn=root;

	dfsMod(sn);

	printf("Articulation Points:\n");
	for(int j=0;j<=artP.size();j++){
        if(artP[j]){
        	c++;
            printf("%d ",j);
        }
	}
	if(c==0){
		printf("No Aritculation Point detected\n");
	}

	return 0;
}
/*
Test Case 1:
7
7
1 2
1 3
3 4
3 7
4 5
4 6
6 7
////
Test Case 2:
6
7
1 2
1 3
2 4
3 4
4 5
4 6
5 6
*/
