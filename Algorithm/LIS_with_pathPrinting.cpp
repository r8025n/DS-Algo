#include<iostream>
#define mx 100

int mem[mx],next_index[mx];
int n;

int lis(int i,int *arr){
    if(mem[i]!=-1)
        return mem[i];

	int ans=0;
	for(int k=i+1;k<n;k++){
		if(arr[i]<arr[k]){
			int res=1+lis(k,arr);
			if(res>ans){
				ans=res;
				next_index[i]=k;
			}
		}
	}
	mem[i]=ans;
	return mem[i];
}

void print_path(int start_index,int *arr){
	printf("Longest Increasing Subsequence: ");
	while(start_index!=-1){
		printf("%d -> ",arr[start_index]);
		start_index=next_index[start_index];
	}
	printf("\n");
}

int main(){
	scanf("%d",&n);
	int arr[n];

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		mem[i]=-1;
		next_index[i]=-1;
	}

	int temp,result=0,start_index;
	for(int i=0;i<n;i++){
		temp=1+lis(i,arr);
		if(temp>result){
			result=temp;
			start_index=i;
		}
	}

	printf("\nLongest Increasing Subsequence length=%d\n\n",result);

	print_path(start_index,arr);

	return 0;
}

/*
7
5 0 9 2 7 3 4
*/
