#include <stdio.h>
#include <stdlib.h>

typedef struct
{
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

void calculate_waiting_and_turnaround_times(Process *processes, int n)
{
    int current_time = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time;
        }
        processes[i].start_time = current_time;
        processes[i].end_time = current_time + processes[i].burst_time + processes[i].io_time;
        processes[i].waiting_time = processes[i].start_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].end_time - processes[i].arrival_time;
        current_time = processes[i].end_time;
    }
}

void print_gantt_chart(Process *processes, int n)
{
    printf("Gantt Chart:\n");
    printf(" ");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < processes[i].burst_time; j++)
        {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < processes[i].burst_time - 1; j++)
        {
            printf(" ");
        }
        printf("P%d", processes[i].process_id);
        for (int j = 0; j < processes[i].burst_time - 1; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < processes[i].burst_time; j++)
        {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    int current_time = 0;
    printf("0");

    for (int i = 0; i < n; i++)
    {
        current_time += processes[i].burst_time;
        printf("%2d", current_time);
    }
    printf("\n");
}

void print_process_table(Process *processes, int n)
{
    printf("P_ID\tAT\tBT\tPR\tIO\tST\tET\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].priority, processes[i].io_time, processes[i].start_time,
               processes[i].end_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main()
{
    int n = 4;
    Process *processes = (Process *)malloc(n * sizeof(Process));

    // Hear me our, g++ compiler just throw error `ISO C++ forbids compound-literals [-Werror=pedantic]`
    // (Command: g++ -Wall -Wextra -Werror -pedantic fcfs.c -o fcfs.out && ./fcfs.out)
    // Which means, I can't create process array like this:
    // Process processes[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // So, I have to use malloc to allocate memory for the array of processes
    // and then assign values to each process in the array
    // If you know the better way, pls open an PR
    processes[0].process_id = 1;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 5;
    processes[0].priority = 3;
    processes[0].io_time = 2;
    processes[0].start_time = 0;
    processes[0].end_time = 0;
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = 0;

    processes[1].process_id = 2;
    processes[1].arrival_time = 1;
    processes[1].burst_time = 3;
    processes[1].priority = 1;
    processes[1].io_time = 1;
    processes[1].start_time = 0;
    processes[1].end_time = 0;
    processes[1].waiting_time = 0;
    processes[1].turnaround_time = 0;

    processes[2].process_id = 3;
    processes[2].arrival_time = 2;
    processes[2].burst_time = 8;
    processes[2].priority = 4;
    processes[2].io_time = 3;
    processes[2].start_time = 0;
    processes[2].end_time = 0;
    processes[2].waiting_time = 0;
    processes[2].turnaround_time = 0;

    processes[3].process_id = 4;
    processes[3].arrival_time = 3;
    processes[3].burst_time = 6;
    processes[3].priority = 2;
    processes[3].io_time = 2;
    processes[3].start_time = 0;
    processes[3].end_time = 0;
    processes[3].waiting_time = 0;
    processes[3].turnaround_time = 0;

    calculate_waiting_and_turnaround_times(processes, n);
    print_process_table(processes, n);
    print_gantt_chart(processes, n);

    free(processes);
    return 0;
}
