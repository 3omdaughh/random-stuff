#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Headers.h"
#include "Logs.h"

// Structure to hold task information
typedef struct {
    char name[100];
    char notes[255];
    int urgency; // 1: Low, 2: High
    int importance; // 1: Low, 2: High
} Task;

// Function prototypes
void add_task(const char *filename, const Task *task);
void display_tasks(const char *filename);
void remove_task(const char *filename, const char *task_name);
void modify_task(const char *filename, const char *task_name, const Task *new_task);

// Add a task to the CSV file
void add_task(const char *filename, const Task *task) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        error();
        return;
    }

    fprintf(file, "%s,%s,%d,%d\n", task->name, task->notes, task->urgency, task->importance);
    fclose(file);
    printf("Task added successfully!\n");
}

// Display tasks in a tabular format
void display_tasks(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        error();
        return;
    }

    printf("| %-20s | %-30s | %-7s | %-10s |\n", "Task Name", "Notes", "Urgency", "Importance");
    printf("|----------------------|--------------------------------|---------|-------------|\n");

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        Task task;
        sscanf(line, "%99[^,],%254[^,],%d,%d", task.name, task.notes, &task.urgency, &task.importance);
        printf("| %-20s | %-30s | %-7s | %-10s |\n",
               task.name, task.notes,
               task.urgency == 1 ? "Low" : "High",
               task.importance == 1 ? "Low" : "High");
    }

    fclose(file);
}

// Remove a task from the CSV file
void remove_task(const char *filename, const char *task_name) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        error();
        return;
    }

    FILE *temp = fopen("temp.csv", "w");
    if (!temp) {
        fclose(file);
        error();
        return;
    }

    char line[512];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        Task task;
        sscanf(line, "%99[^,],%254[^,],%d,%d", task.name, task.notes, &task.urgency, &task.importance);
        if (strcmp(task.name, task_name) != 0) {
            fprintf(temp, "%s", line);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(filename);
    rename("temp.csv", filename);

    if (found) {
        printf("Task '%s' removed successfully!\n", task_name);
    } else {
        printf("Task '%s' not found!\n", task_name);
    }
}

// Modify a task in the CSV file
void modify_task(const char *filename, const char *task_name, const Task *new_task) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        error();
        return;
    }

    FILE *temp = fopen("temp.csv", "w");
    if (!temp) {
        fclose(file);
        error();
        return;
    }

    char line[512];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        Task task;
        sscanf(line, "%99[^,],%254[^,],%d,%d", task.name, task.notes, &task.urgency, &task.importance);
        if (strcmp(task.name, task_name) == 0) {
            fprintf(temp, "%s,%s,%d,%d\n", new_task->name, new_task->notes, new_task->urgency, new_task->importance);
            found = 1;
        } else {
            fprintf(temp, "%s", line);
        }
    }

    fclose(file);
    fclose(temp);

    remove(filename);
    rename("temp.csv", filename);

    if (found) {
        printf("Task '%s' modified successfully!\n", task_name);
    } else {
        printf("Task '%s' not found!\n", task_name);
    }
}

#endif // FUNCTIONS_H
