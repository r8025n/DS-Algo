#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
vector<int> parent(n+3);

//structure for storing an edge with its two nodes and weight
struct edge{
	int uu,vv,ww;
	//sort edges according to weight
	bool operator<(const edge& p) const{
		return ww<p.ww;
	}
};

//find the root node of a node
int root(int u){
	while(parent[u]!=u){
		u=parent[u];
	}

	return u;
}

//join two nodes
void uunion(int u, int v){
	int a=root(u);
	int b=root(v);

	parent[a]=b;
}

//check if two nodes are in same connected component  
bool isConnected(int u, int v){
	if(root(u)==root(v)){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	int e,u,v,w,uuu,vvv,www,ccount=0,minW=0;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the number of edges\n");
	scanf("%d",&e);

	vector<edge> ee(n+3);
	edge edg;
    //parent.assign(n+3,)
	for(int i=0;i<n;i++){
		parent[i]=i;
	}

	for(int i=0;i<e;i++){
		scanf("%d %d %d",&u,&v,&w);
		edg.uu=u;
		edg.vv=v;
		edg.ww=w;

		ee.push_back(edg);
	}

	sort(ee.begin(),ee.end());
    printf("\nMST edges:\n");
	for(int i=0;i!=(int)ee.size();i++){
		uuu=ee[i].uu;
		vvv=ee[i].vv;
		www=ee[i].ww;

		if(!isConnected(uuu,vvv)){
			uunion(uuu,vvv);
			printf("%d %d\n",uuu,vvv);
			ccount++;
			minW+=www;
		}
		if(ccount==n-1){
			break;
		}
	}

	printf("\nTotal Weight: %d\n",minW);
}
/*
Test Case:
8
16
0 5 54
0 4 80
0 2 47
2 4 23
2 5 75
2 1 55
4 6 93
4 1 32
6 2 66
2 3 88
5 3 74
3 7 29
3 1 31
1 7 79
7 6 68
1 6 74
*/
