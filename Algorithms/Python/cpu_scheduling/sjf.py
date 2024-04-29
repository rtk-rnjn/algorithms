from __future__ import annotations


class Process:
    def __init__(self, process_id: int, /, *, arrival_time: int, burst_time: int):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time

        self.remaining_time = burst_time
        self.waiting_time = 0


class GanttChart:
    def __init__(self):
        self.chart = []

    def add(self, process: Process, time: int, /):
        self.chart.append((process.process_id, time))

    def __str__(self):
        return " -> ".join(f"P{process_id}[{time}]" for process_id, time in self.chart)

    def __repr__(self) -> str:
        return str(self)

    def __len__(self) -> int:
        return len(self.chart)


def find_min_burst_time(processes: list[Process], current_time: int, /) -> int:
    min_burst_time = float("inf")
    min_burst_time_index = -1

    for index, process in enumerate(processes):
        if process.arrival_time > current_time:
            break
        if process.remaining_time < min_burst_time:
            min_burst_time = process.remaining_time
            min_burst_time_index = index

    return min_burst_time_index


def sjf(processes: list[Process], /) -> None:
    processes.sort(key=lambda process: process.arrival_time)

    time = 0
    gantt_chart = GanttChart()
    current_time = 0

    avg_waiting_time = 0
    avg_turnaround_time = 0

    completed = 0

    while completed != len(processes):
        min_burst_time_index = find_min_burst_time(processes, current_time)

        if min_burst_time_index == -1:
            current_time += 1
            continue

        processes[min_burst_time_index].remaining_time -= 1

        if len(gantt_chart) == 0 or gantt_chart.chart[-1][0] != processes[min_burst_time_index].process_id:
            gantt_chart.add(processes[min_burst_time_index], current_time)

        if processes[min_burst_time_index].remaining_time == 0:
            completed += 1
            processes[min_burst_time_index].waiting_time = (
                current_time - processes[min_burst_time_index].arrival_time - processes[min_burst_time_index].burst_time
            )
            avg_waiting_time += processes[min_burst_time_index].waiting_time
            avg_turnaround_time += current_time - processes[min_burst_time_index].arrival_time

        current_time += 1

    avg_waiting_time /= len(processes)
    avg_turnaround_time /= len(processes)

    print("Gantt Chart:", gantt_chart)
    print("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time")
    for process in processes:
        print(
            f"P{process.process_id}\t\t{process.arrival_time}\t\t{process.burst_time}\t\t{process.waiting_time}\t\t{process.waiting_time + process.burst_time}",
        )
    print(f"Average Waiting Time: {avg_waiting_time}")
    print(f"Average Turnaround Time: {avg_turnaround_time}")


if __name__ == "__main__":
    processes = [
        Process(1, arrival_time=0, burst_time=4),
        Process(2, arrival_time=1, burst_time=3),
        Process(3, arrival_time=2, burst_time=1),
        Process(4, arrival_time=3, burst_time=5),
    ]

    sjf(processes)
