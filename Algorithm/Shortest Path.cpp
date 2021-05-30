#include<iostream>
#define mx 20
#define inf 0x3f3f3f3f


int n,k;
int mapp[mx][mx],mem[mx];
//int ans=inf;

int short_path(int x){
	if(x==n-1){
		return 0;
	}
    if(mem[x]!=-1){
        return mem[x];
    }
    int ans=inf;
	for(int i=0;i<n;i++){
		if(mapp[x][i]!=-1){
			ans=std::min(ans,short_path(i)+mapp[x][i]);
			printf("ans=%d\n",ans);
		}
	}

    mem[x]=ans;
	return mem[x];
}


int main(){
	int p;
	scanf("%d %d",&n,&p);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mapp[i][j]=-1;
		}
	}

	for(int i=0;i<n;i++)
        mem[i]=-1;

	int a,b,val;
	while(p--){
		scanf("%d %d %d",&a,&b,&val);
		mapp[a][b]=val;
	}

	int res=short_path(0);

	printf("shortest path=%d\n",res);

}

/*
5 6
0 1 2
0 3 1
3 1 3
1 2 1
1 4 9
2 4 3
*/
