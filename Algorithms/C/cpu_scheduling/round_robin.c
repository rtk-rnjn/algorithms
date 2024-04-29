#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct process
{
    int process_id;
    int arrival_time;
    int burst_time;

    // Variables to be used for calculations
    int remaining_time;
    int waiting_time;
};

struct gantt_chart_component
{
    int process_id;
    int time;
};

struct gantt_chart_component gantt_chart[100];
int gantt_chart_size = 0;

void sort_processes(struct process *processes, int num_processes);

int partition(struct process *processes, int low, int high)
{
    int pivot = processes[high].arrival_time;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (processes[j].arrival_time < pivot)
        {
            i++;
            struct process temp = processes[i];
            processes[i] = processes[j];
            processes[j] = temp;
        }
    }

    struct process temp = processes[i + 1];
    processes[i + 1] = processes[high];
    processes[high] = temp;

    return i + 1;
}

void quick_sort(struct process *processes, int low, int high)
{
    if (low < high)
    {
        int pi = partition(processes, low, high);

        quick_sort(processes, low, pi - 1);
        quick_sort(processes, pi + 1, high);
    }
}

void sort_processes(struct process *processes, int num_processes)
{
    quick_sort(processes, 0, num_processes - 1);
}

/* Queue Implementation */

struct process *circular_queue[100];
int queue_size;
int front = 0;
int rear = 0;

void put(struct process *p)
{
    circular_queue[rear] = p;
    rear = (rear + 1) % queue_size;
}

struct process *get()
{
    struct process *p = circular_queue[front];
    front = (front + 1) % queue_size;
    return p;
}

bool empty()
{
    return front == rear;
}

bool full()
{
    return (rear + 1) % queue_size == front;
}

/* Round Robin Scheduling Algorithm */

void round_robin(struct process *processes, int total_processes, int time_quantum)
{
    sort_processes(processes, total_processes);
    int time = 0;

    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    int i = 0;

    while (i < total_processes || !empty())
    {
        while (i < total_processes && processes[i].arrival_time <= time)
        {
            put(&processes[i]);
            i++;
        }

        if (empty())
        {
            time++;
            continue;
        }

        struct process *current_process = get();
        gantt_chart[gantt_chart_size].process_id = current_process->process_id;
        gantt_chart[gantt_chart_size].time = time;
        gantt_chart_size++;

        if (current_process->remaining_time > time_quantum)
        {
            time += time_quantum;
            current_process->remaining_time -= time_quantum;
            put(current_process);
        }
        else
        {
            time += current_process->remaining_time;
            current_process->waiting_time = time - current_process->arrival_time - current_process->burst_time;
            avg_waiting_time += (float)current_process->waiting_time;
            avg_turnaround_time += (float)time - (float)current_process->arrival_time;
            current_process->remaining_time = 0;
        }
    }

    avg_waiting_time /= (float)total_processes;
    avg_turnaround_time /= (float)total_processes;

    printf("Gantt Chart: ");
    for (int i = 0; i < gantt_chart_size; i++)
    {
        printf("P%d [%d] -> ", gantt_chart[i].process_id, gantt_chart[i].time);
    }
    printf("NULL\n");

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < total_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].waiting_time + processes[i].burst_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main()
{
    /*
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    for (int i = 0; i < num_processes; i++)
    {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    */

    int num_processes = 4;
    queue_size = num_processes;

    int time_quantum = 2;
    
    struct process p1 = {1, 0, 4, 4, 0};
    struct process p2 = {2, 1, 3, 3, 0};
    struct process p3 = {3, 2, 5, 5, 0};
    struct process p4 = {4, 3, 2, 2, 0};
    
    struct process processes[] = {p1, p2, p3, p4};

    round_robin(processes, num_processes, time_quantum);

    return 0;
}
