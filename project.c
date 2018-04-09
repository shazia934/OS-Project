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
		a++;
		p=priority[i];
		j=i;
	}
	else
	{
		l1[b]=i;
			rt[b]=burst_time[i];
		b++;

	}
	
}l1[b]=j;
b++;

//sorting of the process in Level1
int t;
for(i=0;i<b;i++)
{
	int z=l1[i];
	for(j=i+1;j<b;j++)
	{
		int k=l1[j];
	if(priority[k]<priority[z])
		{
		t=arrival[k];
		arrival[k]=arrival[z];
		arrival[z]=t;
		t=burst_time[k];
		burst_time[k]=burst_time[z];
		burst_time[z]=t;
		t=priority[k];
		priority[k]=priority[z];
		priority[z]=t;
		t=l1[i];
		l1[i]=l1[j];
		l1[j]=t;
		}
	}
}

printf("\nEnter Time Quantum:\t"); 
    int time_quantum;
      scanf("%d", &time_quantum); 
printf("\n\n\t\t----The Process have been assigned into the two levels of the Queue----\n\n\n");
printf("\t____Process in the Level '1' of the Queue are____\n\n ");
for(i=0;i<b;i++)
{
	printf("p%d\t",l1[i]);
}
printf("\n\n\n\t_____Process in the Level '2' of the Queue are_____\n\n");
for(i=0;i<a;i++)
{
	printf("p%d\t",l2[i]);
}
printf("\n\n\t****Scheduling of Level 1 of the Queue is done With****\n\n\t\t****Prempetive Priority Schedulling****");
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
    int average_time=total/n;   
    total=0;
    printf("\n\n\n\nProcess\tBurst Time\tPriority\tArrival Time\tWaiting Time\tTurnaround Time");
     for(i=0;i<b;i++)
    {
    	int x=l1[i];
        turn_around[x]=burst_time[x]+waiting_time[x];     //calculate turnaround time
        total+=turn_around[x];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t %d\t\t\t%d",x,burst_time[x],priority[x],arrival[x],waiting_time[x],turn_around[x]);
    }
	int average_turnaround_time=total/b;     //average turnaround time
    printf("\n\n\n\nAverage Waiting Time=%d",average_time);
    printf("\n\n\n\nAverage Turnaround Time=%d\n",average_turnaround_time);
    
    
    
    
    
    
    
    
	
	
	
	
	
	
	
	//Solving level 2 by round robin 
	int bt[a],at[a],pt[a];
    for(i=0;i<a;i++)
    {
    	int x=l2[i];
    	bt[i]=burst_time[x];
    	at[i]=arrival[x];
    	pt[i]=priority[x];
    	rt[i]=bt[i];
	}
	
       printf("\nProcess\t  \tWaiting Time \tTurn Around Time\n");
      int time=0,c=0;
      int process=a;
      int waiting=0;
	  int turnAround=0;
    for(time=0,i = 0; process!= 0;) 
      { 
      int g=l2[i];
    if(rt[i]<=time_quantum && rt[i]>0) 
    { 
      time+=rt[i]; 
      rt[i]=0; 
      c=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[i]==0 && c==1) 
    { 
      process--; 
      printf("\nP[%d]\t\t%d\t\t%d\n",g,(time-at[i]),time-at[i]-bt[i]); 
	  waiting+=time-at[i]-bt[i]; 
      turnAround+=time-at[t]; 
      c=0; 
      
    } 
    if(i==a-1) 
     {
	 i=0; 
	}	
    else if(at[i+1]<=time) 
     {
	   i++;
	 
	}
    else 
      i=0; 
  } 
  printf("\n\n\n\nAverage Waiting Time= %f\n",waiting*1.0/n); 
  printf("\n\n\n\nAvg Turnaround Time = %f",turnAround*1.0/n);
}
