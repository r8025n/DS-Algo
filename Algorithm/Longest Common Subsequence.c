#include<stdio.h>
#include<string.h>

char str1[100],str2[100];
int mem[105][105];

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}


int lcs(int i,int j,int n,int m){
    if(i==n || j==m){
        return 0;
    }

    if(mem[i][j]!=-1)
        return mem[i][j];

    int ans=0;
    if(str1[i]==str2[j]){
        ans=1+lcs(i+1,j+1,n,m);
    }
    else{
        int opt1=lcs(i+1,j,n,m);
        int opt2=lcs(i,j+1,n,m);

        ans=max(opt1,opt2);
    }
    mem[i][j]=ans;
    return mem[i][j];
}


int main(){
    memset(mem,-1,sizeof(mem));
    scanf("%s",str1);
    scanf("%s",str2);
    int n=strlen(str1);
    int m=strlen(str2);


    int result=lcs(0,0,n,m);

    printf("Length of the longest common subsequence= %d\n",result);

    return 0;
}



/*
HELLOM
HMRLL
*/