#include<stdio.h>
int main(){
    int burst_time[100],proc[100],wait_time[100],tat[100],pr[100];
    int i,j,n,pos,temp,avg_wt,avg_tat,total;
    printf("Enter total no. of processes: \n");
    scanf("%d",&n);
    printf("Enter burst time and priority: \n");
    for(i=0;i<n;i++){
        printf("\np[%d]\n",i+1);
        printf("burst time: ");
        scanf("%d",&burst_time[i]);
        printf("priority: ");
        scanf("%d",&pr[i]);
        proc[i]=i+1;
    }
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            {
            if(pr[j]<pr[pos])
                pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
        temp=proc[i];
        proc[i]=proc[pos];
        proc[pos]=temp;
        }
        wait_time[0]=0;
    }
    for(i=1;i<n;i++){
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]=wait_time[i]+burst_time[j];
            total+=wait_time[i];
        }
        avg_wt=total/n;
        total=0;
        printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
        for(i=0;i<n;i++){
            tat[i]=burst_time[i]+wait_time[i];
            total+=tat[i];
            printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",proc[i],burst_time[i],wait_time[i],tat[i]);
        }
        avg_tat=total/n;
        printf("\n\nAverage Waiting time=%d",avg_wt);
        printf("\nAverage Turnaround time",avg_tat);
        return 0;
}
