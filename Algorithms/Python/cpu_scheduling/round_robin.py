from __future__ import annotations

from queue import Queue


class Process:
    def __init__(self, process_id: int, /, *, arrival_time: int, burst_time: int):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.remaining_time = burst_time
        self.waiting_time = 0


class GanttChart:
    def __init__(self) -> None:
        self.chart = []

    def add(self, process_id: int, /, *, time: int) -> None:
        self.chart.append((process_id, time))

    def __str__(self) -> str:
        return " -> ".join(f"P{process_id} [{time}]" for process_id, time in self.chart)


def round_robin(processes: list[Process], quantum: int) -> None:
    processes.sort(key=lambda process: process.arrival_time)
    time = 0
    queue: Queue[Process] = Queue()
    gantt_chart = GanttChart()

    avg_waiting_time = 0
    avg_turnaround_time = 0

    i = 0
    while i < len(processes) or not queue.empty():
        while i < len(processes) and processes[i].arrival_time <= time:
            queue.put(processes[i])
            i += 1

        if queue.empty():
            time += 1
            continue

        process = queue.get()
        gantt_chart.add(process.process_id, time=time)

        if process.remaining_time > quantum:
            time += quantum
            process.remaining_time -= quantum
            queue.put(process)
        else:
            time += process.remaining_time
            process.waiting_time = time - process.arrival_time - process.burst_time
            avg_waiting_time += process.waiting_time
            avg_turnaround_time += time - process.arrival_time
            process.remaining_time = 0

    avg_waiting_time /= len(processes)
    avg_turnaround_time /= len(processes)

    print("Gantt Chart:", gantt_chart)

    print("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time")
    for process in processes:
        print(
            f"{process.process_id}\t\t{process.arrival_time}\t\t"
            f"{process.burst_time}\t\t{process.waiting_time}\t\t"
            f"{process.waiting_time + process.burst_time}",
        )
    print(f"Avg Waiting Time: {avg_waiting_time}")
    print(f"Avg Turnaround Time: {avg_turnaround_time}")


if __name__ == "__main__":
    processes = [
        Process(1, arrival_time=0, burst_time=4),
        Process(2, arrival_time=1, burst_time=3),
        Process(3, arrival_time=2, burst_time=5),
        Process(4, arrival_time=3, burst_time=2),
    ]
    round_robin(processes, quantum=2)
