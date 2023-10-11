#include<iostream>
using namespace std;

void SJF_NP(int* at, int* bt, int n)
{
    int tat[n], wt[n];
    int timer=0, RQ[n], count=0,pro;
    for (int pr_num = 1; pr_num <=n; pr_num++)
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

        timer += bt[pro];   //process pro is executed
        tat[pro] = timer - at[pro];
        wt[pro] = tat[pro] - bt[pro];
        
        at[pro] = -1;   
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

    int AT[n], BT[n];
    for(int i=0; i<n; i++)
    {
        cout<<"enter arrival time for process "<<i+1<<": ";
        cin>>AT[i];
        cout<<"enter burst time for process "<<i+1<<": ";
        cin>>BT[i];
        cout<<endl;
    }

    SJF_NP(AT,BT,n);


}