#include<iostream>
#define mx 100

int mem[mx];

int n;

int lis(int i,int *arr){
    if(mem[i]!=-1)
        return mem[i];

	int ans=0;
	for(int k=i+1;k<n;k++){
		if(arr[i]<arr[k]){
            ans=std::max(ans,1+lis(k,arr));
		}
	}
	mem[i]=ans;
	return mem[i];
}

int main(){
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		mem[i]=-1;
	}

	int result=0;
	for(int i=0;i<n;i++){
		result=std::max(result,1+lis(i,arr));
	}

	printf("Longest Increasing Subsequence=%d\n",result);

	return 0;
}

/*
7
5 0 9 2 7 3 4
*/
