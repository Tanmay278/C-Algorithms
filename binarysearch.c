#include<stdio.h>
int bsearch(int a[],int l,int u,int s)
{
	int mid;
	if(l==u)
	{
		if(a[l]==s)
		return l;
		else
		return -1;
	}
	else
	{
		mid=(l+u)/2;
		if(a[mid]==s)
		return mid;
		else if(a[mid]<s)
		return bsearch(a,mid+1,u,s);
		else
		return bsearch(a,l,mid-1,s);
	}
}

int main()
{
	int pos,a[50],item,ub,i;
	printf("Enter the size of the array:");
	scanf("%d",&ub);
	printf("Enter the array elements:");
	for(i=0;i<ub;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the search element:");
	scanf("%d",&item);
	pos=bsearch(a,0,ub-1,item);
	if(pos==-1)
	printf("Element not found!");
	else
	printf("Element found at %d",pos+1);
}
