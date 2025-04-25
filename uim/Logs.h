#include "Headers.h"

void info()
{
    printf("[INFO]:\n");
    printf("Written in 2024 by Mohamed Emad (3omdaughh@gmail.com)\n");
    printf("This program is designed to simplify the creation and management of your UIM (Urgency Importance Matrix).\n");
    printf("It allows you to store your tasks in a CSV file, load them when needed, and provides functionality to modify or delete tasks.\n");
    printf("As an open-source program, you are free to modify the code to suit your needs.\n");
    printf("All rights reserved. This program is licensed under GNU General Public License Version 3.\n");
}

char warning(const char *s)
{
    char c;

    printf("[WARNING]: You are about to delete the task: %s\n", s);
    printf("[y,n] (press Enter for Yes): ");
 
    c = getchar();

    if (c == '\n')
    {
        return 'y';
    }

    while (getchar() != '\n');
  
    if (c == 'y' || c == 'n')
    {
        return c;
    }
    else
    {
        printf("Invalid argument.\n");
        exit(EXIT_FAILURE);
    }
}

void error()
{
    printf("[ERROR]: Can't reach the CSV file.\n");
    printf("Please check if you entered the file name correctly.\n");
}
