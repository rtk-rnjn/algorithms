#include <stdio.h>
#include <limits.h>

struct process
{
    int process_id;
    int arrival_time;
    int burst_time;

    int remaining_time;
    int waiting_time;
};

struct gantt_chart_component
{
    int process_id;
    int time;
};

struct gantt_chart_component gantt_chat[100];
int gantt_chart_size = 0;

void swap(struct process *a, struct process *b)
{
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct process *processes, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (processes[i].arrival_time > processes[j].arrival_time)
            {
                swap(&processes[i], &processes[j]);
            }
        }
    }
}

int find_min_burst_time(struct process *processes, int n, int current_time)
{
    int min_burst_time = INT_MAX;
    int min_burst_time_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_burst_time &&
            processes[i].remaining_time > 0)
        {
            min_burst_time = processes[i].remaining_time;
            min_burst_time_index = i;
        }
    }

    return min_burst_time_index;
}

void sjf_preemptive(struct process *processes, int n)
{
    sort(processes, n);

    int time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
    }

    int completed = 0;
    while (completed != n)
    {
        int min_burst_time_index = find_min_burst_time(processes, n, time);

        if (min_burst_time_index == -1)
        {
            time++;
            continue;
        }

        processes[min_burst_time_index].remaining_time--;

        if (gantt_chart_size == 0 ||
            gantt_chat[gantt_chart_size - 1].process_id != processes[min_burst_time_index].process_id)
        {
            gantt_chat[gantt_chart_size].process_id = processes[min_burst_time_index].process_id;
            gantt_chat[gantt_chart_size].time = time;
            gantt_chart_size++;
        }

        if (processes[min_burst_time_index].remaining_time == 0)
        {
            completed++;
            int completion_time = time + 1;
            int turnaround_time = completion_time - processes[min_burst_time_index].arrival_time;
            int waiting_time = turnaround_time - processes[min_burst_time_index].burst_time;

            processes[min_burst_time_index].waiting_time = waiting_time;

            avg_waiting_time += (float)waiting_time;
            avg_turnaround_time += (float)turnaround_time;
        }

        time++;
    }

    avg_waiting_time /= (float)n;
    avg_turnaround_time /= (float)n;

    printf("Gantt Chart: ");
    for (int i = 0; i < gantt_chart_size; i++)
    {
        printf("P%d[%d] -> ", gantt_chat[i].process_id, gantt_chat[i].time);
    }
    printf("NULL\n");

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].waiting_time + processes[i].burst_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main()
{
    int n = 4;
    struct process p1 = {1, 0, 6, 6, 0};
    struct process p2 = {2, 1, 8, 8, 0};
    struct process p3 = {3, 2, 7, 7, 0};
    struct process p4 = {4, 3, 3, 3, 0};

    struct process processes[] = {p1, p2, p3, p4};

    sjf_preemptive(processes, n);

    return 0;
}
