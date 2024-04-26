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
        return " -> ".join(f"P{process_id}({time})" for process_id, time in self.chart)

    def __repr__(self) -> str:
        return str(self)


def fcfs(processes: list[Process], /) -> None:
    processes.sort(key=lambda process: process.arrival_time)

    gantt_chart = GanttChart()
    current_time = 0

    avg_waiting_time = 0
    avg_turnaround_time = 0

    for process in processes:
        if process.arrival_time > current_time:
            current_time = process.arrival_time

        gantt_chart.add(process, current_time)
        process.waiting_time = current_time
        current_time += process.burst_time

        avg_waiting_time += process.waiting_time
        avg_turnaround_time += current_time

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
        Process(3, arrival_time=2, burst_time=5),
        Process(4, arrival_time=3, burst_time=2),
    ]

    fcfs(processes)
