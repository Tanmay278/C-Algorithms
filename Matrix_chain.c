#include<stdio.h>
#include<limits.h>
void main(){
	int i,n,a[50];
	printf("Enter the length: ");
	scanf("%d",&n);
	printf("Enter the dimensions of matrix to multiply: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nMinimum number of multiplications is %d \n",order(a,n));
}
int order(int a[], int n){
	int m[n][n]; 
	int bracket[n][n];
    int i, j, k, L, q;
    for (i=1; i<n; i++) 
    	m[i][i] = 0;
	for (L=2; L<n; L++) 
    { 
        for (i=1; i<n-L+1; i++) 
        { 
            j = i+L-1; 
            m[i][j] = INT_MAX; 
            for (k=i; k<=j-1; k++) 
            {
                q = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j]; 
                if (q < m[i][j]){ 
                    m[i][j] = q; 
                    bracket[i][j] = k;
                }
            } 
        } 
    } 
    char name = 'A';
  	opt(1, n-1, n, (int *)bracket,name);
    return m[1][n-1]; 
}
void opt(int i, int j, int n,int *a,char name){
	if (i==j)
		printf("%c",name++);
	else{
		printf("(");
		opt(i, *((a+i*n)+j), n,a,name);
		opt(*((a+i*n)+j) + 1, j,n, a, name);
		printf(")");
	}
}

