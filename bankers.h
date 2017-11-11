#ifndef Banker_H
#define Banker_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int avilable[20];
int max[20][20];
int allocation[20][20];
int need[20][20];

void bankersalgo()
{
    int n,m,i,j,cntr=0,allow=0,no,req1,req2,req3;
    int flag[20]={0},f=0;
    printf("\n\tEnter number of processes : ");
    scanf("%d",&n);
    printf("\n\tEnter number of Resources : ");
    scanf("%d",&m);
    
    printf("\nEnter allocation matrix : \n\t");
    
    for(i=0;i<n;i++)
    {
        printf("\n\t");
        for(j=0;j<m;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("\nEnter MAX matrix : \n\t");
    
    for(i=0;i<n;i++)
    {
        printf("\n\t");
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("\n\tEnter Available : ");
    for(i=0;i<m;i++)
    {
        printf("\n\tEnter available value of resource %d : ",i);
        scanf("%d",&avilable[i]);
    }
    printf("\n\t Calculating need....");
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    
    printf("\n\tNeed calculation completed...");
    cntr=0;
    while(1)
    {
    for(i=0;i<n;i++)
    {
        allow=0;
        for(j=0;j<m;j++)
        {
        if(need[i][j]<= avilable[j]&&flag[i]==0)
            allow=1;
        else
        {
            break;
        }
        }
            
        if(allow==1)
        {
            printf("\n\t***process P%d is safe***",i);
            avilable[0]+=allocation[i][0];
            avilable[1]+=allocation[i][1];
            avilable[2]+=allocation[i][2];
            flag[i]=1;
            cntr++;
        }
    }
    if(cntr==n)
        break;
    }
    
    //Resource Request Allocation
    while(1)
    {
    printf("\nEnter Requested process : ");
    scanf("%d",&no);
    printf("\nEnter Requested resources : ");
    scanf("%d%d%d",&req1,&req2,&req3);
    if(req1<=need[no][0]&&req2<need[no][1]&&req3<need[no][2])
        if(req1< avilable[0]&&req2<avilable[1]&&req3< avilable[2])
        {
            printf("\n\t!!!!Granted requested!!!!!");
            avilable[0]=avilable[0]-req1;
            avilable[1]=avilable[1]-req2;
            avilable[2]=avilable[2]-req3;
            allocation[no][0]=allocation[no][0]+req1;
            allocation[no][1]=allocation[no][1]+req2;
            allocation[no][2]=allocation[no][2]+req3;
            need[no][0]=need[no][0]-req1;
            need[no][1]=need[no][1]-req2;
            need[no][2]=need[no][2]-req3;
        }
        else
            printf("\n!!!Process p %d must be waited!!!",no);
    else
printf("Error...exceding request allocation ***");

    printf("\n\tDou want to continue(YES=1/No=0) : ");
    scanf("%d",&f);
    if(f==0)
        break;
    }        
}
#endif
