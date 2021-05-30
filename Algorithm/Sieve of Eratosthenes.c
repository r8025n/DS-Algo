#include<stdio.h>

int main(){
	int n=1010,x;
	int arr[n+3];
	arr[0]=-1;
	arr[1]=-1;
	arr[2]=2;
	for(int i=3;i<=n;i++){
        if(i%2==0){
        	//even numbers except 2 are removed at the beginning
            arr[i]=-1;
        }
        else{
            arr[i]=i;
        }
	}
	//search for the first number in the array which is not -1, let that number x
	for(int i=3;i*i<=n;i++){
		if(arr[i]!=-1){
			x=arr[i];
			//now remove the multiples of x if x*x<n
			for(int k=2;k*x<n;k++){
				arr[x*k]=-1;
			}
		}
	}
	//remaining numbers which are not -1 are the primes
	for(int k=0;k<=n;k++){
		printf("%d,",arr[k]);
	}
}
