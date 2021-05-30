#include<iostream>
#include<algorithm>
#include<vector>

int main(){
	int mid,search;
	scanf("%d",&search);
	int arr[]={50,100,70,30,60,40,20,80,90,10};
	int sz=sizeof(arr)/sizeof(int);
	sort(arr,arr+sz);
	//printf("%d\n",sz);
	int bottom=0;
	int top=sz-1;
	mid=sz/2-1;

	while(arr[mid]!=search){
		if(arr[mid]>search){
			top=mid;
		}
		else if(arr[mid]<search){
			bottom=mid;
		}

		mid=(bottom+top)/2;
	}

	printf("The number is at the %dth position\n",mid);

	return 0;
}