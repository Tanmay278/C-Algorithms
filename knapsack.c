#include<stdio.h>
int v[10],w[10],n,W,pf[10][10],i,j;
void knapsack()
{ 
	for(i=0;i<=W;i++)
		pf[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			if(w[i]<=j)
			{
				if(pf[i-1][j]<(v[i]+pf[i-1][j-w[i]]))
				pf[i][j]=(v[i]+pf[i-1][j-w[i]]);
				else
				pf[i][j]=pf[i-1][j];
			}
			else
			pf[i][j]=pf[i-1][j];
			
		}
	}
}
int main()
{
	int x[10];
	printf("Enter the numbr of items");
	scanf("%d",&n);
	printf("enter the knapsack capacity");
	scanf("%d",&W);
	printf("Enter the values of the items");
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	printf("enter the weight of the items");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	knapsack();
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		printf("%d ",pf[i][j]);
		printf("\n");
		}
		printf("The required profit is %d",pf[n][W]);
		printf("Backtracking the solution");
		for(i=n;i>=1;i--)
		{
			if(pf[i][W]!=pf[i-1][W])
			x[i]=1;
			else
			x[i]=0;
			printf("%d",x[i]);
			W=W-w[i]*x[i];
		}
			
		
	
	return 0;
}

