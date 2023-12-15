#include "TaskManager.h"

void TaskManager::addTask(const Task& task)
	{
    		tasks.push_back(task);
  		TaskByCategory[task.Category].push_back(task);
    		TaskByDate[task.Date].push_back(task);
	}

void TaskManager::displayTasks() 
	{
    		for (const auto& task : tasks)
	       		{
        			cout <<"Name: " << task.Name;
			      	cout <<"\tCategory: " << task.Category;
				cout <<"\tDue Date: " << task.Date << endl;
    			}
	}
