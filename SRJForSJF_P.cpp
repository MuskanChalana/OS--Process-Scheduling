#include<iostream>
using namespace std;

void SRJF(int* at, int* bt,int* bt2, int n)
{
    int tat[n], wt[n];
    int timer=0, RQ[n], count=0,pro, p_cmplt=0;
    while(p_cmplt<n)
    {
        //preparing ready queue
        count=0;
        for(int p=0; p<n; p++) //p=process
        {
            if(at[p] != -1 && timer>=at[p])
            {
                RQ[count]=p;   //RQ stores process numbers
                count++;
            }
        }

        //selecting the process from ready queue
        pro=RQ[0];
        for(int i=1; i<count; i++)
        {
            if(at[RQ[i]] != -1 && bt[RQ[i]]<bt[pro])  // if burst time of process at RQ[i]< bt of pro
            {
                pro=RQ[i];
            }
        }
        //process with the shortest burst from the ready queue is selected

        bt[pro]--;   //process pro is executed for 1 unit time
        timer++;
        if(bt[pro] == 0) //if the current running process completed at this time instance
        {
            tat[pro] = timer - at[pro];
            wt[pro] = tat[pro] - bt2[pro];
        
            at[pro] = -1;
            p_cmplt ++;
        }
           
    }

    for(int i=0; i<n; i++)
    {
        cout<<"TAT for process "<<i+1<<": "<<tat[i]<<endl;
        cout<<"WT for process "<<i+1<<": "<<wt[i]<<endl<<endl;
    }
}

int main()
{
    int n;
    cout<<"enter the number of processes: ";
    cin>>n;

    int AT[n], BT[n], BT2[n];
    for(int i=0; i<n; i++)
    {
        cout<<"enter arrival time for process "<<i+1<<": ";
        cin>>AT[i];
        cout<<"enter burst time for process "<<i+1<<": ";
        cin>>BT[i];
        BT2[i]=BT[i];
        cout<<endl;
    }

    SRJF(AT,BT,BT2,n);


}