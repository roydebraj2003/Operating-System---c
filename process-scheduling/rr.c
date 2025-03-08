#include<stdio.h>

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n], remaining_bt[n];
    
    printf("Enter the burst time: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining_bt[i] = bt[i];
    }
    
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);
    
    int time = 0, done;
    
    do {
        done = 1;
        for(int i = 0; i < n; i++) {
            if(remaining_bt[i] > 0) {
                done = 0;
                if(remaining_bt[i] > quantum) {
                    time += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    time += remaining_bt[i];  // Add only the remaining burst time
                    wt[i] = time - bt[i];  // Calculate waiting time
                    remaining_bt[i] = 0;
                }
            }
        }
    } while(!done);
    
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}

