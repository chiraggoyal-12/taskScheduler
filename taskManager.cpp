#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;

    Task(string n, int p) : name(n), priority(p) {}
};

struct ComparePriority {
    bool operator()(Task const& a, Task const& b) {
        return a.priority < b.priority;  // Max-heap: higher priority comes first
    }
};

class TaskScheduler {
private:
    priority_queue<Task, vector<Task>, ComparePriority> taskQueue;

public:
    void addTask(string name, int priority) {
        taskQueue.push(Task(name, priority));
    }

    void runTask() {
        if (taskQueue.empty()) {
            cout << "No tasks to run.\n";
            return;
        }
        Task t = taskQueue.top();
        taskQueue.pop();
        cout << "Running task: " << t.name << " [Priority: " << t.priority << "]\n";
    }

    void showTasks() {
        if (taskQueue.empty()) {
            cout << "No pending tasks.\n";
            return;
        }
        priority_queue<Task, vector<Task>, ComparePriority> tempQueue = taskQueue;
        cout << "Pending Tasks:\n";
        while (!tempQueue.empty()) {
            Task t = tempQueue.top();
            cout << "- " << t.name << " (Priority: " << t.priority << ")\n";
            tempQueue.pop();
        }
    }
};

int main() {
    TaskScheduler scheduler;
    int choice;

    cout << "===== Task Scheduler =====\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. Run Highest Priority Task\n";
        cout << "3. Show Pending Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            int priority;
            cout << "Enter task name: ";
            getline(cin, name);
            cout << "Enter priority (higher = more important): ";
            cin >> priority;
            cin.ignore();
            scheduler.addTask(name, priority);
            cout << "Task added successfully.\n";
        } else if (choice == 2) {
            scheduler.runTask();
        } else if (choice == 3) {
            scheduler.showTasks();
        } else if (choice == 4) {
            cout << "Exiting Task Scheduler.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
