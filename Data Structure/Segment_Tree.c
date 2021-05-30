#include<stdio.h>


void init(int node,int b,int e,int *arr,int *tree){
	if(b==e){
		tree[node]=arr[b];
		return;
	}

	int left=2*node;
	int right=(2*node)+1;
	int mid=(b+e)/2;

	init(left,b,mid,arr,tree);
	init(right,mid+1,e,arr,tree);

	tree[node]=tree[left]+tree[right];
}

int query(int i,int j,int node,int b,int e,int *tree){
	if(b>j || e<i)
		return 0;
	if(b>=i && j<=e){
		return tree[node];
	}

	left=2*node;
	right=(2*node)+1;

	mid=(b+e)/2;
	int r1=query(i,j,left,b,mid,tree);
	int r2=query(i,j,right,mid+1,e,tree);

	return r1+r2;
}

void update(int i,int x,int node, int b,int e,int *tree){
	if(i<b || i>e)
		return;
	if(b==i && e==i){
		tree[node]=x;
		return;
	}

	left=2*node;
	right=(2*node)+1;
	mid=(b+e)/2;

	update(i,x,left,b,mid,tree);
	update(i,x,right,mid+1,tree);

	tree[node]=tree[left]+tree[right];
}


int main(){
	int n,i,q;
	scanf("%d",&n,&q);
	int arr[n+5],segT[n*3+5];
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}

	init(1,1,n,arr,segT);

	while(q--){
		//queries will go here
	}

	return 0;
}