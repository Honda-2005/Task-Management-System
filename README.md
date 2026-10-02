# Console Task & Deadline Management System

[![Language](https://img.shields.io/badge/C%2B%2B-14%20%2F%2017-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![Storage](https://img.shields.io/badge/Persistence-File%20I%2FO%20(fstream)-orange)](#-storage--persistence)
[![Interface](https://img.shields.io/badge/Interface-Interactive%20CLI-brightgreen)](#-cli-navigation)
[![License](https://img.shields.io/badge/License-MIT-lightgrey.svg)](LICENSE)

A robust, console-driven task organization and deadline-tracking application written in **C++**. Designed for students and software teams, this system provides full lifecycle management for scheduled work items—including multi-category tagging, priority queuing, completion state toggling, disk persistence, and automated deadline proximity alerts.

Developed at **Misr International University (MIU)** by **Younss Yahya** and **Mohanad**.

---

## 📋 System Features

- **Full Task Lifecycle Management**:
  - Create tasks with comprehensive metadata (`id`, `title`, `description`, `deadline`, `priority`, `category`, `completion status`).
  - Search tasks by unique identification number or title substring.
  - In-place task updates and deletions with array compaction.
- **Automated Deadline Alert Engine**:
  - Calculates remaining temporal runway ($\Delta t = \text{deadline} - \text{current\_day}$).
  - Issues real-time urgency warnings:
    - *Urgent Action*: $\Delta t = 1$ ("Only one day remaining to submit!").
    - *Expired*: $\Delta t \le 0$ ("Task submission has expired").
    - *Runway*: $\Delta t > 1$ ("Submission window open for $N$ days").
- **Categorization & Priority Tiers**:
  - Multi-domain categories: `Personal`, `Work`, `Study`.
  - Priority rankings: High (`H`), Medium (`M`), Low (`L`).
- **File I/O Persistence**:
  - Disk serialization via C++ file streams (`std::ifstream` and `std::ofstream`).
  - Safe state restoration across console application restarts.

---

## 🏛️ Data Architecture & Storage

```
Task Structure (struct info)
┌────────────────────────────────────────────────────────┐
│ id: int                   │ e.g. 101                   │
│ title: string             │ e.g. "Network Lab Report"  │
│ description: string       │ e.g. "CCNA subnetting"     │
│ deadline: int             │ e.g. 25 (calendar day)     │
│ priority: char            │ e.g. 'H' (High)            │
│ category: string          │ e.g. "Study"               │
│ complete: bool            │ e.g. false (In Progress)   │
└────────────────────────────────────────────────────────┘
```

### Algorithmic Complexity

| Operation | Time Complexity | Space Complexity | Description |
| :--- | :---: | :---: | :--- |
| **Add Task** | $O(1)$ | $O(1)$ | Direct insertion at current boundary |
| **Search by ID** | $O(n)$ | $O(1)$ | Linear scan across active array elements |
| **Update Task** | $O(n)$ | $O(1)$ | Search followed by member mutation |
| **Delete Task** | $O(n)$ | $O(1)$ | Element detachment with leftward array shift |
| **Save / Load** | $O(n)$ | $O(n)$ | Sequential disk read/write serialization |

---

## 🕹️ CLI Navigation

```text
=== Task Manager ===
1. Add Task
2. Display All Tasks
3. Search Task by ID
4. Update Task Status
5. Delete Task
6. Check Deadline Proximity
7. Save Tasks to File
8. Load Tasks from File
9. Exit
```

---

## 🛠️ Compilation & Execution

### Prerequisites
- C++11 or higher compiler (`g++`, `clang++`, or MSVC)

### Build with GCC / MinGW:
```bash
g++ -O2 -std=c++17 "C++ Project.cpp" -o task_manager
./task_manager
```

### Build with Clang:
```bash
clang++ -O2 -std=c++17 "C++ Project.cpp" -o task_manager
./task_manager
```

### Build with Microsoft Visual C++ (MSVC):
```cmd
cl.exe /O2 /std:c++17 "C++ Project.cpp" /Fe:task_manager.exe
task_manager.exe
```

---

## 📁 Repository Structure

```
Task-Management-System/
├── C++ Project.cpp       # Complete task management engine, data structs, and CLI loop
├── .gitignore            # Ignores compiled binaries (*.exe, *.o) and runtime task files
├── LICENSE               # MIT License
└── README.md             # Complete documentation
```

---

## 👥 Contributors
- **Younss Yahya** ([@youunss](https://github.com/youunss)) — Architecture, validation, and documentation.
- **Mohanad** ([@Honda-2005](https://github.com/Honda-2005)) — CLI implementation, file persistence, and maintenance.
