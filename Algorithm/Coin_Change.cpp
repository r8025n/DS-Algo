//some coins are given and coin of each value can be used only once, have to achieve the given total money by using least number of coins
#include<iostream>
#define inf 0x3f3f3f3f


int arr[25];//assuming highets number of coins will  be 25
int n;
int mem[25][100]; //assuming highest amount will be 100

int coin_change(int i,int w,int n){
    if(w<0){
        return inf;
    }

    if(i==n){
        if(w==0)
            return 0;
        else
            return inf;
    }

    if(mem[i][w]!=-1){
        return mem[i][w];
    }

    int opt1=1+coin_change(i+1,w-arr[i],n);
    int opt2=coin_change(i+1,w,n);

    /*
    //if infinite number of each coins can be used then the code will change

    int opt1=1+coin_change(i,w-arr[i],n);
    int opt2=coin_change(i+1,w,n);

    //and summation will be required,not the minimum
    int res=opt1+opt2;
    */

    int res=std::min(opt1,opt2);


    mem[i][w]=res;
    return mem[i][w];
}


int main(){
    int w;
    scanf("%d %d",&n,&w);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            mem[i][j]=-1;
        }
    }

    int res=coin_change(0,w,n);

    printf("minimum number of coins required: %d\n",res);

    return 0;
}
