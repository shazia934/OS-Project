#include<stdio.h>
#include<unistd.h>
int main()
{
int p,n,i;
printf("Enter the number of process\n::");
scanf("%d",&n);
int burst_time[n];
int priority[n];
int waiting_time[n];
int turn_around[n];
int l1[n];
int l2[n];
printf("Enter the priority of the process P0\t\t:");
	scanf("%d",&priority[0]);
	printf("Enter the Burst Time of the process P0\t\t:");
	scanf("%d",&burst_time[0]);
	p=priority[0];
	int j=0;
int a=0;
int b=0;
for(i=1;i<n;i++)
{
	printf("Enter the priority of the process P%d\t\t:",i);
	scanf("%d",&priority[i]);
printf("Enter the Burst Time of the process p%d\t\t:",i);
	scanf("%d",&burst_time[i]);
	if(priority[i]>p)
	{
		l2[a]=j;
//printf("\tl2=%d\n",l2[a]);
//printf("\ta=%d\n",a);
		a++;
		p=priority[i];
		j=i;
	//	printf("new j=%d",j);
	}
	else
	{
		l1[b]=i;
//printf("\tl1=%d\n",l1[b]);
//printf("\tb=%d\n",b);
		b++;

	}
	
}l1[b]=j;
//printf("\tl2=%d\n",l2[a]);
//printf("\ta=%d\n",a);
b++;
//printf("a=%d",a);
//printf("\nb=%d",b);
printf("\nprocess of l1 is\n");
for(i=0;i<b;i++)
{
	printf("p%d\t",l1[i]);
}
printf("\nprocess of l2 is\n");
for(i=0;i<a;i++)
{
	printf("p%d\t",l2[i]);
}
//sorting of the process in Level1
int t;
for(i=0;i<b;i++)
{
	for(j=i+1;j<b;j++)
	{
	if(l1[j]<l1[i])
		{
		t=l1[i];
		l1[i]=l1[j];
		l1[j]=t;
		}
	}
}
for(i=0;i<a;i++)
{
	for(j=i+1;j<a;j++)
	{
	if(l2[j]<l2[i])
		{
		t=l2[i];
		l2[i]=l2[j];
		l2[j]=t;
		}
	}
}printf("\n\n\nAfter Sorting\n\n\n");
for(i=0;i<b;i++)
{
	printf("p%d\t",l1[i]);
}
printf("\nprocess of l2 is\n");
for(i=0;i<a;i++)
{
	printf("p%d\t",l2[i]);
}
}
