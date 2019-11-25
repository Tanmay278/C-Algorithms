#include<stdio.h>
int mx,mn;
void  maxmin(int a[],int l, int h)
{
	int mx1,mn1,m;
	if(l==h)
	{
	mx=a[l];
	mn=a[l];
}
else if (h==(l+1))
{
	if (a[l]>a[h])
	{
		mx=a[l];
		mn=a[h];
	}
	else
	{
	mx=a[h];
	mn=a[l];
}
}
else
{
	m=(l+h)/2;
	maxmin(a,l,m);
	mx1=mx;
	mn1=mn;
	maxmin(a,m+1,h);
	if(mx1>mx)
	mx=mx1;
	if(mn1<mn)
	mn=mn1;
}

}
main()
{ 
int a[10],n,i;
printf("enter the no of element you want");
scanf("%d",&n);
printf("enter the no of elements");
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
maxmin(a,1,n);
printf("maximun number is %d\n",mx);
printf("minimum number is %d",mn);

}
