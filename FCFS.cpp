#include<iostream>
using namespace std;

void FCFS(int* at, int* bt, int n)
{
    int tat[n], wt[n];
    int term=0, timer=0,min;
    while(term<n)
    {   
        int y=0; 
        for(int i=0; i<n; i++)
        {
            if(at[i] != -1 && at[i]<=timer)
            {
                min=i;
                y=1; //a process with at < timer is found
                break;
            }
        } //min is the first process instance which is ready

        if(y==0)// no process is ready
        {
            timer++; //idle cpu time
            continue;
        }

        for (int i=min; i<n; i++)
        {   
            if(at[i] != -1 && at[i]<=timer && at[i]<at[min])
            {
                min=i;
            }
        }
        //now min is the first come process out of all process left to be executed

        //lets execute min
        timer += bt[min];
        tat[min] = timer - at[min];
        wt[min] = tat[min] - bt[min];
        at[min]=-1;
        term++;

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

    FCFS(AT,BT,n);
}