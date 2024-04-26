#include <stdio.h>
#include <stdlib.h>

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

void fcfs(struct process *processes, int total_process)
{
    sort_processes(processes, total_process);

    int current_time = 0;

    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    for (int i = 0; i < total_process; i++)
    {
        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time;
        }

        gantt_chart[gantt_chart_size].process_id = processes[i].process_id;
        gantt_chart[gantt_chart_size].time = current_time;
        gantt_chart_size++;

        processes[i].waiting_time = current_time;
        current_time += processes[i].burst_time;

        avg_waiting_time += (float)processes[i].waiting_time;
        avg_turnaround_time += (float)current_time;
    }

    avg_waiting_time /= (float)total_process;
    avg_turnaround_time /= (float)total_process;

    printf("Gantt Chart: ");
    for (int i = 0; i < gantt_chart_size; i++)
    {
        printf("P%d[%d] -> ", gantt_chart[i].process_id, gantt_chart[i].time);
    }
    printf("NULL\n");

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < total_process; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].waiting_time + processes[i].burst_time);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main()
{
    int total_processes = 4;
    struct process p1 = {1, 0, 4, 4, 0};
    struct process p2 = {2, 1, 3, 3, 0};
    struct process p3 = {3, 2, 5, 5, 0};
    struct process p4 = {4, 3, 2, 2, 0};

    struct process processes[4] = {p1, p2, p3, p4};

    fcfs(processes, total_processes);

    return 0;
}
