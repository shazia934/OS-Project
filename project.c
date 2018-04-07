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
int rt[n];
int l1[n];
int l2[n];
printf("\nEnter Details of P[0]\n");
printf("priority of the process P[0]:");
	scanf("%d",&priority[0]);
	printf("Burst Time of the process P[0]:");
	scanf("%d",&burst_time[0]);
	rt[0]=burst_time[0];
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
	rt[i]=burst_time[i];
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
printf("\n\n\t\tThe Process have been assigned into the two levels of the Queue\n\n\n");
printf("Process in the Level '1' of the Queue are::\n\n ");
for(i=0;i<b;i++)
{
	printf("p%d\t",l1[i]);
}
printf("\nProcess in the Level '2' of the Queue are::\n\n");
for(i=0;i<a;i++)
{
	printf("p%d\t",l2[i]);
}
printf("\n\n\tScheduling of Level 1 of the Queue is done With\n\tPrempetive Priority Schedulling");
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
    printf("\nProcess\t    Burst Time    \tArrival Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<b;i++)
    {
    	int x=l1[i];
        turn_around[x]=burst_time[x]+waiting_time[x];     //calculate turnaround time
        total+=turn_around[x];
        printf("\nP[%d]\t\t  %d\t\t    \t%d\t%d\t\t\t%d",x,burst_time[x],waiting_time[x],turn_around[x]);
    }
  int limit, total1 = 0,counter = 0; 
      int wait_time = 0, turnaround_time = 0,at[a], bt[a], temp[a]; 
      float average_wait_time, average_turnaround_time;
    printf("\nEnter Time Quantum:\t"); 
    int time_quantum;
      scanf("%d", &time_quantum); 
      limit=a;
      int x1 = limit; 
      for(i = 0; i < limit; i++) 
      {
            int d=l2[i];
            at[i]=arrival[d];
            bt[i]=burst_time[d]; 
            temp[i] = bt[i];
      } 
    for(total1 = 0, i = 0; x1!= 0;) 
      { 
      int g=l2[i];
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total1 = total1 + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total1 = total1+ time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x1--; 
                  printf("\nP[%d]\t\t%d\t\t %d\t\t\t %d", g, bt[i], total - at[i], total1 - at[i] - bt[i]);
                  wait_time = wait_time + total1 - at[i] - bt[i]; 
                  turnaround_time = turnaround_time + total1 - at[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(at[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
}
