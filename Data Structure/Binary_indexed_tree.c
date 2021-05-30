#include<stdio.h>


int query(int id,int *bit){
	int sum=0;
	while(id!=0){
		sum+=bit[id];
		id-=(id & (-id));
	}

	return sum;
}

void updateBIT(int x,int id,int *bit,int n){
	while(id<=n){
		bit[id]+=x;
		id+=(id & (-id));
	}
}

int main(){
	int n,q,i,j;

	scanf("%d %d",&n,&q);
	int arr[n+5],BIT[n+5];

	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		BIT[i]=0;
	}

	for(i=1;i<=n;i++){
		//this loop constructs the initial binary index tree using its updateBIT() function
		updateBIT(arr[i],i,BIT,n);
	}

	int x,result;
	char c;
	while(q--){
		scanf("%d",&x);
		result=query(x,BIT);
		printf("Sum from first to the %dth index= %d\n",x,result);
	}

	return 0;
}
