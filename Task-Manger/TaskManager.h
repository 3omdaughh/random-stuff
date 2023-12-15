/*
 * That is the Class of taskmanager 
 */
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Task.h"
using namespace std;
 
 class TaskManager
{
	private :
		vector<Task> tasks;
		map<string, vector<Task>> TaskByCategory;
		map<string, vector<Task>> TaskByDate;
	
	public :
		void addTask(const Task& task);
		void displayTasks();
};
