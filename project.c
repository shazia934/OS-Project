#include<stdio.h>
#include<unistd.h>
int main()
{
int p,n,i,a=0,b=0,j=0;
printf("\n\n\t\t\t\t\t\t*****WELCOME****\n\n");
printf("Enter the number of process\t\t:");
scanf("%d",&n);
int burst_time[n];
int arrival[n];
int priority[n];
int waiting_time[n];
int turn_around[n];
int l1[n];
int l2[n];
printf("\nEnter Details of P[0]\n");
printf("priority of the process P[0]:");
	scanf("%d",&priority[0]);
	printf("Burst Time of the process P[0]:");
	scanf("%d",&burst_time[0]);
	printf("Arrival Time of the process P[0]:");
	scanf("%d",&arrival[0]);
	p=priority[0];
for(i=1;i<n;i++)
{
	printf("\n\nEnter Details of P[%d]\n",i);
	printf("priority of the process P[%d]:",i);
	scanf("%d",&priority[i]);
	printf("Burst Time of the process p[%d]:",i);
	scanf("%d",&burst_time[i]);
	printf("Arrival Time of the process P[%d]:",i);
	scanf("%d",&arrival[i]);
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
/*printf("\nprocess of l1 is\n");
for(i=0;i<b;i++)
{
	printf("p%d\t",l1[i]);
}
printf("\nprocess of l2 is\n");
for(i=0;i<a;i++)
{
	printf("p%d\t",l2[i]);
}*/
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
}
printf("\n\n\t\tThe Process have been assigned into the two levels of the Queue");
printf("\n\nEnter the Quantum Time:\t");
int q;
scanf("%d",&q);
//printf("Enter 1 to Display the Process in the Level ");
for(i=0;i<b;i++)
{
	printf("p%d\t",l1[i]);
}
printf("\nprocess of l2 is\n");
for(i=0;i<a;i++)
{
	printf("p%d\t",l2[i]);
}
int total=0,x,y;
x=l1[0];
waiting_time[x]=0;
for(i=1;i<b;i++)
    {
    	x=l1[i];
        waiting_time[x]=0;
        for(j=0;j<i;j++)
            {
            	y=l1[j];
			waiting_time[x]+=burst_time[y];
 			}
        total+=waiting_time[x];
    }
    int average_time=total/n;      //average waiting time
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<b;i++)
    {
    	int x=l1[i];
        turn_around[x]=burst_time[x]+waiting_time[x];     //calculate turnaround time
        total+=turn_around[x];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",x,burst_time[x],waiting_time[x],turn_around[x]);
    }
 
    int average_turn=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",average_time);
    printf("\nAverage Turnaround Time=%d\n",average_turn);

}
