#include<stdio.h>
void floyds(int p[10][10],int n,int q[10][10]){
 	int i,j,k,l;
 	for(k=1;k<=n;k++){
  		for(i=1;i<=n;i++)
   			for(j=1;j<=n;j++)
    			if(i==j){
     				p[i][j]=0;
     				q[i][j]=0;
				}
    			else{
    				l=p[i][j];
     				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
     				if(l!=p[i][j])
     					if(q[k][j]==-1)
							q[i][j]=k;
     					else 
     						q[i][j]=q[k][j];
     				
     			}
     			display(q,n);
     		}
}
int min(int a,int b){
 	if(a<b)
  		return a;
 	else
  		return b;
}
void display(int a[10][10],int n){
	int i,j;
	printf("\n");
	printf("\n");
	for(i=1;i<=n;i++){
  		for(j=1;j<=n;j++)
   			printf("%d \t",a[i][j]);
  	printf("\n");
 	}
}
void main(){
 	int p[10][10],Q[10][10],w,n,e,u,v,i,j;;
 	printf("\nEnter the number of vertices:");
 	scanf("%d",&n);
 	printf("\nEnter the number of edges:\n");
 	scanf("%d",&e);
 	for(i=1;i<=n;i++)
  		for(j=1;j<=n;j++){
   			p[i][j]=999;
   			Q[i][j]=-1;
   		}
 	for(i=1;i<=e;i++){
  		printf("\nEnter the end vertices of edge %d with its weight \n",i);
  		scanf("%d%d%d",&u,&v,&w);
  		p[u][v]=w;
  		Q[u][v]=u;
 	}
 	printf("\nMatrix of input data:\n");
 	for(i=1;i<=n;i++){
  		for(j=1;j<=n;j++)
   			printf("%d \t",p[i][j]);
  	printf("\n");
 	}
 
 	floyds(p,n,Q);
 	printf("\nAfter finding shortest path:\n");
 	for(i=1;i<=n;i++){
  		for(j=1;j<=n;j++)
   			printf("%d \t",p[i][j]);
  	printf("\n");
 	}
 	printf("\nPosition Matrix :\n");
 	for(i=1;i<=n;i++){
  		for(j=1;j<=n;j++)
   			printf("%d \t",Q[i][j]);
  	printf("\n");
 	}
 	
	 printf("\n The shortest paths are:\n");
 	for(i=1;i<=n;i++)
  		for(j=1;j<=n;j++)
   			if(i!=j)
    			printf("\n <%d,%d>=%d",i,j,p[i][j]);
  
}
