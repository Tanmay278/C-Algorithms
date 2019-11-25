#include<stdio.h>
int g[100][100],x[100],m,n;
void graphcolor(int k)
{
	int c,i;
	for(c=1;c<=m;c++)
	{
		if(check(k,c))
		{
			x[k]=c;
			if(k+1<=n)
				graphcolor(k+1);
			
			else
			{
				for(i=1;i<=n;i++)
					printf("%d->%d\n",i,x[i]);
				exit(0);
			}
		}
	}
}
int check(int k,int c)
{
	int i;
	for(i=1;i<n;i++)
	{
		if(g[k][i]==1&&c==x[i])
		 return 0;
		}
	return 1;
}
int main()
{
	int i,j;
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	printf("Enter number of colours : ");
	scanf("%d",&m);
	printf("\nEnter graph matrix \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
		}
	graphcolor(1);
	return 0;
}
