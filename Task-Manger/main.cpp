#include "TaskManager.h"

int main ()
{
	TaskManager taskManager;
	Task task;

	cout <<"Enter Task name: ";
	getline(cin, task.Name);

	cout <<"Enter Category: ";
	getline(cin, task.Category);
	
	cout <<"Enter DeadLine (DD-MM-YYYY): ";
	getline(cin, task.Date);

	taskManager.addTask(task);

	cout <<"\n All Tasks:\n";
	taskManager.displayTasks();

	return 0;
}
