#include<stdio.h>
//#define n 5
#define MAX 20
int visited[MAX],parent[MAX],mat[MAX][MAX];
//={{0,1,1,1,0},{1,0,1,0,0},{1,1,0,0,1},{1,0,0,0,0},{0,0,1,0,0}}
void DFS(int start,int n){
	int i,j;
	visited[start]=1;
	i=start;
	for(j=0;j<n;j++){
		if(mat[i][j]==1 && visited[j]==0){
			visited[j]=1;
			printf("%d\n",j);
			parent[j]=i;
			DFS(j,n);
		}
	}
}

int main()
{
	int v,i,n,j;
	printf("Enter the number of vertices:"); scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	    scanf("%d",&mat[i][j]);
	printf("\nEnter the starting vertex:");
	scanf("%d",&v);
	for(i=0;i<n;i++){
		visited[i]=0;
		parent[i]=-1;
	}
	DFS(v,n);
	for(i=0;i<n;i++)
		printf("  %d",visited[i]);
	return 0;
}
