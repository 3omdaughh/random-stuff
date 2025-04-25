#include "Headers.h"
#include "function.h"

#define FILENAME "tasks.csv"

void menu() {
    printf("\n--- Urgency Importance Matrix ---\n");
    printf("[1] Add Task\n");
    printf("[2] Display Tasks\n");
    printf("[3] Remove Task\n");
    printf("[4] Modify Task\n");
    printf("[5] Exit\n");
    printf("Choose an option: ");
}

signed main() {
    int choice;
    Task task;
    char task_name[100];

    info();

    while (1) {
        menu();
        
    	if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) { 
        // If scanf fails or the number is not in the range 1-5
        printf("Invalid input\n");
        return 1;
    	}

 	getchar(); // Clear the input buffer

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(task.name, sizeof(task.name), stdin);
                task.name[strcspn(task.name, "\n")] = 0; // Remove newline

                printf("Enter notes: ");
                fgets(task.notes, sizeof(task.notes), stdin);
                task.notes[strcspn(task.notes, "\n")] = 0; // Remove newline

                printf("Enter urgency (1: Low, 2: High): ");
                scanf("%d", &task.urgency);

                printf("Enter importance (1: Low, 2: High): ");
                scanf("%d", &task.importance);
                getchar(); // Clear the input buffer

                add_task(FILENAME, &task);
                break;

            case 2:
                display_tasks(FILENAME);
                break;

            case 3:
                printf("Enter task name to remove: ");
                fgets(task_name, sizeof(task_name), stdin);
                task_name[strcspn(task_name, "\n")] = 0; // Remove newline

                char confirm = warning(task_name);
                if (confirm == 'y') {
                    remove_task(FILENAME, task_name);
                } else {
                    printf("Task removal canceled.\n");
                }
                break;

            case 4:
                printf("Enter task name to modify: ");
                fgets(task_name, sizeof(task_name), stdin);
                task_name[strcspn(task_name, "\n")] = 0; // Remove newline

                printf("Enter new task name: ");
                fgets(task.name, sizeof(task.name), stdin);
                task.name[strcspn(task.name, "\n")] = 0; // Remove newline

                printf("Enter new notes: ");
                fgets(task.notes, sizeof(task.notes), stdin);
                task.notes[strcspn(task.notes, "\n")] = 0; // Remove newline

                printf("Enter new urgency (1: Low, 2: High): ");
                scanf("%d", &task.urgency);

                printf("Enter new importance (1: Low, 2: High): ");
                scanf("%d", &task.importance);
                getchar(); // Clear the input buffer

                modify_task(FILENAME, task_name, &task);
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
