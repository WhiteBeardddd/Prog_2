#include <stdio.h>
#include <string.h>

// Enum to represent the status of a task
enum TaskStatus
{
    NEW,
    IN_PROGRESS,
    COMPLETED,
    CANCELLED
};

// Structure to represent a task
struct Task
{
    char title[50];
    enum TaskStatus status; // Use enum to store task status
};

// Function to print the status of a task
void printStatus(enum TaskStatus status)
{
    switch (status)
    {
    case NEW:
        printf("Status: New\n");
        break;
    case IN_PROGRESS:
        printf("Status: In Progress\n");
        break;
    case COMPLETED:
        printf("Status: Completed\n");
        break;
    case CANCELLED:
        printf("Status: Cancelled\n");
        break;
    default:
        printf("Unknown Status\n");
    }
}

// Function to update the status of a task
void updateStatus(struct Task *task, enum TaskStatus newStatus)
{
    task->status = newStatus;
    printf("Updated task '%s' to ", task->title);
    printStatus(newStatus);
}

int main()
{
    // Creating a task
    struct Task task1;
    strcpy(task1.title, "Complete Assignment");
    task1.status = NEW;

    // Display initial status
    printf("Task: %s\n", task1.title);
    printStatus(task1.status);

    // Update and display status changes
    updateStatus(&task1, IN_PROGRESS);
    updateStatus(&task1, COMPLETED);

    return 0;
}
