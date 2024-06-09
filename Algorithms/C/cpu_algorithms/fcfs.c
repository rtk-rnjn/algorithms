#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int io_time;
    int start_time;
    int end_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_and_turnaround_times(Process processes[], int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].start_time = current_time;
        processes[i].end_time = current_time + processes[i].burst_time + processes[i].io_time;
        processes[i].waiting_time = processes[i].start_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].end_time - processes[i].arrival_time;
        current_time = processes[i].end_time;
    }
}

void print_gantt_chart(Process processes[], int n) {
    printf("Gantt Chart:\n");
    printf(" ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst_time; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst_time - 1; j++) {
            printf(" ");
        }
        printf("P%d", processes[i].process_id);
        for (int j = 0; j < processes[i].burst_time - 1; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst_time; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    int current_time = 0;
    printf("0");

    for (int i = 0; i < n; i++) {
        current_time += processes[i].burst_time;
        printf("%2d", current_time);
    }
    printf("\n");
}

void print_process_table(Process processes[], int n) {
    printf("P_ID\tAT\tBT\tPR\tIO\tST\tET\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
            processes[i].process_id, 
            processes[i].arrival_time, 
            processes[i].burst_time, 
            processes[i].priority, 
            processes[i].io_time, 
            processes[i].start_time, 
            processes[i].end_time, 
            processes[i].waiting_time, 
            processes[i].turnaround_time);
    }
}

int main() {
    int n = 4;
    Process processes[n];

    processes[0] = (Process){1, 0, 5, 3, 2, 0, 0, 0, 0};
    processes[1] = (Process){2, 1, 3, 1, 1, 0, 0, 0, 0};
    processes[2] = (Process){3, 2, 8, 4, 3, 0, 0, 0, 0};
    processes[3] = (Process){4, 3, 6, 2, 2, 0, 0, 0, 0};    

    calculate_waiting_and_turnaround_times(processes, n);
    print_process_table(processes, n);
    print_gantt_chart(processes, n);

    return 0;
}
