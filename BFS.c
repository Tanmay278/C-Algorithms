#include<stdio.h>
#define MAX 20
int visited[MAX],mat[MAX][MAX]={{0,1,1,1},{1,0,0,1},{1,0,0,1},{1,1,1,0}},Q[MAX],front=0,rear=0;

void BFS(int start,int num){
	int i,j,k;
	for(i=0;i<num;i++){
		visited[i]=0;
		Q[i]=0;
	}
	visited[start]=1;
	Q[rear++]=start;
	while(front<=rear){
		j=Q[++front];
		for(k=0;k<num;k++){
			if(mat[j][k]==1 && visited[k]==0){
				visited[k]=1;
				Q[rear++]=k;
				printf("%d  \n",k);
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	int n,i,j,v;
	n=4;
	printf("\nEnter the starting vertex:");
	scanf("%d",&v);
	BFS(v,n);
	for(i=0;i<n;i++)
		printf("  %d",visited[i]);
	return 0;
}
