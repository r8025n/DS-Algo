#include<stdio.h>

#define mx 100000

int arr[mx+5];
struct info{
	int sum;
	int prop=0;
} segT[mx*3+5];

void init(int node,int b,int e){
	if(b==e){
		segT[node].sum=arr[b];
		return;
	}

	int left=2*node;
	int right=2*node+1;
	int mid=(b+e)/2;

	init(left,b,mid);
	init(right,mid+1,e);

	segT[node].sum=segT[left].sum+segT[right].sum;
}

void update(int node,int b,int e,int i,int j,int x){
	if(b>j || e<i)
		return;

	if(b>=i && e<=j){
		segT[node].sum+=((e-b+1)*x);
		segT[node].prop+=x;
		return;
	}

	int left=node*2;
	int right=node*2+1;
	int mid=(b+e)/2

	update(left,b,mid,i,j,x);
	update(right,mid+1,e,i,j,x);

	segT[node].sum=segT[left].sum+segT[right].sum+(e-b+1)*segT[node].prop;
}

int query(int node,int b,int e,int i,int j,int carry){
	if(b>j || e<i)
		return 0;
	if(b>=i && e<=j){
		return segT[node].sum+carry;
	}

	left=node*2;
	right=2*node+1;
	mid=(b+e)/2;

	int s1=query(left,b,mid,i,j,carry+segT[node].prop);
	int s2=query(right,mid+1,e,i,j,carry+segT[node].prop);

	return s1+s2;
}


int main(){
	int n,q,i;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}

	init(1,1,n);

	while(q--){
		//update
		//query
	}

	return 0;
}