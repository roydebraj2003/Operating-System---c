// Multilevel Queue Scheduling with Process Creation and Termination
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

struct Process {
    int id;
    int burst_time;
    int priority;
    int queue; // 1 = high-priority, 2 = medium, 3 = low
    int waiting_time;
    int turnaround_time;
    int is_active; // 1 if active, 0 if terminated
};

void calculateTimes(struct Process processes[], int n) {
    int time = 0;
    for (int q = 1; q <= 3; q++) { // Iterate through all queues
        for (int i = 0; i < n; i++) {
            if (processes[i].queue == q && processes[i].is_active) {
                processes[i].waiting_time = time;
                time += processes[i].burst_time;
                processes[i].turnaround_time = time;
            }
        }
    }
}

void printProcesses(struct Process processes[], int n) {
    printf("\nProcess\tBurst Time\tPriority\tQueue\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        if (processes[i].is_active) {
            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].priority, processes[i].queue, processes[i].waiting_time, processes[i].turnaround_time);
        }
    }
}

void createProcess(struct Process processes[], int *n) {
    if (*n >= MAX_PROCESSES) {
        printf("Process limit reached!\n");
        return;
    }
    struct Process new_process;
    new_process.id = *n + 1;
    printf("Enter burst time for P%d: ", new_process.id);
    scanf("%d", &new_process.burst_time);
    printf("Enter priority for P%d: ", new_process.id);
    scanf("%d", &new_process.priority);
    printf("Enter queue (1 = high, 2 = medium, 3 = low) for P%d: ", new_process.id);
    scanf("%d", &new_process.queue);
    new_process.is_active = 1;
    processes[*n] = new_process;
    (*n)++;
}

void terminateProcess(struct Process processes[], int n) {
    int pid;
    printf("Enter process ID to terminate: ");
    scanf("%d", &pid);
    for (int i = 0; i < n; i++) {
        if (processes[i].id == pid && processes[i].is_active) {
            processes[i].is_active = 0;
            printf("Process P%d terminated.\n", pid);
            return;
        }
    }
    printf("Process P%d not found or already terminated.\n", pid);
}

int main() {
    int n = 0;
    struct Process processes[MAX_PROCESSES];
    int choice;

    do {
        printf("\n1. Create Process\n2. Terminate Process\n3. Calculate Times\n4. Display Processes\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createProcess(processes, &n);
                break;
            case 2:
                terminateProcess(processes, n);
                break;
            case 3:
                calculateTimes(processes, n);
                break;
            case 4:
                printProcesses(processes, n);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);

    return 0;
}

