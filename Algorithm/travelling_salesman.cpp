#include<iostream>

#define inf 0x3f3f3f3f
#define mx 22

using namespace std;


int dis[mx][mx];
int mem[mx][1<<mx];
int n;

int turnOn(int mask,int pos){
	return mask | (1<<pos);
}

bool isOn(int mask,int pos){
	return (bool)(mask & (1<<pos));
}

int distance(int i,int mask){
	if(mask==(1<<n)-1)
		return dis[i][0];

	if(mem[i][mask]!=-1)
		return mem[i][mask];
	int ans=inf;
	for(int j=0;j<n;j++){
		if(dis[i][j]==inf)
			continue;
		if(isOn(mask,j)==0){
			int result=distance(j,turnOn(mask,j))+dis[i][j];
			ans=min(ans,result);
			printf("answer=%d\n",ans);
		}
	}

	return mem[i][mask]=ans;
}


int main(){
	int p;
	scanf("%d %d",&n,&p);

	int lim=1<<n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dis[i][j]=inf;
		}
		for(int k=0;k<lim;k++){
			mem[i][k]=-1;
		}
	}

	int src,des,d;
	while(p--){
		scanf("%d %d %d",&src,&des,&d);
		dis[src][des]=d;
		dis[des][src]=d;
	}

	int result=distance(0,1);

	printf("Minimum distance= %d\n",result);

	return 0;
}


/*
here is the test data:

n=5,p=8

i j distance

0 1 1
0 3 9
0 4 4
1 2 3
1 3 2
3 2 4
3 4 3
2 4 2

*/
