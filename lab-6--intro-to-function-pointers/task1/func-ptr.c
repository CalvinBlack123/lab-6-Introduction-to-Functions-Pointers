#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int priority;
} Process;

// Comparison function for sorting by arrival time (ascending)
int compare_arrival_time(const void* a, const void* b) {
    Process* p1 = (Process*)a;
    Process* p2 = (Process*)b;
    return p1->arrival_time - p2->arrival_time;
}

// Comparison function for sorting by priority (descending, with arrival time as secondary)
int compare_priority(const void* a, const void* b) {
    Process* p1 = (Process*)a;
    Process* p2 = (Process*)b;
    
    // First, compare priority in descending order
    if (p1->priority != p2->priority)
        return p2->priority - p1->priority;
    
    // If priorities are equal, compare arrival time
    return p1->arrival_time - p2->arrival_time;
}

int main() {
    FILE* file = fopen("process.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Process processes[100];  // Assuming max 100 processes
    int count = 0;

    // Read processes from file
    while (fscanf(file, "%d %d %d", 
        &processes[count].pid, 
        &processes[count].arrival_time, 
        &processes[count].priority) == 3) {
        count++;
    }
    fclose(file);

    // Sort by arrival time
    printf("Sorted by Arrival Time (Ascending):\n");
    qsort(processes, count, sizeof(Process), compare_arrival_time);
    
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", 
            processes[i].pid, 
            processes[i].arrival_time, 
            processes[i].priority);
    }

    // Sort by priority
    printf("\nSorted by Priority (Descending):\n");
    qsort(processes, count, sizeof(Process), compare_priority);
    
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", 
            processes[i].pid, 
            processes[i].arrival_time, 
            processes[i].priority);
    }

    return 0;
}