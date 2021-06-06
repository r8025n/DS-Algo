#include<stdio.h>

void merge(int* arr,int lo,int mid,int hi){
    int arr1Size;
    int arr2Size;

    int leftArrSize=mid-lo+1;
    int rightArrSize=hi-mid;

    //temporary array for temporarily store left and right halves
    int left[leftArrSize],right[rightArrSize];

    for(int i=0;i<leftArrSize;i++){
        left[i]=arr[lo+i];
    }

    for(int i=0;i<rightArrSize;i++){
        right[i]=arr[mid+1+i];
    }

    //marging left and right halves
    //ll=left array  index, rr=right array index, k=main array index
    int ll=0,rr=0,k=lo;
    while(ll<leftArrSize && rr<rightArrSize){
        if(left[ll]<=right[rr]){
            arr[k]=left[ll];
            ll++;
        }
        else{
            arr[k]=right[rr];
            rr++;
        }
        k++;
    }

    //if any element left in left array
    while(ll<leftArrSize){
        arr[k]=left[ll];
        ll++;
        k++;
    }
    //if any element left in right array
    while(rr<rightArrSize){
        arr[k]=right[rr];
        rr++;
        k++;
    }


}


void mergeSort(int* arr,int lo,int hi){

    if(lo>=hi)
        return;

    int mid=(hi+lo)/2;

    mergeSort(arr,lo,mid);
    mergeSort(arr,mid+1,hi);

    merge(arr,lo,mid,hi);
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    mergeSort(arr,0,n-1);

    printf("\nSorted Array:\n");

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("\n");

    return 0;
}

/*
10
9 100 50 20 1 1000 1001 5 99 10
*/
